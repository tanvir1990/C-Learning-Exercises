#include <stdio.h>

//Basic Syntax Refreshing
int main(){
    float fx = 300.600006;

    float *pt = &fx;


    *pt = 12345678;
    printf("01 Value at address of fx = %f \n", fx); //This gives a different value, why?

    *pt = 123456789; 
    printf("02 Value at address of fx = %f \n", fx); //This gives a different value, why?

    *pt = 1234.5678;
    printf("03 Value at address of fx = %f \n", fx); //This gives a different value, why?

   *pt = 12345678.0;
    printf("04 Value at address of fx = %f \n", fx); //This gives a different value, why?

   *pt = 12345678.1;
    printf("05 Value at address of fx = %f \n", fx); //This gives a different value, why?

    return 0;
}