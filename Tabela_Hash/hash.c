#include <stdio.h>
#include "hash.h"

int main(){

    Hash *H;
    H = criaHash(15);
    int busca;

    int i;
    for(i=0; i<100; i++)
        insereHashLSE(H, i);

    if(!buscaHashLSE(H, 62, &busca))
        printf("Elemento NAO encontrado.\n");
    else
        printf("Elemento %d encontrado.\n", busca);

    imprimeHash(H);

    return 0;
}