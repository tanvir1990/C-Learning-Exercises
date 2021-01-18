#include <stdio.h>

//Basic Syntax Refreshing

int add(int *pa, int *pb){
    int sum = *pa + *pb;
    return sum;
}
int main(){
    int a = 55;
    int b = 1;

    int *pa, *pb;
    pa = &a;
    pb = &b;

    int sum = add(pa, pb);

    printf("%u", sum);
    

    return 0;
}