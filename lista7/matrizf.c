#include <stdio.h>
#include "matrizf.h"

int main(){
    MFaixa* M;
    int escolha=0,elem,i,j;

    do{
       printf("\n===========MATRIZ===========\n");
       printf("1 - Criar matriz\n");
       printf("2 - Inserir\n");
       printf("3 - Consulta\n");
       printf("4 - Imprime em vetor\n");
       printf("5 - Imprime Faixa\n");
       printf("6 - Destruir\n");
       printf("7 - Sair\n");
       printf("===========================\n");


       printf("Selecione uma opcao: ");
       scanf("%d",&escolha);


    switch (escolha){
        case 1:
            M = criaMatriz(5);
            break;
        case 2:
            printf("Qual elemento deseja inserir?\n");
            scanf("%d",&elem);
            printf("Aonde? [i][j]\n");
            scanf("%d",&i);
            scanf("%d",&j);
            insereElem(M,elem,i,j);
            break;
        case 3:
            printf("Qual elemento deseja consultar? [i][j]\n");
            scanf("%d",&i);
            scanf("%d",&j);
            consultaElem(M,i,j);
           break;
       case 4:
           imprimeFaixaVetores(M);
           break;
       case 5:
           imprimeFaixa(M);
           break;
       case 6:
           destroiMatriz(M);
           break;
       case 7:
           break;   
       default:
           printf("Opcao inexistente!\n");
           break;
       }
   }while(escolha != 7);
    return 0;
}
