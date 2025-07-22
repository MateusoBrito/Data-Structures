#include <stdio.h>

int multiplicacao(int M,int N, int R){
    if(N==0) return R;
    R += M;
    return multiplicacao(M,N-1,R);
}

int main(){
    int M,N;
    printf("Primeiro Valor: ");
    scanf("%d",&M);
    printf("Segundo Valor: ");
    scanf("%d",&N);
    int result = 0;
    result = multiplicacao(M,N,result);
    printf("Resultado: %d",result);
    return 0;
}