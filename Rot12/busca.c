#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp;

void troca(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
} 

int particao(int *v, int ini, int fim){
    int i = ini, j = fim;
    int pivo = v[(ini+fim)/2];
    while (1) {
        while(v[i] < pivo){ i++; }
        while(v[j] > pivo){ j--; }
        
        if(i<j){
            troca(&v[i], &v[j]);
            i++;
            j--;
        }else
            return j;
    }    
}

void QuickSort(int *v, int ini, int fim){
    if(ini < fim ){
        int q = particao(v, ini, fim);
        QuickSort(v, ini, q);
        QuickSort(v, q+1, fim);
    }
}

void preencheAleatorio(int* v, int n, int ini, int fim){
    int i;
    for(i=0; i<n; i++)
        v[i] = ini + rand() % (fim-ini + 1); 
}

int buscaBinaria(int *v, int ini, int fim, int elem){
    if(ini>fim) return -1;
    int meio = (ini+fim)/2;
    comp++;
    if(elem == v[meio])
        return meio;
    else if(elem > v[meio])
        return buscaBinaria(v, meio+1, fim, elem);
    else
        return buscaBinaria(v, ini, meio-1, elem);
}

int buscaSequencial(int *v, int n, int elem){
    for(int i=0;i<n;i++){
        comp++;
        if(v[i]==elem)
            return i;
    }
    return -1;
}

void imprimeVetor(int* v, int n){
    int i, prim = 1;
    printf("[");
    for(i=0; i<n; i++)
        if(prim){ printf("%d", v[i]); prim = 0; }
        else printf(", %d", v[i]);
    printf("]\n");
}

int main(){
    
    srand(time(NULL));
    comp = 0;
    clock_t t;

    int *v;
    int n, elem;
    printf("Digite o tamanho do vetor:");
    scanf("%d",&n);
    v = (int*)malloc(n*sizeof(int));

    preencheAleatorio(v, n, 1, n);
    //imprimeVetor(v, n);
    QuickSort(v, 0, n-1);

    printf("Qual elemento deseja buscar: ");
    scanf("%d",&elem);

    int ind;

    t = clock();
    ind = buscaSequencial(v, n, elem);
    t = clock() - t;
    printf("    Busca Sequencial\n");
    printf("Tempo Execucao:  %f\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);

    if(ind!=-1)
        printf("O elemento %d foi encontrado na pos %d.\n", elem, ind);
    else
        printf("O elemento %d NAO foi encontrado!\n", elem);

    comp = 0;
    t = clock();
    ind = buscaBinaria(v, 0, n-1, elem);
    t = clock() - t;
    printf("    Busca Binaria\n");
    printf("Tempo Execucao:  %f\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);

    if(ind != -1)
        printf("O elemento %d foi encontrado na pos %d.\n", elem, ind);
    else
        printf("O elemento %d NAO foi encontrado!\n", elem);

    free(v);
    return 0;
}
