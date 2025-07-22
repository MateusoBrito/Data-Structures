#include <stdio.h>

void ordem_crescente(int n){
    if(n>0){
        ordem_crescente(n-1);
        printf("%d\n",n);
    }
}

void ordem_decrescente(int n){
    if(n>0){
        printf("%d\n",n);
        ordem_decrescente(n-1);
    }
}

int main(){
    printf("Ordem crescente: \n");
    ordem_crescente(5);
    printf("Ordem decrescente: \n");
    ordem_decrescente(5);
}