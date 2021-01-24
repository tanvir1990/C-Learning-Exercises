#include <stdio.h>

/*
 * @function count_vowel_and_consonants
 * @discussion counts the number of vowel and consonants of an input string
 * @param str pointer input string
 * @param *vowel_number pointer to the result
 * @param *consonant_number pointer the result
*/

int count_vowel_and_consonants(char* str, int* vowel_number, int* consonant_number){
    int i = 0;

    while (*(str+i) != '\0'){
        if (*(str+i) == 'a'|| *(str+i) == 'e'|| *(str+i) == 'i'||
                    *(str+i) == 'o'|| *(str+i) == 'u'){
                *vowel_number = *vowel_number +1 ;
            }
        else {
            *consonant_number = *consonant_number + 1;
        }
        i++;
    }
}


/**
 * The main function that calls all different functions
 * 
*/ 
int main(){
    char str[] = "Tanvir";
    int vowel_no = 0;
    int consonant_no = 0;

    count_vowel_and_consonants(str, &vowel_no, &consonant_no);
    printf("Number of Vowels = %d \n", vowel_no);
    printf("Number of Consonants = %d \n", consonant_no);
    return 0;
}

