#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

typedef struct ContaBancaria {
    int numero;
    int agenciaNumero;  // NÃºmero da agÃªncia
    char nomeCliente[100];
    char dataAbertura[11]; // Formato "DD/MM/AAAA"
    float saldo;
    char status[20]; // Status da conta
    struct ContaBancaria *esquerda;
    struct ContaBancaria *direita;
} ContaBancaria;

// FunÃ§Ãµes para manipulaÃ§Ã£o de contas bancÃ¡rias
ContaBancaria *criar_conta(int numero, int agenciaNumero, const char *nomeCliente, const char *dataAbertura, float saldo, const char *status);
void inserir_conta(ContaBancaria **raiz, ContaBancaria *novaConta);
void listar_contas_agencia(ContaBancaria *raiz, int agenciaNumero);
void salvar_contas(ContaBancaria *raiz, FILE *file);
ContaBancaria *ler_contas(FILE *file);
void liberar_contas(ContaBancaria *raiz);

#endif // CONTABANCARIA_H
