/*
O programa do Exemplo 2 não reconhece "Amor a Roma" como uma cadeia palíndroma. Use a função toupper(), declarada em ctype.h, para resolver esse problema (essa função converte uma letra minúscula em maiúscula).
*/
#include <stdio.h>
#include <ctype.h>
#include "pilha.h"
#include "fila.h"

int main(void) {
   char s[256];
   Fila F = fila(256);
   Pilha P = pilha(256);
   printf("\nFrase? ");
   gets(s);
   
   for(int i=0; s[i]; i++)
      if( isalpha(s[i]) ) { 
        s[i]=toupper(s[i]);
        enfileira(s[i],F); 
        empilha(s[i],P); 
      }
   while( !vaziaf(F) && desenfileira(F)==desempilha(P) );
   if( vaziaf(F) ) puts("A frase e palindroma");
   else puts("A frase nao e palindroma");
   destroif(&F);
   destroip(&P);
   return 0;
}
