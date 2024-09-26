
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contaBancaria.h"

ContaBancaria *criar_conta(int numero, int agenciaNumero, const char *nomeCliente, const char *dataAbertura, float saldo, const char *status)
{
    ContaBancaria *novaConta = (ContaBancaria *)malloc(sizeof(ContaBancaria));
    if (novaConta == NULL)
    {
        printf("Erro ao alocar memoria para nova conta.\n");
        return NULL;
    }
    novaConta->numero = numero;
    novaConta->agenciaNumero = agenciaNumero;
    strcpy(novaConta->nomeCliente, nomeCliente);
    strcpy(novaConta->dataAbertura, dataAbertura);
    novaConta->saldo = saldo;
    strcpy(novaConta->status, status);
    novaConta->esquerda = NULL;
    novaConta->direita = NULL;
    return novaConta;
}


void inserir_conta(ContaBancaria **raiz, ContaBancaria *novaConta)
{
    // Verifica se novaConta é NULL
    if (novaConta == NULL)
    {
        printf("Erro: nova conta é NULL.\n");
        return; // Sai da função se novaConta for NULL
    }

    // Inserção da nova conta
    if (*raiz == NULL)
    {
        *raiz = novaConta; // Se a raiz é NULL, insere a nova conta aqui
    }
    else if (novaConta->numero < (*raiz)->numero)
    {
        inserir_conta(&(*raiz)->esquerda, novaConta); // Insere na subárvore esquerda
    }
    else if (novaConta->numero > (*raiz)->numero)
    {
        inserir_conta(&(*raiz)->direita, novaConta); // Insere na subárvore direita
    }
    else
    {
        printf("A conta com numero %d ja existe.\n", novaConta->numero); // Conta já existente
        free(novaConta);                                                 // Libera a memória da nova conta
    }
}


// Função para salvar as contas no arquivo contas.txt
void salvar_contas(ContaBancaria *raiz, FILE *file)
{
    if (raiz != NULL)
    {
        salvar_contas(raiz->esquerda, file); // Salvar contas à esquerda

        // Salvar a conta atual
        fprintf(file, "Agencia %d\tConta %d\tCliente:%s\tData:%s\tSaldo:%.2f\tStatus:%s\n",
                raiz->agenciaNumero, raiz->numero, raiz->nomeCliente, raiz->dataAbertura,
                raiz->saldo, raiz->status);

        salvar_contas(raiz->direita, file); // Salvar contas à direita
    }
}


