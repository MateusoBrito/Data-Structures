#ifndef MATRIZ_H
#define MATRIZ_H


#include <stdio.h>
#include <stdlib.h>
#define MAX 100


typedef struct{
    int dados[MAX][MAX];
    int lin, col;
}Matriz;


int zeraMatriz(Matriz *mat){
    if(mat==NULL) return 0;
    for(int i=0;i<mat->lin;i++){
        for(int j=0;j<mat->col;j++){
            mat->dados[i][j] = 0;
        }
    }
    return 1;
}


Matriz* criaMatriz(int l, int c){
    Matriz *mat;
    mat = (Matriz*)malloc(sizeof(Matriz));
    if(mat != NULL){
        if(l<=0 || c<=0 || l>MAX || c>MAX){
            printf("Valores invalidos, matriz nao criada!\n");
            return NULL;
        }
        mat->lin = l;
        mat->col = c;
        zeraMatriz(mat);
    }
    return mat;
}


void destroiMatriz(Matriz *mat){
    if(mat != NULL)
    free(mat);
}


int insereElem(Matriz *mat, int elem, int l, int c){
    if(mat==NULL) return 0;mat->lin, mat->col;
    if(l < 0 || c < 0 || l >= mat -> lin || c >= mat ->col ){
        printf("Valores invalidos, elem nao inserido!\n");
        return 0;
    }
    mat->dados[l][c] = elem;
    printf("Elemento inserido!\n");
    return 1;
}


int consultaElem(Matriz *mat, int *p, int l, int c){
    if(mat==NULL) return 0;
    if(l<0 || c<0 || l>=mat->lin || c>=mat->col){
        printf("Valores invalidos, elem nao inserido!\n");
        return 0;
    }
    *p = mat->dados[l][c];
    printf("Elemento inserido!\n");
    return 1;
}


int imprime(Matriz *mat){
    if(mat==NULL) return 0;
    printf("Matriz %d x %d:\n", mat->lin, mat->col);
    for(int i=0;i<mat->lin;i++){
        for(int j=0; j<mat->col; j++)
            printf(" %d ", mat->dados[i][j]);
            printf("\n");
    }
    printf("\n");
    return 1;
}


Matriz *criaTransposta(Matriz *mat){
    if(mat==NULL) return NULL;
    Matriz *t = criaMatriz(mat->col, mat->lin);
    for(int i=0;i<mat->lin;i++){
        for(int j=0;j<mat->col;j++)
            t->dados[j][i] = mat->dados[i][j];
    }
    return t;
}


int eMatrizQuadrada(Matriz *mat){
    if(mat==NULL) return 0;
    return (mat->lin == mat->col);
}


int eSimetrica(Matriz *mat){
    if(mat==NULL) return 0;
    if(!eMatrizQuadrada(mat)){
        printf("A matriz nao eh quadratica!\n");
        return 0;
    }
    for(int i=0;i<mat->lin;i++){
        for(int j=0;j<mat->col;j++)
            if(mat->dados[i][j] != mat->dados[j][i])
                return 0;
        }
    return 1;
}


Matriz *criaTriangularSup(Matriz *mat){
    if(mat==NULL) return NULL;
    if(!eMatrizQuadrada(mat)){
        printf("A matriz nao eh quadratica!\n");
        return 0;
    }
    Matriz *ts = criaMatriz(mat->lin,mat->col);
    for(int i=0;i<mat->lin;i++){
        for(int j=0;j<mat->col;j++)
            if(i<=j) ts->dados[i][j] = mat->dados[i][j];
    }
    return ts;
}


Matriz* criaTriangularInf(Matriz *mat){
    if(mat == NULL) return NULL;
    if(!eMatrizQuadrada(mat)){
        printf("Matriz nao quadrada!\n");
        return NULL;
    }
    Matriz *ti= criaMatriz(mat->lin,mat->col);
    for(int i=0;i<mat->lin;i++){
        for(int j=0;j<mat->col;j++)
            if(i>=j) ti->dados[i][j] = mat->dados[i][j];
    }
    return ti;
}


Matriz* criaDiagonal(Matriz *mat){
    if(mat==NULL) return NULL;
    if(!eMatrizQuadrada(mat)){
        printf("Matriz nao quadrada!\n");
        return NULL;
    }
    Matriz *d = criaMatriz(mat->lin,mat->col);
    for(int i=0;i<mat->lin;i++)
        d->dados[i][i] = mat->dados[i][i];
    return d;
}


#endif
