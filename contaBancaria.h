#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

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

// Funções para manipulação de contas bancárias
ContaBancaria *criar_conta(int numero, int agenciaNumero, const char *nomeCliente, const char *dataAbertura, float saldo, const char *status);
void inserir_conta(ContaBancaria **raiz, ContaBancaria *novaConta);
void listar_contas_agencia(ContaBancaria *raiz, int agenciaNumero);
void salvar_contas(ContaBancaria *contas, FILE *file);
void liberar_contas(ContaBancaria *raiz);
char le_opcao(int menorValor, int maiorValor);

#endif // CONTABANCARIA_H