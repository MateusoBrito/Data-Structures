#include <stdio.h>
#include "OrdemPilha.h"

int main(){
    Pilha *pi;
    pi = criaPilha();

    empilhar(pi,1);
    empilhar(pi,2);
    printf("%d\n",verTopo(pi));
    empilhar(pi,3);
    empilhar(pi,4);
    printf("%d\n",verTopo(pi));
    desempilhar(pi);
    printf("%d\n",verTopo(pi));
    desempilhar(pi);
    desempilhar(pi);
    printf("%d\n",verTopo(pi));

    destroiPilha(pi);
    return 0;
}