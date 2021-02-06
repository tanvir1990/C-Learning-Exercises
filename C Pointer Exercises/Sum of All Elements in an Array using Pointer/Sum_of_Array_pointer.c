// Sum of Array using pointer, pointer function, and call by reference

#include <stdio.h>
#include <stdlib.h>

int* sum_of_array(int n, int* array_input){
    int start = 0;
    int *result = &start;
    for (int i = 0; i < n; i++){
        *result = *result + *(array_input + i);
    }   
    return result;
}

int main(){
    int n = 5;
    int array_input[] = {1, 2};
    int* result = 0;

    result = sum_of_array(n, array_input);
    printf("Sum is %d", *result);

    return 0;
}
