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