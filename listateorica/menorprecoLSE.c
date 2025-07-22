#include <stdio.h>
#include "menorprecoLSE.h"

int main(){
    Lista *L;
    L = criaLista();

    insereFim(L, 50);
    insereFim(L, 10);
    insereFim(L, 20);
    insereFim(L, 9);
    insereFim(L, 23);


    imprimeLista(L);
    menorPreco(L);

    destroiLista(L);
    return 0;
}
