/*
	Name: mergeSort.cpp
	Author: Logan Maia
	Date: 28/04/26 11:19
	Description: programa para demonstrar o mergeSort
*/
#include <stdio.h>

//Sessão de prototipação
void mergeSort(int *, int, int); //Quebra tudo em uma unidade
void merge(int *, int, int, int); //Mescla tudo

main()
{
	int vet[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
	int tam = sizeof(vet)/sizeof(int);
	int i;
	
	puts("Vetor original:");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);
		
	mergeSort(vet, 0, tam-1);//vet, inicio, fim
	
	puts("\n\nVetor ordenado:");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);
	
	
}//fim do main

//Função recursiva para "quebrar" todo o conjunto de dados
//em diversos vetores de um UNICO elemento
void mergeSort(int *V, int inicio, int fim)
{
	if(inicio < fim)
	{
		int meio = (inicio + fim) / 2; //Calcula o meio do conjunto
		mergeSort(V, inicio, meio); //Divide do lado esquerdo
		mergeSort(V, meio+1, fim); //Divide do lado direito
		merge(V, inicio, meio, fim); //Começa a juntar os subconjuntos
	}
}//fim da função função mergeSort

//Função que junta os sub-vetores divididos
//pela função recursiva mergeSort
void merge(int *V, int inicio, int meio, int fim)
{
	int i, j, k; //i j e auxiliar K
	int tamEsq, tamDir; //para ver tamanho dos vetores temporários, lado esquerdo e direito
	
	tamEsq = meio - inicio + 1; // o meio é o novo fim, já que está dividido
	tamDir = fim - meio;
	
	//Cria os vetores auxiliares/temporários
	int esquerda[tamEsq], direita[tamDir];
	
	//Copia os dados do vetor original para os 
	//arrays temporários esquerda[] e direita[]
	for(i = 0; i < tamEsq; i++)
		esquerda[i] = V[inicio + i];
	
	for(j = 0; j < tamDir; j++)
		direita[j] = V[meio + 1 + j];
		
	//mescla os arrays temporários de 
	//volta para o vetor original (V)
	
	i = 0; //indice inicial do primeiro subarray (esquerdo)
	j = 0; //indice inicial do primeiro subarray (direito)
	k = inicio; //indice inicial do subarray mesclado
	
	while(i < tamEsq && j < tamDir)
	{
		if(esquerda[i] < direita[j])
		{
			V[k] = esquerda[i];
			i++;
		}
		else
		{
			V[k] = direita[j];
			j++;
		}
	k++;
	}
	
	//Copia os elementos restantes da esquerda[]
	//se houver
	while(i < tamEsq)
	{
		V[k] = esquerda[i];
		i++;
		k++;
	}
	//Copia os elementos restantes de direita[]
	//se houver
	while(j < tamDir)
	{
		V[k] = direita[j];
		j++;
		k++;
	}
	
}//fim da função merge
