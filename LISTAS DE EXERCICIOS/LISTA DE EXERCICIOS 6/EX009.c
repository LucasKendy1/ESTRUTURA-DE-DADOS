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
        printf("%d nao e par",n);
    }
    else{
        printf("%d e par",n);
    }

    return 0;
}