#include "stdio.h"
#include "stdlib.h"

/*
    p1 = 50 ud
    p2 = 100 ud

    custo = 0
    faturamento = (5 * 50) + (10 * 100)
    
    faturamento = (q1 * p1) + (q2 * p2)
    imposto = faturamento / 10
    lucro = faturamento - imposto


    q1 = 10
    q2 = 20
*/

#define PRECO_P1 50
#define PRECO_P2 100
#define DESCONTO_IMPOSTO 10

// #define PI 3.14
// #define CONSTANTE_EULER 2.71828
// 2.71828

int calcular_faturamento(int q1, int q2)
{
    int faturamento_p1 = q1 * PRECO_P1;
    int faturamento_p2 = q2 * PRECO_P2;
    int faturamento_total = faturamento_p1 + faturamento_p2;
    return faturamento_total;
    // return q1 * 50 + q2 * 100;
}

int calcular_imposto(int faturamento)
{
    return faturamento / DESCONTO_IMPOSTO;
}

int calcular_lucro(int faturamento, int imposto)
{
    return faturamento - imposto;
}


int main()
{
    int q1;
    int q2;
    int faturamento;
    int imposto;
    int lucro;

    scanf("%d", &q1);
    scanf("%d", &q2);

    faturamento = calcular_faturamento(q1, q2);
    imposto = calcular_imposto(faturamento);
    lucro = calcular_lucro(faturamento, imposto);

    printf("Faturamento = %d\n", faturamento);
    printf("Imposto = %d\n", imposto);
    printf("Lucro = %d\n", lucro);

    return 0;
}
