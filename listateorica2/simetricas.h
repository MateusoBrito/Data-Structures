#ifndef SIMETRICAS_H
#define SIMETRICAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct{
   int qtd, ini, fim;
   char letras[MAX];
}Deque;


Deque* criaDeque(){
   Deque *dq;
   dq = (Deque*)malloc(sizeof(Deque));
   if(dq!=NULL){
       dq->qtd = dq->ini = dq->fim = 0;
   }
   return dq;
}


void destroiDeque(Deque *dq){
   if(dq != NULL)
       free(dq);
}


int tamanhoDeque(Deque *dq){
   if(dq == NULL) return -1;
   return dq->qtd;
}


int estaCheio(Deque *dq){
   if(dq == NULL) return -1;
   return (dq->qtd == MAX);
}


int estaVazio(Deque *dq){
   if(dq==NULL) return -1;
   return (dq->qtd == 0);
}


int insereFim(Deque *dq, char elem){
   if(dq == NULL) return 0;
   dq->letras[dq->fim] = elem;
   dq->fim = (dq->fim+1) % MAX;
   dq->qtd++;
   return 1;
}


void imprime(Deque *dq){
   if(dq==NULL) return;
   if(estaVazio(dq)){
       printf("Deque Vazio!\n");
       return;
   }
   printf("%s\n",dq->letras);
   return;
}

int simetricas(Deque *dq){
   if(dq==NULL) return 0;
   if(estaVazio(dq)){
       printf("Deque Vazio!\n");
       return 0;
   }
   int ini = 0;
   int fim = dq->qtd-1;
   printf("\n=========TESTE SIMETRIA=========\n");
   while (ini<fim){
      if(dq->letras[ini] != dq->letras[fim]){
         printf("       Nao eh simetrico!:(\n");
         printf("================================\n\n");
         return 0;
      }
      ini++;
      fim--;
   }
   printf("       Eh simetrico!:)\n");
   printf("================================\n\n");
   return 1;
}

#endif
