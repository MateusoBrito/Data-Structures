#include <stdio.h>
#include "Pilha.h"


int main(){
   Pilha *pi;
   int escolha=0,elem;


   do{
       printf("\n===========PILHA===========\n");
       printf("1 - Criar pilha\n");
       printf("2 - Empilhar\n");
       printf("3 - Ver topo\n");
       printf("4 - Desempilhar\n");
       printf("5 - Imprimir\n");
       printf("6 - Destruir\n");
       printf("7 - Sair\n");
       printf("===========================\n");


       printf("Selecione uma opcao: ");
       scanf("%d",&escolha);


       switch (escolha){
       case 1:
           pi = criaPilha();
           break;
       case 2:
           printf("Qual elemento deseja empilhar?\n");
           scanf("%d",&elem);
           empilhar(pi,elem);
           break;
       case 3:
           printf("O inicio da pilha eh %d\n",verTopo(pi));
           break;
       case 4:
           desempilhar(pi);
           break;
       case 5:
           imprime(pi);
           break;
       case 6:
            destroiPilha(pi);
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
