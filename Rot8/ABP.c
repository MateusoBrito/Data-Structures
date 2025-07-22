#include <stdio.h>
#include "ABP.h"

int main() {
    ABP *A;
    int escolha, elem;

    do {
        printf("\nMenu de Operacoes:\n");
        printf("1 - Criar ABP\n");
        printf("2 - Inserir um elemento\n");
        printf("3 - Buscar um elemento\n");
        printf("4 - Remover um elemento\n");
        printf("5 - Imprimir a ABP em ordem\n");
        printf("6 - Imprimir a ABP em pre-ordem\n");
        printf("7 - Imprimir a ABP em pos-ordem\n");
        printf("8 - Mostrar a quantidade de nos na ABP\n");
        printf("9 - Destruir a ABP\n");
        printf("10 - Sair\n");

        printf("Escolha uma escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                A = criaABP();
                break;

            case 2:
                printf("Digite o elemento: ");
                scanf("%d", &elem);
                insereElem(A, elem);
                break;

            case 3:
                printf("Digite o elemento que deseja buscar: ");
                scanf("%d", &elem);
                if (pesquisa(A, elem)) {
                    printf("Elemento encontrado.\n");
                } else {
                    printf("Elemento nao encontrado.\n");
                }
                break;

            case 4:
                printf("Digite o elemento que deseja remover: ");
                scanf("%d", &elem);
                removeElem(A, elem);
                break;

            case 5:
                printf("Imprimindo a ABP em ordem:\n");
                imprimeEmOrdem(A);
                break;

            case 6:
                printf("Imprimindo a ABP em pre-ordem:\n");
                imprimePre(A);
                break;

            case 7:
                printf("Imprimindo a ABP em pos-ordem:\n");
                imprimePos(A);
                break;

            case 8:
                printf("A quantidade de nos na ABP e: %d\n", quantidadeNos(A));
                break;

            case 9:
                destroiABP(A);
                break;

            case 10:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("escolha invalida. Tente novamente.\n");
                break;
        }

    } while (escolha != 10);

    return 0;
}
