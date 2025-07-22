#include <stdio.h>

void preencher_vetor(int *vet,int N, int P){
    if(P!=N){
        printf("Valor: ");
        scanf("%d",&vet[P]);
        preencher_vetor(vet,N,P+1);
    }
}

int main(){
    int N;
    printf("Qual o tamanho do vetor: ");
    scanf("%d",&N);
    int vet[N];
    preencher_vetor(vet,N,0);
    //__________________________________________//

    return 0;   
}