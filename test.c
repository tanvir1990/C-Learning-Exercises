#include <stdio.h>

//Basic Syntax Refreshing

// int add(int *pa, int *pb){
//     int sum = *pa + *pb;
//     return sum;
// }
int main(){
    int a = 5;
    int b = 10;

    int *pa, *pb;
    pa = &a;
    pb = &b;

    if ( *pa > *pb){
        printf("%u is greater", *pa);
    }
    else 
        printf("%u is greater", *pb);
    

    return 0;
}