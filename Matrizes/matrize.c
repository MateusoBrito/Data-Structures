#include <stdio.h>
#include "matrize.h"

int main(){
    Matriz *M;
    MEsparsaCSR *MS;
    int escolha=0,elem,i,j;

    do{
       printf("\n===========MATRIZ===========\n");
       printf("1 - Criar matriz\n");
       printf("2 - Inserir\n");
       printf("3 - Remove\n");
       printf("4 - Consulta\n");
       printf("5 - Transforma em CSR\n");
       printf("6 - Imprime em vetor\n");
       printf("7 - Imprime Esparsa\n");
       printf("8 - Destruir\n");
       printf("9 - Sair\n");
       printf("===========================\n");


       printf("Selecione uma opcao: ");
       scanf("%d",&escolha);


        switch (escolha){
            case 1:
                MS = criaMatrizEsparsa(4,6,0);
                break;
            case 2:
                printf("Qual elemento deseja inserir?\n");
                scanf("%d",&elem);
                printf("Aonde? [i][j]\n");
                scanf("%d",&i);
                scanf("%d",&j);
                insereElemEsparsa(MS,elem,i,j);
                break;
            case 3:
                printf("Qual elemento deseja remover? [i][j]\n");
                scanf("%d",&i);
                scanf("%d",&j);
                removeElemEsparsa(MS,i,j);
                break;
            case 4:
                printf("Qual elemento deseja consultar? [i][j]\n");
                scanf("%d",&i);
                scanf("%d",&j);
                consultaElemEsparsa(MS,i,j);
                break;
            case 5:
                MS = transformaEmCSR(M);
                break;
            case 6:
                imprimeEsparsaVetores(MS);
                break;
            case 7:
                imprimeEsparsa(MS);
                break;
            case 8:
                destroiMatriz(M);
                destroiMatrizEsparsa(MS);
                break;
            case 9:
                break;
            default:
                printf("Opcao inexistente!\n");
                break;
            }
        }while(escolha != 9);
    return 0;
}
