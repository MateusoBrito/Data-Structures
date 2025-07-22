#include <stdio.h>
#include "Lista.h"


int main(){
    Lista *li;
    li = criaLista();
    Lista *ord;
    ord = criaLista();

    insereOrd(ord,12);
    insereOrd(ord,2);
    insereOrd(ord,54);
    insereOrd(ord,23);
    printf("Lista ordenada: ");
    imprimeLista(ord);

    insereFim(li,1);
    insereFim(li,2);
    insereFim(li,2);
    insereFim(li,3);
    insereFim(li,4);
    insereIni(li,5);
    insereIni(li,6);
    insereIni(li,7);

    imprimeLista(li);

    printf("O elemento 1 esta na posicao %d.\n", procura(li,1));
    printf("O tamanho da lista eh %d.\n", tamanhoLista(li));

    removeOco(li,2);
    removeIni(li);
    removeIni(li);
    removeIni(li);
    removeFim(li);

    imprimeLista(li);


    destroiLista(li);
    return 0;
}
