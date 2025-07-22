#include <stdio.h>
#include "inverteFila.h"

int main(){
    Fila *fi;
    fi = criaFila();

    enfileirar(fi,10);
    enfileirar(fi,34);
    enfileirar(fi,45);
    enfileirar(fi,23);
    enfileirar(fi,54);
    enfileirar(fi,87);
    enfileirar(fi,45);
    enfileirar(fi,43);
    printf("Frente: %d\n",verInicio(fi));
    desenfileirar(fi);
    printf("Frente: %d\n",verInicio(fi));
    printf("------------------------------\n");
    printf("Fila :\n");
    imprime(fi);
    printf("------------------------------\n");
    printf("Fila invertida:\n");
    inverteFila(fi);
    destroiFila(fi);   
    return 0;
}