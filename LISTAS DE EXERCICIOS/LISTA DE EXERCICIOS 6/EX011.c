//Crie a função recursiva quoc(m,n), que devolve o quociente da divisão inteira 
//do número natural m pelo número natural n0, usando apenas soma e subtração
#include <stdio.h>

int quoc(int m, int n){
    if(n<m){
        return m - quoc(m-n,n);
    }

}

int main(){
    int m,n;
    printf("Digite dois numeros: ");
    scanf("%d %d", &m, &n);
    printf("%d / %d = %d", m, n, quoc(m,n));
    return 0;
}