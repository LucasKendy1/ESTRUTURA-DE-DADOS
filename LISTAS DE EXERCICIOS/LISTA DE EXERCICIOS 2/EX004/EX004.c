/*
Usando pilha, crie uma função para verificar se uma expressão composta apenas por chaves,
colchetes e parênteses, representada por uma cadeia de caracteres, está ou não balanceada. Por
exemplo, as expressões "[{()()}{}]" e "{[([{}])]}" estão balanceadas, mas as
expressões "{[(}])" e "{[)()(]}" não estão.

P = [ {[(}]) ]
c = [ {[(}]) ]
por espelhamento n deu certo, passou nos testes {[([{}])]}, {[(}]) e {[)()(]}, porem com o [{()()}{}] não funcionou. 
acho que por varredura pode dar certo, mas não sei como fazer isso.
*/
#include <stdio.h>
#include "pilha.h"
#include <string.h>
/* CODIGO POR ESPELHAMENTO
int main() {
    Pilha P = pilha(256);
    char c[256];
    char aux;
    printf("Entre com a expressão: ");
    scanf("%s", c);

    //Inserindo todos os elementos de c em P
    for(int i =0; i < strlen(c); i++){
        empilha(c[i], P);
    }

    //Verificando se a expressão está balanceada
    for(int i = 0; i < strlen(c); i++){     //c[i] = {
        aux = desempilha(P);                //aux = }
        // printf("%c\n", aux);
        if(aux == '{' || aux =='[' || aux == '('){
            if(aux == '{'){
                if(c[i]!='}'){
                    printf("Expressao nao esta balanceada\n");
                    return 0;
                }
            }
            else if(aux == '['){
                if(c[i]!=']'){
                    printf("Expressao nao esta balanceada\n");
                    return 0;
                }
            }
            else if(aux == '('){
                if(c[i]!=')'){
                    printf("Expressao nao esta balanceada\n");
                    return 0;
                }
            }
        }
    }
    if(vaziap(P) && aux == c[0]){
        printf("Expressao esta balanceada\n");
    }
    return 0;
}
*/

//CODIGO POR CONTAGEM
int main(){
    Pilha P = pilha(256);
    Pilha P2 = pilha(256);
    char c[256];
    printf("Entre com a expressao: ");
    scanf("%s", &c);                    //c = [ {[(}]) ]
    int tam= strlen(c);

    if(tam%2!=0){                       //se o tamanho da string for impar, a expressão não está balanceada
        printf("Expressao nao esta balanceada\n");
        return 0;
    }
    else{
         int countOC=0, countOP=0, countOCh=0, countCC=0, countCP=0, countCCh=0;
        for(int i=0; i<tam; i++){           
            empilha(c[i], P);               //P = [ [{}] ]
        }
        char target = desempilha(P);        //target = ]
        // printf("%c\n", target);             //target = ]
        int ok = 0;                                 
        
        while(!vaziap(P)){                  //P = [  ]
                                            //target = [
            for(int i=0; i < tam; i++){
                if(target==']'){    
                    if(c[i]=='['){
                        countOC++;          //1
                        countCC++;          //1
                        empilha(target, P2);//P2 = [ ] ]
                        i=tam+1;
                    }
                }
                if(target==')'){
                    if(c[i]=='('){
                        countOP++;
                        countCP++;
                        empilha(target, P2);
                        i=tam+1;
                    }
                    
                }
                if(target=='}'){
                    if(c[i]=='{'){
                        countOCh++;         //1
                        countCCh++;         //1
                        empilha(target, P2);//P2 = [  ]
                        i=tam+1;
                    }
                }
                if(target=='[' && topo(P2)==']' || target=='{' && topo(P2)=='}' || target=='(' && topo(P2)==')'){   
                    desempilha(P2);
                    ok++;
                    i=tam+1;
                }
            }
            target = desempilha(P);
        }
        ok++;
        int metade = tam/2;
        
        if(countOC == countCC && countOP == countCP && countOCh == countCCh && ok == metade){
            printf("Expressao esta balanceada\n");
        }
        else{
            printf("Expressao nao esta balanceada\n");
        }
    }

    return 0;
}