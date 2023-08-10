#include "stdio.h"
#include "stdlib.h"

int main()
{
    int a;
    int b;
    scanf("%d %d", &a, &b);
    int c = a * b;
    printf("Multiplicao: %d", c);
    return 0;
}