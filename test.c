#include <stdio.h>

//Basic Syntax Refreshing

int main(){
    int n = 5;
    int e[2];
    // for (int i = 0; i < n; i++){
    //     e[i] = i;
    // }
    e[0] = 1;
    e[1] = 2;
    printf("%d \n", *e);
    printf("%d \n", *(e+1));
    printf("%d \n", e+2);
    printf("%d \n", e+3);



    return 0;
}