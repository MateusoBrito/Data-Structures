#include <stdio.h>
#include "cubo.h"

int main(){
    Cubo c;
    printf("        CALCULADORA DE CUBO\n");

    printf("Comprimento: ");
    scanf("%f", &c.comprimento);
    printf("Altura: ");
    scanf("%f", &c.altura);
    printf("Profundidade: ");
    scanf("%f", &c.profundidade);
    printf("________________________________________\n");

    printf("        RESULTADOS\n");
    printf("Lado: %.2f\n",lado(&c));
    printf("Area: %.2f\n",area(&c));
    printf("Volume: %.2f\n",volume(&c));

    return 0;
}