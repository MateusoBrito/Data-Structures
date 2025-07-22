#include <stdio.h>


void troca(int *a, int *b){
   int aux = *a;
   *a=*b;
   *b=aux;
}


void InsertionSort(int *v, int n){
   int atual, j;
   for(int i=1; i<n; i++){
       atual = v[i];
       for(j=i; (j>0)&&(atual<v[j-1]);j--){
           v[j] = v[j-1];
       }
       v[j] = atual;
   }
}


void SelectionSort(int *v, int n){
   int menor;
   for(int i=0;i<n-1;i++){
       menor = i;
       for(int j=i+1; j<n; j++){
           if(v[j]<v[menor])
               menor = j;
       }
       if(i != menor){
           troca(&v[i], &v[menor]);
       }
   }
}


void BubbleSort(int *v, int n){
   int continua, fim = n;
   do{
       continua = 0;
       for(int j =0;j<fim-1;j++){
           if(v[j]>v[j+1]){
               troca(&v[j],&v[j+1]);
               continua = j;
           }
       }
       fim--;
   }while(continua != 0);
}


int main(){
   int tamanho;
   printf("Qual o Tamanho do vetor?\n");
   scanf("%d",&tamanho);


   int vetor[tamanho];
   for(int i=0;i<tamanho;i++){
       printf("vetor[%d]: ",i);
       scanf("%d",&vetor[i]);
   }


   SelectionSort(vetor,tamanho);
   printf("==============================\n");
   for(int i=0;i<tamanho;i++){
       printf("vetor[%d]: %d\n",i, vetor[i]);
   }


   return 0;
}
