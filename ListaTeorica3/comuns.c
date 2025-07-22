#include <stdio.h>
#include <stdlib.h>


void Merge(int *v, int ini, int meio, int fim){
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


void MergeSort(int *v, int ini, int fim){
    if(ini < fim ){
        int meio = (ini + fim)/2;
        MergeSort(v, ini, meio);
        MergeSort(v, meio+1, fim);
        Merge(v, ini, meio, fim);
    }
}


void elementosIguais(int *v1, int *v2, int n){
    printf("Elementos comuns aos dois vetores: \n");
    int i, j;
    for(i=0; i<n; ){
        for(j=0; j<n; ){
            if(v1[i] == v2[j]){
                printf("%d ", v1[i]);
                i++; j++;
            }
            else if(v1[i] < v2[j]) i++;
            else if(v2[j] < v1[i]) j++;
        }
    }
}


int main(){
    int *v1, *v2, n;
    printf("Digite o tamanho dos seus dois vetores: ");
    scanf("%d", &n);
    v1 = (int*)malloc(n*sizeof(int));
    v2 = (int*)malloc(n*sizeof(int));
    printf("Digite os elementos do vetor 1: ");
    for(int i=0; i<n; i++){
        scanf("%d", &v1[i]);
    }
    printf("Digite os elementos do vetor 2: ");
    for(int i=0; i<n; i++){
        scanf("%d", &v2[i]);
    }
    MergeSort(v1, 0, n-1);
    MergeSort(v2, 0, n-1);
    elementosIguais(v1, v2, n);


    free(v1);
    free(v2);
    return 0;
}