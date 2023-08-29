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
    
    printf("Verificador de balanceamento de expressoes\n ");
    printf("Digite o tamanho da expressao: ");
    scanf("%d", &tamanhoExpressao);
    // Pilha P = pilha(tamanhoExpressao);
    char x[tamanhoExpressao];

    for(int i=0; i < tamanhoExpressao; i++){
        printf("Digite uma chave, parenteses ou colchetes: ");
        scanf("%c", &x[i]);
        printf("%c", x[i]); 
    }

    // for (int i=0; i < tamanhoExpressao; i++){
    // }
    return 0;
}