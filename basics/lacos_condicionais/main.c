#include "stdio.h"
#include "stdlib.h"

int main()
{
    int n;
    
    scanf("%d", &n);

    // if (n > 10) {
    //     printf("N e maior que 10.");
    // } else {
    //     printf("N e menor ou igual a 10.");
    // }

    // if (n > 10) {
    //     printf("N e maior que 10.");
    // }
    // if (n <= 10) {
    //     printf("N e menor ou igual a 10.");
    // }

    // 5
    // 10
    // 21
    // if (n < 10) {
    //     printf("N e menor que 10.");
    // } else if (n < 20) {
    //     printf("N e maior ou igual a 10 e menor que 20.");
    // } else {
    //     printf("N e maior ou igual a 20.");
    // }

    if (n == 0) {
        printf("N e igual a 0");
    } else if (n == 1) {
        printf("N e igual a 1");
    } else if (n == 2) {
        printf("N e igual a 2");
    } else {
        printf("N e qualquer coisa");
    }

    return 0;
}