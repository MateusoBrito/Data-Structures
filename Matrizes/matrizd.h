#ifndef MATRIZD_H
#define MATRIZD_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct{
    int **dados;
    int lin,col;
}Matriz;


int zeraMatriz(Matriz *mat){
    if(mat==NULL) return 0;
    for(int i=0;i<mat->lin;i++){
        for(int j=0;j<mat->col;j++)
            mat->dados[i][j] = 0;
    }
    return 1;
}


Matriz* criaMatriz(int l, int c){
    Matriz *mat;
    mat = (Matriz*)malloc(sizeof(Matriz));
    if(mat != NULL){
        if(l<=0 || c<=0){
            printf("Valores invalidos!\n");
            return NULL;
        }
    }
    mat->lin = l;
    mat->col = c;
    mat->dados = (int**)malloc(l*sizeof(int*));
    for(int i=0;i<l;i++)
        mat->dados[i] = (int*)malloc(c*sizeof(int));
    zeraMatriz(mat);
    return mat;
}


void destroiMatriz(Matriz *mat){
    if(mat != NULL){
        for(int i=0;i<mat->lin; i++)
            free(mat->dados[i]);
        free(mat->dados);
        free(mat);
    }
}


int preencheAleatorio(Matriz* mat, int ini, int fim){
    if(mat == NULL) return 0;
    srand(time(NULL));
    int i, j;
    for(i=0; i<mat->lin; i++)
        for(j=0; j<mat->col; j++)
            mat->dados[i][j] = ini + rand() % (fim-ini + 1);
    return 1;
}


int insereElem(Matriz *mat, int elem, int l, int c){
    if(mat == NULL) return 0;
    if(l<=0 || c<=0 || l>mat->lin || c>mat->col){
        printf("Valores invalidos!\n");
        return 0;
    }
    mat->dados[l][c] = elem;
    return 1;
}


int consultaElem(Matriz *mat, int *p, int l, int c){
    if(mat==NULL) return 0;
    if(l<0 || c<0 || l > mat->lin || c > mat->col){
        printf("Valores invalidos!\n");
        return 0;
    }
    *p = mat->dados[l][c];
    return 1;
}


void imprime(Matriz *mat){
    if(mat==NULL) return;
    printf("Matriz %d x %d:\n", mat->lin, mat->col);
    for(int i=0;i<mat->lin;i++){
        for(int j=0;j<mat->col;j++)
            printf("%d ", mat->dados[i][j]);
        printf("\n");
    }
    printf("\n");
}


int eMatrizQuadrada(Matriz *mat){
    if(mat == NULL) return 0;
    return (mat->lin == mat->col);
}


Matriz* criaTriangularSup(Matriz *mat){
    if(mat == NULL) return NULL;
    if(!eMatrizQuadrada(mat)){
        printf("A matriz nao eh quadratica!\n");
        return 0;
    }
    Matriz *ts = criaMatriz(mat->lin, mat->col);
    for(int i=0;i<mat->lin;i++){
        for(int j=0;j<mat->col;j++){
            if(i<=j)
            ts->dados[i][j] = mat->dados[i][j];
        }
    }
    return ts;
}


Matriz* criaTriangularInf(Matriz *mat){
    if(mat == NULL) return NULL;
    if(!eMatrizQuadrada(mat)){
        printf("A matriz nao eh quadratica!\n");
        return 0;
    }
    Matriz *ti = criaMatriz(mat->lin, mat->col);
    for(int i=0;i<mat->lin;i++){
        for(int j=0;j<mat->col;j++){
            if(i>=j)
            ti->dados[i][j] = mat->dados[i][j];
        }
    }
    return ti;
}




Matriz* criaDiagonal(Matriz *mat){
    if(mat == NULL) return NULL;
    if(!eMatrizQuadrada(mat)){
        printf("A matriz nao eh quadratica!\n");
        return 0;
    }
    Matriz *d = criaMatriz(mat->lin, mat->col);
    for(int i=0;i<mat->lin;i++)
        d->dados[i][i] = mat->dados[i][i];
    return d;
}


int eSimetrica(Matriz *mat){
    if(mat == NULL) return 0;
    if(!eMatrizQuadrada(mat)) return 0;
    for(int i=0;i<mat->lin;i++){
        for(int j=0;j<mat->col;j++)
            if(mat->dados[i][j] != mat->dados[j][i])
                return 0;
    }
    return 1;
}

Matriz* criaTransposta(Matriz *mat){
    if(mat == NULL) return 0;
    Matriz *t = criaMatriz(mat->lin,mat->col);
    for(int i=0;i<t->lin;i++){
        for(int j=0;j<t->col;j++)
            t->dados[i][j] = mat->dados[i][j];
    }
    return t;
}


#endif
