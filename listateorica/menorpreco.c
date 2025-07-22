#include <stdio.h>
#include "menorpreco.h"

int main(){
    Lista *L;
    L = criaLista();

    insereFim(L, 50);
    insereFim(L, 80);
    insereFim(L, 10);
    insereFim(L, 70);
    insereFim(L, 40);


    imprimeLista(L);
    menorPreco(L);

    destroiLista(L);
    return 0;
}