#include "stdio.h"
#include "stdlib.h"

int main()
{
    int n;
    // unsigned long long

    scanf("%d", &n);

    int i;
    for(i = 0; i < n; i = i + 1) {
        printf("%d ", i);
    }

    // for(int i = 0; i <= n; i = i + 1) {
    //     printf("%d ", i);
    // }

    // int i;
    // i = 0;
    // while(i < n) {
    //     printf("%d ", i);
    //     i = i + 1;
    // }

    // for(int i = 0; i < n;) {
    //     printf("%d ", i);
    // }

    // int i;
    // i = 0;
    // while(1) {
    //     printf("%d ", i);
    //     i = i + 1;
    // }

    // int i;

    // i = 0;
    // goto l1;

    // l2:
    //     i = i + 1;
    // l1:
    //     if (i < n) { // Se a iteração pode continuar
    //         printf("%d ", i);
    //         goto l2;
    //     }

    return 0;
}