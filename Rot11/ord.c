#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
    int aux = *a;
    *a=*b;
    *b=aux;
}

void criaHeap(int *v, int pai, int fim){
    int aux = v[pai];
    int filho = 2*pai + 1;
    while(filho<=fim){
        if(filho<fim)
            if(v[filho] < v[filho+1])
                filho++;
        if(aux<v[filho]){
            v[pai] = v[filho];
            pai = filho;
            filho = 2*pai + 1;
        } else {
            filho = fim+1;
        }
    }
    v[pai] = aux;
}

void HeapSort(int *v, int n){
    for(int i=(n-1)/2;i>=0;i--)
        criaHeap(v,i,n-1);
    for(int i=n-1; i>=1; i--){
        troca(&v[0],&v[i]);
        criaHeap(v,0,i-1);
    }
}

int particao(int *v, int ini, int fim){
    int i=ini, j=fim;
    int pivo = v[(ini+fim)/2];
    while(1){
        while(v[i] < pivo) i++;
        while(v[j] > pivo) j--;
        if(i<j){
            troca(&v[i], &v[j]);
            i++;
            j--;
        } else {
            return j;
        }

    }
}

void quickSort(int *v, int ini, int fim){
    if(ini<fim){
        int q = particao(v, ini, fim);
        quickSort(v, ini , q);
        quickSort(v, q+1, fim);
    }
}

void merge(int *v, int ini, int meio, int fim){
    int tam = fim-ini+1;
    int *A = (int*)malloc(tam*sizeof(int));
    int i = ini, j = meio+1, k=0;
    while(i<=meio && j<=fim){
        if(v[i] < v[j]){
            A[k] = v[i];
            i++;
        } else {
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
        A[k] = v[j];
        j++;
        k++;
    }
    for(i=ini,k=0; i<=fim;i++,k++)
        v[i] = A[k];
    free(A);
}

void mergeSort(int *v, int ini, int fim){
    if(ini<fim){
        int meio = (ini+fim)/2;
        mergeSort(v, ini , meio);
        mergeSort(v, meio+1, fim);
        merge(v, ini, meio, fim);
    }
}

void shellsort(int *v, int n){
    int h=1,j, atual;
    while(h<n)
        h = 3*h+1;
    while(h>0){
        for(int i=h;i<n;i++){
            atual = v[i];
            j = i;
            while(j>h-1 && atual <= v[j-h]){
                v[j] = v[j-h];
                j = j-h;
            }
            v[j] = atual;
        }
        h = h/3;
    }
}

void imprimeVetor(int *v, int tamanho){
    for(int i=0; i<tamanho; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main(){
    int tamanho;
    printf("Qual o tamanho do vetor?\n");
    scanf("%d",&tamanho);

    int vetor[tamanho];
    for(int i=0;i<tamanho;i++){
        printf("vetor[%d]: ",i);
        scanf("%d",&vetor[i]);
    }

    //printf("ShellSort: \n");
    //shellsort(vetor, tamanho);
    //imprimeVetor(vetor, tamanho);
    
    //printf("MergeSort: \n");
    //mergeSort(vetor, 0, tamanho-1);
    //imprimeVetor(vetor, tamanho);

    //printf("QuickSort: \n");
    //quickSort(vetor, 0, tamanho-1);
    //imprimeVetor(vetor, tamanho);

    printf("HeapSort: \n");
    HeapSort(vetor,tamanho);
    imprimeVetor(vetor, tamanho);

    return 0;
}