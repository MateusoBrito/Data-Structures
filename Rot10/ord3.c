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

void imprime(int* v, int n){
    int prim = 1;
    printf("[");
    for(int i=0; i<n; i++)
        if(prim){ printf("%d", v[i]); prim = 0; }
        else printf(", %d", v[i]);
    printf("]\n");
}

void troca(int *a, int *b){
   int aux = *a;
   *a=*b;
   *b=aux;
}

void InsertionSort(int *v, int n){
   int atual, j;
   for(int i=1; i<n; i++){
       atual = v[i];
       comp++;
       for(j=i; (j>0)&&(atual<v[j-1]);j--){
           v[j] = v[j-1];
           comp++;
           mov++;
       }
       v[j] = atual;
   }
}


void SelectionSort(int *v, int n){
   int menor;
   for(int i=0;i<n-1;i++){
       menor = i;
       for(int j=i+1; j<n; j++){
            comp++;
            if(v[j]<v[menor])
                menor = j;
       }
       if(i != menor){
           troca(&v[i], &v[menor]);
           mov++;
       }
   }
}


void BubbleSort(int *v, int n){
   int continua, fim = n;
   do{
       continua = 0;
       for(int j =0;j<fim-1;j++){
            comp++;
            if(v[j]>v[j+1]){
                troca(&v[j],&v[j+1]);
                mov++;
                continua = j;
            }
        }
        fim--;
   }while(continua != 0);
}


int main(){
   
    srand(time(NULL));
    comp = 0; mov = 0;
    clock_t tempo;

    FILE *f;  
    int i, tamanho, y, c;

    printf("Tamanho do arquivo: ");
    scanf("%d", &tamanho);

    int p[tamanho]; 

    f = fopen("1000-misturado.txt", "r");
    if(f==NULL) return printf("Erro ao abrir o arquivo.\n");

    for(i= 0;i<tamanho;i++){
        if(fscanf(f, "%d", &y) != 1){
            printf("Erro ao ler o arquivo.\n");
            break; 
        }
        p[i] = y;
    }

    int *v1, *v2, *v3;
    v1 = (int*) malloc (tamanho*sizeof(int));
    v2 = (int*) malloc (tamanho*sizeof(int));
    v3 = (int*) malloc (tamanho*sizeof(int));
    imprime(p, tamanho);
    
    v1 = copiaVetor(p, tamanho);
    v2 = copiaVetor(p, tamanho);
    v3 = copiaVetor(p, tamanho);

    tempo = clock();
    SelectionSort(v1, tamanho);
    tempo = clock() - tempo;
    printf("        Informacoes Selection:\n");
    printf("Tempo Execucao:  %f seg\n", ((float)tempo)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    printf("Movimentacoes: %d\n", mov);
    printf("Memoria (bytes): %ld\n", tamanho*sizeof(int));

    comp = 0; mov = 0;
    tempo = clock();
    InsertionSort(v2, tamanho);
    tempo = clock() - tempo;
    printf("        Informacoes Insertion:\n");
    printf("Tempo Execucao:  %f seg.\n", ((float)tempo)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    printf("Movimentacoes: %d\n", mov);
    printf("Memoria (bytes): %ld\n", tamanho*sizeof(int));

    comp = 0; mov = 0;
    tempo = clock();
    BubbleSort(v3, tamanho);
    tempo = clock() - tempo;
    printf("-----Informacoes Bubble:\n");
    printf("Tempo Execucao:  %f seg.\n", ((float)tempo)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    printf("Movimentacoes: %d\n", mov);
    printf("Memoria (bytes): %ld\n", tamanho*sizeof(int));

    imprime(v3, tamanho);

    free(v1);
    free(v2);
    free(v3);
    return 0;
}
