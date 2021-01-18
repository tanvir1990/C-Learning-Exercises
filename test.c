#include <stdio.h>

//Basic Syntax Refreshing
int main(){
    int a = 5;
    int b = 10;

    int *pa, *pb, psum;
    pa = &a;
    pb = &b;

    int sum = *pa + *pb;

    printf("%u", sum);
    

    return 0;
}