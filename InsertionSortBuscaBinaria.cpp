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
int buscaBinaria (int *, int, int);
int buscaSequencial(int *, int, int);
//variaveis globais
int trocas, comp, comp2; 
clock_t inicio, fim;
double tempo;

main()
{
	//int vet[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
	int vet[1000];
	int tam, x;
	tam = sizeof(vet)/sizeof(int);
	
	//plantando a semente para a função random
	srand(time(NULL));
	for(x = 0; x < tam; x++)
	vet[x] = rand()%1000;
	
	printf("Vetor original: \n");
	for(x = 0; x < tam; x++)
		printf("%d|", vet[x]);
		
	insertionSort(vet, tam); //invoke do metodo
	
	printf("\n\nVetor ORDENADO com Insertion Sort: \n");
	for(x = 0; x < tam; x++)
		printf("%d|", vet[x]);
		
	printf("\nQtd de trocas: {%d}\n", trocas);
	printf("\nQtd de comparacoes: {%d} \n", comp);
	printf("\n\n ==> Tempo decorrido para ordenação: %.6f\n\n", tempo);
	int elem = 0;
	printf("\n\nDigite um elemento para localizar: ");
	scanf("%d", &elem);
	buscaBinaria(vet, tam, elem);
	printf("\nQtd de comparacoes: {%d} \n", comp2);
	buscaSequencial(vet, tam, elem);
}
//Função para localizar um elemento pela Busca Linear
int buscaSequencial(int *V, int tam, int elem)
{
	int comp = 0;
	for(int i = 0; i < tam; i++)
	{
		comp++;
		if(elem == V[i])
		{
			printf("\n\nElemento localizado na posicao %d", i+1);
			printf("\nQtd de comparacoes: {%d} \n", comp);
			break;
		}
	}
	puts("Elemento nao localizado!");
}

//Função para realizar a Busca Binaria ou Logaritmica
int buscaBinaria(int *V, int tam, int elem)
{
	int inicio, fim, meio;
	inicio = 0;
	fim = tam-1;
	while(inicio <= fim)
	{
	meio = (inicio + fim)/2;
	comp2++;
	if(V[meio] != elem)
	{
		if(V[meio] > elem)
		{
			fim = meio -1;
		}
		
		else
			inicio = meio +1;
	}
	else
	{
		printf("\n\nElemento localizado na posicao %d", meio+1);
		break;
	}
	
	}	
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

