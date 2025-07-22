#include <stdio.h>
#include "FilaP.h"


int main(){
   FilaP *fp;
   int escolha=0,elem, prio;
   int *p;

   do{
       printf("\n===========FILA===========\n");
       printf("1 - Criar fila\n");
       printf("2 - Inserir item\n");
       printf("3 - Ver inicio\n");
       printf("4 - Remover item\n");
       printf("5 - Imprimir\n");
       printf("6 - Tamanho\n");
       printf("7 - Destruir\n");
       printf("8 - Sair\n");
       printf("===========================\n");


       printf("Selecione uma opcao: ");
       scanf("%d",&escolha);


       switch (escolha){
       case 1:
            fp = criaFila();
            break;
       case 2:
            printf("Qual elemento deseja enfileirar?\n");
            scanf("%d",&elem);
            printf("Qual sua prioridade?\n");
            scanf("%d",&prio);
            inserirPrio(fp,elem,prio);
            break;
       case 3:
            verIni(fp,p);
            printf("O inicio da fila eh %d\n",*p);
            break;
       case 4:
            removeIni(fp);
            break;
       case 5:
            imprime(fp);
            break;
       case 6:
            printf("O tamanho da fila eh %d\n",tamanho(fp));
            break;
        case 7:
            destroFila(fp);
            break;
        case 8:
            break;      
       default:
            printf("Opcao inexistente!\n");
            break;
       }
   }while(escolha != 8);


   return 0;
}
