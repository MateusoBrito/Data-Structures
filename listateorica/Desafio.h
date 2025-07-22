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
    if(*li == NULL) return 1;
    return 0;
}


NO* alocarNO(){
    return (NO*)malloc(sizeof(NO));    
}


void liberarNO(NO* no){
    free(no);
}


int tamanho(Lista *li){
    if(li == NULL) return -1;
    NO *aux = *li;
    int tam=0;
    while(aux!=NULL){
        tam++;
        aux = aux->prox;
    }
    return tam;
}


int procura(Lista *li,int elem){
    if(li==NULL) return 0;
    NO *aux = *li;
    while(aux->prox!=NULL){
        if(aux->info == elem)
            return 1;
        aux = aux->prox;
    }
    return 0;
}


int insereIni(Lista *li, int elem){
    if(li == NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->prox = *li;
    *li = novo;
    return 1;
}


int insereFim(Lista *li, int elem){
    if(li == NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->prox = NULL;
    if(listaVazia(li)){
        *li = novo;
    } else {
        NO* aux = *li;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return 1;
}


int insereOrd(Lista *li, int elem){
    if(li==NULL) return 0;
    NO *novo = alocarNO();
    if(novo==NULL) return 0;
    novo->info = elem;
    if(listaVazia(li)) *li = novo;
    else{
        NO *ant = *li,*aux = *li;
        while(aux->prox!=NULL){
            if((ant->info < elem) && (aux->info >= elem)){
                ant->prox = novo;
                novo->prox = aux;
                return 1;
            }
        }
        aux->prox = novo;
        return 1;
    }
}


int removeIni(Lista *li){
    if(li==NULL) return 0;
    if(listaVazia(li)) return 0;
    NO* aux = *li;
    *li = aux->prox;
    liberarNO(aux);
    return 1;
}


int removeFim(Lista *li){
    if(li==NULL) return 0;
    if(listaVazia(li)) return 0;
    NO *ant, *aux = *li;
    while(aux->prox != NULL) {
        ant = aux;
        aux = aux->prox;
    }
    if(aux == *li) *li = aux->prox;
    else ant->prox = aux->prox;
    liberarNO(aux);
    return 1;
}


int removeOco(Lista *li, int elem){
    if(li==NULL) return 0;
    if(listaVazia(li)) return 0;
    NO *ant,*aux = *li;
    while(aux->prox!=NULL){
        ant = aux;
        if(aux->info == elem){
            ant->prox = aux->prox;
            liberarNO(aux);
            return 1;
        }
        aux = aux->prox;
    }
    printf("O elemento nao foi encontrado!\n");
    return 0;
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

void imprimeListaContrario(Lista *li){
    if(li==NULL) return;
    if(!listaVazia(li)){
        NO *aux = *li;
        int *vetor = (int*)malloc(sizeof(int));
        int tam = 0;
        printf("Elementos:\n");
        while(aux != NULL){
            vetor[tam] = aux->info;
            tam++;
            aux = aux->prox;
        }
        tam--;
        for(;tam>=0;tam--){
            printf("%d ", vetor[tam]);
        }
    } else {
        printf("A lista esta vazia!");
    }
    printf("\n");
}

void imprime(NO *elem){
    if(elem == NULL)
        return;
    imprime(elem->prox);
    printf("%d ", elem->info);
}

void imprimeListaContrarioRep(Lista *li){
    if(li == NULL) return;
    if(!listaVazia(li)){
        printf("Elementos:\n");
        imprime(*li);
    } else {
        printf("A lista esta vazia!");
    }
    printf("\n");
}


void destroiLista(Lista *li){
    if(li==NULL) return;
    NO *aux;
    while((*li)!=NULL){
        aux = *li;
        *li = (*li)->prox;
        liberarNO(aux);
    }
    free(li);
}


#endif
