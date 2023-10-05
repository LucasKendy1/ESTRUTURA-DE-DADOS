//Crie a funÃ§Ã£o recursiva inv(s,p,u), que inverte a string s, cujo primeiro caractere estÃ¡ na posiÃ§Ã£o p e cujo Ãºltimo caractere estÃ¡ na posiÃ§Ã£o u. A funÃ§Ã£o deve devolver s como resposta

//abacate 0 6
//ebacata 1 5
//etacaba 2 4
//etacaba 3 3


#include <stdio.h>
#include <string.h>

void inv(char *s, int p, int u){
    if(p!=u){
        int aux;
        aux=s[p];
        s[p]=s[u];
        s[u]=aux;
        inv(s,p+1,u-1);
    }
}



int main(){
    char s[100];
    int p,u;
    printf("Digite uma string: ");
    fgets(s,100,stdin);
    printf("Digite a posicao inicial e final: ");
    scanf("%d %d", &p, &u);
    inv(s,p,u);
    printf("A string invertida eh: \n");
    printf("%s", s);
    
    return 0;
}