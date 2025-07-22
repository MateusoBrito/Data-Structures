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

int verTopo(Pilha *pi){
    if(pi == NULL) return 0;
    if(pi->qtd == 0) return 0;
    printf("O topo eh %d\n",pi->topo->info);
    return 1;
}

int desempilhar(Pilha *pi){
    if(pi==NULL) return 0;
    if(pilhaVazia(pi)) return 0;
    NO *aux = pi->topo;
    pi->topo = aux->prox;
    free(aux);
    pi->qtd--;
    printf("Elemento removido!\n");
    return 1;
}

void imprime(Pilha *pi){
    if(pi==NULL) return;
    if(pilhaVazia(pi)) {
        printf("Lista vazia!\n");
        return;
    }
    NO* aux = pi->topo;
    printf("Elementos:\n");
    for(int i=0;i<pi->qtd;i++){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
    return;
}

void destroiPilha(Pilha *pi){
    if(pi != NULL){
        NO *aux;
        while(pi->topo != NULL){
            aux = pi->topo;
            desempilhar(pi);
            liberarNO(aux);
        }
        free(pi);
    }
}

#endif