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

// Cria uma nova agência com os parâmetros fornecidos.
Agencia *criar_agencia(int codigo, const char *nome, const char *localizacao, const char *horario);

// Insere uma nova agência na árvore de agências.
void inserir_agencia(Agencia **raiz, Agencia *novaAgencia);

// Busca uma agência pelo código na árvore.
Agencia *buscar_agencia(Agencia *raiz, int codigo);

// Lista todas as agências na árvore.
void listar_agencias(Agencia *raiz);

// Salva todas as agências em um arquivo.
void salvar_agencias(Agencia *raiz, FILE *file);

// Lê as agências de um arquivo.
Agencia *ler_agencias();

// Libera a memória da árvore de agências.
void liberar_agencias(Agencia *raiz);

// Salva as agências em um arquivo com o nome fornecido.
void salvar_arquivo(Agencia *raiz, const char *nome_arquivo);

// Verifica se uma string contém apenas letras.
int verificar_somente_letras(const char *str);

// Lê as contas bancárias de um arquivo e associa às agências.
void ler_contas(Agencia *raiz_agencias, FILE *file);

// Busca uma conta com maior saldo.
void buscar_maior_saldo(Agencia *agencia);


#endif // AGENCIA_H
