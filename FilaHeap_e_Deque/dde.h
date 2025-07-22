#ifndef DDE_H
#define DDE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO *ant;
    struct NO *prox;
}NO;

typedef struct{
    int qtd;
    struct NO *ini;
    struct NO *fim;
}Deque;

Deque *criaDeque(){
    Deque *dq;
    dq = (Deque*)malloc(sizeof(Deque));
    if(dq!=NULL){
        dq->qtd = 0;
        dq->ini = dq->fim = NULL;
    }
    return dq;
}

int tamanhoDeque(Deque *dq){
    if(dq==NULL) return -1;
    return dq->qtd;
}

int estaVazio(Deque *dq){
    if(dq==NULL) return -1;
    return (dq->qtd == 0);
}

NO* alocarNO(){
    return (NO*)malloc(sizeof(NO));
}

void liberarNO(NO* no){
    free(no);
}

int insereFim(Deque *dq, int elem){
    if(dq==NULL) return 0;
    NO *novo = alocarNO();
    novo->info = elem;
    novo->prox = NULL;
    if(estaVazio(dq)){
        novo->ant = NULL;
        dq->ini = novo;
    } else {
        dq->fim->prox = novo;
        novo->ant = dq->fim;
    }
    dq->fim = novo;
    dq->qtd++;
    printf("Elemento inserido!\n");
    return 1;
}

int insereIni(Deque *dq,int elem){
    if(dq==NULL) return 0;
    NO *novo = alocarNO();
    novo->info = elem;
    novo->ant = NULL;
    if(estaVazio(dq)){
        dq->fim = novo;
        novo->prox = NULL;
    } else {
        dq->ini->ant = novo;
        novo->prox = dq->ini;
    }
    dq->ini = novo;
    dq->qtd++;
    printf("Elemento inserido!\n");
    return 1;
}

int removeFim(Deque *dq){
    if(dq=NULL) return 0;
    if(estaVazio(dq)) return 0;
    NO *aux = dq->fim;
    if(dq->ini == dq->fim){
        dq->ini = dq->fim = NULL;
    } else {
        dq->fim = dq->fim->ant;
        dq->fim->prox = NULL;
    }
    liberarNO(aux);
    dq->qtd--;
    printf("Elemento removido!\n");
    return 1;
}

int removeIni(Deque *dq){
    if(dq==NULL) return 0;
    if(estaVazio(dq)) return 0;
    NO *aux = dq->ini;
    if(dq->ini == dq->fim){
        dq->ini = dq->fim = NULL;
    } else {
        dq->ini = dq->ini->prox;
        dq->ini->ant = NULL;
    }
    liberarNO(aux);
    dq->qtd--;
    printf("Elemento removido!\n");
    return 1;
}

int verIni(Deque *dq, int *p){
    if(dq==NULL) return 0;
    if(estaVazio(dq)) return 0;
    *p = dq->ini->info;
    return 1;
}


int verFim(Deque *dq, int *p){
    if(dq==NULL) return 0;
    if(estaVazio(dq)) return 0;
    *p = dq->fim->info;
    return 1;
}

void imprime(Deque *dq){
    if(dq==NULL) return;
    if(estaVazio(dq)) return;
    NO *aux = dq->ini;
    printf("Elementos:\n");
    while(aux!=NULL){
        printf("%d ",aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

void destroiDeque(Deque *dq){
    if(dq != NULL){
        NO *aux;
        while(dq->ini != NULL){
            aux = dq->ini;
            dq->ini = dq->ini->prox;
            liberarNO(aux);
        }
        free(dq);
    }
}

#endif