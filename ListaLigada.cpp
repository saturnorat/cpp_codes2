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
		int opc = 0;
		do
		{
			opc = menu();
			tratarOpcao(Lista, opc);
			puts("\n\n\n");
			system("pause");
			system("cls");
		}while(opc);
	}
	exibirLista(Lista);
}//fim do programa

//Função para apresentar oum menu ao usuário
int menu()
{
	int opc;
	puts("Escolha sua opcao: ");
	puts("-----------------------------------------");
	printf("1 - Zerar a Lista\n");
	printf("2 - Exibir a Lista\n");
	printf("3 - Inserir elemento do FIM da Lista\n");
	printf("4 - Inserir elemento do INICIO da Lista\n");
	printf("5 - Excluir elemento do FIM da Lista\n");
	printf("6 - Excluir elemento do INICIO da Lista\n");
	printf("7 - Sair...\n");
	puts("-----------------------------------------");
	printf("Opcao: "); scanf("%d", &opc);
	return opc;
}

//Função para tratar a escolha da opção do menu
void tratarOpcao(No *Lista, int opc)
{
	No *tmp;
	switch(opc)
	{
		case 1: iniciarLista(Lista);
			break;
		case 2: exibirLista(Lista);
			break;
		case 3: insereFim(Lista);
			break;
		case 4: insereInicio(Lista);
			break;
		case 5: //retiraFim(Lista);
			break;
		case 6: //retiraInicio(Lista);
			break;
		case 7: exit(0);
		
		default: puts("Opcao invalida!! Verifique!!!");
			break;
			
	}//fim do switch
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
//Função para inserir um Nó no inicio da Lista
void insereInicio(No *Lista)
{
	No* novo = alocaMemoria();
	No *head = Lista->prox;
	Lista->prox = novo;
	novo->prox = head;
	puts("No inserido no INICIO da Lista!!!");
	tamanho++;
}
//Função para inserir o Nó no fim da Lista
void insereFim(No *Lista)
{
	No *novo = alocaMemoria();
	novo->prox = NULL;
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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //cor original
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;
	
	//Salvar os atributos de cores
	GetConsoleScreenBufferInfo(hConsole,&consoleInfo);
	saved_attributes = consoleInfo.wAttributes; //salva a cor original
	
	
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
			SetConsoleTextAttribute(hConsole,11); //define a cor do texto
			printf(" ===> ");
			SetConsoleTextAttribute(hConsole,saved_attributes);
			tmp = tmp->prox;
		}
	}
}
