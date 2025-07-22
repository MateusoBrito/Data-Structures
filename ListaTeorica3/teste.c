/*---------------- File: Insertion.c  ------------------+
|Insertion Sort                                         |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 06/11/2023      |
+-------------------------------------------------------+ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Medidas de Complexidade
int comp; //Num. de comparacoes
int mov; //Num. de movimentacoes

int* copiaVetor(int* v, int n){
    int i;
    int *v2;
    v2 = (int*) malloc (n*sizeof(int));
    for(i=0; i<n; i++) v2[i] = v[i];
    return v2;
}
void imprimeVetor(int* v, int n){
    int i, prim = 1;
    printf("[");
    for(i=0; i<n; i++)
        if(prim){ printf("%d", v[i]); prim = 0; }
        else printf(", %d", v[i]);
    printf("]\n");
}

void troca(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
} 

void InsertionSort(int *v, int n){
  int i, j, atual;
  for(i=1; i < n; i++){
    atual = v[i];
    comp++;
    for(j=i; (j>0) && (atual < v[j-1]); j--){
       v[j] = v[j-1];
       comp++;
       mov++;
    }
    v[j] = atual;
  }
}

int main(){

    //Atribuicoes iniciais
    srand(time(NULL));
    comp = 0; mov = 0;
    clock_t t;

    /*
    //Template de Calculo do Tempo de Execucao
    t = clock();
    //Chamada do Algoritmo aqui...
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    */

    int v[6] = {15,27,2,18,11,6};
    int n;
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);

    
    imprimeVetor(v, n);
    
    
    t = clock();
    InsertionSort(v, n);
    t = clock() - t;
    printf("-----Informacoes:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    printf("Movimentacoes: %d\n", mov);
    printf("Memoria (bytes): %d\n", n*sizeof(int));

    imprimeVetor(v, n);

    return 0;
}