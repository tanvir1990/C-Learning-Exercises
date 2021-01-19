#include <stdio.h>

//Basic Syntax Refreshing
int main(){
    int m = 10;
    int n, o;
    int* z;
    z = &m;

    printf ("z stores the address of m %x \n", &m);
    //printf ("*z stores the address of m %u", *z);
    printf ("*z stores the address of m %x", *(&z));
    //Changin again
    return 0;
}