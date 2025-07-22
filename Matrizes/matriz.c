#include <stdio.h>
#include "matriz.h"


int main(){
    Matriz *M;
    M = criaMatriz(5, 5);
    imprime(M);
    for(int i=0; i<5; i++){
    for(int j=0;j<5;j++)
    M->dados[i][j] = i+j;
    }
    imprime(M);
    printf("==============================\n");




    Matriz *TS, *TI;
    TS = criaTriangularSup(M);
    TI = criaTriangularInf(M);


    printf("Triangular Sup:\n");
    imprime(TS);
    printf("Triangular Inf:\n");
    imprime(TI);


    Matriz* T;
    T = criaTransposta(M);
    printf("Transposta:\n"); imprime(T);


    destroiMatriz(M);
    return 0;
}
