#include <stdio.h>
#include "Fila.h"


int main(){
   Fila *fi;
   int escolha=0,elem;


   do{
       printf("\n===========FILA===========\n");
       printf("1 - Criar fila\n");
       printf("2 - Enfileirar\n");
       printf("3 - Ver inicio\n");
       printf("4 - Desenfileirar\n");
       printf("5 - Imprimir\n");
       printf("6 - Destruir\n");
       printf("7 - Sair\n");
       printf("===========================\n");


       printf("Selecione uma opcao: ");
       scanf("%d",&escolha);


       switch (escolha){
       case 1:
           fi = criaFila();
           break;
       case 2:
           printf("Qual elemento deseja enfileirar?\n");
           scanf("%d",&elem);
           enfileirar(fi, elem);
           break;
       case 3:
           printf("O inicio da fila eh %d\n",verInicio(fi));
           break;
       case 4:
           desenfileirar(fi);
           break;
       case 5:
           imprime(fi);
           break;
       case 6:
           break;
        case 7:
           destroiFila(fi);
           break;     
       default:
           printf("Opcao inexistente!\n");
           break;
       }
   }while(escolha != 7);


   return 0;
}
