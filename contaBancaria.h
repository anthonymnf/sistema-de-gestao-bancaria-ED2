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

#endif // CONTABANCARIA_H
