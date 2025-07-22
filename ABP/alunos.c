#include <stdio.h>
#include "alunos.h"

int main() {
    ABP* A;
    int escolha;
    Aluno aluno;
    
    do {
        printf("\nMenu:\n");
        printf("1 - Criar ABP\n");
        printf("2 - Inserir um Aluno\n");
        printf("3 - Buscar um Aluno pelo nome\n");
        printf("4 - Remover um Aluno pelo nome\n");
        printf("5 - Imprimir a ABP em ordem\n");
        printf("6 - Imprimir Aluno com a maior nota\n");
        printf("7 - Imprimir Aluno com a menor nota\n");
        printf("8 - Destruir a ABP\n");
        printf("9 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                if (A != NULL) {
                    A = criaABP();
                    printf("ABP criada.\n");
                }
                break;
            case 2:
                printf("Informe o nome do aluno: ");
                scanf("%s", aluno.nome);
                printf("Informe a matricula do aluno: ");
                scanf("%d", &aluno.matricula);
                printf("Informe a nota do aluno: ");
                scanf("%lf", &aluno.nota);
                insereElem(A, aluno);
                break;
            case 3:
                printf("Informe o nome do aluno a ser buscado: ");
                char nome[100];
                scanf("%s", nome);
                if (pesquisa(A, nome)) {
                    printf("Aluno encontrado!\n");
                } else {
                    printf("Aluno não encontrado.\n");
                }
                break;
            case 4:
                printf("Informe o nome do aluno a ser removido: ");
                char nome2[100];
                scanf("%s", nome2);
                if (removeElem(A, nome2)) {
                    printf("Aluno removido com sucesso.\n");
                } else {
                    printf("Aluno não encontrado ou erro na remoção.\n");
                }
                break;
            case 5:
                printf("Árvore em ordem:\n");
                imprimeEmOrdem(A);
                break;
            case 6:
                imprimeMaiorNota(A);
                break;
            case 7:
                imprimeMenorNota(A);
                break;
            case 8:
                destroiABP(A);
                printf("ABP destruída.\n");
                break;
            case 9:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opcao inválida.\n");
                break;
        }
    } while (escolha != 9);
    
    return 0;
}
