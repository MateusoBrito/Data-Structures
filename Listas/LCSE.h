#ifndef LCSE_H
#define LCSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* prox;
}NO;

typedef struct NO *Lista;

Lista* criaLista(){
    Lista *li;
    li = (Lista*)malloc(sizeof(Lista));
    if(li!= NULL)
        *li = NULL;
    return li;
}

int listaVazia(Lista *li){
    if(li==NULL)
        return -1;
    return (*li == NULL);
}

NO* alocarNO(){
    return (NO*)malloc(sizeof(NO));
}

void liberarNO(NO* no){
    free(no);
}

int insereIni(Lista *li, int elem){
    if(li==NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    if(listaVazia(li)){
        novo->prox = novo;
        *li = novo;
    } else {
        NO* aux = *li;
        while(aux->prox != (*li))
            aux = aux->prox;
        aux->prox = novo;
        novo->prox = *li;
        *li = novo;
    }
    return 1;
}

int insereFim(Lista *li, int elem){
    if(li=NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    if(listaVazia(li)){
        novo->prox = novo;
        *li = novo;
    } else {
        NO* aux = *li;
        while(aux->prox != (*li))
            aux = aux->prox;
        aux->prox = novo;
        novo->prox = *li;
    }
    return 1;
}

#endif