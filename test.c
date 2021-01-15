#include <stdio.h>

//Basic Syntax Refreshing
int main(){
    int m = 29;
    int n, o;
    int* z, *ab;
    z = &m;
    
    printf("Address of m: %x \n", z);
    printf("Value of m: %u \n\n", m);

    printf("Now ab is assigned with the address of m \n");
    ab = z;

    printf("Address of pointer ab: %x \n", ab);
    printf("Content of pointer ab: %u \n\n", *(ab));

    printf("The m is assigned 34 \n");

    m = 34;

    printf("Address of pointer ab: %x \n", ab);
    printf("Content of pointer ab: %u \n\n", *(ab));


    printf("Pointer variable ab is assigned 7 \n");
    *ab = 7;
    printf("Address of m %x \n", &m);
    printf("value of m %u \n", m);



    return 0;
}