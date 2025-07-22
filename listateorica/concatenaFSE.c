#include <stdio.h>
#include "concatenaFSE.h"

int main(){
    Fila *f1;
    f1 = criaFila();

    enfileirar(f1,80);
    enfileirar(f1,90);
    enfileirar(f1,100);
    printf("Fila 1:\n");
    imprime(f1);

    printf("-----------------------------\n");

    Fila *f2;
    f2 = criaFila();

    enfileirar(f2,110);
    enfileirar(f2,120);
    enfileirar(f2,130);
    printf("Fila 2:\n");
    imprime(f2);

    printf("-----------------------------\n");
    concatenaFilas(f1,f2);
    printf("Fila concatenada:\n");
    imprime(f1);
    printf("Fila 2:\n");
    imprime(f2);

    destroiFila(f1);
    destroiFila(f2);
    return 0;
}