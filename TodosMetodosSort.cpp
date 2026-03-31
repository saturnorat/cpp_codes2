/*
	Name: TodosMetodosSort.cpp
	Author: Logan Maia
	Date: 31/03/26 11:52
	Description: Neste programa iremos apresentar
	o desempenho de todos os métodos de ordenação
*/

//bibliotecas
#include <stdio.h>
#include <windows.h>
#include <time.h>

//Sessão de prototipação
void bubbleSort(int *, int);
void selectionSort(int*, int);

//Variaveis globais
	int comp, trocas;
	
main()
{
	int vet[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
	int vet2[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
	//int vet[100000];
	int tam = sizeof(vet)/sizeof(int);
	
	//srand(time(NULL)); //plantar semente baseado na hora
	//for(int i = 0; i < tam; i++)
		//vet[i] = rand()%100000;
		
	trocas = comp = 0;
	
	puts("Vetor ORIGINAL: ");
	for(int i = 0; i < tam; i++)
		printf("%d|", vet[i]);

	bubbleSort(vet, tam);
	puts("\n\nBubble Sort:");

	printf("\n\nQtd de Comparacoes: %d", comp);
	printf("\n\nQtd de Trocas: %d", trocas);
	
	trocas = comp = 0;
	
	selectionSort(vet2, tam);
	puts("\n\n====================");
	puts("\n\nSelection Sort:");
	printf("\n\nQtd de Comparacoes: %d", comp);
	printf("\n\nQtd de Trocas: %d", trocas);
	
	
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
	
	//Laço externo que itera do inicio ao fim do vetor
	for(i = 0; i < tam-1; i++)
	{

		//Assume que o menor elemento está na primeira posição do vetor
		chave = i;
		menor = i + 1;

		//Laço interno para localizar quem é o menor elemento do subconjunto
		for(j = i+1; j < tam; j++)
		{
			comp++;
			if(S[j] < S[menor])
				menor = j; //Guarda o indice do menor elemento do subconjunto
				
		}
		comp++;
		//Troca o menor elemento encontrado com o que 
		//está na chave(posição inicial)
		if(S[menor] < S[chave])
		{
			aux = S[chave];
			S[chave] = S[menor];
			S[menor] = aux;
			trocas++;
		}
	}
}
