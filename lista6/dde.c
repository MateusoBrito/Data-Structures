#include <stdio.h>
#include "dde.h"


int main(){
   Deque *dq;
   int escolha=0,elem;
   int *p;


   do{
       printf("\n===========DEQUE===========\n");
       printf("1 - Criar deque\n");
       printf("2 - Inserir no fim\n");
       printf("3 - Inserir no inicio\n");
       printf("4 - Ver inicio\n");
       printf("5 - Ver Fim\n");
       printf("6 - Remover no fim\n");
       printf("7 - Remover no inicio\n");
       printf("8 - Imprimir\n");
       printf("9 - Destruir\n");
       printf("10 - Sair\n");
       printf("===========================\n");


       printf("Selecione uma opcao: ");
       scanf("%d",&escolha);


       switch (escolha){
       case 1:
           dq = criaDeque();
           break;
       case 2:
           printf("Qual elemento deseja inserir?\n");
           scanf("%d",&elem);
           insereFim(dq,elem);
           break;
       case 3:
           printf("Qual elemento deseja inserir?\n");
           scanf("%d",&elem);
           insereIni(dq,elem);
           break;
       case 4:
           verIni(dq,p);
           printf("O inicio eh %d\n",*p);
           break;
       case 5:
           verFim(dq,p);
           printf("O inicio eh %d\n",*p);
           break;
       case 6:
           removeFim(dq);
           break;
       case 7:
           removeIni(dq);
           break;
       case 8:
           imprime(dq);
           break;
       case 9:
           destroiDeque(dq);
           break;
       case 10:
           break;       
       default:
           printf("Opcao inexistente!\n");
           break;
       }
   }while(escolha != 7);


   return 0;
}
