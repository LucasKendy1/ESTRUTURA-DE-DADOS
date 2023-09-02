/*
  2. Uma cadeia c composta apenas por letras A e B é uma concha SE cada letra em c pode ser conectada a exatamente uma única outra letra igual a ela em c, por meio de um arco, de modo que nenhum arco intercepte outro arco. Por exemplo, na figura a seguir, a cadeia em (a) é uma concha, mas aquela em (b) não o é

  Com base nesta definição:
   Crie a função concha(c), que recebe uma cadeia c e devolve 1 se c for uma concha (caso contrário, devolve 0).
   Crie a função filtra(F), que recebe uma fila F contendo cadeias compostas apenas por letras A e B e exibe apenas aquelas cadeias em F que são conchas, bem como o total de cadeias em F que são conchas.
*/

//AAAAAAAA AA ABA

/*i=10
F=[];
P=[B];
*/

#include <stdio.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"

int concha(char *c)
{ // verifica se c é uma concha
  Pilha P = pilha(strlen(c));
  // printf("c= %s\n", c);
  for(int i=0; i<strlen(c); i++){
    if(c[i]!=c[i+1]){
        if(vaziap(P)){
          empilha(c[i],P);
        }
        else if(topo(P)==c[i] || topo(P)==c[i+1]){
          desempilha(P);
        }
        else{
          empilha(c[i],P);
        }
    }
    else{
      i++;
    }
  }
  if(vaziap(P)){
    return 1;
  }
  else{
    return 0;
  }
}

int filtra(Fila F)
{ // exibe apenas as cadeias em F que são conchas
  int total = 0;
  for (int i = 0; i < 20; i++)
  {
    char *c = desenfileira(F);
    if (concha(c))
    {
      printf("%s e uma concha\n", c);
      total++;
    }
  }
  return total;
}

int main()
{
  Fila F = fila(20);
  enfileira("AAAAAAAABAAABA", F);//nao concha
  enfileira("BBBBBBBBBBBBBB", F);//sim concha
  enfileira("ABBABBABBABB", F);  //sim concha
  enfileira("AAABAAABBABAAA", F);//nao concha
  enfileira("ABAABAAAAAAAAA", F);//sim concha
  enfileira("AABAAAAAABAAAA", F);//sim concha
  enfileira("AAAABB", F);        //sim concha
  enfileira("AABBBBAABAAB", F);  //sim concha
  enfileira("ABAAAAAAAAAB", F);  //nao concha
  enfileira("ABABBBABAB", F);    //nao concha
  enfileira("BBBBBBBBBBBBBB", F);//sim concha
  enfileira("AABAABAAAA", F);    //sim concha
  enfileira("AABAAABBBBBABB", F);//nao concha
  enfileira("BBBAAAAABA", F);    //nao concha
  enfileira("BBBBBBBBBBBBBB", F);//sim concha
  enfileira("AAAAAAAAAAAABB", F);//sim concha
  enfileira("BAAAAABAAAAAAA", F);//nao concha
  enfileira("BBBBABBBBBBA", F);  //sim concha
  enfileira("BBABABAAAAAABB", F);//nao concha
  enfileira("ABAABAABAB", F);    //nao concha
  printf("Total de sim conchas: %d", filtra(F)); // deve exibir 12 conchas
  destroif(&F);
  return 0;
}
