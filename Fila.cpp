/*
	Name: Fila.cpp
	Author: Logan Maia
	Date: 24/02/26 10:53
	Description: Programa para implementar uma fila
	do tipo FiFo - First in First out
*/
#include <stdio.h>

//variáveis globais, todas as funções terão acesso
int itens[5]; 
int inicio = -1, fim = -1;
int tam = 5;

//Prototipação das funções
void Enqueue(int); //inserir elemento
int Dequeue(); //retira um elemento da fila
int isFull(); //retorna 1 se a fila estiver cheia
int isEmpty(); //testa se a fila está vazia
void imprimirFila();

main()
{
	Enqueue(100);
	Enqueue(101);
	Enqueue(102);
	Enqueue(103);
	Enqueue(104);
	Enqueue(505);
	imprimirFila();
	Dequeue();
	//Enqueue(505);
	Dequeue();
	Dequeue();
	imprimirFila();
	Dequeue();
	Dequeue();
	Dequeue();

}//fim do programa

//Função para inserir elemento na fila
void Enqueue(int elem)
{
	if(isFull() == 1)
		puts("\n===>A fila esta cheia!");
	else
	{
		if(inicio == -1)	
			inicio = 0;
		fim = (fim + 1)%tam;
		itens[fim] = elem;
		printf("\nElemento %d inserido na FIFO!", elem);
	}
}

//Função que retira um elemento da fila
int Dequeue()
{
	int elem;
	if(isEmpty() == 1)
	{
		puts("\n===>A Fila esta vazia!");
		return -1;
	}
	else
	{
		elem = itens[inicio];
		if(inicio == fim)
		{
			inicio = -1;
			fim = -1;
		}
		else
		{
			inicio = (inicio + 1)%tam;
		}
		printf("\n%d foi Excluido da FIFO", elem);
		return elem;
	}
}

//Função que testa se a fila está cheia
int isFull()
{
	if((inicio == (fim+1)%tam) || (inicio == 0 && fim == tam-1))
		return 1;
	else 
		return 0;
}

//Função que testa se a fila está vazia
int isEmpty()
{
	if(inicio == -1)
		return 1;
	else
		return 0;
}

//Função que exibe todos os elementos da fila
void imprimirFila()
{
	int i;
	if(isEmpty() == 1)
		puts("A Fila esta vazia");
	else
	{
		puts("\n ===>Conteudo da FIFO: ");
		for(i = inicio; i != fim; i = (i+1)%tam)
			printf("%d|", itens[i]);
	}
}
