typedef enum
{
	true = 1,
	false = 0,
} bool;

typedef struct arquivo
{
	char nome[11];
	int tamanho;
	int tamanhoFragmento;
	struct arquivo *prox;
	struct arquivo *ant;
} Arq;

typedef struct disco
{
	int celulaCapacidade;
	int espacoLivre;
	struct arquivo *arq;
	struct disco *prox;

} Celula;

Celula *criaSetor()
{
	Celula *novaCelula = (Celula *)malloc(sizeof(Celula));
	novaCelula->celulaCapacidade = novaCelula->espacoLivre = 0;
	novaCelula->arq = NULL;
	novaCelula->prox = NULL;
	return novaCelula;
}

void criaDisco(struct disco **cabeca)
{
	*cabeca = NULL;
	Celula *nova;
	int i;
	for (i = 0; i < 8; i++)
	{
		nova = criaSetor();
		nova->prox = *cabeca;
		*cabeca = nova;
	}
}

void converteKb(int *tam, char un)
{
	*tam *= un != 'K' ? 1024 * (un == 'G' ? 1024 : 1) : 1;

	//Outras conversoes
	/*
	 * tam = (un == 'M') ? (*tam) * 1024 : *tam;
	 * tam = (un == 'G') ? (*tam) * 1024 * 1024 : *tam;
	 * tam *= un == 'M' ? 1024 : (un == 'G' ? 1024 * 1024 : 1);
	 */
}

Arq *criaArq(const char *nome, int tam, int tamFrag, Arq *ant, Arq *prox)
{
	Arq *novoArq = (Arq *)malloc(sizeof(Arq));
	strcpy(novoArq->nome, nome);
	novoArq->tamanho = tam;
	novoArq->tamanhoFragmento = tamFrag;
	novoArq->ant = ant;
	novoArq->prox = prox;
	return novoArq;
}

void redefineCelulas(struct disco *hd, int tam, char un)
{
	converteKb(&tam, un);
	tam /= 8;

	while (hd != NULL)
	{
		hd->celulaCapacidade = hd->espacoLivre = tam;
		hd->arq = NULL;
		hd = hd->prox;
	}
}

bool estaLivre(struct disco *hd, int tam)
{
	//converteKb(&tam, un);
	int espLivre = 0;

	while (hd != NULL && espLivre < tam)
	{
		espLivre += hd->espacoLivre;
		hd = hd->prox;
	}

	return espLivre >= tam;
}

bool temEspSeq(struct disco *hd, int tam, Celula **setor, Arq **arqCabeca)
{
	int espacoSeq = 0;

	*setor = hd;
	*arqCabeca = hd->arq;

	while (hd != NULL && espacoSeq < tam)
	{
		if (hd->arq == NULL)
			espacoSeq += hd->celulaCapacidade;
		else
		{
			espacoSeq += hd->espacoLivre;

			if (espacoSeq < tam)
			{
				espacoSeq = hd->espacoLivre;

				if (hd->espacoLivre == 0 && hd->prox != NULL)
				{
					*setor = hd->prox;
					*arqCabeca = hd->prox->arq;
				}
				else
				{
					*setor = hd;
					*arqCabeca = hd->arq;
					while ((*arqCabeca)->prox != NULL)
						*arqCabeca = (*arqCabeca)->prox;
				}
			}
		}
		hd = hd->prox;
	}

	return espacoSeq >= tam;
}


//refatorar
bool insere(struct disco *hd, char *nomeArq, int tam, char un)
{
	converteKb(&tam, un);
	
	if (estaLivre(hd, tam))
	{
		Arq 	 *arqInsercao = NULL;
		Celula *celuInsercao = NULL;

		if (temEspSeq(hd, tam, &celuInsercao, &arqInsercao))
		{
			int tempFrag;
			int auxTamFrag = tam;
		
			while (auxTamFrag > 0)
			{
				tempFrag = auxTamFrag;
				auxTamFrag -= celuInsercao->espacoLivre;

				if (auxTamFrag <= 0)
				{
					if (celuInsercao->arq == arqInsercao)
						celuInsercao->arq = criaArq(nomeArq, tam, tempFrag, NULL, arqInsercao);
					else
						arqInsercao->prox = criaArq(nomeArq, tam, tempFrag, arqInsercao, NULL);
				
					celuInsercao->espacoLivre -= tempFrag;
				}
				else
				{
					if (celuInsercao->arq == arqInsercao)
						celuInsercao->arq = criaArq(nomeArq, tam, celuInsercao->espacoLivre, NULL, arqInsercao);
					else
						arqInsercao->prox = criaArq(nomeArq, tam, celuInsercao->espacoLivre, arqInsercao, NULL);

					celuInsercao->espacoLivre = 0;
					celuInsercao = celuInsercao->prox;
					arqInsercao = celuInsercao->arq;
				}
			}
			return true;
		}
	}
	return false;
}

void propriedades(struct disco *hd, char *buffstring)
{

	*buffstring = '\0';
	
	while (hd != NULL)
	{
		if ((double)hd->espacoLivre / hd->celulaCapacidade <= 0.25)
			strcat(buffstring, "[#]");
		else if ((double)hd->espacoLivre / hd->celulaCapacidade <= 0.75)
			strcat(buffstring, "[-]");
		else
			strcat(buffstring, "[ ]");
		
		hd = hd->prox;
	}
}


void deleta(struct disco *hd, char *nomeArq)
{
	Arq *auxArq;
	Arq *auxArqDel;
	Arq *auxArqAnt;

	while (hd != NULL)
	{
		
		hd = hd->prox;
	}
}

void formataDisco()
{
	puts("formataDisco()");
}

void destroiDisco()
{
	puts("destroiDisco()");
}

void otimiza()
{
	puts("otimiza()");
}