#ifndef MATRIZF_H
#define MATRIZF_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *diagonal;
    int *superior;
    int *inferior;
    int tam;
}MFaixa;

int zeraMatriz(MFaixa *mat){
    if(mat==NULL) return 0;
    for(int i=0;i<mat->tam;i++){
        mat->diagonal[i] = 0;
        mat->inferior[i] = 0;
        mat->superior[i] = 0;
    }
    return 1;
}


MFaixa* criaMatriz(int t){
    MFaixa *mf;
    mf = (MFaixa*)malloc(sizeof(MFaixa));
    if(mf!=NULL){
        if(t<=1){
            printf("Deve ser maior que 1!\n");
            return NULL;
        }
        mf->tam = t;
        mf->diagonal = (int*)malloc(t*sizeof(int));
        mf->superior = (int*)malloc((t-1)*sizeof(int));
        mf->inferior = (int*)malloc((t-1)*sizeof(int));
        if(mf->diagonal == NULL || mf->inferior == NULL || mf->superior == NULL)
            return NULL;
        zeraMatriz(mf);
    }
    return mf;
}

void destroiMatriz(MFaixa *mf){
    if(mf != NULL){
        free(mf->diagonal);
        free(mf->inferior);
        free(mf->superior);
        free(mf);
    }
}

int insereElem(MFaixa *mf, int elem, int i, int j){
    if(mf==NULL) return 0;
    if(i < 0 || j < 0 || i >= mf ->tam || j >= mf -> tam )
        return 0;
    if(i == j) mf->diagonal[i] = elem;
    else if(i+1==j) mf->superior[i] = elem;
    else if(i==j+1) mf->inferior[j] = elem;
    else{
        printf("Indices fora da faixa!\n");
        return 0;
    }
    return 1;
}

int consultaElem(MFaixa *mf, int i, int j){
    if(mf==NULL) return 0;
    if(i < 0 || j < 0 || i >= mf ->tam || j >= mf -> tam )
        return 0;
    if(i == j) return mf->diagonal[i];
    else if(i+1==j) return mf->superior[i];
    else if(i==j+1) return mf->inferior[j];
    else return 0;
} 

void imprimeFaixaVetores(MFaixa *mf){
    if(mf==NULL) return;
    printf("Matriz Faixa, Tam: %d x %d:\n",mf->tam, mf->tam);
    printf("Diagonal = [");
    for(int i=0; i<mf->tam;i++)
        printf("%d ", mf->diagonal[i]);
    printf("]\n");
    printf("Superior = [");
    for(int i=0; i<mf->tam-1;i++)
        printf("%d ", mf->superior[i]);
    printf("]\n");
    printf("Inferior = [");
    for(int i=0; i<mf->tam-1;i++)
        printf("%d ", mf->inferior[i]);
    printf("]\n\n");
    return;
}

void imprimeFaixa(MFaixa *mf){
    if(mf==NULL) return;
    printf("Matriz Original:\n");
    for(int i=0;i<mf->tam;i++){
        for(int j=0;j<mf->tam;j++)
            printf("%d\t", consultaElem(mf,i,j));
        printf("\n");
    }
}

#endif