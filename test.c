#include <stdio.h>

//Basic Syntax Refreshing
int main(){
    int m = 300;
    float fx = 300.600006;
    char cht = 'z';

    printf("address of m = %x \n", &m);
    printf("address of fx = %x \n", &fx);
    printf("address of cht = %x \n", &cht);

    printf("Value at address of m = %u \n", *(&m));
    printf("Value at address of fx = %f \n", *(&fx));
    printf("Value at address of cht = %c \n", *(&cht));

    int *pt1 = &m;
    float *pt2 = &fx;
    char *pt3 = &cht;

    printf("address of m = %x \n", pt1);
    printf("address of fx = %x \n", pt2);
    printf("address of cht = %x \n", pt3);

    printf("Value at address of m = %u \n", *(pt1));
    printf("Value at address of fx = %f \n", *(pt2));
    printf("Value at address of cht = %c \n", *(pt3));

    *pt1 = 5;
    *pt2 = 12345678;
    *pt3 = 'x';

    printf("Value at address of m = %u \n", m);
    printf("Value at address of fx = %f \n", fx); //This gives a different value, why?
    printf("Value at address of cht = %c \n", cht);






    return 0;
}