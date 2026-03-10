/*
	Name: ListaLigada.cpp
	Author: Logan Maia
	Date: 10/03/26 11:15
	Description: Implementação da estrutura de dados 
	Lista Encadeada
*/
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

//Definição da estrutura de um nó
typedef struct No
{
	char nome[20];
	int idade;
	No *prox;
};

//Variavel global 
int tamanho; //tamanho da lista

//Seção de prototipação
int vazia(No *);
No *alocaMemoria();
void insereFim(No *);
No *retiraFim(No *);
void insereInicio(No *);
No *retiraInicio();
void exibirLista(No *);
void iniciarLista(No *);
int menu();
void tratarOpcao(No *, int);

//função principal
main()
{
	No *Lista = (No *) malloc(sizeof(No));
	if(!Lista)
	{
		puts("Sem memoria para criar lista");
		exit(1);
	}
	else
	{
		insereFim(Lista);
	}
}//fim do programa

//Função para apresentar oum menu ao usuário
int menu()
{
	
}

//Função para tratar a escolha da opção do menu
void tratarOpcao(No *Lista, int opc)
{
	
}

//Função para iniciar a Lista
void iniciarLista(No *Lista)
{
	Lista->prox = NULL;
	tamanho = 0;	
}

//Função que testa se a Lista está vazia
int vazia(No *Lista)
{
	if(Lista->prox == NULL)
		return 1; //está vazia
	else
		return 0;//não está vazia
}

//Função para alocação de memória para um NÓ
No *alocaMemoria()
{
	No *novo = (No *) malloc(sizeof(No));
	if(!novo)
	{
		puts("Sem memoria disponivel para criar um novo No!!");
		exit(1);
	}
	else
	{
		printf("Nome: ");
		scanf("%s", &novo->nome);
		printf("Idade: ");
		scanf("%d", &novo->idade);
		return novo;
	}
}

//Função para inserir o Nó no fim da Lista
void insereFim(No *Lista)
{
	No *novo = alocaMemoria();
	novo->prox == NULL;
	if(vazia(Lista))
		Lista->prox = novo;
	else
	{
		No *tmp = Lista->prox;
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		tmp->prox = novo;
	}
	tamanho++;
	puts("Novo elemento inserido com sucesso!!");
}

//Função para exibir todo o conteúdo da Lista
void exibirLista(No *Lista)
{
	if(vazia(Lista))
		puts("\n======> Lista vazia!");
	else
	{
		No *tmp;
		tmp = Lista->prox;
		printf("Lista: ");
		while(tmp != NULL)
		{ 
			printf("%s", tmp->nome);
			printf("| %d", tmp->idade);
			printf("===>");
			tmp = tmp->prox;
		}
	}
}
