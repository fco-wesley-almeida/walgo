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

#define PRECO_P1 50.0
#define PRECO_P2 100.0
#define DESCONTO_IMPOSTO 10.0

// #define PI 3.14
// #define CONSTANTE_EULER 2.71828
// 2.71828

float calcular_faturamento(float q1, float q2)
{
    float faturamento_p1 = q1 * PRECO_P1;
    float faturamento_p2 = q2 * PRECO_P2;
    float faturamento_total = faturamento_p1 + faturamento_p2;
    return faturamento_total;
    // return q1 * 50 + q2 * 100;
}

float calcular_imposto(float faturamento)
{
    return faturamento / DESCONTO_IMPOSTO;
}

float calcular_lucro(float faturamento, float imposto)
{
    return faturamento - imposto;
}


int main()
{
    float q1;
    float q2;
    float faturamento;
    float imposto;
    float lucro;

    scanf("%f", &q1);
    scanf("%f", &q2);

    faturamento = calcular_faturamento(q1, q2);
    imposto = calcular_imposto(faturamento);
    lucro = calcular_lucro(faturamento, imposto);

    printf("Faturamento = %f\n", faturamento);
    printf("Imposto = %f\n", imposto);
    printf("Lucro = %f\n", lucro);

    return 0;
}
