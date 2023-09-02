/*
  Crie a função valpre(e), que devolve o valor da expressão aritmética prefixa e. Em seguida, faça um programa para testar a função.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int charInt(int x)
{
   switch (x)
   {
   case 48:
      return x = 0;
      break;
   case 49:
      return x = 1;
      break;
   case 50:
      return x = 2;
      break;
   case 51:
      return x = 3;
      break;
   case 52:
      return x = 4;
      break;
   case 53:
      return x = 5;
      break;
   case 54:
      return x = 6;
      break;
   case 55:
      return x = 7;
      break;
   case 56:
      return x = 8;
      break;
   case 57:
      return x = 9;
      break;
   }
}

int valpre(char *e)
{
   printf("\n%s\n", e);
   // char s[256];
   Pilha R = pilha(256);
   int j = strlen(e);
   for (int i = j - 1; i >= 0; i--)
   { // 8

      if (isdigit(e[i]))
      {
         empilha(e[i], R);                      //      R[4,8]
         printf("Estou empilhando %c\n", e[i]); // R["4","8"]
      }
      else if (strchr("+*-/", e[i]))
      {
         printf("O operador eh: %c\n", e[i]);

         int a = desempilha(R);
         int b = desempilha(R);
         int x = charInt(a);
         int y = charInt(b);
         printf("X : %d\n", x);
         printf("Y : %d\n", y);
        
         int c=0;
         switch (e[i])
         {
         case '+':
            c = y+x;
            empilha(c+'0', R);
            break;
         case '-':
            c = y-x;
            empilha(c+'0', R);
            break;
         case '*':
            c = y*x;
            empilha(c+'0', R);
            break;
         case '/':
            c = x/y; 
            empilha(c+'0', R);
            break;
         }
         printf("O topo de R: %c\n", topo(R));
      }
   }
   int z = desempilha(R);
   destroip(&R);
   return z;
}

char *prefixa(char *e)
{
   static char s[256];
   int j = strlen(e);
   int i = 0;
   // printf("%d", j);
   Pilha P = pilha(256);
   //((2*3)+(8/4))
   for (j; j > 0; j--)
   {
      // printf("%c",e[j]);      //   ))

      if (isdigit(e[j]))
      {
         s[i++] = e[j]; //   s[4,8,/,3,2,*,+]
      }
      else if (strchr("+*-/", e[j]))
      {
         empilha(e[j], P); // P []
      }
      else if (e[j] == '(')
      {
         s[i++] = desempilha(P);
      }
   }
   s[i++] = desempilha(P);
   // s[j] = '\0';
   // destroip(&P);
   return s;
}

int main(void)
{
   char e[513];
   printf("Infixa? ");
   gets(e);

   printf("Prefixa: %s\n", strrev(prefixa(e)));
   printf("Resultado: %d\n", charInt(valpre(strrev(prefixa(e)))));
   return 0;
}
