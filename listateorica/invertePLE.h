#ifndef PSE_H
#define PSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* prox;
}NO;

typedef struct{
    int qtd;
    struct NO* topo;
}Pilha;

Pilha* criarPilha(){
    Pilha *pi;
    pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi != NULL) {
        pi->qtd = 0;
        pi->topo = NULL;
    }
    return pi;
}

int pilhaVazia(Pilha *pi){
    if(pi == NULL) return -1;
    return (pi->topo==NULL);
}

NO* alocarNO(){
    return (NO*)malloc(sizeof(NO));
}

void liberarNO(NO* no){
    free(no);
}

int empilhar(Pilha *pi, int elem){
    if(pi==NULL) return 0;
    NO *novo = alocarNO();
    novo->info = elem;
    if(pilhaVazia(pi)){
        novo->prox = NULL;
    } else
        novo->prox = pi->topo;
    pi->topo = novo;
    pi->qtd++;
    printf("Elemento inserido!\n");
    return 1;
}

void imprime(Pilha *pi){
    if(pi==NULL) return;
    if(pilhaVazia(pi)) {
        printf("Lista vazia!\n");
        return;
    }
    NO* aux = pi->topo;
    printf("Pilha:\n");
    for(int i=0;i<pi->qtd;i++){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
    return;
}

void imprimeInvertido(Pilha *pi){
    if(pi==NULL) return;
    if(pilhaVazia(pi)) {
        printf("Lista vazia!\n");
        return;
    }
    int *vetor;
    NO* aux = pi->topo;
    vetor = (int*)malloc(sizeof(int));
    for(int i=0;i<pi->qtd;i++){
        vetor[i] = aux->info;
        aux = aux->prox;
    }
    printf("Pilha Invertida:\n");
    for(int i=pi->qtd-1;i>=0;i--)
        printf("%d ", vetor[i]);
    printf("\n");
    return;
}

#endif