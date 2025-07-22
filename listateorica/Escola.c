#include <stdio.h>
#include "Escola.h"


int main(){
    Lista *li;
    li = criaLista();


    insereOrd(li,"Mateus Brito", 2023, 9);
    insereOrd(li,"Ester Maria", 2024, 10);
    insereOrd(li,"Abner Carvalho", 2025, 9);
    insereOrd(li,"Gabriel Minato", 2026, 9);
    insereOrd(li,"Matheus Souza", 2027, 5);

    imprimeLista(li);

    printf("--------------------------\n");

    removeAluno(li,2026);
    imprimeLista(li);

    destroiLista(li);
    return 0;
}
