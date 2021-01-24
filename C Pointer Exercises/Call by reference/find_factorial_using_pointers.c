#include <stdio.h>

/*
 * @function find_fact
 * @discussion finds the factorial of a number using pointer
 * @param n the number for which factorial is to be found
 * @param *f pointer to the result
*/

int find_fact(int n, int *f){
    *f = 1;
    for (int i = 1; i <= n; i++){
        *f = *f * i;
    }
    
}

int count_vowel_and_consonants(char* str, int vowel_number, int consonant_number){

}



/**
 * The main function that calls all different functions
 * 
*/ 
int main(){
    int n = 5;
    int ref_variable;
    find_fact(n, &ref_variable);
    printf("Factorial is %d", ref_variable);

    char str[] = "Test";
    int 
    return 0;
}

