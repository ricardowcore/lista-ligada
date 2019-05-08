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
	// Criando o no para percorrer a lista
	no *contatinhoAtual;
	// Apontando o no para o inicio da lista
	contatinhoAtual = *LISTA;
	// Setando o cabeçalho da informação
	printf("Lista com todos os contatos:\n");
	// Loop logico para percorrer a lista
	while( contatinhoAtual != NULL )
	{
		// Mostrando as informações de nome para o user
		printf("Nome: %s\n", contatinhoAtual->nome );
		// Mostrando as informaçõe do numero para o user
		printf("Número: %d\n", contatinhoAtual->numero );
		// Passando o no para o proximo item da lista
		contatinhoAtual =  contatinhoAtual->prox;
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

int pesquisarContatinho(lista *LISTA, char nome[50])
{
	// backup da lista
	no *inicio;
	inicio = *LISTA;

	// Criando um novo no para aponta na lista
	no *contatinhoAtual;
	// Fazendo com o novo no fique apontado para o inicio da lista
	contatinhoAtual = *LISTA;
	// Criando um no para ser utilizado na pesquisa
	no *contatinhoPesquisa;
	// Alocando memoria para o novo no
	contatinhoPesquisa = (no *) malloc(sizeof(no));
	// Copiando a informação recebida na função para a pesquisa
	strcpy (contatinhoPesquisa->nome, nome);

	// Loop lógico que pesquisa o nome do contato na lista

	while(contatinhoAtual->prox != NULL)
	{
		// Verificação lógica para comparar o nome recebido com os nomes da lista
		if (strncmp(contatinhoPesquisa->nome, nome, 50)==0)
		{
			// Se for encontrado, retorna o numero do contao
			return printf("Numero do contatinho: %d\n", contatinhoAtual->numero);
		}
		// Se caso não foi encontrado muda a posição do ponteiro
		contatinhoPesquisa = contatinhoPesquisa->prox;
	}
	// Caso o contatinho não se encontre na lista
	return printf("contatinho nao encontrado\n");
}


int tamanho(lista *LISTA) {
  no *NoAtual;
  NoAtual = *LISTA;
  int quantidade = 0;
  while (NoAtual != NULL) {
    quantidade++;
    NoAtual = NoAtual->prox;
  }
  return quantidade;
};


int excluirVacilao(lista *LISTA, char nome[50]){
	// backup da lista
	no *inicio;
	inicio = *LISTA;
	// Criando um novo nó
	no *vacilao;
	// Apontando o novo no para o inicio da lista
	vacilao = *LISTA;
	vacilao = (no *) malloc(sizeof(no));
	strcpy (vacilao->nome, nome);
	printf("%s\n",vacilao->nome);
	//
	// // Se o vacilao for o primeiro da lista ele ja é excluido
	// if (strncmp(vacilao->nome, nome, 50)==0)
	// {
	// 	// passando o ponteiro da lista para o proximo elemento
	// 	*LISTA = vacilao->prox;
	// 	// Jogando o contato do vacilão fora
	// 	free(vacilao);
	// 	// Voltando mensagem de sucesso para o user
	// 	return printf("Você ta melhor sem ele agora migs\n");
	// }


	// Caso o vacilão não tiver no inicio da lista a gente vai atras dele
	//











	// no *contatinhoAtual;
	// contatinhoAtual = *LISTA;
	// contatinhoAtual = (no *) malloc(sizeof(no));
	// strcpy (contatinhoAtual->nome, nome);
	//
	//
	//
	// no *contatoAnterior;
	// contatoAnterior = (no *) malloc(sizeof(no));
	// while(contatinhoAtual->prox != NULL)
	// {
	// 	contatoAnterior = contatinhoAtual;
	// 	contatinhoAtual = contatinhoAtual->prox;
	// }
	// if (strncmp(contatinhoAtual->nome, nome, 50)==0)
	// {
	// 	contatoAnterior->prox = contatinhoAtual->prox;
	// 	free(contatinhoAtual);
	// 	return printf("Você ta melhor sem ele agora migs\n");
	// }else
	// {
	// 	return printf("Ele nem ta na sua agenda migs\n");
	// }
	//
	// no *contatinhoProx;
	// contatinhoProx = (no *) malloc(sizeof(no));
	//
	// while (contatinhoAtual->prox != NULL) {
	// 	if (strncmp(contatinhoAtual->nome, nome, 50)==0) {
	//
	// 		no *contatinhoAnterior;
	// 		contatinhoAnterior = (no *) malloc(sizeof(no));
	//
	// 		contatinhoAnterior->cod = (contatinhoAtual->cod-1);
	// 		no *contatinhoAux;
	// 		contatinhoAux = *LISTA;
	// 		while (contatinhoAux->prox != NULL) {
	// 			if (contatinhoAux->cod == contatinhoAnterior->cod) {
	// 				contatinhoAnterior = contatinhoAux;
	// 				contatinhoAnterior->prox = contatinhoProx;
	// 				free(contatinhoAtual);
	// 				return printf("certo\n");
	// 			}
	// 			contatinhoAux = contatinhoAux->prox;
	// 		}
	// 	}
	// 	contatinhoAtual = contatinhoAtual->prox;
	// }
	//
	//
	//

	// while(contatinhoAtual->prox != NULL)
	// {
	// 	printf("primeiro\n");
	// 	if (strncmp(vacilao->nome, nome, 50)==0)
	// 	{
	// 		printf("segundo\n");
	// 		no *contatoAnterior;
	// 		contatoAnterior->cod = contatinhoAtual->cod-1;
	// 		printf("terceiro\n");
	// 		while(vacilao->prox != NULL)
	// 		{
	// 			printf("quarto\n");
	// 			if (vacilao->cod == contatoAnterior->cod)
	// 			{
	// 				printf("quinto\n");
	// 				vacilao = contatinhoAtual;
	// 				no *contatoProx;
	// 				contatoProx = contatinhoAtual->prox->prox;
	// 				contatoAnterior = contatoProx;
	// 				free(vacilao);
	// 				return printf("Você ta melhor sem ele agora migS\n");
	// 			}
	// 			printf("sexto\n");
	// 			vacilao = vacilao->prox;
	// 		}
	// 		printf("setimo\n");
	// 	}
	// 	contatinhoAtual = contatinhoAtual->prox;
	// 	printf("oitavo\n");
	// }
}

int contatinhosLetra(lista *LISTA, char nome[50])
{

}





int menuContato()
{
	int opcao;
	// printf("\e[H\e[2J"); // impar tela no linux <- NÂO CONSEGUI FAZER ESSA MISÊRA FUNFAR
	printf("MENU - ESCOLHA UMA DAS OPÇÕES \n");
	printf("1. Inserir um contato: \n");
	printf("2. Localizar um telefone: \n");
	printf("3. Excluir um contato: (não ta funfando) \n"); // <- NÂO CONSEGUI FAZER ESSA MISÊRA FUNFAR
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
			printf("Excluir o vacilão\n");
			printf("Digite o nome do vacilão:\n");
			scanf("%s", nome);
			excluirVacilao(&LL, nome);
			break;

			case 4:
			printf("Contatinhos com a letra:\n");
			scanf("%s\n", nome);
			break;

		case 5:
			printf("Localizar o contatinho:\n");
			mostrarContatos(&LL);
			break;
		}


	}while( opcao !=0 );




	return 0;
}
