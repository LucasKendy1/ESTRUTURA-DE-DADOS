/*
    Usando uma pilha, crie um programa para inverter a ordem das letras nas palavras de uma frase,
    sem inverter a ordem das palavras na frase. Por exemplo, se for     digitada a frase "apenas um
    teste", o programa deverá produzir a seguinte saída: sanepa mu etset.
*/

#include <stdio.h>
#include "pilha.h"
#include <string.h>

char reverse(char *palavra, int x){
     int i;
    Pilha X = pilha(x * sizeof(int));
    for(i = 0; i < x; i++){
        empilha(palavra[i],X);
    }

    for (i = 0; i < x; i++){
        palavra[i]=desempilha(X);
    }
    return *palavra;
}


int main()
{
    char txt[100];

    printf("Digite uma frase: \n");
    gets(txt);

    int x = strlen(txt);
    char frase[x];
    strcpy(txt,frase);
    printf("%s", frase);
    
    // reverse(*frase,x);
    // printf("%s", frase);  
    
    return 0;
}
