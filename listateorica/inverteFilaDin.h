#ifndef FSE_H
#define FSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* prox;
}NO;

typedef struct{
    int qtd;
    struct NO* ini;
    struct NO* fim;
}Fila;

Fila* criaFila(){
    Fila *fi;
    fi = (Fila*)malloc(sizeof(Fila));
    if(fi != NULL){
        fi->ini = fi->fim = 0;
        fi->qtd = 0;
    }
    return fi;
}

NO* alocarNO(){
    return (NO*)malloc(sizeof(NO));
}

void liberarNO(NO* no){
    free(no);
}

int enfileirar(Fila *fi, int elem){
    if(fi == NULL) return 0;
    NO *novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->prox = NULL;
    if(fi->qtd == 0){
        fi->ini = fi->fim = novo;
    } else {
        fi->fim->prox = novo;
        fi->fim = novo;
    }
    fi->qtd++;
    printf("Elemento inserido!\n");
    return 1;
}

int desenfileirar(Fila *fi){
    if(fi == NULL) return 0;
    if(fi->qtd == 0) return 0;
    NO* aux = fi->ini;
    fi->ini = fi->ini->prox;
    liberarNO(aux);
    fi->qtd--;
    printf("Elemento removido!\n");
    return 1;
}

void imprimeFila(Fila *fi){
    if(fi == NULL) return;
    if(fi->qtd == 0){
        printf("Fila Vazia!\n");
        return;
    }
    NO* aux = fi->ini;
    printf("Fila:\n");
    while(aux != fi->fim->prox){
        printf("%d ",aux->info);
        aux = aux->prox;
    }
    printf("\n");
    return;
}

void imprimeFilaInvertida(Fila *fi){
    if(fi == NULL) return;
    if(fi->qtd == 0){
        printf("Fila Vazia!\n");
        return;
    }
    int *vetor;
    NO* aux = fi->ini;
    vetor = (int*)malloc(sizeof(int));
    for(int i=0;i<fi->qtd;i++){
        vetor[i] = aux->info;
        aux = aux->prox;
    }
    printf("Fila invertida:\n");
    for(int i=fi->qtd-1;i>=0;i--){
        printf("%d ", vetor[i]);
    }
    free(vetor);
    printf("\n");
    return;

}

void destroiFila(Fila *fi){
    if(fi != NULL){
        NO *aux;
        while(fi->qtd > 0){
            aux = fi->ini;
            fi->ini = fi->ini->prox;
            liberarNO(aux);
            fi->qtd--;
        }
        free(fi);
        return;
    }
    return;
}

#endif