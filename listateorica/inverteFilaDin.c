#include <stdio.h>
#include "inverteFilaDin.h"

int main(){
    Fila *fi;
    fi = criaFila();

    enfileirar(fi,23);
    enfileirar(fi,43);
    enfileirar(fi,12);
    enfileirar(fi,65);
    enfileirar(fi,89);
    enfileirar(fi,18);
    desenfileirar(fi);
    printf("------------------------------\n");
    imprimeFila(fi);
    printf("------------------------------\n");
    imprimeFilaInvertida(fi);
    destroiFila(fi);
    return 0;
}