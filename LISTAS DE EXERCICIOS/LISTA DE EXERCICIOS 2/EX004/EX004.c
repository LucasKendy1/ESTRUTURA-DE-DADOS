/*
Usando pilha, crie uma função para verificar se uma expressão composta apenas por chaves,
colchetes e parênteses, representada por uma cadeia de caracteres, está ou não balanceada. Por
exemplo, as expressões "[{()()}{}]" e "{[([{}])]}" estão balanceadas, mas as
expressões "{[(}])" e "{[)()(]}" não estão.
*/

#include <stdio.h>
#include "pilha.h"
#include <string.h>

int main(){
    int tamanhoExpressao;
    char x;
    printf("Verificador de balanceamento de expressoes\n ");
    printf("Digite o tamanho da expressao: ");
    scanf("%d", &tamanhoExpressao);
    Pilha P = pilha(tamanhoExpressao);

    for(int i=0; i < tamanhoExpressao; i++){
        printf("Digite uma chave, parenteses ou colchetes: ");
        gets(x);
        empilha(x,P);
    }
    
    return 0;
}