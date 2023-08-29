/*
  Crie a função valpre(e), que devolve o valor da expressão aritmética prefixa e. Em seguida, faça um programa para testar a função.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int valpre(char *e){
   printf("\n%s\n", e);
   // char s[256];
   Pilha R = pilha(256);
   int j = strlen(e);
   for(int i=j-1; i>=0; i--){     //8

      if(isdigit(e[i])){
         empilha(e[i],R);//      R[4,8]
         printf("Estou empilhando %c\n", e[i]);
      }
      else if(strchr("+*-/",e[i]) ){
         printf("O operador eh: %c\n",e[i]);
         int a = desempilha(R);     //a="2"

         int b = desempilha(R);     //b="3"

         printf("A : %d\n", a);
         printf("B : %d\n", b);

         switch(e[i]){
            case '+': empilha(b+a,R); break;
            case '-': empilha(b-a,R); break;
            case '*': empilha(b*a,R); break;
            case '/': empilha(a/b,R); break;    //R= 2,5
         }
         printf("O topo de R: %c\n", topo(R));
      }
   }
   int z = desempilha(R);
   destroip(&R);
   return z;
}

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
   printf("Resultado: %d\n", valpre(strrev(prefixa(e))));
   return 0;
} 
