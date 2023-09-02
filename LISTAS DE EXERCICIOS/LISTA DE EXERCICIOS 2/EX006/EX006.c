#include <stdio.h>
#include "pilha.h" 
#include <string.h>

int main(void)
{
    Pilha P = pilha(12);
    char s[11];

    for (int i = 1; i <= 3; i++)
    {
        printf("? ");
        gets(s);
        char *palavra = strdup(s);
        // printf("%x", palavra);
        for (int j = 0; s[j]; j++)
        {
            empilha(palavra[j], P);
        }
        free(palavra);
    }
    while (vaziap(P) == 0)
        printf("%c", desempilha(P));
    return 0;
}
