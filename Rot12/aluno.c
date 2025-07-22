#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct sAluno{
    char nome[50];
    int matricula;
    float n1, n2, n3;
}Aluno;


//Medidas de Complexidade
int comp; //Num. de comparacoes
int mov; //Num. de movimentacoes


void preencheVetorAluno(Aluno* v, int n){
    int i;
    for(i=0; i<n; i++){
        while(getchar() != '\n'); // Limpa o buffer de entrada
        printf("Digite o nome: ");
        //fflush(stdin);
        //fgets(v[i].nome, 50, stdin);
        //v[i].nome[strlen(v[i].nome)-1] = '\0';
        scanf("%s", v[i].nome);
        printf("Digite a matricula: ");
        scanf("%d", &v[i].matricula);
        printf("Digite as tres notas: ");
        scanf("%f %f %f", &v[i].n1, &v[i].n2, &v[i].n3);
    }
}


void imprimeVetorAluno(Aluno* v, int n){
    int i, prim = 1;
    printf("\nAluno, matricula, n1, n2 e n3, respectivamente: \n");
    printf("[");
    for(i=0; i<n; i++)
        if(prim){
            printf("(%s, %d, %.2f %.2f %.2f)", v[i].nome, v[i].matricula, v[i].n1, v[i].n2, v[i].n3);
            prim = 0;
        }
        else
            printf(", (%s, %d, %.2f %.2f %.2f)", v[i].nome, v[i].matricula, v[i].n1, v[i].n2, v[i].n3);
    printf("]\n\n");
}


void trocaAluno(Aluno* a, Aluno *b){
    char auxNome[50];
    int auxMatricula;
    float auxN1, auxN2, auxN3;
    strcpy(auxNome, a->nome);
    strcpy(a->nome, b->nome);
    strcpy(b->nome, auxNome);
    auxMatricula = a->matricula;
    a->matricula = b->matricula;
    b->matricula = auxMatricula;
    auxN1 = a->n1;
    a->n1 = b->n1;
    b->n1 = auxN1;
    auxN2 = a->n2;
    a->n2 = b->n2;
    b->n2 = auxN2;
    auxN3 = a->n3;
    a->n3 = b->n3;
    b->n3 = auxN3;
}


int comparaAluno(Aluno* a, Aluno* b){
    if(strcmp(a->nome, b->nome) < 0) return 1;
    else if(strcmp(a->nome, b->nome) > 0) return 0;
    else{ //strcmp(a.nome, b.nome) == 0
        if(a->matricula < b->matricula) return 1;
        else return 0;
    }
}


void imprimeAluno(Aluno *v, int indice){
    int i = indice;
    printf("\nAluno: %s\n", v[i].nome);
    printf("Matricula: %d\n", v[i].matricula);
    printf("N1: %.2f\n", v[i].n1);
    printf("N2: %.2f\n", v[i].n2);
    printf("N3: %.2f\n", v[i].n3);
}


void insertionSortAluno(Aluno *v, int n) {
    int i, j;
    Aluno atual;
    for (i = 1; i < n; i++) {
        atual = v[i];
        comp++;
        for (j = i; j > 0 && comparaAluno(&atual, &v[j - 1]); j--) {
            v[j] = v[j - 1];
            comp++;
            mov++;
        }
        v[j] = atual;
    }
}


int it_buscaBinariaNome(Aluno *v, int ini, int fim, char *name){
    int meio;
    while(ini <= fim){
        meio = (ini + fim)/2;
        comp++;
        if(strcmp(name, v[meio].nome) == 0) return meio;
        else
            if(strcmp(name, v[meio].nome) < 0)
                fim = meio-1;
            else
                ini = meio+1;
    }
    return -1;
}


int it_buscaBinariaMat(Aluno *v, int ini, int fim, int mat){
    int meio;
    while(ini <= fim){
        meio = (ini + fim)/2;
        comp++;
        if(mat == v[meio].matricula) return meio;
        else
            if(mat < v[meio].matricula)
                fim = meio-1;
            else
                ini = meio+1;
    }
    return -1;
}




int main(){
    comp = 0; mov = 0;
    clock_t t;

    Aluno *v;
    int n, mat;
    char nome[20];
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    v = (Aluno*) malloc (n*sizeof(Aluno));


    preencheVetorAluno(v, n);
    imprimeVetorAluno(v, n);
   
   
    t = clock();
    insertionSortAluno(v, n);
    t = clock() - t;
    printf("-----Informacoes (Insertion sort):\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    printf("Movimentacoes: %d\n", mov);
    printf("Memoria (bytes): %ld\n", n*sizeof(int));


    imprimeVetorAluno(v, n);


    printf("Digite o nome do aluno que deseja buscar: ");
    scanf("%s", nome);
    if(it_buscaBinariaNome(v, 0, n-1, nome) != -1){
        printf("\nO aluno %s esta no indice %d.\n", nome, it_buscaBinariaNome(v, 0, n-1, nome));
        imprimeAluno(v, it_buscaBinariaNome(v,0,n-1,nome));
    }else
        printf("Aluno nao encontrado");


    printf("Digite a matricula do aluno que deseja buscar: ");
    scanf("%d", &mat);
    if(it_buscaBinariaMat(v, 0, n-1, mat) != -1){
        printf("\nO aluno de matricula %d esta no indice %d.\n", mat, it_buscaBinariaMat(v, 0, n-1, mat));
        imprimeAluno(v, it_buscaBinariaMat(v,0,n-1,mat));
    }else
        printf("Aluno nao encontrado");


    free(v);


    return 0;
}