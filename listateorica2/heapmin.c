#include <stdio.h>
#include "heapmin.h"
    
int main(){
    FilaP *fp = NULL;
    int escolha;
    int elem, prio,valor, pri;
    do{
        printf("\nMenu:\n");
        printf("1 - Criar Fila\n");
        printf("2 - Inserir um item pela prioridade\n");
        printf("3 - Ver o inicio da Fila\n");
        printf("4 - Remover um item\n");
        printf("5 - Imprimir a Fila\n");
        printf("6 - Mostrar o tamanho da Fila\n");
        printf("7 - Destruir a Fila\n");
        printf("8 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                if(fp == NULL)
                    fp = criaFila();
                break;
            case 2:
                printf("Digite o elemento e a prioridade: ");
                scanf("%d %d", &elem, &prio);
                inserirPrio(fp, elem, prio);
                break;
            case 3:
                verIni(fp, &valor, &pri);
                printf("Prioridade e valor do início da fila: [%d, %d]\n", pri, valor);
                
                break;
            case 4:
                removeIni(fp);
                printf("Elemento removido!\n");
                break;
            case 5:
                imprime(fp);
                break;
            case 6:
                int tamanho = tamanhoFila(fp);
                printf("Tamanho: %d\n", tamanho);
                break;
            case 7:
                destroiFila(fp);
                break;
            case 8:
                break;
            default:
                printf("Opcao inválida!\n");
        }
    } while (escolha != 8);
    return 0;
}
