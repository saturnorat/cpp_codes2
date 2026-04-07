/*
	Name: TodosMetodosSort.cpp
	Author: Logan Maia
	Date: 31/03/26 11:52
	Description: Neste programa iremos apresentar
	o desempenho de todos os m?todos de ordena??o
*/

//bibliotecas
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

//Sess?o de prototipa??o
void bubbleSort(int *, int);
void selectionSort(int*, int);
void insertionSort(int*, int);

//Variaveis globais
	int comp, trocas;
	clock_t inicio, fim;
	double tempo;
	
main()
{
//	int vet[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
//	int vet2[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
//	int vet3[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
	int vet[1000];
	int vet2[1000];
	int vet3[1000];
	int tam = sizeof(vet)/sizeof(int);
	
	srand(time(NULL)); //plantar semente baseado na hora
	for(int i = 0; i < tam; i++)
	{
		vet[i] = rand()%1000;
		vet2[i] = rand()%1000;
		vet3[i] = rand()%1000;
}
	trocas = tempo = comp = 0;
	
	puts("Vetor ORIGINAL: ");
	for(int i = 0; i < tam; i++)
		printf("%d|", vet[i]);
	
	bubbleSort(vet, tam);
	puts("\n\nBubble Sort:");

	printf("\n\nQtd de Comparacoes: %d", comp);
	printf("\n\nQtd de Trocas: %d", trocas);
	printf("\n\n ==> Tempo decorrido para ordenação: %.3f", tempo);
	
	trocas = tempo = comp = 0;
	
	selectionSort(vet2, tam);
	puts("\n\n====================");
	puts("\n\nSelection Sort:");
	printf("\n\nQtd de Comparacoes: %d", comp);
	printf("\n\nQtd de Trocas: %d", trocas);
	printf("\n\n ==> Tempo decorrido para ordenação: %.3f", tempo);
	
	tempo = trocas = comp = 0;
	
	insertionSort(vet3, tam);
	puts("\n\n====================");
	puts("\n\nInsertion Sort:");

	printf("\n\nQtd de Comparacoes: %d", comp);
	printf("\n\nQtd de Trocas: %d", trocas);
	printf("\n\n ==> Tempo decorrido para ordenação: %.3f", tempo);
	
	puts("\n\nVetor ordenado pelo Selection Sort: ");
	for(int i = 0; i < tam; i++)
		printf("%d|", vet[i]);

}

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

void selectionSort(int *S, int tam)
{
	int chave, menor;
	int i, j, aux;
	
	//La?o externo que itera do inicio ao fim do vetor
	for(i = 0; i < tam-1; i++)
	{

		//Assume que o menor elemento est? na primeira posi??o do vetor
		chave = i;
		menor = i + 1;

		//La?o interno para localizar quem ? o menor elemento do subconjunto
		for(j = i+1; j < tam; j++)
		{
			comp++;
			if(S[j] < S[menor])
				menor = j; //Guarda o indice do menor elemento do subconjunto
				
		}
		comp++;
		//Troca o menor elemento encontrado com o que 
		//est? na chave(posi??o inicial)
		if(S[menor] < S[chave])
		{
			aux = S[chave];
			S[chave] = S[menor];
			S[menor] = aux;
			trocas++;
		}
	}
}
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

