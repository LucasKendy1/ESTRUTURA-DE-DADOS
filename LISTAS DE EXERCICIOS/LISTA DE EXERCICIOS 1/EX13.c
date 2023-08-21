#include <stdio.h>

void troca(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main(){
    int x = 5, y=3;
    troca(&x, &y);
    printf("o valor de x= %d, e o valor de y= %d", x,y);
    return 0;
}