#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


struct Contato
{
	int cod;
	char nome[50];
	int numero;
	struct Contato *prox;
};
typedef struct Contato no;
typedef struct Contato * lista;


void mostrarContatos( lista *LISTA )
{
	no *ContatinhoAtual;
	ContatinhoAtual = *LISTA;
	printf("Lista com todos os contatos:\n");
	while( ContatinhoAtual != NULL )
	{
		printf("cod: %d\n", ContatinhoAtual->cod );
		printf("Nome: %s\n", ContatinhoAtual->nome );
		printf("Número: %d\n", ContatinhoAtual->numero );

		ContatinhoAtual =  ContatinhoAtual->prox;
	}
	printf("\n\n");
}

void addContatinho( lista *LISTA, char nome[50], int numero )
{
	// Criando um novo nó para add o novo contato
	no *Novocontato;
	// Alocando memória para esse novo contato
	Novocontato = (no *) malloc(sizeof(no));
	// Pegando dado nome e setando no novo contato
	 strcpy (Novocontato->nome, nome);
	// Pegando dado do telefone e setando no novo contato
	Novocontato->numero = numero;
	// Apontando Novocontato para o inicio da lista

	Novocontato->cod = Novocontato->cod + 1;

	Novocontato->prox = *LISTA;
	// Apontando o inicio da lista para o novo contato criado
	*LISTA = Novocontato;

	
}

void pesquisarContatinho(lista *LISTA, char nome[50])
{

	int i = 0;
	no *contatinhoAtual;
	contatinhoAtual = *LISTA;

	no *contatinhoPesquisa;
	contatinhoPesquisa = (no *) malloc(sizeof(no));
	strcpy (contatinhoPesquisa->nome, nome);

	while(contatinhoAtual->prox != NULL)
	{
		if (strncmp(contatinhoPesquisa->nome, nome, 50))
		{
			printf("Número do contatinho:%d\n", contatinhoAtual->numero );

		}else
		{
			printf("ERROW TROUXA\n");
		}
	}
}






int menuContato()
{
	int opcao;
	printf("\n");
	printf("MENU - ESCOLHA UMA DAS OPÇÕES \n");
	printf("1. Inserir um contato: \n");
	printf("2. Localizar um telefone: \n");
	printf("3. Excluir um contato: \n");
	printf("4. Contatos que iniciam com a letra: \n");
	printf("5. Exibir todos os contatos: \n");
	printf("6. Apagar a agenda: \n");
	printf("0. Sair do sistema: \n\n\n");
	printf("Digite uma opção desejada: \n");

	scanf("%d", &opcao);
	return opcao;
}


int main(int argc, char const *argv[])
{
	
	int opcao, numero;
	char nome[50];

	lista LL;
	LL = NULL;

	do{
		opcao = menuContato();
		switch(opcao)
		{
		case 1:
			printf("Inserir um novo contatinho:\n");
			printf("Informe o nome do contatinho:\n");
			scanf("%s", nome);
			printf("Informe o número do contatinho:\n");
			scanf("%d", &numero);
			addContatinho(&LL, nome, numero);
			break;
		case 2:
			printf("Localizar o contatinho:\n");
			printf("Digite o nome do contatinho:\n");
			scanf("%s", nome);
			pesquisarContatinho(&LL, nome);
			break;	

		case 3:
			printf("contatos\n");
			mostrarContatos(&LL);
			break;	
		}

	
	}while( opcao !=0 );
	



	return 0;
}
