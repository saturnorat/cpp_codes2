/*
	Name: BubbleSort.cpp
	Author: Logan Maia
	Date: 24/03/26 11:02
	Description: Programa para demonstrar o funcionamento do 
	método de ordenação Bubble sort
*/
//Sessão de Prototipação
void bubbleSort(char *V, int);

#include <stdio.h>
#include <windows.h>
#include <time.h>
//Variaveis globais
	int comp, trocas;

main()
{
	//int vet[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
	//int vet[100000];
	char vet[] = {'l', 'o', 'g', 'a', 'n'};
	int tam = sizeof(vet)/sizeof(char);
	int i;
	comp = trocas = 0;
	
	//srand(time(NULL)); //plantar semente baseado na hora
	//for(i = 0; i < tam; i++)
		//vet[i] = rand()%100000;
	
	puts("Vetor ORIGINAL: ");
	for(i = 0; i < tam; i++)
		printf("%c|", vet[i]);
	
	bubbleSort(vet, tam);
	
	puts("\nVetor ordenado pelo BubbleSort: ");
	for(i = 0; i < tam; i++)
		printf("%c|", vet[i]);

	printf("\n\nQtd de Comparacoes: %d", comp);
	printf("\n\nQtd de Trocas: %d", trocas);
}

//Função para o método de ordenação
//BubbleSort
void bubbleSort(char *V, int tam)
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
