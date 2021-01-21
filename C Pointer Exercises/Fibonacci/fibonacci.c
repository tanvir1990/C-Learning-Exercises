
#include <stdio.h>

int calc_fibonacci(int n){
    if (n == 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else 
        return calc_fibonacci(n-1) + calc_fibonacci(n-2);
}

int main(){
    int n = 8;
    int result = calc_fibonacci(n);
    printf("The fibonacci series for %d number of elements is ", n);
    for (int i = 0; i < n; i++){
        printf("%d  ", calc_fibonacci(i));
    }
    
}