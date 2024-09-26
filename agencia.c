#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "agencia.h"

Agencia *criar_agencia(int codigo, const char *nome, const char *localizacao, const char *horario)
{
  Agencia *novaAgencia = (Agencia *)malloc(sizeof(Agencia));
  if (novaAgencia == NULL)
  {
    printf("Erro ao alocar memoria para nova agencia.\n");
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
    printf("Agencia com código %d ja existe.\n", novaAgencia->codigo);
    free(novaAgencia);
  }
}

void listar_agencias(Agencia *raiz)
{
  if (raiz != NULL)
  {
    listar_agencias(raiz->esquerda);
    printf("Agencia: %d, Nome: %s, Localizacao: %s, Horario: %s\n",
           raiz->codigo, raiz->nome, raiz->localizacao, raiz->horario);
    listar_agencias(raiz->direita);
  }
}

// Função para salvar as agencias no arquivo agencias.txt
void salvar_agencias(Agencia *raiz, FILE *file)
{
  if (raiz != NULL)
  {
    salvar_agencias(raiz->esquerda, file); // Salvar agências à esquerda
    fprintf(file, "Agencia %d\tNome:%s\tLocalizacao:%s\tHorario:%s\n",
            raiz->codigo, raiz->nome, raiz->localizacao, raiz->horario);
    salvar_agencias(raiz->direita, file); // Salvar agências à direita
  }
}

Agencia *ler_agencias()
{
  // Abre o arquivo agencias.txt para leitura
  FILE *arquivo = fopen("agencias.txt", "r");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo agencias.txt.\n");
    exit(1); // Sai do programa se ocorrer erro ao abrir o arquivo
  }

  Agencia *raiz_agencias = NULL;
  char linha[256];

  // Lê cada linha do arquivo e extrai os dados da agência
  while (fgets(linha, sizeof(linha), arquivo) != NULL)
  {
    int codigo;
    char nome[51], localizacao[101], horario[20];

    // Analisa a linha e extrai os dados no formato esperado
    sscanf(linha, "Agencia %d\tNome:%50[^\t]\tLocalizacao:%100[^\t]\tHorario:%19[^\n]",
           &codigo, nome, localizacao, horario);

    // Cria uma nova agência com os dados extraídos
    Agencia *novaAgencia = criar_agencia(codigo, nome, localizacao, horario);

    // Insere a nova agência na árvore de agências
    inserir_agencia(&raiz_agencias, novaAgencia);
  }

  // Fecha o arquivo após a leitura
  fclose(arquivo);

  return raiz_agencias;
}

void liberar_agencias(Agencia *raiz)
{
  if (raiz != NULL)
  {
    liberar_agencias(raiz->esquerda);
    liberar_agencias(raiz->direita);
    liberar_contas(raiz->contas);
    free(raiz);
  }
}

void salvar_arquivo(Agencia *raiz, const char *nome_arquivo)
{
  FILE *file = fopen(nome_arquivo, "w");
  if (file)
  {
    salvar_agencias(raiz, file);
    fclose(file);
  }
  else
  {
    printf("Erro ao abrir o arquivo para salvar.\n");
  }
}

Agencia *buscar_agencia(Agencia *raiz, int codigo)
{
  if (raiz == NULL || raiz->codigo == codigo)
    return raiz;
  if (codigo < raiz->codigo)
    return buscar_agencia(raiz->esquerda, codigo);
  else
    return buscar_agencia(raiz->direita, codigo);
}