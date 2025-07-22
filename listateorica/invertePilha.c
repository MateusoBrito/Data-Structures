#include <stdio.h>
#include "invertePilha.h"

int main(){
    Pilha *pi;
    pi = criaPilha();

    empilhar(pi,20);
    empilhar(pi,25);
    empilhar(pi,30);
    empilhar(pi,35);

    printf("Topo: %d\n",verTopo(pi));
    desempilhar(pi);
    printf("------------------------------\n");
    imprime(pi);
    printf("------------------------------\n");
    imprimeInvertido(pi);

    destroiPilha(pi);
    return 0;
}