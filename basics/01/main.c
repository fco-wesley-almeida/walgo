// TIPO_RETORNO NOMEDAFUNCAO (TIPO1 VAR1, TIPO2 VAR2, ...)
// int, float, char, double, void
#include <stdlib.h>
#include <stdio.h>

int somaMaisUm(int x)
{
    return x + 1;
}



int main()
{
    int a; // 32 bits
    // 000 0 
    // 001 1
    // 00000000000000000000000000000000000000000010 2
    // 011 3
    // 100 4
    // 101 5
    // 110 6
    // 111 7
    int x1 = 1;
    int x2 = 2;
    int x3 = x1 + x2;
    // printf("VALOR=%d", x3);
    printf("VALOR=%d", x3);
    return EXIT_SUCCESS;
}