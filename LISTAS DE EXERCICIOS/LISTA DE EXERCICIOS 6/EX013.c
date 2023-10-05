//O quadrado de um natural n é a soma dos n primeiros ímpares, i.e., n2  1  3  5    (2n1). Crie a função recursiva q(n), que devolve o quadrado de n, como base nesta informação.

#include <stdio.h>

int q(n){
    if(n==1){
        return 1;
    }
    else{
        return (2*n-1) + q(n-1);
    }
}

int main(){
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    printf("%d^2 = %d", n, q(n));
    return 0;
}