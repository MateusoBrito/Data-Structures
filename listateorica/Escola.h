#ifndef ESCOLA_H
#define ESCOLA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    char nome[50];
    int matricula;
    double nota;
}aluno;

typedef struct NO{
    aluno info;
    struct NO *prox;
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

int insereOrd(Lista *li, char *nome, int matricula, double nota){
    if(li == NULL) return 0;
    NO *novo = alocarNO();
    if(novo == NULL) return 0;
    strcpy(novo->info.nome, nome);
    novo->info.matricula = matricula;
    novo->info.nota = nota;
    if(listaVazia(li) || strcmp((*li)->info.nome, novo->info.nome) == 1){
        novo->prox = *li;
        *li = novo;
    } else {
        NO *aux = *li, *ant = *li;
        while(1){
            if(strcmp(aux->info.nome,novo->info.nome) == 1){
                novo->prox = aux;
                ant->prox = novo;
                break;
            }
            ant = aux;
            aux = aux->prox;
            if(aux == NULL){
                ant->prox = novo;
                novo->prox = aux;
                break;
            }
        }
    }
    return 1;
}

int removeAluno(Lista *li, int maticula){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    NO *aux = *li, *ant = *li;
    while(aux != NULL){
        if(aux->info.matricula == maticula){
            if(aux == *li) *li = aux->prox;
            else ant->prox = aux->prox;
            liberarNO(aux);
            printf("Aluno removido!\n");
            break;
        }
        ant = aux;
        aux = aux->prox;
    }
}

void imprimeLista(Lista *li){
    if(li == NULL) return;
    if(!listaVazia(li)){
        NO *aux = *li;
        printf("Alunos:\n");
        while(aux != NULL){
            printf("%s \n",aux->info.nome);
            aux = aux->prox;
        }
    } else {
        printf("A lista esta vazia!");
    }
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

#endif