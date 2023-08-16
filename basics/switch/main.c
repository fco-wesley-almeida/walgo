#include "stdio.h"
#include "stdlib.h"

int main()
{
    int n;
    
    scanf("%d", &n);

    switch (n) {
        case 0:
            printf("N e igual a 0");
            break;
        case 1:
            printf("N e igual a 1");
            break;
        case 2:
            printf("N e igual a 2");
            break;
        default:
            printf("N e qualquer coisa");
    }

    // if (n == 0) {
    //     printf("N e igual a 0");
    // } else if (n == 1) {
    //     printf("N e igual a 1");
    // } else if (n == 2) {
    //     printf("N e igual a 2");
    // } else {
    //     printf("N e qualquer coisa");
    // }

    return 0;
}