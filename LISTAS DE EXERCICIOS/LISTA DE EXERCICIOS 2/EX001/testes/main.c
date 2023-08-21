/*
EX001

Crie um programa que usa duas pilhas A e B para ordenar uma sequ?ncia de n n?meros dados
pelo usu?rio. A ideia ? organizar a pilha A de modo que nenhum item seja empilhado sobre outro
menor (use a pilha B apenas para manobra) e, depois, descarregar e exibir os itens da pilha A.
*/

#include <stdio.h>
#include "pilha.h"

void bubbleSort(int veta[], int n);

int main(void)
{
	int tamanhoPilha;
	int n;
	int i;
	printf("Entre com a quantidade total de numeros: \n");
	scanf("%d", &tamanhoPilha);
	Pilha A = pilha(tamanhoPilha * sizeof(int));
	// Pilha B = pilha(tamanhoPilha*sizeof(int));
	int veta[tamanhoPilha];

	for (i = 0; i < tamanhoPilha; i++)
	{
		printf("Insira o numero: \n");
		scanf("%d", &n);
		empilha(n, A);
		veta[i] = n;
	}

	// imprime "pilha"
	for (i = 0; i < tamanhoPilha; i++)
	{
		printf("%d\n", veta[i]);
	}

	bubbleSort(veta, tamanhoPilha);

	// imprime "pilha" ordenada
	for (i = 0; i < tamanhoPilha; i++)
	{
		printf("%d\n", veta[i]);
	}
	// menor=veta[0];
	// int ciclo=0;
	// int menor2;
	// //procura menor valor
	// while(vaziap(A)==0){

	// 	for(i=0; i<tamanhoPilha; i++){
	// 		if(veta[i]<menor){
	// 			menor=veta[i];
	// 		}
	// 		if(ciclo>0 && veta[i]==menor){
	// 			//refazer o for com uma condi??o: o novo menor deve ser maior que o menor atual
	// 			// menor2 > menor ? menor=menor2 : procura mais
	// 		}
	// 	}
	// 	printf("O menor valor da pilha e o: %d",menor);

	// 	empilha(menor,B);
	// 	ciclo++;
	// }

	void bubbleSort(int veta[], int n);
	{
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

	//    while(vaziap(A)==0){
	//	    x=desempilha(A);
	//	    if(x<topo(A)){
	//	    	menor=x;
	//		}
	//		printf("%d", menor);
	//	}

	//    for(int i=0; i)
	//
	//    do{
	//		int x;
	//	    x= desempilha(A);
	//	    printf("%d\n\n",x);
	//    	if(vaziap(B)==1){
	//    		empilha(x,B);
	//		}
	//		else{
	//			if(x < topo(B)){
	//	    		topo(B)=empilha(x,B);
	//			}
	//		}
	//	}while(cheiap(B)==0);
	//
	//	do{
	//		int y;
	//		y= desempilha(B);
	//		printf("%d\n",y);
	//	}while(vaziap(B)==1);

	return 0;
}
