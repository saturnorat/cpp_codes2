/*
	Name: heapSort.cpp
	Author: Logan Maia
	Date: 05/05/26 11:22
	Description: 
*/

//Sessão de prototipação
void heapfy(int *, int, int);
void heapSort(int *, int);
void swap (int *, int *);
void imprimir(int *);
int tam;

//Sessão de bibliotecas
#include <stdio.h>

main()
{
	int vet[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
	int i;
	tam = sizeof(vet)/sizeof(int);
	
	puts("Vetor original:");
	imprimir(vet);
	heapSort(vet,tam);
	puts("\nVetor ordenado pelo HeapSort:");
	imprimir(vet);
}

//Função para troca de posições (swap)
void swap(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

//Função que faz heapfy, ou seja, testa se o pai é maior que os filhos (MAXHEAP)
//ou se o pai é menor que os filhos (MIN HEAP) e invoca o "swap" para fazer a troca
void heapfy(int *V, int n, int i)
{
	int maior = i; //inicializa o maior como raiz
	int esq = 2 * i + 1; //indice do filho da esquerda
	int dir = 2 * i + 2; //filho da direita
	
	//se o filho da esquerda é maior que o pai 
	if(esq < n && V[esq] > V[maior])
		maior = esq;
	//Se o filho da direita é maior que o pai
	if(dir < n && V[dir] > V[maior])
		maior = dir;
	
	if(maior != i)
	{
		swap(&V[i], &V[maior]); 
		//invoca recursivamente heapfy
		//na sub-arvore afetada
		heapfy(V, n, maior);
	}
}

//Função principal que monta a arvore e submete a função recursiva heapfy
//para verificar as regras de MaxHeap ou MinHeap
void heapSort(int *V, int n)
{
	//1. constroi um Max Heap
	for(int i = n/2 - 1; i >= 0; i--)
		heapfy(V, n, i);
	//2. troca a raiz com o ultimo elemento
	//e reduz a arvore (heap)
	for(int i = n-1; i > 0; i--)
	{
		//move o elemento atual (raiz) para o fim do array
		swap(&V[0], &V[i]);
		//invoca a função heapfy na raiz para restaurar a propiedade do heap
		heapfy(V, i, 0);
	}
}

//função para imprimir todo o conteudo do vet
void imprimir(int *V)
{
	for(int i = 0; i < tam; i++)
		printf("%d|", V[i]);
}
