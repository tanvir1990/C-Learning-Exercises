//Basic Traffic light Operation and Interruptions
//Author: Tanvir Hossain
//Version: 07th October, 2018


// Source: Documents\ValvanoWare\EdgeInterrupt_MSP432\EdgeInterrupt
//    -- In Valvano's original, there were two versions, the second one eliminates critical sections
//    -- Have cleaned up the code to keep only the first version; will cover critical sections later
//    -- Have also removed BitBanding (because not covered yet in class)
//    Schramm, August 2018

// EdgeInterrupt.c
// Runs on MSP432
// Request an interrupt on the falling edge of P1.1 (when the user
// button is pressed) and increment a counter in the interrupt.  Note
// that button bouncing is not addressed.
// Daniel Valvano
// May 20, 2015

/* This example accompanies the book
   "Embedded Systems: Introduction to the MSP432 Microcontroller",
   ISBN: 978-1512185676, Jonathan Valvano, copyright (c) 2015
   Volume 1, Program 9.4


 Copyright 2015 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */

// built-in LED1 connected to P1.0
// negative logic built-in Button 1 connected to P1.1 (increment counter on falling edge)
// negative logic built-in Button 2 connected to P1.4 (increment counter on falling edge)
// built-in red LED connected to P2.0
// built-in green LED connected to P2.1
// built-in blue LED connected to P2.2

#include <stdint.h>
#include "..\..\inc\msp432p401r.h"

#define RED       0x01
#define BLUE      0x04

// global variable visible in Watch window of debugger
// increments at least once per button press
volatile uint32_t FallingEdges = 0;

void EdgeCounter_Init(void){
	__ASM("CPSID I");
	
  FallingEdges = 0;                // initialize counter

  P1SEL0 &= ~0x12;
  P1SEL1 &= ~0x12;                 // configure P1.4 and P1.1 as GPIO
  P1DIR &= ~0x12;                  // make P1.4 and P1.1 in (built-in Button 1 and Button 2)
  P1REN |= 0x12;                   // enable pull resistors on P1.4 and P1.1
  P1OUT |= 0x12;                   // P1.4 and P1.1 are pull-up
  P1IES |= 0x12;                   // P1.4 and P1.1 are falling edge event
  P1IFG &= ~0x12;                  // clear flag4 and flag1 (reduce possibility of extra interrupt)
  P1IE |= 0x12;                    // arm interrupt on P1.4 and P1.1

  NVIC_IPR8 = (NVIC_IPR8&0x00FFFFFF)|0x40000000; // priority 2
  NVIC_ISER1 = 0x00000008;         // enable interrupt 35 in NVIC

	__ASM("CPSIE I");								// Globally enable interrupts
}

void Port2_Output(uint8_t data){  // write three outputs bits of P2
  P2OUT = (P2OUT&0xF8)|data;

}

void PORT1_IRQHandler(void){
  FallingEdges = FallingEdges + 1;

	if ((P1IFG & 0x02) != 0) {

		P1IFG &= ~0x02;		// clear flag1, acknowledge
		P2OUT &= 0x00;
    P2OUT ^= RED;   // toggle LED1
		
  } else if ((P1IFG & 0x10) != 0) {
		
		P1IFG &= ~0x10;		// clear flag4, acknowledge
		P2OUT &= 0x00; 		 //clear with mask
    P2OUT ^= BLUE;   // toggle blue LED
  }
}

int main(void){

  EdgeCounter_Init();              // initialize P1.4 and P1.1 interrupts
  // initialize P1.0 and make it output (P1.0 built-in LED1)
  P1SEL0 &= ~0x01;
  P1SEL1 &= ~0x01;                 // configure built-in LED1 as GPIO
  P1DIR |= 0x01;                   // make built-in LED1 out
  P1OUT &= ~0x01;                  // LED1 = off
  // initialize P2.2-P2.0 and make them outputs (P2.2-P2.0 built-in RGB LEDs)
  P2SEL0 &= ~0x07;
  P2SEL1 &= ~0x07;                 // configure built-in RGB LEDs as GPIO
  P2DS |= 0x07;                    // make built-in RGB LEDs high drive strength
  P2DIR |= 0x07;                   // make built-in RGB LEDs out
  P2OUT &= ~0x07;                  // RGB = off

  while(1){
		//__ASM("WFI");
  }
}




#ifdef notdef

// Alternative Version: Uses P1IV to solve critical section/race
void PORT1_IRQHandler(void){ 
  uint8_t status;
  FallingEdges = FallingEdges + 1;
  status = P1IV;  // 2*(n+1) where n is highest priority
// if P1.1, returns 0x04 and clears flag1
// if P1.4, returns 0x0A and clears flag4
  if(status == 0x04){
    P1OUT ^= 0x01;                 // toggle LED1
    status = P1IV;
  }
  if(status == 0x0A){
    P2OUT ^= 0x06;                 // toggle blue and green RGB LEDs
  }
}
#endif
