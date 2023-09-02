/*
   Considere n processos a serem executados. 
   Uma fila F contendo a ordem de chamada dos processos 
   E uma pilha P contendo a ordem de execução ideal dos processos (se um processo i está sobre outro processo j em P, então i deve ser executado antes de j). 
   

   Supondo que cada mudança de ordem dos processos na fila, bem como a execução de um processo, consome 1 segundo, crie a função ttm(F,P) que devolve o tempo total mínimo necessário para executar todos os processos na ordem ideal. 
      Por exemplo, se                  F = [2,3,1] 
      e a ordem de execução ideal em   P = [1,3,2], 
      então o ttm=6 segundos. 
      Note que a função ttm() deve funcionar para qualquer quantidade de processos e, no final da execução da função, F e P devem estar vazias.

      2==1? n 
      t=1   F=[3,1,2]
      1==3? n
      t=2   F=[1,2,3]
      1==1? s
      t=3   F=[2,3]
      3==2? n
      t=4   F=[3,2]
      3==3? s
      t=5   F=[2]
      2==2? s
      t=6   F=[]
*/

#include <stdio.h> 
#include "pilha.h" 
#include "fila.h" 

int ttm(Fila F, Pilha P) { // tempo total mínimo 
   int t = 0; // tempo total
   while(!vaziap(P) && !vaziaf(F)){
      int x = topo(P);           //1
      int y = desenfileira(F);   //3
      printf("x=%d y=%d\n",x,y); //1 3

      if(x == y){                //1==3? n
         desempilha(P);
      }
      else{
         enfileira(y,F);         //F=[1,2,3]
      }
      t++;                       //t=1
      
   }
   return t;
} 

int main(void) { 
 Fila F = fila(3); 
 enfileira(2,F); 
 enfileira(3,F); 
 enfileira(1,F); 
 Pilha P = pilha(3); 
 empilha(2,P); 
 empilha(3,P); 
 empilha(1,P); 
 printf("\nTempo total mínimo: %d\n\n", ttm(F,P) ); 
 destroif(&F); 
 destroip(&P); 
 return 0; 
}

