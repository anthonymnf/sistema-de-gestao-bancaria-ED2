#ifndef AGENCIA_H
#define AGENCIA_H
#include "contaBancaria.h"

typedef struct Agencia
{
    int codigo;
    char nome[51];
    char localizacao[101];
    char horario[20];
    ContaBancaria *contas; // Raiz da árvore AVL de contas
    struct Agencia *esquerda;
    struct Agencia *direita;
} Agencia;

Agencia *criar_agencia(int codigo, const char *nome, const char *localizacao, const char *horario);
void inserir_agencia(Agencia **raiz, Agencia *novaAgencia);
Agencia *buscar_agencia(Agencia *raiz, int codigo);
void listar_agencias(Agencia *raiz);
void salvar_agencias(Agencia *raiz, FILE *file);
Agencia *ler_agencias();
void liberar_agencias(Agencia *raiz);
void salvar_arquivo(Agencia *raiz, const char *nome_arquivo);
int verificar_somente_letras(const char *str);
void ler_contas(Agencia *raiz_agencias, FILE *file);

#endif // AGENCIA_H