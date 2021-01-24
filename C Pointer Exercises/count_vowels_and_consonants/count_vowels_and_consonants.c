#include <stdio.h>

/*
 * @function count_vowel_and_consonants
 * @discussion counts the number of vowel and consonants of an input string
 * @param str pointer input string
 * @param *vowel_number pointer to the result
 * @param *consonant_number pointer the result
*/

int count_vowel_and_consonants(char* str, int* vowel_number, int* consonant_number){

    while (*(str) != '\0'){
        if (*(str) == 'a'|| *(str) == 'e'|| *(str) == 'i'||
                    *(str) == 'o'|| *(str) == 'u'){
                *vowel_number = *vowel_number + 1 ;
            }
        else {
            *consonant_number = *consonant_number + 1;
        }
        str++;
    }
}


/**
 * The main function that calls all different functions
 * 
*/ 
int main(){
    char str[] = "Test";
    int vowel_no = 0;
    int consonant_no = 0;

    count_vowel_and_consonants(str, &vowel_no, &consonant_no);
    printf("Number of Vowels = %d \n", vowel_no);
    printf("Number of Consonants = %d \n", consonant_no);
    return 0;
}

