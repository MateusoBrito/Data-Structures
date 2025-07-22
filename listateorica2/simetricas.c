#include <stdio.h>
#include "simetricas.h"

int main(){
    Deque *dq;
    dq = criaDeque();

    insereFim(dq,'X');
    insereFim(dq,'Y');
    insereFim(dq,'Z');
    insereFim(dq,'Y');
    insereFim(dq,'X');

    simetricas(dq);

    destroiDeque(dq);
    return 0;
}