// Swapping an unsorted Array using bubble sort

#include <stdio.h>
#include <stdlib.h>


int swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int sort(int n, int *input_array){

    int a, b;
    for (int j = 0; j < n; j ++){
        for (int i = 0; i < n - 1; i++){
            a  = input_array[i];
            b = input_array[i+1];
            if ( a > b) {
                swap(input_array + i, input_array + i + 1);
            }
        }
    }   

}

int main(){
    
    int n = 5;
    //Dynamically create the input array
    // Could create the input array like following
    // *(input_array) = 5;
    // *(input_array + 1) = 2;
    // *(input_array + 2) = 3;
    // *(input_array + 3) = 4;
    // *(input_array + 4) = 1;

    int input_array[] = {5, 2, 3, 4, 1};
    sort(n, input_array);
    for (int i = 0; i< n; i++){
        printf("%d,  ", input_array[i]);
    }
    
    return 0;
}
