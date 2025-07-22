#ifndef CONJUNTOINTEIROS_H
#define CONJUNTOINTEIROS_H

#include <stdio.h>

typedef struct{
    int tam;
    int vetor[100];
}Conjunto;

Conjunto criar_vetor(Conjunto *c){
    c->tam=0;
}

Conjunto uniao_vetores(Conjunto *c1,Conjunto *c2){
    Conjunto c3;
    criar_vetor(&c3);
    for(int i=0;i<c1->tam;i++){
        c3.vetor[i]= c1->vetor[i];
        c3.tam++;
    }
    for(int i=0;i<c2->tam;i++){
        c3.vetor[c3.tam] = c2->vetor[i];
        c3.tam++;
    }
    return c3;
}

void inserir(Conjunto *v, int elem){
    v->vetor[v->tam] = elem;
    v->tam++;
}

void remove_elemento(Conjunto *v, int elem){
    for(int i=0;i<v->tam;i++){
        if(v->vetor[i]==elem){
            for(int j=i;j<v->tam;j++){
                v->vetor[j] = v->vetor[j+1];
            }
            v->tam--;
        }
    }
}

Conjunto interseccao_elementos(Conjunto *c1, Conjunto *c2){
    Conjunto c3;
    criar_vetor(&c3);
    for(int i=0;i<c1->tam;i++){
        for(int j=0;j<c2->tam;j++){
            if(c1->vetor[i]==c2->vetor[j]){
                c3.vetor[c3.tam] = c2->vetor[j]; 
                c3.tam++;
                break;
            }
        }
    }
    return c3;
}

Conjunto diferenca_conjuntos(Conjunto *c1, Conjunto *c2) {
    Conjunto c3;
    criar_vetor(&c3);
    for (; c3.tam < c1->tam; c3.tam++) {
        c3.vetor[c3.tam] = c1->vetor[c3.tam];
    }
    for (int i = 0; i < c1->tam; i++) {
        for (int j = 0; j < c2->tam; j++) {
            if (c3.vetor[i] == c2->vetor[j]) {
                remove_elemento(&c3, c3.vetor[i]);
            }
        }
    }
    
    return c3;
}

int teste_presenca(Conjunto *c, int elem){
    for(int i=0;i<c->tam;i++){
        if(c->vetor[i] == elem) return 1;
    }
    return 0;
}

int menor_elemento(Conjunto *c){
    int menor = c->vetor[0];
    for(int i=0;i<c->tam;i++){
        if(c->vetor[i] < menor)
            menor = c->vetor[i];
    }
    return menor;
}

int maior_elemento(Conjunto *c){
    int maior = c->vetor[0];
    for(int i=0;i<c->tam;i++){
        if(c->vetor[i] > maior)
            maior = c->vetor[i];
    }
    return maior;
}

int tamanho_conjunto(Conjunto *c){
    return c->tam;
}

int teste_vazio(Conjunto *c){
    if(c->tam == 0)
        return 1;
    return 0;
}

int teste_igualdade(Conjunto *c1,Conjunto *c2){
    int aux=0;
    if(c1->tam != c2->tam) return 0;
    for(int i=0;i<c1->tam;i++){
        if(c1->vetor[i] == c2->vetor[i])
            aux++;
    }
    if(aux == c1->tam) return 1;
    return 0;
}

#endif