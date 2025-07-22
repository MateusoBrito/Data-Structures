#include <stdio.h>
#include <math.h>

int raizes(float A, float B, float C, float* X1, float * X2){
    float bask =  pow(B,2)-4*A*C;
    if(sqrt(bask)>0){
        *X1= (-B+sqrt(bask))/2*A;
        *X1= (-B-sqrt(bask))/2*A;
    } else {
        return 0;
    }
}

void main(){



    return 0;
}