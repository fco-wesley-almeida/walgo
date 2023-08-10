#include "stdio.h"
#include "stdlib.h"

int main()
{
    int a; // 4 bytes = 32 bits
    int b; // 4 bytes = 32 bits
    scanf("%d", &a);
    scanf("%d", &b);
    int c = a - b;
    printf("Substracao: %d", c);
    return 0;
}