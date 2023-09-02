/*
Qual a saída exibida pelo programa a seguir?
*/

#include <stdio.h>
#include "fila.h"
int main(void) {
   Fila F = fila(5);
   for(int i=0; i<=3; i++) 
      enfileira('A'+i,F);
   while( !vaziaf(F) ) 
      printf("%c\n",desenfileira(F));
   destroif(&F);   
   return 0;
}

// A B C D