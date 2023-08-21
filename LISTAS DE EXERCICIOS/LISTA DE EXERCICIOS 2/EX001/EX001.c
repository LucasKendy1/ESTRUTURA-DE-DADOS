/*
EX001
	Crie um programa que usa duas pilhas A e B para ordenar uma sequ�ncia de n n�meros dados
	pelo usu�rio. A ideia � organizar a pilha A de modo que nenhum item seja empilhado sobre outro
	menor (use a pilha B apenas para manobra) e, depois, descarregar e exibir os itens da pilha A.
*/

#include <stdio.h>
#include "pilha.h"

void bubbleSort(int veta[], int n){
	int k, j, aux;
	for (k = 1; k < n; k++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (veta[j] > veta[j + 1])
			{
				aux = veta[j];
				veta[j] = veta[j + 1];
				veta[j + 1] = aux;
			}
		}
	}
}

int main(void)
{
	int tamanhoPilha;
	int n;
	int i;
	printf("Entre com a quantidade total de numeros: \n");
	scanf("%d", &tamanhoPilha);
	Pilha A = pilha(tamanhoPilha * sizeof(int));
	Pilha B = pilha(tamanhoPilha*sizeof(int));
	int veta[tamanhoPilha];
	//limpa vetor
	for(i = 0; i < tamanhoPilha; i++){
		veta[i]=0;
	}

	for (i = 0; i < tamanhoPilha; i++)
	{
		printf("Insira o numero: \n");
		scanf("%d", &n);
		empilha(n, A);
		veta[i] = n;
	}

	// imprime "pilha"
	printf("imprime pilha : \n");
	for (i = 0; i < tamanhoPilha; i++)
	{
		printf("%d\n", veta[i]);
		desempilha(A);
	}

	bubbleSort(veta, tamanhoPilha);

	// imprime "pilha" ordenada
	printf("\n\n\nimprime pilha ordenada: \n");
	for (i = tamanhoPilha-1; i >= 0; i--)
	{
		printf("%d\n", veta[i]);
		empilha(veta[i],B);
		empilha(topo(B),A);
	}

	printf("\n\n\nImprimindo pilha A: \n");
	for (i = 0; i < tamanhoPilha; i++)
	{
		int x;
		x=topo(A);
		printf("%d\n", x);
		desempilha(A);
	}

	return 0;
}
