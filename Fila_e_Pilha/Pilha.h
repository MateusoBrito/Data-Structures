#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    int dados[MAX];
    int topo;
}Pilha;

Pilha* criaPilha(){
    Pilha *pi;
    pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi != NULL) pi->topo = 0;
    return pi;
}

void destroiPilha(Pilha *pi){
    if(pi == NULL) return;
    free(pi);
}

int tamanho(Pilha *pi){
    if(pi == NULL) return -1;
    return pi->topo;
}

int estaVazia(Pilha *pi){
    if(pi == NULL) return -1;
    return (pi->topo == 0);
}

int estaCheia(Pilha *pi){
    if(pi == NULL) return -1;
    return (pi->topo == MAX);
}

int empilhar(Pilha *pi, int elem){
    if(pi == NULL) return 0;
    if(estaCheia(pi)) return 0;
    pi->dados[pi->topo] = elem;
    pi->topo++;
    printf("Elemento inserido!\n");
    return 1;
}

int verTopo(Pilha *pi){
    if(pi == NULL) return 0;
    if(estaVazia(pi)) return 0;
    return pi->dados[pi->topo-1];
}

int desempilhar(Pilha *pi){
    if(pi==NULL) return 0;
    if(estaVazia(pi)) return 0;
    pi->topo--;
    printf("Elemento removido!\n");
    return 1;
}

int imprime(Pilha *pi){
    if(pi == NULL) return 0;
    if(estaVazia(pi)){
        printf("Esta vazia!\n");
        return 0;
    }
    printf("Elementos:\n");
    for(int i=pi->topo-1;i>=0;i--)
        printf("%d ", pi->dados[i]);
    printf("\n");
    return 1;
}
#endif