#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "agencia.h"

Agencia *criar_agencia(int codigo, const char *nome, const char *localizacao, const char *horario)
{
  Agencia *novaAgencia = (Agencia *)malloc(sizeof(Agencia));
  if (novaAgencia == NULL)
  {
    printf("Erro ao alocar memoria para nova agencia.\n");
    return NULL;
  }
  novaAgencia->codigo = codigo;
  strcpy(novaAgencia->nome, nome);
  strcpy(novaAgencia->localizacao, localizacao);
  strcpy(novaAgencia->horario, horario);
  novaAgencia->contas = NULL;
  novaAgencia->esquerda = NULL;
  novaAgencia->direita = NULL;
  return novaAgencia;
}

void inserir_agencia(Agencia **raiz, Agencia *novaAgencia)
{
  if (*raiz == NULL)
  {
    *raiz = novaAgencia;
  }
  else if (novaAgencia->codigo < (*raiz)->codigo)
  {
    inserir_agencia(&(*raiz)->esquerda, novaAgencia);
  }
  else if (novaAgencia->codigo > (*raiz)->codigo)
  {
    inserir_agencia(&(*raiz)->direita, novaAgencia);
  }
  else
  {
    printf("Agencia com código %d ja existe.\n", novaAgencia->codigo);
    free(novaAgencia);
  }
}

/*void listar_agencias(Agencia *raiz)
{
  if (raiz != NULL)
  {
    listar_agencias(raiz->esquerda);
    printf("Agencia: %d, Nome: %s, Localizacao: %s, Horario: %s\n",
           raiz->codigo, raiz->nome, raiz->localizacao, raiz->horario);
    listar_agencias(raiz->direita);
  }
}*/

// Função para salvar as agencias no arquivo agencias.txt
void salvar_agencias(Agencia *raiz, FILE *file)
{
  if (raiz != NULL)
  {
    salvar_agencias(raiz->esquerda, file); // Salvar agências à esquerda
    fprintf(file, "Agencia %d\tNome:%s\tLocalizacao:%s\tHorario:%s\n",
            raiz->codigo, raiz->nome, raiz->localizacao, raiz->horario);
    salvar_agencias(raiz->direita, file); // Salvar agências à direita
  }
}

Agencia *ler_agencias()
{
  // Abre o arquivo agencias.txt para leitura
  FILE *arquivo = fopen("agencias.txt", "r");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo agencias.txt.\n");
    exit(1); // Sai do programa se ocorrer erro ao abrir o arquivo
  }

  Agencia *raiz_agencias = NULL;
  char linha[256];

  // Lê cada linha do arquivo e extrai os dados da agência
  while (fgets(linha, sizeof(linha), arquivo) != NULL)
  {
    int codigo;
    char nome[51], localizacao[101], horario[20];

    // Analisa a linha e extrai os dados no formato esperado
    sscanf(linha, "Agencia %d\tNome:%50[^\t]\tLocalizacao:%100[^\t]\tHorario:%19[^\n]",
           &codigo, nome, localizacao, horario);

    // Cria uma nova agência com os dados extraídos
    Agencia *novaAgencia = criar_agencia(codigo, nome, localizacao, horario);

    // Insere a nova agência na árvore de agências
    inserir_agencia(&raiz_agencias, novaAgencia);
  }

  // Fecha o arquivo após a leitura
  fclose(arquivo);

  return raiz_agencias;
}

void liberar_agencias(Agencia *raiz)
{
  if (raiz != NULL)
  {
    liberar_agencias(raiz->esquerda);
    liberar_agencias(raiz->direita);
    liberar_contas(raiz->contas);
    free(raiz);
  }
}

void salvar_arquivo(Agencia *raiz, const char *nome_arquivo)
{
  FILE *file = fopen(nome_arquivo, "w");
  if (file)
  {
    salvar_agencias(raiz, file);
    fclose(file);
  }
  else
  {
    printf("Erro ao abrir o arquivo para salvar.\n");
  }
}

Agencia *buscar_agencia(Agencia *raiz, int codigo)
{
  if (raiz == NULL || raiz->codigo == codigo)
    return raiz;
  if (codigo < raiz->codigo)
    return buscar_agencia(raiz->esquerda, codigo);
  else
    return buscar_agencia(raiz->direita, codigo);
}

void listar_contas_agencia(ContaBancaria *raiz, int agenciaNumero)
{
  if (raiz != NULL)
  {
    listar_contas_agencia(raiz->esquerda, agenciaNumero);
    if (raiz->agenciaNumero == agenciaNumero)
    {
      printf("Numero da Conta: %d\tCliente: %s\tData: %s\tSaldo: %.2f\tStatus: %s\n",
             raiz->numero, raiz->nomeCliente, raiz->dataAbertura, raiz->saldo, raiz->status);
    }
    listar_contas_agencia(raiz->direita, agenciaNumero);
  }
}

int verificar_somente_letras(const char *str)
{
  while (*str)
  {
    if (!isalpha(*str) && !isspace(*str))
    {
      return 0; // Retorna 0 se não for letra ou espaço
    }
    str++;
  }
  return 1; // Retorna 1 se todas forem letras ou espaços
}

// Função para ler todas as contas do arquivo contas.txt
void ler_contas(Agencia *raiz_agencias, FILE *file)
{
  int agenciaNumero, numero;
  char nomeCliente[51], dataAbertura[11], status[10];
  float saldo;

  while (fscanf(file, "Agencia %d\tConta %d\tCliente:%50[^\t]\tData:%10[^\t]\tSaldo:%f\tStatus:%9[^\n]\n",
                &agenciaNumero, &numero, nomeCliente, dataAbertura, &saldo, status) == 6)
  {
    // Criar a nova conta lida do arquivo
    ContaBancaria *novaConta = criar_conta(numero, agenciaNumero, nomeCliente, dataAbertura, saldo, status);

    // Encontrar a agência correspondente
    Agencia *agencia = buscar_agencia(raiz_agencias, agenciaNumero);
    if (agencia != NULL)
    {
      // Inserir a conta na árvore de contas da agência encontrada
      inserir_conta(&(agencia->contas), novaConta);
    }
    else
    {
      printf("Agencia %d nao encontrada para a conta %d.\n", agenciaNumero, numero);
    }
  }
}

void buscar_maior_saldo(Agencia *agencia)
{
  Heap heap;
  inicializar_heap(&heap);

  // Percorrer a árvore de contas e inserir cada conta na heap
  if (agencia != NULL)
  {
    percorrer_arvore(agencia->contas, &heap); // Chama a função de percorrer

    // Obter a conta com o maior saldo
    ContaBancaria *contaMaiorSaldo = obter_maior_saldo(&heap);
    if (contaMaiorSaldo != NULL)
    {
      printf("Conta com maior saldo:\n");
      printf("Numero: %d\n", contaMaiorSaldo->numero);
      printf("Agencia: %d\n", contaMaiorSaldo->agenciaNumero);
      printf("Nome do Cliente: %s\n", contaMaiorSaldo->nomeCliente);
      printf("Data de Abertura: %s\n", contaMaiorSaldo->dataAbertura);
      printf("Saldo: %.2f\n", contaMaiorSaldo->saldo);
      printf("Status: %s\n", contaMaiorSaldo->status);
    }
    else
    {
      printf("Nenhuma conta encontrada na agencia.\n");
    }
  }
  else
  {
    printf("Agência não encontrada.\n");
  }
}

HashTable *criar_tabela_hash(int tamanho)
{
  HashTable *tabela = (HashTable *)malloc(sizeof(HashTable));
  tabela->tamanho = tamanho;
  tabela->num_agencias = 0;
  tabela->entradas = (HashEntry **)malloc(tamanho * sizeof(HashEntry *));

  for (int i = 0; i < tamanho; i++)
  {
    tabela->entradas[i] = NULL; // Inicializa todas as entradas como NULL
  }
  return tabela;
}

int funcao_hash(int codigo, int tamanho)
{
  return codigo % tamanho; // Usando o módulo para determinar o índice
}

void inserir_agencia_hash(HashTable *tabela, Agencia *agencia)
{
  if (tabela->num_agencias >= tabela->tamanho)
  {
    // Dobrar o tamanho da tabela se necessário
    int novo_tamanho = tabela->tamanho * 2;
    HashEntry **novas_entradas = (HashEntry **)malloc(novo_tamanho * sizeof(HashEntry *));

    for (int i = 0; i < novo_tamanho; i++)
    {
      novas_entradas[i] = NULL; // Inicializa todas as novas entradas como NULL
    }

    // Rehash de todas as entradas existentes
    for (int i = 0; i < tabela->tamanho; i++)
    {
      HashEntry *atual = tabela->entradas[i];
      while (atual != NULL)
      {
        HashEntry *proximo = atual->proximo; // Armazena próximo
        int novo_indice = funcao_hash(atual->codigo, novo_tamanho);

        atual->proximo = novas_entradas[novo_indice]; // Adiciona na nova tabela
        novas_entradas[novo_indice] = atual;          // Atualiza a entrada
        atual = proximo;                              // Move para o próximo
      }
    }

    free(tabela->entradas);            // Libera a memória da tabela antiga
    tabela->entradas = novas_entradas; // Aponta para a nova tabela
    tabela->tamanho = novo_tamanho;    // Atualiza o tamanho
  }

  int indice = funcao_hash(agencia->codigo, tabela->tamanho);
  HashEntry *nova_entrada = (HashEntry *)malloc(sizeof(HashEntry));
  nova_entrada->codigo = agencia->codigo;
  nova_entrada->agencia = agencia;
  nova_entrada->proximo = tabela->entradas[indice]; // Coloca na lista
  tabela->entradas[indice] = nova_entrada;          // Adiciona a nova entrada
  tabela->num_agencias++;                           // Incrementa o número de agências
}

void listar_agencias_hash(HashTable *tabela)
{
  for (int i = 0; i < tabela->tamanho; i++)
  {
    HashEntry *entrada = tabela->entradas[i];
    while (entrada != NULL)
    {
      printf("Agencia: %d, Nome: %s, Localizacao: %s, Horario: %s\n",
             entrada->agencia->codigo, entrada->agencia->nome,
             entrada->agencia->localizacao, entrada->agencia->horario);
      entrada = entrada->proximo; // Move para o próximo na lista
    }
  }
}

void pegar_agencias_da_arvore(Agencia *raiz, HashTable *tabela)
{
  if (raiz != NULL)
  {
    pegar_agencias_da_arvore(raiz->esquerda, tabela);
    inserir_agencia_hash(tabela, raiz); // Insere a agência na tabela hash
    pegar_agencias_da_arvore(raiz->direita, tabela);
  }
}

void liberar_tabela_hash(HashTable *tabela)
{
  for (int i = 0; i < tabela->tamanho; i++)
  {
    HashEntry *entrada = tabela->entradas[i];
    while (entrada != NULL)
    {
      HashEntry *proximo = entrada->proximo;
      free(entrada); // Libera a entrada
      entrada = proximo;
    }
  }
  free(tabela->entradas); // Libera o array de entradas
  free(tabela);           // Libera a tabela hash
}