#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
    int aux = *a;
    *a=*b;
    *b=aux;
}

int mediana(int num1, int num2, int num3){
    if ((num1 >= num2 && num1 <= num3) || (num1 >= num3 && num1 <= num2))
        return num1;
    else if ((num2 >= num1 && num2 <= num3) || (num2 >= num3 && num2 <= num1))
        return num2;
    else
        return num3;
}

int particao(int *v, int ini, int fim){
    int i = ini, j = fim;
    int pivo = mediana(v[ini], v[fim], v[fim-ini]);
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

void QuickSort(int *v, int ini, int fim){
    if(ini<fim){
        int q = particao(v, ini, fim);
        QuickSort(v, ini, q);
        QuickSort(v, q+1, fim);
    }
}

int main(){
   int v[10] = {10,9,8,7,6,5,4,3,2,1};

   QuickSort(v,0,9);
   for(int i=0;i<10;i++)
       printf("%d ", v[i]);
   printf("\n");

   return 0;
}