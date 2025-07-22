#ifndef DELIVERY_H
#define DELIVERY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct{
    char nome[50];
    double preco;
    int qtd;
}Itens;

typedef struct Pedido{
    Itens itens[MAX];
    int tam;
    char endereco[100];
    double total;
    char status[20];
} Pedido;

Pedido* criaPedido(){
    Pedido *li;
    li=(Pedido*)malloc(sizeof(Pedido));
    if(li != NULL)
        li->tam = 0;
    return li;
}

int alocar_item(Pedido *ped, Itens *item){
    if(ped->itens == NULL) return 0;
    if(ped->tam != 50){
        strcpy(ped->itens[ped->tam].nome, item->nome);
        ped->itens[ped->tam].preco = item->preco;
        ped->itens[ped->tam].qtd = item->qtd;
        ped->tam++;
        ped->total += (item->preco*item->qtd);
        printf("Item inserido no pedido!\n");
        return 1;
    } else {
        printf("Elemento nao inserido - Carrinho cheio!\n");
        return 0;
    }
}

int remover_item(Pedido *ped, Itens *item){
    if(ped->itens == NULL) return 0;
    if(ped->tam != 0){
        for(int i=0;i<ped->tam;i++){
            if(strcmp(ped->itens[i].nome, item->nome) == 0){
                for(int j=i;j<ped->tam;j++){
                    ped->itens[j] = ped->itens[j+1];
                }
            }
        }
        ped->tam--;
        ped->total -= (item->preco*item->qtd);
        printf("Elemento removido!\n");
        return 1;
    }else{
        printf("Elemento nao removido - Carrinho vazia!\n");
        return 0;
    }
}

void calcular_total(Pedido *ped){
    printf("> Total da compra : %.2lf\n", ped->total);
}

void definir_endereco(Pedido *ped,char endereco[]){
    strcpy(ped->endereco,endereco);
    printf("Endereco inserido!\n");
}

void alterar_status(Pedido *ped, char status[]){
    strcpy(ped->status,status);
    printf("> Pedido %s!\n", status);
}

void finalizar_pedido(Pedido *ped){
    printf("---------------------------------------\n");
    printf("        COMPRA FINALIZADA\n");
    printf("---------------------------------------\n");

    for(int i=0;i<ped->tam;i++){
        printf("\nItem %d:\n", i+1);
        printf("Nome: %s\n", ped->itens[i].nome);
        printf("Preco: %.2lf\n", ped->itens[i].preco);
        printf("Quantidade: %d\n", ped->itens[i].qtd);
    }
    printf("---------------------------------------\n");
    calcular_total(ped);
    printf("> Endereco de entrega: %s\n", ped->endereco);
    alterar_status(ped, "preparando");  
}

#endif