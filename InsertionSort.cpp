/*
	Name: InsertionSort.cpp
	Author: Logan Maia
	Date: 07/04/26 10:55
	Description: Programa para demonstrar
	a implementação do método de ordenação Insertion Sort
*/
//Sessão de importação de bibiotecas
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//Prototipação das funções
void insertionSort(int *, int);
//variaveis globais
int trocas, comp; 
clock_t inicio, fim;
double tempo;

main()
{
	//int vet[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
	int vet[10000];
	int tam, x;
	tam = sizeof(vet)/sizeof(int);
	
	//plantando a semente para a função random
	srand(time(NULL));
	for(x = 0; x < tam; x++)
	vet[x] = rand()%10000;
	
	printf("Vetor original: \n");
	for(x = 0; x < tam; x++)
		printf("%d|", vet[x]);
		
	insertionSort(vet, tam); //invoke do metodo
	
	printf("\n\nVetor ORDENADO com Insertion Sort: \n");
	for(x = 0; x < tam; x++)
		printf("%d|", vet[x]);
		
	printf("\nQtd de trocas: {%d}\n", trocas);
	printf("\nQtd de comparacoes: {%d} \n", comp);
	printf("\n\n ==> Tempo decorrido para ordenação: %.3f", tempo);
}

//Função do método insertion sort
void insertionSort(int *V, int tam)
{
	int i, j, chave;

	inicio = clock();
	for(i = 1; i < tam; i++)
	{
		chave = V[i];
		j = i - 1;
		
		while(j >= 0 && chave < V[j])
		{
			comp++;
			V[j + 1] = V[j];
			j--;
			trocas++;
		}
	V[j + 1] = chave;
	trocas++;
	}
	fim = clock(); //recebe tempo final
	tempo = ((double)fim - inicio)/CLOCKS_PER_SEC;
}

