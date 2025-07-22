#ifndef ABP_H
#define ABP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    int matricula;
    double nota;
}Aluno;

typedef struct NO{
    Aluno info;
    struct NO *esq, *dir;
}NO;

typedef struct NO* ABP;

NO* alocarNO(){
    return (NO*)malloc(sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

ABP *criaABP(){
    ABP *raiz = (ABP*)malloc(sizeof(ABP));
    if(raiz != NULL) *raiz = NULL;
    return raiz;
}

int estaVazia(ABP *raiz){
    if(raiz == NULL) return -1;
    return (*raiz == NULL);
}

int insereRec(NO** raiz, Aluno aluno){
    if(*raiz == NULL){
        NO *novo = alocarNO();
        if(novo == NULL) return 0;
        novo->info = aluno;
        novo->esq = NULL; novo->dir = NULL;
        *raiz = novo;
    }else{
        if(strcmp(aluno.nome, (*raiz)->info.nome) == 0){
            printf("Aluno já existente!\n"); return 0;
        }
        if(strcmp(aluno.nome, (*raiz)->info.nome) < 0)
            return insereRec(&(*raiz)->esq, aluno);
        else if(strcmp(aluno.nome, (*raiz)->info.nome) > 0)
            return insereRec(&(*raiz)->dir, aluno);
    }
    return 1;
} 

int insereElem(ABP *raiz, Aluno aluno){
    if(raiz == NULL) return 0;
    return insereRec(raiz, aluno);
}

int pesquisaRec(NO **raiz, char *nome){
    if(*raiz == NULL) return 0;
    if(strcmp(nome, (*raiz)->info.nome) == 0) return 1;
    if(strcmp(nome, (*raiz)->info.nome) < 0)
        return pesquisaRec(&(*raiz)->esq, nome);
    else
        return pesquisaRec(&(*raiz)->dir, nome);
}

int pesquisa(ABP *raiz, char *nome){
    if(raiz == NULL) return 0;
    if(estaVazia(raiz)) return 0;
    return pesquisaRec(raiz, nome);
}

int removeRec(NO **raiz, char *nome){
    if(*raiz == NULL) return 0;
    if(strcmp(nome, (*raiz)->info.nome) == 0){
        NO *aux;
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            liberarNO(*raiz); *raiz = NULL;
        }else if((*raiz)->esq == NULL){
            aux = *raiz; *raiz = (*raiz)->dir; liberarNO(aux);
        }else if((*raiz)->dir == NULL){
            aux = *raiz; *raiz = (*raiz)->esq; liberarNO(aux);
        }else{
            NO *Filho = (*raiz)->esq;
            while(Filho->dir != NULL)
                Filho = Filho->dir;
            (*raiz)->info = Filho->info;
            strcpy((*raiz)->info.nome, Filho->info.nome);
            return removeRec(&(*raiz)->esq, nome);
        }
        return 1;
    }else if(strcmp(nome, (*raiz)->info.nome) < 0)
        return removeRec(&(*raiz)->esq, nome);
    else
        return removeRec(&(*raiz)->dir, nome);
}

int removeElem(ABP *raiz, char *nome){
    if(pesquisa(raiz, nome) == 0){
        printf("Aluno inexistente!\n"); return 0;
    }
    return removeRec(raiz, nome);
}

void em_ordem(NO *raiz, int nivel){
    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1);
        printf("[%s, %d, %.2lf, %d]\n", raiz->info.nome, raiz->info.matricula, raiz->info.nota, nivel);
        em_ordem(raiz->dir, nivel+1);
    }
}

void imprimeEmOrdem(ABP *raiz){
    if(raiz == NULL) return;
    if(estaVazia(raiz)){
        printf("Arvore Vazia!\n"); return;
    }
    printf("\nEm Ordem: "); em_ordem(*raiz, 0);
    printf("\n");
}

void maiorNotaRec(NO *raiz, Aluno *maior){
    if(raiz == NULL) return;
    if(raiz->info.nota > maior->nota){
        *maior = raiz->info;
    }
    maiorNotaRec(raiz->esq, maior);
    maiorNotaRec(raiz->dir, maior);
}

void imprimeMaiorNota(ABP *raiz){
    if(raiz == NULL) return;
    if(estaVazia(raiz)){
        printf("Arvore vazia!\n");
        return;
    }
    Aluno maiorNota = (*raiz)->info;
    maiorNotaRec(*raiz, &maiorNota);

    printf("Aluno com a maior nota:\n");
    printf("[%s, %.2lf]\n", maiorNota.nome, maiorNota.nota);
}

void menorNotaRec(NO *raiz, Aluno *menor){
    if(raiz == NULL) return;
    if(raiz->info.nota < menor->nota){
        *menor = raiz->info;
    }
    menorNotaRec(raiz->esq, menor);
    menorNotaRec(raiz->dir, menor);
}

void imprimeMenorNota(ABP *raiz){
    if(raiz == NULL) return;
    if(estaVazia(raiz)){
        printf("Arvore vazia!\n");
        return;
    }
    Aluno menorNota = (*raiz)->info;
    menorNotaRec(*raiz, &menorNota);

    printf("Aluno com a menor nota:\n");
    printf("[%s, %.2lf]\n", menorNota.nome, menorNota.nota);
}

int contaRec(NO **raiz){
    if(raiz == NULL) return -1;
    if(*raiz == NULL) return 0;
    int esquerda = contaRec(&(*raiz)->esq);
    int direita = contaRec(&(*raiz)->dir);
    return direita + esquerda + 1;
}

int quantidadeNos(ABP *raiz){
    if(raiz == NULL) return 0;
    return contaRec(raiz);
}

void destroiRec(NO *no){
    if(no == NULL) return;
    destroiRec(no->esq);
    destroiRec(no->dir);
    liberarNO(no);
    no = NULL;
}

void destroiABP(ABP *raiz){
    if(raiz != NULL){
        destroiRec(*raiz);
        free(raiz);
    }
}


#endif

