#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(char *arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (strlen(arr[j]) < strlen(arr[j + 1])) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    char delimitadores[] = " ";

    for (int i = 0; i < N; i++) {
        fflush(stdin);
        char frase[50];
        fgets(frase, 50, stdin);

        char *palavras[50];
        char *p = strtok(frase, delimitadores);
        int j = 0, tam = 0;
        while (p != NULL) {
            palavras[j] = malloc(strlen(p) + 1);
            strcpy(palavras[j], p);
            j++;
            tam++;
            p = strtok(NULL, delimitadores);
        }
        

        BubbleSort(palavras, tam);

        for (int k = 0; k < tam; k++) {
            if(k == tam-1){
                printf("%s", palavras[k]);
            } else {
                printf("%s ", palavras[k]);
            }
            free(palavras[k]);
        }
        
        fflush(stdin);
    }

    return 0;
}