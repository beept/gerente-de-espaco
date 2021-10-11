#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef __linux__
	#include "recursos/getchForLinux.h"
#else
	#include <conio.h>
#endif

typedef enum
{
	true = 1,
	false = 0,
} bool;

#include "recursos/listaDupEnc_otimiza.h"
#include "recursos/tad.h"

//VERSAO LEITURA COM ARQUIVO

void main(void)
{
	FILE *input = fopen("entrada_dados.txt", "r");
	if (input != NULL)
	{
		bool falhaInsercao;
		char operacao[8];
		char nomeArq[11];
		char buff[25] = "";
		char un;

		int maxOperacao;
		int tamanho;

		struct disco *hd;
		criaDisco(&hd);

		//scanf("%d", &maxOperacao);
		fscanf(input, "%d", &maxOperacao);
		while (maxOperacao)
		{
			//scanf("%d ", &tamanho);
			//scanf("%cB", &un);
			fscanf(input, "%d%cB", &tamanho, &un);

			redefineCelulas(hd, tamanho, un);

			falhaInsercao = false;
			while (maxOperacao)
			{
				//scanf("%s", &operacao); 
				//scanf("%s", &nomeArq);
				fscanf(input, "%s %s", &operacao, &nomeArq);

				if (!strcmp(operacao, "insere"))
				{
					//scanf("%d", &tamanho);
					//scanf("%cB", &un);
					fscanf(input, "%d%cB", &tamanho, &un);

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
				printf("%s", buff);
			}
			else
				printf("ERRO: disco cheio\t");
			
			printf("\tExibir disco? [S][N]: ");
			if(toupper(getche()) == 'S')
				bonus(hd);
			putchar('\n');


			formataDisco(hd);
			//scanf("%d", &maxOperacao);
			fscanf(input, "%d", &maxOperacao);
		}
		destroiDisco(&hd);
		fclose(input);
	}
	else
		perror("ErroMsg");
	getch();
	return 0;
}
