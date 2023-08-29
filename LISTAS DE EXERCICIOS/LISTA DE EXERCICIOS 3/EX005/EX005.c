/*
   Crie a função prefixa(e), que devolve a forma prefixa da expressão aritmética completa-mente parentesiada e. Em seguida, faça um programa para testar a função.

   Dicas: 
   Percorra a expressão infixa da direita para a esquerda.
   Use strlen() para determinar o tamanho da expressão infixa.
   Use _strrev() para inverter uma cadeia de caracteres
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

char *prefixa(char *e) {
   static char s[256];
   int j = strlen(e);
   int i=0;
   // printf("%d", j);
   Pilha P = pilha(256);
                                 //((2*3)+(8/4))
   for(j; j>0; j--){
      // printf("%c",e[j]);      //   ))

      if( isdigit(e[j]) ) {
         s[i++] = e[j];       //   s[4,8,/,3,2,*,+]
         
      }
      else if( strchr("+*-/",e[j]) ){
         empilha(e[j],P);         //P []
      }
      else if( e[j]=='(' ) {
         s[i++] = desempilha(P);
      }
   }
   s[i++] = desempilha(P);
   // s[j] = '\0';
   // destroip(&P);
   return s;
} 

int main(void) {
   char e[513];
   printf("Infixa? ");
   gets(e);
 
   printf("Prefixa: %s\n", strrev(prefixa(e)));
   // printf("Resultado: %d\n", valor2(prefixa(e)));
   return 0;
} 
