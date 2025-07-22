#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp; 
int mov; 

int* copiaVetor(int *v, int n){
    int i;
    int *v2;
    v2 = (int*)malloc(n*sizeof(int));
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

void preencheAleatorio(int* v, int n, int ini, int fim){
    int i;
    for(i=0; i<n; i++)
        v[i] = ini + rand() % ((fim-ini) + 1); 
}

void troca(int* a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
} 

void shellSort(int *v, int n){
    int i, j, atual;
    int h=1;
    while(h<n) h = 3*h+1;
    while(h>0){
        for(i=h; i<n; i++){
            atual = v[i];
            j=i;
            while(j>h-1 && atual<=v[j-h]){
                v[j] = v[j-h];
                j = j-h;
            }
            v[j] = atual;
        }
        h = h/3;
    }
}

void merge(int *v, int ini, int meio, int fim){
    int tam = fim-ini+1;
    //vetor auxiliar - A
    int *A = (int*)malloc(tam*sizeof(int));
    int i=ini, j=meio+1, k=0;
    while(i<=meio && j<=fim){
        if(v[i] < v[j]){
            A[k] = v[i];
            i++;
        }else{
            A[k] = v[j];
            j++;
        }
        k++;
    }
    while(i<=meio){
        A[k] = v[i];
        i++;
        k++;
    }
    while(j<=fim){
        A[k]= v[j];
        j++;
        k++;
    }
    for(i = ini, k=0; i<=fim; i++, k++)
        v[i] = A[k];
    free(A);
}

void mergeSort(int *v, int ini, int fim){
    if(ini<fim){
        int meio = (ini+fim)/2;
        mergeSort(v, ini, meio);
        mergeSort(v, meio+1, fim);
        merge(v, ini, meio, fim);
    }
}

int particao(int *v, int ini, int fim){
    int i = ini, j = fim;
    int pivo = v[(ini+fim)/2];
    while(1){
        while(v[i]<pivo) 
            i++; 
        while(v[j]>pivo)
            j--; 
        if(i<j){
            troca(&v[i], &v[j]); 
            i++;
            j--;
        }else
            return j; 
    }
}

void quickSort(int *v, int ini, int fim){
    if(ini< fim){
        int q = particao(v, ini, fim);
        quickSort(v, ini, q);
        quickSort(v, q+1, fim);
    }
}

void criaHeap(int *v, int pai, int fim){
    int aux = v[pai];
    int filho = 2*pai + 1;
    while(filho <= fim){
        if(filho < fim)
            if(v[filho] < v[filho+1])
                filho++;
        if(aux < v[filho]){
            v[pai] = v[filho];
            pai = filho;
            filho = 2*pai + 1;
        }else filho = fim + 1;
    }
    v[pai] = aux;
}

void heapSort(int *v, int n){
    int i;
    for(i=(n-1); i>=0; i--)
        criaHeap(v, i, n-1);
    for(i=n-1; i>=1; i--){
        troca(&v[0], &v[i]);
        criaHeap(v, 0, i-1);
    }
}

int main(){

    srand(time(NULL));
    comp = 0; mov = 0;
    clock_t t;

    FILE *f;  
    int i, tam, y, c;

    printf("Digite o tamanho do arquivo: ");
    scanf("%d", &tam);

    int p[tam]; 

    f = fopen("1000-misturado.txt", "r");

    if(f == NULL){
        return printf("Erro ao abrir o arquivo.\n");
    }

    for(i = 0; i < tam; i++){
        if (fscanf(f, "%d", &y) != 1){
            printf("Erro ao ler o arquivo.\n");
            break; 
        }
        p[i] = y;
    }

    int *v2, *v3, *v4, *v5;
    
    v2 = (int*) malloc (tam*sizeof(int));
    v3 = (int*) malloc (tam*sizeof(int));
    v4 = (int*) malloc (tam*sizeof(int));
    v5 = (int*) malloc (tam*sizeof(int));

    imprimeVetor(p, tam);

    v2 = copiaVetor(p, tam);
    v3 = copiaVetor(p, tam);
    v4 = copiaVetor(p, tam);
    v5 = copiaVetor(p, tam);

    t = clock();
    shellSort(v2, tam);
    t = clock() - t;
    printf("    Informacoes Shell:\n");
    printf("Tempo Execucao:  %f segundos.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    printf("Movimentacoes: %d\n", mov);
    printf("Memoria (bytes): %ld\n", tam*sizeof(int));


    comp = 0; mov = 0;
    t = clock();
    quickSort(v3, 0, tam-1);
    t = clock() - t;
    printf("    Informacoes Quick:\n");
    printf("Tempo Execucao:  %f segundos.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    printf("Movimentacoes: %d\n", mov);
    printf("Memoria (bytes): %ld\n", tam*sizeof(int));


    comp = 0; mov = 0;
    t = clock();
    mergeSort(v4, 0, tam-1);
    t = clock() - t;
    printf("    Informacoes Merge:\n");
    printf("Tempo Execucao:  %f segundos.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    printf("Movimentacoes: %d\n", mov);
    printf("Memoria: %ld\n", tam*sizeof(int));

    comp = 0; mov = 0;
    t = clock();
    heapSort(v4, tam);
    t = clock() - t;
    printf("    Informacoes Heap:\n");
    printf("Tempo Execucao:  %f segundos.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    printf("Movimentacoes: %d\n", mov);
    printf("Memoria: %ld\n", tam*sizeof(int));

    printf("Vetor Impresso:\n");
    imprimeVetor(v4, tam);

    free(v2);
    free(v3);
    free(v4);
    free(v5);
    return 0;
}