#include <stdio.h>
#include "Desafio.h"


int main(){
    Lista *li;
    li = criaLista();
    
    insereFim(li,1);
    insereFim(li,2);
    insereFim(li,2);
    insereFim(li,3);
    insereFim(li,4);
    insereIni(li,5);
    insereIni(li,6);
    insereIni(li,7);

    imprimeLista(li);
    imprimeListaContrario(li);
    imprimeListaContrarioRep(li);
    

    destroiLista(li);
    return 0;
}
