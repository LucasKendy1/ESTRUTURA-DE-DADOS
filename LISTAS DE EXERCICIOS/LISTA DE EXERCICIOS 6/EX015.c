//Crie a funÃ§Ã£o recursiva qd(n), que devolve a quantidade de dÃ­gitos binÃ¡rios para representar o natural n. Por exemplo, a chamada qd(13) deve devolver 4 (pois 13 em binÃ¡rio Ã© 1101).
/*
Passos de conversÃ£o:

Divida o nÃºmero por 2.
Obtenha o quociente inteiro para a prÃ³xima iteraÃ§Ã£o.
Obtenha o resto do dÃ­gito binÃ¡rio.
Repita as etapas atÃ© que o quociente seja igual a 0.
*/

#include <stdio.h>

int qd(int n){
    if(n==0){
        return 0;
    }
    else{
        return 1+qd(n/2);
    }
    
}

int main(){
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    printf("O numero %d em binario tem %d digitos", n, qd(n));
    return 0;
}