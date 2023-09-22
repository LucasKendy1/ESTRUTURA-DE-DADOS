#include <stdio.h>
//Crie a função recursiva prod(m,n), 
//que devolve o produto 
//de dois números naturais m e n, 
//usando apenas soma e subtração

int prod(int m, int n){
    if(n==1){
        return m; 
    }
    return m + prod(m, n-1);
}

int main(){
    int m,n;
    printf("Digite dois numeros: ");
    scanf("%d %d", &m, &n);
    printf("%d x %d = %d", m, n, prod(m,n));
    return 0;
}