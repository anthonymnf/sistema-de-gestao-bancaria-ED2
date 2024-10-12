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

#define INITIAL_TABLE_SIZE 100

typedef struct HashEntry
{
    int codigo;                // Chave
    Agencia *agencia;          // Ponteiro para a estrutura de agência
    struct HashEntry *proximo; // Para o tratamento de colisões
} HashEntry;

typedef struct HashTable
{
    HashEntry **entradas; // Array de ponteiros para entradas
    int tamanho;          // Tamanho da tabela
    int num_agencias;     // Contador de agências
} HashTable;

// Cria uma nova agência com os parâmetros fornecidos.
Agencia *criar_agencia(int codigo, const char *nome, const char *localizacao, const char *horario);

// Insere uma nova agência na árvore de agências.
void inserir_agencia(Agencia **raiz, Agencia *novaAgencia);

// Busca uma agência pelo código na árvore.
Agencia *buscar_agencia(Agencia *raiz, int codigo);

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

// função para inicializar a tabela hash
HashTable *criar_tabela_hash(int tamanho);

//  função simples de hash
int funcao_hash(int codigo, int tamanho);

// função para Inserir Agências na Tabela Hash
void inserir_agencia_hash(HashTable *tabela, Agencia *agencia);

// função para Listar Agências da Tabela Hash
void listar_agencias_hash(HashTable *tabela);

// função para pegar todas as agências da árvore e inseri-las na tabela hash
void pegar_agencias_da_arvore(Agencia *raiz, HashTable *tabela);

// função para liberar a memória alocada para a tabela hash e suas entradas
void liberar_tabela_hash(HashTable *tabela);
#endif // AGENCIA_H
