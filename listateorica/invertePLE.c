#include <stdio.h>
#include "invertePLE.h"

int main(){
    Pilha *pi;
    pi = criarPilha();

    empilhar(pi, 12);
    empilhar(pi, 87);
    empilhar(pi, 65);
    empilhar(pi, 23);

    imprime(pi);
    imprimeInvertido(pi);
    
    return 0;
}