#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct ContaBancaria
{
    int numero;
    int agenciaNumero; // Número da agência
    char nomeCliente[100];
    char dataAbertura[11]; // Formato "DD/MM/AAAA"
    float saldo;
    char status[20]; // Status da conta
    struct ContaBancaria *esquerda;
    struct ContaBancaria *direita;
} ContaBancaria;

#define MAX_HEAP_SIZE 100 // Tamanho máximo da heap (pode ser ajustado)

typedef struct Heap
{
    ContaBancaria *contas[MAX_HEAP_SIZE];
    int tamanho; // Número atual de contas na heap
} Heap;


// Cria uma nova conta bancária com os parâmetros fornecidos.
ContaBancaria *criar_conta(int numero, int agenciaNumero, const char *nomeCliente, const char *dataAbertura, float saldo, const char *status);

// Insere uma nova conta bancária na árvore de contas.
void inserir_conta(ContaBancaria **raiz, ContaBancaria *novaConta);

// Lista todas as contas de uma agência específica.
void listar_contas_agencia(ContaBancaria *raiz, int agenciaNumero);

// Salva todas as contas bancárias em um arquivo.
void salvar_contas(ContaBancaria *contas, FILE *file);

// Libera a memória da árvore de contas bancárias.
void liberar_contas(ContaBancaria *raiz);

// Lê uma opção entre um intervalo de valores.
char le_opcao(int menorValor, int maiorValor);

// Limpa o buffer de entrada.
void limpa_buffer(void);

// Verifica se a entrada contém apenas dígitos.
bool entradaContemApenasDigitos(const char *entrada);

// Função para inicializar a heap
void inicializar_heap(Heap *heap);

// Função para inserir uma conta na heap
void inserir_heap(Heap *heap, ContaBancaria *conta);

// Função para obter a conta com o maior saldo (a raiz da heap)
ContaBancaria *obter_maior_saldo(Heap *heap);

// Função recursiva para percorrer a árvore
void percorrer_arvore(ContaBancaria *raiz, Heap *heap);


#endif // CONTABANCARIA_H
