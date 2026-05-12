/*
	Name: quickSort.cpp
	Author: Logan Maia
	Date: 12/05/26 11:40
	Description: Implementação do método de ordenação Quick Sort
*/
#include <stdio.h>

//Sessão de prototipação
void swap(int *, int *); //troca elementos
int partition(int *, int *, int); 
void quickSort(int *, int, int);

main()
{
	int vet[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
	int i;
	int tam = sizeof(vet)/sizeof(int);
	
	puts("Vetor original: ");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);
		
	quickSort(vet, 0, tam - 1);
		
	puts("\n\nVetor ordenado pelo Quick Sort: ");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);	
		
}

//Função que realiza a particão do conjunto de dados

int partition(int *V, int inicio, int fim)
{
	int pivot = V[inicio]; //1° elemento como pivot
	int i = (fim + 1);
	
	for(int j = fim; j >= inicio+1; j--)
	{
		if(V[j] >= pivot)
		{
			i--;
			swap(&V[i], &V[j]);
		}
	}
	swap(&V[i-1], &V[inicio]);
	return(i-1);
}

//Função principal do Quick Sort
void quickSort(int *V, int inicio, int fim)
{
	if(inicio < fim)
	{
		int pivot = partition(V, inicio, fim);
		quickSort(V, inicio, pivot-1); //partição do lado esquerdo
		quickSort(V, pivot+1, fim); //partição do lado direito
	}
}

//Função para fazer a troca de elementos entre si
void swap(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

