#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad.h"

//MAIN VERSION

void main(void)
{
	bool falhaInsercao = false;
	char operacao[8];
	char nomeArq[11];
	char buff[25] = "";
	char un;

	int maxOperacao;
	int tamanho;
	int qtEntradas;

	struct disco *hd;
	criaDisco(&hd);

	scanf("%d", &maxOperacao);
	while (maxOperacao)
	{
		scanf("%d ", &tamanho);
		scanf("%cB", &un);
		redefineCelulas(hd, tamanho, un);

		while (maxOperacao)
		{
			scanf("%s", &operacao); //insere
			scanf("%s", &nomeArq);  //arq3

			if (!strcmp(operacao, "insere"))
			{
				scanf("%d", &tamanho); //2
				scanf("%cB", &un);     //M

				if (!falhaInsercao)
				{
					falhaInsercao = !insere(hd, nomeArq, tamanho, un);

					if (falhaInsercao)
					{
						otimiza(hd);
						falhaInsercao = !insere(hd, nomeArq, tamanho, un);
					}
				}
			}
			else if (!falhaInsercao && !strcmp(operacao, "remove"))
				deleta(hd, nomeArq);

			maxOperacao--;
		}

		if (!falhaInsercao)
		{
			propriedades(hd, buff);
			printf("%s\n", buff);
		}
		else
			puts("ERRO: disco cheio");

		

		/*
		Arq *aux;
		Celula *hdAux = hd;
		int i = 1;
		int j;
		while (hdAux != NULL)
		{
			printf("\n[%d] espacoLivre: %d\n", i++, hdAux->espacoLivre);
			printf("celulaCapacidade: %d\n", hdAux->celulaCapacidade);

			aux = hdAux->arq;
			j = 1;
			while (aux != NULL)
			{
				printf("		[%d] nome: %s\n", j++, aux->nome);
				printf("		tam: %d\n", aux->tamanho);
				printf("		tamFrag: %d\n", aux->tamanhoFragmento);
				aux = aux->prox;
			}
			hdAux = hdAux->prox;
		}

		getc(stdin);
		getc(stdin);
		getc(stdin);
		getc(stdin);
		getc(stdin);
		getc(stdin);
		getc(stdin);
		getc(stdin);
		getc(stdin);
		getc(stdin);
		*/

		formataDisco(hd);
		scanf("%d", &maxOperacao);
	}
	destroiDisco(&hd);
}
