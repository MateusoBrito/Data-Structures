#ifndef CUBO_H
#define CUBO_H

#include <stdio.h>

typedef struct{
    float comprimento;
    float altura;
    float profundidade;
}Cubo;

float lado(Cubo *c){
    return c->comprimento * c->altura;
}

float area(Cubo *c){
    return 6*(c->comprimento * c->altura);
}

float volume(Cubo *c){
    return c->comprimento * c->altura * c->profundidade;
}

#endif