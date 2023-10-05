#include <stdio.h>
#include "pilha.h" // pilha de char *

int main(void) {
    Pilha P = pilha(12);
    char s[11];

    for(int i=1; i<=3; i++) {
        printf("? ");
        gets(s);
        for(int j = 0; s[j]; j++){
            empilha(s[j],P);
        }
    }
    
    // while( vaziap(P) == 0 ){
    //     printf("%c", desempilha(P));
    // } 
    while( !vaziap(P) ) puts(desempilha(P));

    return 0;
}

//Não terá saida nenhuma, pois a Pilha não está recebendo valor nenhum. O empilha(s,P) não está funcionando corretamente, visto que a função deve ser executada para cada caractere da cadeia "s[x]" e não para uma string inteira "s". Outro erro que está acontecendo é a forma de impressão usando o while.
//A função puts() não está reconhecendo o caractere desempilhado pela função desempilha(P) 
//O tamanho da pilha não suporta todos os caracteres inseridos