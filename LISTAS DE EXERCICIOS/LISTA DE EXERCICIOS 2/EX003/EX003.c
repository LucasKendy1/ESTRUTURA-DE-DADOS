/*
    Usando uma pilha, crie um programa para inverter a ordem das letras nas palavras de uma frase,
    sem inverter a ordem das palavras na frase. Por exemplo, se for     digitada a frase "apenas um
    teste", o programa deverá produzir a seguinte saída: sanepa mu etset.
*/

#include <stdio.h>
#include "pilha.h"
#include <string.h>

int main()
{
    char *espaco;
    char txt[15];
    char vetposicoes[15];

    Pilha P = pilha(15);

    printf("Digite uma frase: \n");
    gets(txt);
    for (int i = 0; txt[i]; i++)
    {
        empilha(txt[i], P);
    }

    int k;
    int j;
    espaco = strchr(txt, ' ');
    for (j = 0; txt[j]; j++)
    {
        printf("%c", txt[j]);       //lucas kendy
        if (espaco != NULL)
        {
            int posicao = espaco-txt;
            // printf("Achei o espaco, ele esta na %d posição ",posicao);
            
            // printar uma unica palavra
            for (k=0; k<posicao; k++)
            {
                printf("%c\n", txt[k]);
            }
            
        }
        else printf("Espaco nao encontrado");
    }

    printf("\n\n\n");

    for (int i = 0; txt[i]; i++)
    {
        printf("%c", topo(P));
        desempilha(P);
    }

    // printf("%s", txt);
    return 0;
}