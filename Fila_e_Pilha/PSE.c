#include <stdio.h>
#include "PSE.h"

int main(){
    Pilha *pi;
    pi = criarPilha();

    empilhar(pi, 12);
    empilhar(pi, 87);
    empilhar(pi, 65);
    empilhar(pi, 23);
    verTopo(pi);
    imprime(pi);
    desempilhar(pi);
    verTopo(pi);
    imprime(pi);
    destroiPilha(pi);
    return 0;
}