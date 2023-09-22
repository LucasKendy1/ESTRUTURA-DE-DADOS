#include <stdio.h>
//Crie a função recursiva par(n), que determina se o natural n é par, 
//usando apenas subtração.

int par(int n){
    if(n==0){
        return 1;
    } 
    else if(n==1){
        return 0;
    }
    else{
        par(n-2);
    }
}

int main(){
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    if(par(n)!=1){
        printf("%d não é par",n);
    }
    else{
        printf("%d é par",n);
    }

    return 0;
}