#include <stdio.h>
#include "delivery.h"

int main(){
    Pedido *ped;
    ped = criaPedido();

    Itens produto1;
    strcpy(produto1.nome, "Hamburguer");
    produto1.preco = 3.5;
    produto1.qtd = 2;

    Itens produto2;
    strcpy(produto2.nome, "Pao");
    produto2.preco = 7;
    produto2.qtd = 6;

    Itens produto3;
    strcpy(produto3.nome, "Queijo");
    produto3.preco = 6.50;
    produto3.qtd = 1;

    Itens produto4;
    strcpy(produto4.nome, "Alface");
    produto4.preco = 3;
    produto4.qtd = 2;

    alocar_item(ped, &produto1);
    alocar_item(ped, &produto2);
    alocar_item(ped, &produto3);
    alocar_item(ped, &produto4);
    remover_item(ped, &produto4);

    definir_endereco(ped, "CTAN");

    finalizar_pedido(ped);
    return 0;
}