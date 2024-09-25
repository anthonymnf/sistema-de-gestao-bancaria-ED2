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
void inserir_agencia(Agencia **raiz, Agencia *novaAgencia) {
    if (*raiz == NULL) {
        *raiz = novaAgencia;
    } else if (novaAgencia->codigo < (*raiz)->codigo) {
        inserir_agencia(&(*raiz)->esquerda, novaAgencia);
    } else if (novaAgencia->codigo > (*raiz)->codigo) {
        inserir_agencia(&(*raiz)->direita, novaAgencia);
    } else {
        printf("Agência com código %d já existe.\n", novaAgencia->codigo);
        free(novaAgencia);
    }
}

// Busca uma agência pelo código
Agencia *buscar_agencia(Agencia *raiz, int codigo) {
    if (raiz == NULL || raiz->codigo == codigo)
        return raiz;
    if (codigo < raiz->codigo)
        return buscar_agencia(raiz->esquerda, codigo);
    return buscar_agencia(raiz->direita, codigo);
}
