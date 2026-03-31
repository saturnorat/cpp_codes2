/*
	Name: SelectionSort.cpp
	Author: Logan Maia
	Date: 31/03/26 10:51
	Description: programa para implementar o método de ordenação 
		Selection Sort
*/
//Sessão de prototipação
void selectionSort(int*, int);

#include <stdio.h>

//Variaveis globais
	int comp, trocas;
	
main()
{
	int vet[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
	int tam = sizeof(vet)/sizeof(int);
	trocas = comp = 0;
	int i;
	
	puts("Vetor ORIGINAL: ");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);
	
	selectionSort(vet, tam);
	
	puts("\nVetor ordenado pelo Selection Sort: ");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);

	printf("\n\nQtd de Comparacoes: %d", comp);
	printf("\n\nQtd de Trocas: %d", trocas);
}

//função com o algoritmo do SelectionSort
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
