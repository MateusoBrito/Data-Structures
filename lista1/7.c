#include <stdio.h>

int soma_internos(int n1,int n2, int result){
    if(n2 >= n1){
        result += n2;
        return soma_internos(n1,n2-1,result);
    }
    return result;
}

int main(){
    int result = soma_internos(5,10,0);
    printf("%d\n",result);
    return 0;
}