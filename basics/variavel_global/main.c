#include "stdio.h"
#include "stdlib.h"

int pi = 3; // GLOCAL

void f1() 
{
    int pi = 4; // LOCAL
    printf("%d\n", pi);
    pi = 5; // LOCAL
}


void f2() 
{
    printf("%d\n", pi);
}

int main()
{
    f1();
    f2();
    return 0;
}
