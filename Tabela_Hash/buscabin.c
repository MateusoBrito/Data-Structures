#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
} 

int particao(int *v, int ini, int fim){
    int i = ini, j = fim;
    int pivo = v[(ini+fim)/2];
    while (1) {
        while(v[i] > pivo) i++; 
        while(v[j] < pivo) j--; 
        
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

int rec_buscaBin(int *v, int ini, int fim, int elem){
    if(ini>fim) return -1;
    int meio = (ini+fim)/2;
    if(elem == v[meio])
        return meio;
    else if(elem > v[meio])
        return rec_buscaBin(v, ini, meio-1, elem);
    else
        return rec_buscaBin(v, meio+1, fim, elem);
}

int it_buscaBin(int *v, int ini, int fim, int elem){
    int meio;
    while(ini<=fim){
        meio=(ini+fim)/2;
        if(elem == v[meio])
            return meio;
        else if(elem<v[meio])
            ini = meio+1;
        else
            fim = meio-1;
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

    int *v;
    int n, elem;
    printf("Digite o tamanho do vetor:");
    scanf("%d",&n);
    v = (int*)malloc(n*sizeof(int));

    preencheAleatorio(v, n, 1, n);
    imprimeVetor(v, n);
    QuickSort(v, 0, n-1);

    printf("Qual elemento deseja buscar: ");
    scanf("%d",&elem);

    int ind;

    printf("    Busca Recursiva\n");
    ind = rec_buscaBin(v, 0, n-1, elem);
    if(ind != -1)
        printf("O elemento %d foi encontrado na pos %d.\n", elem, ind);
    else
        printf("O elemento %d NAO foi encontrado!\n", elem);

    printf("    Busca Iterativa\n");
    ind = it_buscaBin(v, 0, n-1, elem);
    if(ind != -1)
        printf("O elemento %d foi encontrado na pos %d.\n", elem, ind);
    else
        printf("O elemento %d NAO foi encontrado!\n", elem);

    free(v);
    return 0;
}
