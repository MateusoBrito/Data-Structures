#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
   int aux = *a;
   *a=*b;
   *b=aux;
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
int main(){
    int N;
    scanf("%d",&N);

    int par[N];
    int tamanhopar=0;
    int tamanhoimpar=0;
    int impar[N];

    for(int i=0; i<N;i++){
        int num;
        scanf("%d",&num);

        if(num%2==0){
            par[tamanhopar] = num;
            tamanhopar++;
        } else {
            impar[tamanhoimpar] = num;
            tamanhoimpar++;
        }

    }

    mergeSort(par, 0, tamanhopar-1);
    for(int i=0;i<tamanhopar;i++)
        printf("%d\n", par[i]);
    mergeSort(impar, 0, tamanhoimpar-1);
    for(int i=tamanhoimpar-1;i>=0;i--)
        printf("%d\n", impar[i]);
    
    
    return 0;
}