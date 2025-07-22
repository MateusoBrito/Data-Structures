#include <stdio.h>
#include "uniao.h"

int main(){
    FilaP *f1;
    FilaP *f2;
    f1 = criaFila();
    f2 = criaFila();

    inserirPrio(f1,1,5);
    inserirPrio(f1,2,2);
    inserirPrio(f1,3,10);

    imprime(f1);
    
    inserirPrio(f2,4,1);
    inserirPrio(f2,5,15);
    inserirPrio(f2,6,7);

    imprime(f2);

    printf("======================\n");

    uniaofilas(f1,f2);
    imprime(f1);
    imprime(f2);

    destroFila(f1);
    destroFila(f2);
}