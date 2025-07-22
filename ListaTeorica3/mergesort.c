#include <stdio.h>
#include <stdlib.h>


void Merge(int *v, int ini, int meio, int fim, int *result){
   int tam = fim-ini+1;
   int i = ini, j = meio+1, k = ini;
   while(i<=meio && j<=fim){
       if(v[i]<v[j]){
           result[k] = v[i];
           i++;
       } else {
           result[k] = v[j];
           j++;
       }
       k++;
   }
   while(i<=meio){
       result[k] = v[i];
       i++;
       k++;
   }
   while(j<=meio){
       result[k] = v[j];
       j++;
       k++;
   }
   for(int i=ini, k= ini; i<=fim; i++, k++)
       v[i] = result[k];
}




void MergeSort(int *v, int ini, int fim, int *result){
   if(ini<fim){
       int meio = (ini+fim)/2;
       MergeSort(v,ini,meio, result);
       MergeSort(v, meio+1, fim, result);
       Merge(v, ini, meio, fim, result);
   }
}


int main(){
   int v[10] = {10,9,8,7,6,5,4,3,2,1};
   int *result = (int*)malloc(10*sizeof(int));
   MergeSort(v,0, 9, result);
   for(int i=0;i<10;i++)
       printf("%d ", result[i]);
   printf("\n");
}
