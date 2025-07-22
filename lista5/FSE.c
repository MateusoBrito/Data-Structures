#include <stdio.h>
#include "FSE.h"

int main(){
    Fila *fi;
    fi = criaFila();

    enfileirar(fi,23);
    enfileirar(fi,43);
    enfileirar(fi,12);
    enfileirar(fi,65);
    enfileirar(fi,89);
    enfileirar(fi,18);
    imprimeFila(fi);
    desenfileirar(fi);
    imprimeFila(fi);
    destroiFila(fi);
    return 0;
}