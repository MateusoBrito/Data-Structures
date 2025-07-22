#include <stdio.h>
#include "ABP.h"

int main(){

    ABP* A;
    A = criaABP();
    imprime(A);

    insereElem(A, 10);
    insereElem(A, 2);
    insereElem(A, 5);
    insereElem(A, 14);
    insereElem(A, 10);
    insereElem(A, 6);
    insereElem(A, 20);
    insereElem(A, 1);
    insereElem(A, 12);
    insereElem(A, 4);

    removeElem(A, 10);
    imprime(A);

    maiorElemento(A);
    menorElemento(A);
    destroiABP(A);
    return 0;
}