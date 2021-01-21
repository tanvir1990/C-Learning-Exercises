#include <stdio.h>
#include <stdlib.h>

//Find the maximum number using Dynamic Memory Allocation

int main(){
    
    int n, i, *ptr, sum = 0;
    static int largest_value = 0;
    n = 5;
    //Allocating memory
    ptr = (int*) malloc(n * sizeof(int));

    //Checking for NULL
    if (ptr == NULL) {
        printf("Error, Memory Cant be allocated");
        exit(0);
    }
    
    //Assigning Some Random Values to the 5 addresses
    *(ptr + 0) = 1;
    *(ptr + 1) = 2;
    *(ptr + 2) = 10;
    *(ptr + 3) = 5;
    *(ptr + 4) = 7;

    //A for loop to go through all the n addresses, and
    //retrieve and compare the values to find the largest
    for (i = 0; i < n; i++){
        if (*(ptr + i) > largest_value){
            largest_value = *(ptr+i);
        }
    }

    printf("largest Value is %d \n", largest_value);
    free(ptr);

    return 0;
}
