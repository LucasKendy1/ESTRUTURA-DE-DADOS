// Crie a função recursiva resto(m,n), que devolve o resto da divisão inteira do número natural m pelo número natural n0, usando apenas subtração.

#include <stdio.h>

int resto(int m, int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (m - n < n)
    {
        return m - n;
    }
    else
    {
        return resto(m - n, n);
    }
}

int main()
{
    int m, n;
    printf("Digite dois numeros: ");
    scanf("%d %d", &m, &n);
    printf("%d %% %d = %d", m, n, resto(m, n));
    return 0;
}