/*
EX003
    Usando uma pilha, crie um programa para inverter a ordem das letras nas palavras de uma frase,
    sem inverter a ordem das palavras na frase. Por exemplo, se for     digitada a frase "apenas um
    teste", o programa deverá produzir a seguinte saída: sanepa mu etset.
*/

#include <stdio.h>
#include "pilha.h"
#include <string.h>

void reverse(char *palavra){
    int x = strlen(palavra);
    Pilha X = pilha(x * sizeof(int));
    for(int i = 0; i < x; i++){
        empilha(palavra[i],X);
    }

    for(int i = 0; i < x; i++){
        palavra[i]=desempilha(X);
        printf("%c", palavra[i]);
    }
    printf(" ");
}


int main()
{
    char txt[100];
    char *palavra;
    printf("Digite uma frase: \n");
    gets(txt);

    int x = strlen(txt);
    char frase[x];
    strcpy(frase,txt);
    
    palavra = strtok(frase, " ");

    while(palavra != NULL){
        reverse(palavra);
        palavra = strtok(NULL, " ");
    }
    return 0;
}