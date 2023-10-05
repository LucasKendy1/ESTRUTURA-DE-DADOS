//Crie a funÃ§Ã£o recursiva pal(s,p,u), que informa se a string s, cujo primeiro caractere estÃ¡ na posiÃ§Ã£o p e cujo Ãºltimo caractere estÃ¡ na posiÃ§Ã£o u, Ã© palÃ­ndroma (ignorando brancos).

#include <stdio.h>

//subi no onibus  0 13
// ubi no onibu   1 12
//  bi no onib    2 11
//   i no oni     3 10
//     no on      4 9
//     no on      5 9
//      o o       6 8
//                7 7




int pal(char *s, int p, int u){
    if(s[p]==s[u]){
        if(p==u && s[p]==s[u]){
            return 1;
        }
        return pal(s,p+1,u-1);
    }
    else if(s[p]==' '){
        return pal(s,p+1,u);
    }
    else if(s[u]==' '){
        return pal(s,p,u-1);
    }
    else{
        return 0;
    }
}
//subinoonibus
int main(){
    char s[100];
    int p,u;
    printf("Digite uma string: ");
    fgets(s,100,stdin);
    printf("Digite a posicao inicial e final: ");
    scanf("%d %d", &p, &u);
    if(pal(s,p,u)==1){
        printf("A cadeia %s eh palindroma", s);
    }
    else{
        printf("A cadeia %s nao eh palindroma", s);
    }

    return 0;
}
