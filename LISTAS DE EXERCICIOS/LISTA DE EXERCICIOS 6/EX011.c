//Crie a função recursiva quoc(m,n), que devolve o quociente da divisão inteira do número natural m pelo número natural n!=0, usando apenas soma e subtração.

#include <stdio.h>

int quoc(int m, int n){
    if(n==0){
        return 0;
    }
    if(n<=m){
        return  1 + quoc(m-n,n);
    }
    else{
        return 0;
    }
}

int main(){
    int m,n;
    printf("Digite dois numeros: ");
    scanf("%d %d", &m, &n);
    printf("%d / %d = %d", m, n, quoc(m,n));
    return 0;
}