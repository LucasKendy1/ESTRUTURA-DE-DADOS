//Crie a funÃ§Ã£o recursiva h(n), que devolve o nÃºmero mÃ­nimo de movimentos para resolver o problema das Torres de HanÃ³i com n discos. Por exemplo, h(3) deve devolver 7

#include <stdio.h>
#include <math.h>

int h(int n){
    if(n==1){
        return 1;
    }
    else{
        return 2*(h(n-1))+1;
    }
}

int main(){
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    printf("O numero minimo para resolver uma torre de hanoi de %d discos eh %d", n, h(n));
    return 0;
}