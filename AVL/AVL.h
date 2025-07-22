#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAIOR(a, b) ((a > b) ? (a) : (b))

typedef struct{
    char nome[20];
    double salario;
    int ano;
}Funcionario;

typedef struct NO{
    Funcionario fun;
    int fb, alt;
    struct NO *esq;
    struct NO *dir;
}NO;

typedef struct NO *AVL;

AVL *criaAVL(){
    AVL *raiz = (AVL*)malloc(sizeof(AVL));
    if(raiz != NULL) *raiz = NULL;
    return raiz;
}

NO* alocarNO(){
    return (NO*)malloc(sizeof(NO));
}

void liberarNO(NO *n){
    free(n);
}

void destroiRec(NO *no){
    if(no == NULL) return;
    destroiRec(no->esq);
    destroiRec(no->dir);
    liberarNO(no);
    no = NULL;
}

void destroiAVL(AVL *raiz){
    if(raiz != NULL){
        destroiRec(*raiz);
        free(raiz);
    }
}

int estaVazia(AVL *raiz){
    if(raiz == NULL) return 0;
    return (*raiz == NULL);
}


void em_ordem(NO *raiz, int nivel){
    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1);
        printf("[%d] ", (*raiz).fun.salario);
        em_ordem(raiz->dir, nivel+1);
    }
}

void imprime(AVL *raiz){
    if(raiz==NULL) return;
    if(estaVazia(raiz)) return;
    printf("\nEm Ordem:\n");
    em_ordem(*raiz, 0);
    printf("\n");
}

int altura(NO* raiz){
    if(raiz == NULL) return 0;
    if(raiz->alt > 0)
        return raiz->alt;
    else{ 
        printf("Calculando altura do (%s)..\n", raiz->fun.nome);
        return MAIOR(altura(raiz->esq), altura(raiz->dir)) + 1;
    }
}

int FB(NO* raiz){
    if(raiz == NULL) return 0;
    printf("Calculando FB do (%d)..\n", raiz->fun.nome);
    return altura(raiz->esq) - altura(raiz->dir);
}

void avl_RotDir(NO **raiz){
    printf("Rotacao Simples a DIREITA!\n");
    NO *aux;
    aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = *raiz;

    (*raiz)->alt = aux->alt = -1;
    aux->alt = altura(aux);
    (*raiz)->alt = altura(*raiz);
    aux->fb = FB(aux);
    (*raiz)->fb = FB(*raiz);

    *raiz = aux;
}

void avl_RotEsq(NO **raiz){
    printf("Rotacao Simples a ESQUERDA!\n");
    NO *aux;
    aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = *raiz;

    (*raiz)->alt = aux->alt = -1;
    aux->alt = altura(aux);
    (*raiz)->alt = altura(*raiz);
    aux->fb = FB(aux);
    (*raiz)->fb = FB(*raiz);

    *raiz = aux;
}

void avl_RotEsqDir(NO **raiz){
    printf("Rotacao Dupla ESQUERDA-DIREITA!\n");
    NO *fe;
    NO *ffd;

    fe = (*raiz)->esq;
    ffd = fe->dir;

    fe->dir = ffd->esq;
    ffd->esq = fe;

    (*raiz)->esq = ffd->dir;
    ffd->dir = *raiz;

    (*raiz)->alt = fe->alt = ffd->alt = -1;
    fe->alt = altura(fe); 
    ffd->alt = altura(ffd);
    (*raiz)->alt = altura(*raiz); 
    fe->fb = FB(fe); 
    ffd->fb = FB(ffd);
    (*raiz)->fb = FB(*raiz);

    *raiz = ffd;
}

void avl_RotDirEsq(NO** raiz){
    printf("Rotacao Dupla DIREITA-ESQUERDA!\n");
    NO* fd;
    NO* ffe;

    fd = (*raiz)->dir;
    ffe = fd->esq;
    
    fd->esq = ffe->dir;
    ffe->dir = fd;
    
    (*raiz)->dir = ffe->esq;
    ffe->esq = *raiz;

    (*raiz)->alt = fd->alt = ffe->alt = -1;
    fd->alt = altura(fd); 
    ffe->alt = altura(ffe);
    (*raiz)->alt = altura(*raiz); 
    fd->fb = FB(fd);
    ffe->fb = FB(ffe);
    (*raiz)->fb = FB(*raiz);

    *raiz = ffe;
}

void avl_RotEsqDir2(NO** raiz){
    printf("Rotacao Dupla 2 ESQUERDA-DIREITA!\n");
    avl_RotEsq(&(*raiz)->esq);
    avl_RotDir(raiz);
}

void avl_RotDirEsq2(NO** raiz){
    printf("Rotacao Dupla 2 DIREITA-ESQUERDA!\n");
    avl_RotDir(&(*raiz)->dir);
    avl_RotEsq(raiz);
}

void avl_AuxFE(NO **raiz){
    NO *fe;
    fe = (*raiz)->esq;
    if(fe->fb == +1)
        avl_RotDir(raiz);
    else
        avl_RotEsqDir(raiz);
}

void avl_AuxFD(NO **raiz){
    NO *fd;
    fd = (*raiz)->dir;
    if(fd->fb == -1)
        avl_RotEsq(raiz);
    else
        avl_RotDirEsq(raiz);
}

int insereRec(NO **raiz, char* nome, double salario, int ano){
    int ok;
    if(*raiz == NULL){
        NO *novo = alocarNO();
        if(novo == NULL) return 0;
        strcpy(novo->fun.nome, nome);
        novo->fun.salario = salario;
        novo->fun.ano = ano;
        novo->fb = 0;
        novo->alt = 1;
        novo->esq = novo->dir = NULL;
        *raiz = novo;
        return 1;
    } else {
        if((*raiz)->fun.salario == salario){
            printf("Elemento Existente!\n");
            ok = 0;
        }
        if(salario < (*raiz)->fun.salario){
            ok = insereRec(&(*raiz)->esq, nome, salario, ano);
            if(ok){
                switch ((*raiz)->fb){
                    case -1:
                        (*raiz)->fb = 0;
                        ok = 0;
                        break;
                    case 0:
                        (*raiz)->fb = +1;
                        (*raiz)->alt++;
                        break;
                    case +1:
                        avl_AuxFE(raiz);
                        ok = 0;
                        break;
                }  
            }
        } else if(salario > (*raiz)->fun.salario){
            ok = insereRec(&(*raiz)->dir, nome, salario, ano);
            if(ok){
                switch((*raiz)->fb){
                    case +1:
                        (*raiz)->fb = 0;
                        ok = 0;
                        break;
                    case 0:
                        (*raiz)->fb = -1;
                        (*raiz)->alt++;
                        break;
                    case -1:
                        avl_AuxFD(raiz);
                        ok = 0;
                        break;
                }
            }
        }
    }
    return ok;
}

int insereElem(AVL* raiz, Funcionario *fun){
    if(raiz == NULL) return 0;
    return insereRec(raiz, (*fun).nome, (*fun).salario, (*fun).ano);
}

NO *pesquisaRec(NO** raiz, char* nome){
    if(*raiz == NULL) return 0;
    if(strcmp((*raiz)->fun.nome, nome))
        return (*raiz);
    if(nome < (*raiz)->fun.nome)
        return pesquisaRec(&(*raiz)->esq, nome);
    else 
        return pesquisaRec(&(*raiz)->dir, nome);
}

NO *pesquisa(AVL* raiz, char *nome){
    if(raiz == NULL) return 0;
    if(estaVazia(raiz)) return 0;
    return pesquisaRec(raiz, nome);
}

double maiorRec(NO* raiz, int nivel){
    if(raiz->dir != NULL)
        maiorRec(raiz->dir, nivel+1);
    return (*raiz).fun.salario;
}

void maior(AVL *raiz){
    if(raiz==NULL) return;
    if(estaVazia(raiz)) return;
    double maior = (*raiz)->fun.salario;
    maior = maiorRec(*raiz, 0);
    printf("O maior salario eh %lf\n", maior);
    printf("\n");
}

double menorRec(NO* raiz, int nivel){
    if(raiz->esq != NULL)
        menorRec(raiz->esq, nivel+1);   
    return (*raiz).fun.salario;
}

void menor(AVL *raiz){
    if(raiz==NULL) return;
    if(estaVazia(raiz)) return;
    double menor = (*raiz)->fun.salario;
    menor = menorRec(*raiz, 0);
    printf("O menor salario eh %lf\n", menor);
    printf("\n");
}


int removeRec(NO** raiz, double salario){
    if(*raiz == NULL) return 0;
    int ok;
    if((*raiz)->fun.salario == salario){
        NO* aux;
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            printf("Caso 1: Liberando %s..\n", (*raiz)->fun.nome);
            liberarNO(*raiz);
            *raiz = NULL;
        }else if((*raiz)->esq == NULL){
            printf("Caso 2.1: Liberando %s..\n", (*raiz)->fun.nome);
            aux = *raiz;
            *raiz = (*raiz)->dir;
            liberarNO(aux);
        }else if((*raiz)->dir == NULL){
            printf("Caso 2.2: Liberando s..\n", (*raiz)->fun.nome);
            aux = *raiz;
            *raiz = (*raiz)->esq;
            liberarNO(aux);
        }else{
            printf("Caso 3: Liberando %s..\n", (*raiz)->fun.nome);
            NO* Filho = (*raiz)->esq;
            while(Filho->dir != NULL)
                Filho = Filho->dir;
            (*raiz)->fun.salario = Filho->fun.salario;
            Filho->fun.salario = salario;
            return removeRec(&(*raiz)->esq, salario);
        }
        return 1;
    }else if(salario < (*raiz)->fun.salario){
        ok = removeRec(&(*raiz)->esq, salario); 
        if(ok){
            switch((*raiz)->fb){
                case +1:
                case 0:
                    (*raiz)->alt = -1;
                    (*raiz)->alt = altura(*raiz); 
                    (*raiz)->fb = FB(*raiz);
                    break;
                case -1:
                    avl_AuxFD(raiz); break;
            }
        }
    }
    else{ 
        ok = removeRec(&(*raiz)->dir, salario);
        if(ok){
            switch((*raiz)->fb){
                case -1:
                case 0:
                    (*raiz)->alt = -1;
                    (*raiz)->alt = altura(*raiz); 
                    (*raiz)->fb = FB(*raiz);
                    break;
                case +1:
                    avl_AuxFE(raiz); break;
            }
        }
    }
    return ok;
}

int removeElem(AVL* raiz, char *nome){
    NO *aux = pesquisa(raiz, nome);
    if(aux->fun.salario == 0){
        printf("Elemento inexistente!\n");
        return 0;
    }
    return removeRec(raiz, aux->fun.salario);
}

#endif