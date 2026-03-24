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

main()
{
	int vet[] = {44, 38, 12, 2, 17, 25, 19, 10, 30, -4};
	int tam = sizeof(vet)/sizeof(int);
	int i = 0;
	int aux = 0;
	int comp, trocas;
	comp = trocas = 0;
	
	puts("Vetor ORIGINAL: ");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);
	
	puts("\n\nConteudo passo a passo da ordenacao: ");
	//Método de ordenação
	do
	{
	i = 0;
	while(i < tam-1)
	{
		comp++;
		if(vet[i] > vet[i+1])
		{
			aux = vet[i];
			vet[i] = vet[i+1];
			vet[i+1] = aux;
			trocas++;
		}
		i++;
	}
	
	//Exibição do vetor após cada passagem pelo While
	puts("");
	for(i = 0; i < 10; i++)
		printf("%d|", vet[i]);
	
	tam --;
	}while(tam > 0);
	printf("\n\nQtd de Comparacoes: %d", comp);
	printf("\n\nQtd de Trocas: %d", trocas);
}

//Função para o método de ordenação
//BubbleSort
void bubbleSort(int, V*, int tam)
{
	
}
