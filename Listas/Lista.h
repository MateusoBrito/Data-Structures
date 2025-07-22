#ifndef LISTA_H
#define LISTA_H


#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Lista{
    int dados[MAX];
    int qtd;
}Lista;

Lista* criaLista(){
    Lista *li;
    li=(Lista*)malloc(sizeof(Lista));
    if(li!=NULL)
        li->qtd = 0;
    return li;
}

void destroiLista(Lista *li){
    if(li!=NULL) free(li);
}

int tamanhoLista(Lista *li){
    if(li == NULL) return -1;
    return li->qtd;
}

int listaCheia(Lista *li){
    if(li == NULL) return -1;
    return (li->qtd == MAX);
}

int listaVazia(Lista *li){
    if(li == NULL) return -1;
    return (li->qtd == 0);
}

int insereFim(Lista *li, int elem){
    if(li == NULL) return 0;
    if(!listaCheia(li)){
        li->dados[li->qtd] = elem;
        li->qtd++;
        printf("Elemento inserido!\n");
        return 1;
    } else {
        printf("Elemento nao inserido - Lista cheia!\n");
        return 0;
    }
}

int insereIni(Lista *li, int elem){
    if(li == NULL) return 0;
    if(!listaCheia(li)){
        for(int i=li->qtd-1;i>=0;i--)
            li->dados[i+1] = li->dados[i];
        li->dados[0] = elem;
        li->qtd++;
        printf("Elemento inserido!\n");
        return 1;
    } else {
        printf("Elemento nao inserido - Lista cheia!\n");
        return 0;
    }
}

int removeFim(Lista *li){
    if(li==NULL) return 0;
    if(!listaVazia(li)){
        li->qtd--;
        printf("Elemento removido!\n");
        return 1;
    } else{
        printf("Elemento nao removido - Lista vazia!\n");
        return 0;
    }
}

int removeIni(Lista *li){
    if(li==NULL) return 0;
    if(!listaVazia(li)){
        for(int i=0;i<li->qtd-1;i++)
            li->dados[i] = li->dados[i+1];
        li->qtd--;
        printf("Elemento removido!\n");
        return 1;
    } else{
        printf("Elemento nao removido - Lista vazia!\n");
        return 0;
    }
}

int imprimeLista(Lista *li){
    if(li==NULL) return 0;
    if(!listaVazia(li)){
        printf("Elementos:\n");
        for(int i=0;i<li->qtd;i++)
            printf("%d ",li->dados[i]);
        printf("\n");
    } else {
        printf("Lista vazia!\n");
        return 0;
    }
}

int procura(Lista *li, int elem){
    if(li==NULL) return 0;
    for(int i=0;i<li->qtd;i++){
        if(li->dados[i] == elem)
            return i;
    }
    printf("Elemento nao encontrado!\n");
    return 0;
}

int insereOrd(Lista *li, int elem){
    if(li==NULL) return 0;
    if(listaVazia(li)){
        insereIni(li,elem);
        return 1;
    }
    if(!listaCheia(li)){
        for(int i=li->qtd-1;i>=0;i--){
            li->dados[i+1] = li->dados[i];
            if( li->dados[i+1] <= elem){
                li->dados[i+1] = elem;
                break;
            }
            if(i==0) li->dados[i] = elem;
        }
        li->qtd++;
        printf("Elemento inserido!\n");
        return 1;
    } else {
        printf("Elemento nao inserido - Lista cheia!\n");
        return 0;
    }
}

int removeOco(Lista *li, int elem){
    if(li==NULL) return 0;
    if(!listaVazia(li)){
        int oco;
        for(int i=0;li->dados[i] != elem; i++)
            oco = i+1;
        for(int i=oco;i<li->qtd;i++){
            li->dados[i] = li->dados[i+1];
        }
        li->qtd--;
        printf("Elemento removido!\n");
        return 1;
    } else{
        printf("Elemento nao removido - Lista vazia!\n");
        return 0;
    }
}

#endif