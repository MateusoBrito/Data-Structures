#ifndef LSE_H
#define LSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* prox;
}NO;

typedef struct NO* Lista;

Lista* criaLista(){
    Lista *li;
    li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL) *li = NULL;
    return li;
}

int listaVazia(Lista *li){
    if(li == NULL) return -1;
    return ((*li) == NULL);
}

NO* alocarNO(){
    return (NO*)malloc(sizeof(NO));
}

void liberarNO(NO* no){
    free(no);
}

int insereIni(Lista *li, int elem){
    if(li==NULL) return 0;
    NO *novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->prox = *li;
    *li = novo;
    printf("Elemento inserido!\n");
    return 1;
}

int insereFim(Lista *li, int elem){
    if(li==NULL) return 0;
    NO *novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->prox = NULL;
    if(listaVazia(li)){
        *li = novo;
    } else {
        NO *aux = *li;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    printf("Elemento inserido!\n");
    return 1;
}

int removeIni(Lista *li){
    if(li==NULL) return 0;
    if(listaVazia(li)) return 0;
    NO *aux = *li;
    *li = aux->prox;
    liberarNO(aux);
    printf("Elemento removido!\n");
    return 1;
}

int removeFim(Lista *li){
    if(li==NULL) return 0;
    if(listaVazia(li)) return 0;
    NO *ant,*aux = *li;
    while(aux->prox != NULL){
        ant = aux;
        aux = aux->prox;
    }
    if(aux == *li)
        *li = aux->prox;
    else 
        ant->prox = aux->prox;
    liberarNO(aux);
    printf("Elemento removido!\n");
    return 1;
}

void imprimeLista(Lista *li){
    if(li == NULL) return;
    if(!listaVazia(li)){
        NO *aux = *li;
        printf("Elementos:\n");
        while(aux != NULL){
            printf("%d ",aux->info);
            aux = aux->prox;
        }
    } else {
        printf("A lista esta vazia!");
    }
    printf("\n");
}

void destroiLista(Lista *li){
    if(li != NULL){
        NO *aux;
        while((*li) != NULL){
            aux = *li;
            *li = (*li)->prox;
            liberarNO(aux);
        }
        free(li);
    }
}

int tamanhoLista(Lista *li){
    if(li==NULL) return 0;
    int tam;
    NO *aux = *li;
    while(aux->prox != NULL){
        aux = aux->prox;
        tam++;
    }
    return tam;
}

int procura(Lista *li, int elem){
    if(li == NULL) return -1;
    NO *aux = *li;
    for(int i=0; aux != NULL; i++){
        aux = aux->prox;
        if(aux->info == elem)
            return i;
    }
    return -1;
}

#endif