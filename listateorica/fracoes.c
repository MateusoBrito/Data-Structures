#include <stdio.h>
#include "fracoes.h"

int main(){
    fracao *f1 = criaFracao();
    fracao *f2 = criaFracao();
    printf("============CALCULADORA FRACAO============\n");

    printf("Fracao 1.\nNumerador: ");
    scanf("%d",&f1->numerador);
    printf("Denominador: ");
    scanf("%d",&f1->denominador);

    printf("Fracao 2.\nNumerador: ");
    scanf("%d",&f2->numerador);
    printf("Denominador: ");
    scanf("%d",&f2->denominador);
    printf("------------------------------------------\n");

    printf("Soma: %.2f\n",somaFracoes(f1,f2));
    printf("Subtracao: %.2f\n",subtracaoFracoes(f1,f2));
    printf("Multiplicacao: %.2f\n",multiplicacaoFracoes(f1,f2));
    printf("Divisao: %.2f\n",divisaoFracoes(f1,f2));
    printf("Fracao 1:  %.2f\n",decimalFracao(f1));
    printf("Fracao 2:  %.2f\n",decimalFracao(f2));
    fracao *simp1 = simplificarFracao(f1);
    printf("Fracao 1 simplificada: ");
    imprimeFracao(simp1);
    fracao *simp2 = simplificarFracao(f2);
    printf("Fracao 2 simplificada: ");
    imprimeFracao(simp2);

    return 0;
}