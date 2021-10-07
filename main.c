#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
	true = 1,
	false = 0,
} bool;

#include "tad.h"

//MAIN VERSION

void main(void)
{
	bool falhaInsercao = false;
	char operacao[8];
	char nomeArq[11];
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
			else 
				if (!falhaInsercao && !strcmp(operacao, "remove"))
					remove();
					
			maxOperacao--;
		}

		if(!falhaInsercao)
			propriedades();
		else
			puts("ERRO: disco cheio");

		formataDisco();
		scanf("%d", &maxOperacao);
	}
	destroiDisco();
}
