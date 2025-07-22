#include <stdio.h>
#include "AVL.h"


int main(){
    AVL *A;
    int escolha=0;
    Funcionario *fun;


    printf("\n===========AVL===========\n");
    printf("1 - Criar AVL\n");
    printf("2 - Inserir um Funcionario\n");
    printf("3 - Buscar um Funcionario\n");
    printf("4 - Remover um elemento\n");
    printf("5 - Imprimir a AVL em ordem\n");
    printf("6 - Imprimir as informacoes do maior salario\n");
    printf("7 - Imprimir as informacoes do menor salario\n");
    printf("8 - Destruir a AVL\n");
    printf("9 - Sair;\n");
    printf("=========================\n");

   do{
       printf("Selecione uma opcao: ");
       scanf("%d",&escolha);


       switch (escolha){
       case 1:
           A = criaAVL();
           break;
       case 2:
           printf("Qual o nome?\n");
           fflush(stdin);
           fgets(fun->nome, 20, stdin);
           printf("Qual o salario?\n");
           scanf("%lf",&fun->salario);
           printf("Qual o ano?\n");
           scanf("%d",&fun->ano);
           insereElem(A, fun);
           break;
       case 3:
           printf("Qual funcionario deseja buscar?\n");
           fflush(stdin);
           fgets(fun->nome, 20, stdin);
           NO *aux = pesquisa(A, fun->nome);
           printf("Funcionario %s   Salario: %lf\n  Ano:%d\n", aux->fun.nome, aux->fun.salario, aux->fun.ano);
           break;
       case 4:
            printf("Qual funcionario deseja demitir?\n");
            fgets(fun->nome, 20, stdin);
            removeElem(A, fun->nome);
            break;
       case 5:
            imprime(A);
            break;
       case 6:
            maior(A);
            break;
       case 7:
            menor(A);
            break;
       case 8:
            destroiAVL(A);
            break;
        case 9:
            break;       
       default:
           printf("Opcao inexistente!\n");
           break;
       }
   }while(1);


   return 0;
}
