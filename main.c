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
			scanf("%s", &operacao);
			scanf("%s", &nomeArq);

			if (!strcmp(operacao, "insere"))
			{
				scanf("%d", &tamanho);
				scanf("%cB", &un);

				if (!falhaInsercao)
				{
					falhaInsercao = !insere(hd, nomeArq, tamanho, un);

					if (falhaInsercao)
					{
						otimiza();
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

		getc(stdin);
		getc(stdin);
		getc(stdin);
		getc(stdin);
		getc(stdin);
		getc(stdin);

		formataDisco();
		scanf("%d", &maxOperacao);
	}
	destroiDisco();
}
