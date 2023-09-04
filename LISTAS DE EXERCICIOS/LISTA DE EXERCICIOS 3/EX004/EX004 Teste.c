
/*
   Com base nos algoritmos descritos, crie um programa para ler uma expressão booleana comple-tamente parentesiada e exibir sua forma posfixa correspondente, bem como seu valor numérico.

   Considere que as expressões são compostas por:
   Operandos: letras maiúsculas F e V, com valores numéricos 0 e 1, respectivamente.

   Operadores: ! (não), & (e) e | (ou), da maior para a menor prioridade.

   Delimitadores: parênteses de abertura e fechamento.
                                                                     
   Por exemplo, para a expressão booleana infixa parentesiada "((!F)|(F&V))", o programa deve apresentar como saída a forma posfixa "F!FV&|" e o valor numérico 1.

   (0 -> 1) ou (0 & 1 -> 0) -> 1
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int Opou(char x, char y){
   if(x=='V')x=1; else x=0;
   if(y=='V')y=1; else y=0;
   if(x==1 || y==1 ){
      return 1;
   }
   else{
      return 0;
   }
   printf("%d",x);
   printf("%d\n",y);
}

int Ope(char x, char y){
   if(x=='V')x=1; else x=0;
   if(y=='V')y=1; else y=0;
   if(x==1 && y ==1){
      return 1;
   }
   else{
      return 0;
   }
   printf("%d",x);
   printf("%d\n",y);
}

int OpInv(char x){
   if(x=='V')x=0;
   if(x=='F')x=1;
   printf("%d",x);
   return x;
}


int valor(char *e) {
   Pilha P = pilha(256);
   for(int i=0; e[i]; i++){
      if( e[i]=='V' || e[i]=='F' ) {
        //  printf("%c",e[i]);
         empilha(e[i],P);
      }
      
      else {
         if(e[i]=='!'){
            int x = desempilha(P);
            empilha(OpInv(x),P);
         }
         int y = desempilha(P);
         int x = desempilha(P);
         
         switch( e[i] ) {
            case '|': empilha(Opou(x,y),P); break;
            case '&': empilha(Ope(x,y),P); break;
         }
      }	
   }
      
   int z = desempilha(P);
   destroip(&P);
   return z;
}

int prio(char o) {
   switch( o ) {
      case '|': return 0;
      case '&': return 1;
      case '!': return 2;
   }
   return -1; // operador inválido!
}

char *posfixa(char *e) {
   static char s[256];
   int j = 0;
   Pilha P = pilha(256);

   for(int i=0; e[i]; i++)
      if( e[i]=='(' ) empilha('(',P);
      else if( e[i]=='V' || e[i]=='F' ) s[j++] = e[i];
      else if( strchr("!&|",e[i]) ) {
         while( !vaziap(P) && prio(topo(P))>=prio(e[i]) ) 
            s[j++] = desempilha(P);
         empilha(e[i],P);
      }
      else if( e[i] == ')' ) {
         while( topo(P)!='(' ) 
           s[j++] = desempilha(P);
         desempilha(P);
      }                                       
      while( !vaziap(P) )
         s[j++] = desempilha(P);
      s[j] = '\0';
      destroip(&P);
    return s;
} 

int main(void) {
   char e[513];
   printf("Infixa? ");
   gets(e);
   printf("Posfixa: %s\n", posfixa(e));
   printf("Resultado: %d", valor(posfixa(e)));
   return 0;
} 