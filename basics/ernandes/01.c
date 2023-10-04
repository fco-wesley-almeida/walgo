#include "stdio.h"
#include "stdlib.h"

// area = largura * comprimento
// calcularArea (java, c#, php, js): camelCase
// calcaular_area (python): snake_case
// calcular-area: kebab-case
// CalcularArea: PascalCase (c#) 

int calcular_area(int largura, int comprimento)
{
    return largura * comprimento;
}


int main()
{
    int largura;
    int comprimento;
    int area;

    scanf("%d", &largura);
    scanf("%d", &comprimento);

    area = calcular_area(largura, comprimento);

    printf("Area = %d\n", area);

    return 0;
}
