#include <stdio.h>

int calc_factorial(int n){
    if (n == 0 || n == 1){
        return 1;
    }

    else 
        return n * calc_factorial(n - 1);
}

int main(){
    int n = 10;

    int result = calc_factorial(n);

    printf("Factorical of %d is %u", n , result);
}