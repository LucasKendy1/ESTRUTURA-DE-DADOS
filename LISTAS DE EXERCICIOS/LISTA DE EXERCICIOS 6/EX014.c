#include <stdio.h>
#include <string.h>

//Crie a função recursiva sd(n), que devolve a soma dos dígitos do número natural n. Por exem-plo, a chamada sd(7859) deve devolver 29 (pois 7+8+5+9 = 29).
// n[0] n[1] n[2] n[3]
// 7    8    5    9

int charToInt(int n){
    switch (n)
    {
    case 48:
        return 0;
        break;
    case 49:
        return 1;
        break;
    case 50:
        return 2;
        break;
    case 51:
        return 3;
        break;
    case 52:
        return 4;
        break;
    case 53:
        return 5;
        break;
    case 54:
        return 6;
        break;
    case 55:
        return 7;
        break;
    case 56:
        return 8;
        break;
    case 57:
        return 9;
        break;
    default:
        break;
    }
}

int sd(int *n, int l)
{
    if(l==0){
        return 0;
    }
    else{
        return n[l-1] + sd(n, l-1);     //somar um a menos no começo pois a string começa em n+1
    }

}

int main()
{
    int n[100];
    char s[100];
    printf("Digite um numero: ");
    scanf("%s", s);
    for(int i=0; i<strlen(s); i++){ //converter char em int e converter codigo int em int
        n[i] = (int) s[i];
        n[i] = charToInt(n[i]);
        //printf("%d\n", n[i]);
    }
    int l = strlen(s);              //passar tamanho total da string
    printf("soma dos digitos = %d\n", sd(n,l)); 
    return 0;

}