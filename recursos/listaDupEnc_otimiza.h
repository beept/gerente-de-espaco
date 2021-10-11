typedef struct lista_otimiza
{
  struct lista_otimiza *ant;
  char nome[11];
  int tamanho;
  struct lista_otimiza *prox;

} arqInfo;

typedef struct lista_otimiza_descritor
{
  struct lista_otimiza *primeiroNodo;
  struct lista_otimiza *ultimoNodo;
} descritor;

void init(descritor *desc)
{
  desc->primeiroNodo = desc->ultimoNodo = NULL;
}

arqInfo *criaNodo(char *nomeArq, int tam)
{
  arqInfo *novoNo = (arqInfo *)malloc(sizeof(arqInfo));
  novoNo->ant = novoNo->prox = NULL;
  strcpy(novoNo->nome, nomeArq);
  novoNo->tamanho = tam;
  return novoNo;
}

void insereAntes(descritor *desc, char *nomeArq, int tam)
{
  if (desc->primeiroNodo == NULL)
    desc->primeiroNodo = desc->ultimoNodo = criaNodo(nomeArq, tam);
  else
  {
    desc->primeiroNodo->ant = criaNodo(nomeArq, tam);
    desc->primeiroNodo->ant->prox = desc->primeiroNodo;
    desc->primeiroNodo = desc->primeiroNodo->ant;
  }
}

void insereApos(descritor *desc, char *nomeArq, int tam)
{
  if (desc->ultimoNodo == NULL)
    desc->ultimoNodo = desc->primeiroNodo = criaNodo(nomeArq, tam);
  else
  {
    desc->ultimoNodo->prox = criaNodo(nomeArq, tam);
    desc->ultimoNodo->prox->ant = desc->ultimoNodo;
    desc->ultimoNodo = desc->ultimoNodo->prox;
  }
}

arqInfo *buscaInfo(descritor desc, char *nomeArq)
{
  while (desc.primeiroNodo != NULL && strcmp(desc.primeiroNodo->nome, nomeArq))
    desc.primeiroNodo = desc.primeiroNodo->prox;

  return desc.primeiroNodo;
}

bool estaVazio(descritor desc)
{
  return desc.primeiroNodo == NULL;
}

void removeNodo(descritor *desc, char *nomeArq)
{
  arqInfo *nodo = buscaInfo(*desc, nomeArq);
  if (nodo != NULL)
  {
    if (nodo == desc->primeiroNodo && nodo == desc->ultimoNodo)
      desc->primeiroNodo = desc->ultimoNodo = NULL;
    else
    {
      if (nodo == desc->primeiroNodo)
      {
        desc->primeiroNodo = nodo->prox;
        desc->primeiroNodo->ant = nodo->ant;
      }
      else if (nodo == desc->ultimoNodo)
      {
        desc->ultimoNodo = nodo->ant;
        desc->ultimoNodo->prox = nodo->prox;
      }
      else
      {
        nodo->ant->prox = nodo->prox;
        nodo->prox->ant = nodo->ant;
      }
    }
    free(nodo);
  }
}

void display(descritor desc)
{
  while (desc.primeiroNodo != NULL)
  {
    printf("[%s][%d]\n", desc.primeiroNodo->nome, desc.primeiroNodo->tamanho);
    desc.primeiroNodo = desc.primeiroNodo->prox;
  }
}