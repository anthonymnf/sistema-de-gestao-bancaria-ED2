#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agencia.h"

// Cria uma nova agência
Agencia *criar_agencia(int codigo, const char *nome, const char *localizacao, const char *horario)
{
  Agencia *novaAgencia = (Agencia *)malloc(sizeof(Agencia));
  if (novaAgencia == NULL)
  {
    printf("Erro ao alocar memória para nova agência.\n");
    return NULL;
  }
  novaAgencia->codigo = codigo;
  strcpy(novaAgencia->nome, nome);
  strcpy(novaAgencia->localizacao, localizacao);
  strcpy(novaAgencia->horario, horario);
  novaAgencia->contas = NULL;
  novaAgencia->esquerda = NULL;
  novaAgencia->direita = NULL;
  return novaAgencia;
}

// Insere uma agência na árvore
void inserir_agencia(Agencia **raiz, Agencia *novaAgencia)
{
  if (*raiz == NULL)
  {
    *raiz = novaAgencia;
  }
  else if (novaAgencia->codigo < (*raiz)->codigo)
  {
    inserir_agencia(&(*raiz)->esquerda, novaAgencia);
  }
  else if (novaAgencia->codigo > (*raiz)->codigo)
  {
    inserir_agencia(&(*raiz)->direita, novaAgencia);
  }
  else
  {
    printf("Agência com código %d já existe.\n", novaAgencia->codigo);
    free(novaAgencia);
  }
}

// Busca uma agência pelo código
Agencia *buscar_agencia(Agencia *raiz, int codigo)
{
  if (raiz == NULL || raiz->codigo == codigo)
    return raiz;
  if (codigo < raiz->codigo)
    return buscar_agencia(raiz->esquerda, codigo);
  return buscar_agencia(raiz->direita, codigo);
}

// Lista todas as agências
void listar_agencias(Agencia *raiz)
{
  if (raiz != NULL)
  {
    listar_agencias(raiz->esquerda);
    printf("Agência: %d, Nome: %s, Localização: %s, Horário: %s\n", raiz->codigo, raiz->nome, raiz->localizacao, raiz->horario);
    listar_agencias(raiz->direita);
  }
}

// Salva as agências e suas contas no arquivo
// Exemplo para salvar as agências e contas corretamente
void salvar_agencias(Agencia *raiz, FILE *file)
{
  if (raiz)
  {
    fprintf(file, "Agencia %d\tNome:%s\tLocalizacao:%s\tHorario:%s\n",
            raiz->codigo, raiz->nome, raiz->localizacao, raiz->horario);

    // Chama a função para salvar as contas da agência
    salvar_contas(raiz->contas, file);

    // Chamada recursiva para o próximo nó na árvore
    salvar_agencias(raiz->esquerda, file);
    salvar_agencias(raiz->direita, file);
  }
}

// Lê as agências e suas contas do arquivo
Agencia *ler_agencias(FILE *file)
{
  Agencia *raiz = NULL;
  int codigo;
  char nome[51], localizacao[101], horario[20];
  // Removi a duplicação do código
  while (fscanf(file, "Agencia %d\tNome:%50[^\t]\tLocalizacao:%100[^\t]\tHorario:%19[^\n]\n", &codigo, nome, localizacao, horario) == 4)
  {
    Agencia *novaAgencia = criar_agencia(codigo, nome, localizacao, horario);
    novaAgencia->contas = ler_contas(file); // Lê as contas dessa agência
    inserir_agencia(&raiz, novaAgencia);
  }
  return raiz;
}


// Libera as agências
void liberar_agencias(Agencia *raiz) {
    if (raiz != NULL) {
        liberar_agencias(raiz->esquerda);
        liberar_agencias(raiz->direita);
        liberar_contas(raiz->contas); // Libera a árvore ou lista de contas
        free(raiz);
    }
}