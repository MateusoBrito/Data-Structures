#ifndef FRACOES_H
#define FRACOES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct fracao{
    int numerador;
    int denominador;
}fracao;

fracao* criaFracao(){
    fracao *f;
    f = (fracao*)malloc(sizeof(fracao));
    return f;
}

float somaFracoes(fracao *f1, fracao *f2){
    return ((float)(f1->numerador)/f1->denominador) + ((float)(f2->numerador)/f2->denominador);
}

float subtracaoFracoes(fracao *f1, fracao *f2){
    return ((float)(f1->numerador)/(f1->denominador)) - ((float)(f2->numerador)/(f2->denominador));
}

float multiplicacaoFracoes(fracao *f1, fracao *f2){
    return ((float)f1->numerador * f2->numerador) / ((float)f1->denominador * f2->denominador);
}

float divisaoFracoes(fracao *f1, fracao *f2){
    return ((float)(f1->numerador / f1->denominador) * ((float)f2->denominador / f2->numerador));
}

float decimalFracao(fracao *f){
    return ((float)f->numerador / (float)f-> denominador);
}

int MDC(int n1, int n2){
    if(n2 == 0) return n1;
    else return MDC(n2, n1 % n2);
}

fracao* simplificarFracao(fracao *f){
    int mdc = MDC(f->numerador, f->denominador);
    fracao *simp = criaFracao();
    simp->numerador = f->numerador / mdc;
    simp->denominador = f->denominador / mdc;
    return simp;
}

void imprimeFracao(fracao *f){
    printf("%d / %d\n", f->numerador,f->denominador);
}

#endif