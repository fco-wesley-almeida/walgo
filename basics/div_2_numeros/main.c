#include "stdio.h"
#include "stdlib.h"

int main()
{
    int a; // 4 bytes = 32 bits
    int b; // 4 bytes = 32 bits
    scanf("%d", &a);
    scanf("%d", &b);

    if (b == 0) {
        printf("Erro: B nao pode ser zero.");
        return 1;
    }
    
    int c = a / b;
    printf("Divisao: %d", c);
    return 0;
}