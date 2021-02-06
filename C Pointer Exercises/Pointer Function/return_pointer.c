#include <stdio.h>
#include <stdlib.h>

int* find_max(int* a, int* b){
    if (*a > *b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    int a = 8;
    int b = 9;
    int* result = 0;

    result = find_max(&a, &b);
    printf("Larger Value is : %d", *result);


    return 0;
}
