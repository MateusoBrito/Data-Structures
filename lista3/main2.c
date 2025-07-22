#include <stdio.h>
#include "conjuntointeiros.h"

int main(){
    Conjunto c1;
    Conjunto c1igual;
    Conjunto c2;
    Conjunto vazio;

    criar_vetor(&c1);
    criar_vetor(&c1igual);
    criar_vetor(&c2);
    criar_vetor(&vazio);

    inserir(&c1,10);
    inserir(&c1,20);
    inserir(&c1,30);
    inserir(&c1,40);
    inserir(&c1,50);

    inserir(&c1igual,10);
    inserir(&c1igual,20);
    inserir(&c1igual,30);
    inserir(&c1igual,40);
    inserir(&c1igual,50);


    inserir(&c2,40);
    inserir(&c2,50);
    inserir(&c2,60);
    inserir(&c2,70);
    remove_elemento(&c2,70);

    printf("Conjunto 1: ");
    for(int i=0;i<c1.tam;i++){
        printf("%d ",c1.vetor[i]);
    }

    printf("\nConjunto 2: ");
    for(int i=0;i<c2.tam;i++){
        printf("%d ",c2.vetor[i]);
    }

    printf("\n_________________________________________________\n");

    Conjunto c3 = uniao_vetores(&c1,&c2);
    printf("\nUniao dos conjuntos: ");
    for(int i=0;i<c3.tam;i++){
        printf("%d ",c3.vetor[i]);
    }

    Conjunto c4 = interseccao_elementos(&c1,&c2);
    printf("\nInterseccao dos conjuntos: ");
    for(int i=0;i<c4.tam;i++){
        printf("%d ",c4.vetor[i]);
    }

    Conjunto c5 = diferenca_conjuntos(&c1,&c2);
    printf("\nDiferenca dos conjuntos: ");
    for(int i=0;i<c5.tam;i++){
        printf("%d ",c5.vetor[i]);
    }

    printf("\n_________________________________________________\n");

    if(teste_presenca(&c1,10))
        printf("\nO numero 10 esta no primeiro Conjunto");
    if(teste_presenca(&c1,100))
        printf("\nO numero 100 esta no primeiro Conjunto");

    printf("\n_________________________________________________\n");

    printf("\nO menor elemento do Conjunto 2 eh %d", menor_elemento(&c2));
    printf("\nO maior elemento do Conjunto 2 eh %d", maior_elemento(&c2));

    printf("\n_________________________________________________\n");

    if(teste_igualdade(&c1,&c1igual))
        printf("\nOs Conjuntos comparados sao iguais");
    if(teste_igualdade(&c1,&c2))
        printf("\nOs Conjuntos comparados sao iguais");

    printf("\nO tamanho do Conjunto 1 eh %d",tamanho_conjunto(&c1));

    if(teste_vazio(&vazio))
        printf("\nO conjunto testado esta vazio");

    return 0;
}