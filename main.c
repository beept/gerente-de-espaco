#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
	true = 1,
	false = 0,
} bool;

#include "listaDupEnc_otimiza.h"
#include "tad.h"

//VERSAO LEITURA COM ARQUIVO

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
			scanf("%s", &nomeArq);	//arq3

			if (!strcmp(operacao, "insere"))
			{
				scanf("%d", &tamanho); //2
				scanf("%cB", &un);		 //M

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

		formataDisco(hd);
		scanf("%d", &maxOperacao);
	}
	destroiDisco(&hd);
}
