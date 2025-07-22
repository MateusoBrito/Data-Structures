#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void imprimir_contrario(char *str){
    if(str[0]!='\0'){
        printf("%c",str[strlen(str)-1]);
        str[strlen(str)-1] = '\0';
        imprimir_contrario(str);
    }
}

int main(){
    char frase[50];
    printf("Qual frase deseja inverter?\n");
    fgets(frase,50,stdin);
    imprimir_contrario(frase);
    return 0;
}