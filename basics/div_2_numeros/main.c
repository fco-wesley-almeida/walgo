#include "stdio.h"
#include "stdlib.h"


int main()
{
    int a; // 2 bytes = 16 bits
    int b; // 2 bytes = 16 bits

    scanf("%d", &a);
    scanf("%d", &b);

    if (b == 0) {
        printf("Erro: B nao pode ser zero.");
        return 1;
    } else {
        int c = a / b;
        printf("Divisao: %d", c);
        return 0;
    }
}
