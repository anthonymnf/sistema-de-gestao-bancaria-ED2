
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
