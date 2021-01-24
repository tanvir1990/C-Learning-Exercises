#include <stdio.h>

//Basic Syntax Refreshing
int main(){
    char str[] = "Test";
    int count = 0;
    int * p_count = &count;
    int i = 0;

    while ( *(str + i) != '\0'){
        *p_count = *p_count + 1;
        i++;

    }
    printf("Length is %d", count);
    
    return 0;
}