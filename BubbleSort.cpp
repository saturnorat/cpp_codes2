/*
	Name: BubbleSort.cpp
	Author: Logan Maia
	Date: 24/03/26 11:02
	Description: Programa para demonstrar o funcionamento do 
	método de ordenação Bubble sort
*/
//Sessão de Prototipação
void bubbleSort(int *V, int);


#include <stdio.h>
//Variaveis globais
	int comp, trocas;

main()
{
	int vet[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
	int tam = sizeof(vet)/sizeof(int);
	int i = 0;
	comp = trocas = 0;
	
	puts("Vetor ORIGINAL: ");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);
	
	bubbleSort(vet, tam);
	
	puts("\nVetor ordenado pelo BubbleSort: ");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);

	printf("\n\nQtd de Comparacoes: %d", comp);
	printf("\n\nQtd de Trocas: %d", trocas);
}

//Função para o método de ordenação
//BubbleSort
void bubbleSort(int *V, int tam)
{
	int i = 0;
	int aux = 0;
	
	do
	{
	i = 0;
	while(i < tam-1)
	{
		comp++;
		if(V[i] > V[i+1])
		{
			aux = V[i];
			V[i] = V[i+1];
			V[i+1] = aux;
			trocas++;
		}
		i++;
	}
	
	tam --;
	}while(tam > 0);
}
