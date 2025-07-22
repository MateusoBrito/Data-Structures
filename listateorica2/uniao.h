#ifndef FILAP_H
#define FILAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info,prio;
    struct NO *prox;
}NO;
typedef struct NO *FilaP;

FilaP* criaFila(){
    FilaP *fp;
    fp = (FilaP*)malloc(sizeof(FilaP));
    if(fp != NULL) *fp = NULL;
    return fp;
}

NO* alocarNO(){
    return (NO*)malloc(sizeof(NO));
}

void liberarNO(NO* no){
    free(no);
}

int estaVazia(FilaP *fp){
    if(fp==NULL) return -1;
    return ((*fp) == NULL);
}

int tamanho(FilaP *fp){
    if(fp==NULL) return -1;
    if(estaVazia(fp)) return 0;
    int tam=0;
    NO *aux = *fp;
    while(aux!=NULL){
        aux = aux->prox;
        tam++;
    }
    return tam;
}

int inserirPrio(FilaP *fp, int elem, int prio){
    if(fp==NULL) return 0;
    NO *novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->prio = prio;
    if(estaVazia(fp)){
        novo->prox = *fp;
        *fp = novo;
    } else {
        NO *aux, *ant;
        aux = *fp;
        ant = NULL;
        while(aux != NULL && aux->prio >= novo->prio){
            ant = aux;
            aux = aux->prox;
        }
        if(ant == NULL){
            novo->prox = *fp;
            *fp = novo;
        } else {
            novo->prox = ant->prox;
            ant->prox = novo;
        }
    }
    return 1;
}
int removerIni(FilaP *fp){
    if(fp==NULL) return 0;
    if(estaVazia(fp)) return 0;
    NO *aux = *fp;
    *fp = aux->prox;
    liberarNO(aux);
    return 1;
}

int verIni(FilaP *fp, int *p){
    if(fp == NULL) return 0;
    if( estaVazia(fp)) return 0;
    *p = (*fp)->info;
    return 1;
}

void imprime(FilaP *fp){
    if(fp==NULL) return;
    if(estaVazia(fp)) return;
    NO *aux = *fp;
    printf("Elementos:\n");
    while(aux != NULL){
        printf("[%d, %d] ",aux->prio,aux->info);
        aux = aux->prox;
    }
    printf ("\n");
}

void destroFila(FilaP *fp){
    if(fp != NULL){
        NO *aux;
        while((*fp) != NULL){
            aux = *fp;
            *fp = (*fp)->prox;
            liberarNO(aux);
        }
        free(fp);
    }
}

int uniaofilas(FilaP *f1, FilaP *f2){
    if(f1==NULL || f2==NULL) return 0;
    NO *aux = *f2;
    while(aux != NULL){
        inserirPrio(f1,aux->info, aux->prio);
        removerIni(f2);
        aux=aux->prox;
    }
    return 1;
}

#endif