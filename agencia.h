#ifndef AGENCIA_H
#define AGENCIA_H

#include "contaBancaria.h"

typedef struct Agencia {
    int codigo;
    char nome[51];
    char localizacao[101];
    char horario[20];
    ContaBancaria *contas; // Raiz da Ã¡rvore AVL de contas
    struct Agencia *esquerda;
    struct Agencia *direita;
} Agencia;

Agencia *criar_agencia(int codigo, const char *nome, const char *localizacao, const char *horario);
void inserir_agencia(Agencia **raiz, Agencia *novaAgencia);
Agencia *buscar_agencia(Agencia *raiz, int codigo);
void listar_agencias(Agencia *raiz);
void salvar_agencias(Agencia *raiz, FILE *file);
Agencia *ler_agencias(FILE *file);
void liberar_agencias(Agencia *raiz);

#endif // AGENCIA_H
