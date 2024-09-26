#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agencia.h"
#include <stdbool.h>
#include "contaBancaria.h"

int main()
{
    Agencia *raiz_agencias = NULL;
    FILE *file;

    // Abrir o arquivo de agencias
    file = fopen("agencias.txt", "r");
    if (file)
    {
        raiz_agencias = ler_agencias();
        fclose(file);
    }

    // Abrir o arquivo de contas e ler todas as contas
    file = fopen("contas.txt", "r");
    if (file)
    {
        ler_contas(raiz_agencias, file); // Lê todas as contas e associa às agências
        fclose(file);
    }

    char opcao;             // Armazena a opção verificada
    bool numValido = false; // Variável para verificar se o numero do codigo da agencia fornecido é válido
    char input[50];         // Armazena número como string
    int numAgencia;         //  Variável para armazenar o valor do codigo de uma agência
    int localizacaoValida = 0;  // Variável para verificar se a localização da agência fornecida é válida

    int codigo;
    char nome[51], localizacao[101], horario[20];
    do
    {
        printf("\n\t MENU DE OPCOES \n");
        printf("\n1. ADICIONAR NOVA AGENCIA.");
        printf("\n2. ADICIONAR NOVA CONTA BANCARIA.");
        printf("\n3. LISTAR TODAS AS AGENCIAS.");
        printf("\n4. LISTAR TODAS AS CONTAS DE UMA AGENCIA PELO CODIGO.");
        printf("\n5. SAIR\n");

        opcao = le_opcao('1', '5');

        switch (opcao)
        {
        case '1':
        {

            // Verifica se o numero do codigo da agencia fornecido é válido
            do
            {
                printf("Informe o codigo da agencia: ");
                if (scanf(" %49s", input) != 1)
                {
                    printf("Entrada invalida. Tente novamente.\n");
                    while (getchar() != '\n')
                    {
                        // Limpa o buffer de entrada para evitar loop infinito
                    }
                }
                else if (!entradaContemApenasDigitos(input))
                {
                    printf("Entrada invalida. Apenas numeros sao permitidos. Tente novamente.\n");
                }
                else
                {
                    sscanf(input, "%d", &codigo);
                    numValido = true;
                }
            } while (!numValido);

            printf("Digite o nome da agencia (apenas letras): ");
            scanf(" %[^\n]s", nome);
            limpa_buffer();
            while (!verificar_somente_letras(nome))
            {
                printf("Nome invalido. Digite novamente: ");
                scanf(" %[^\n]s", nome);
                limpa_buffer();
            }

            // Verifica se a localização da agência fornecida é válida
            do
            {
                printf("Informe a localizacao da agencia: ");
                scanf(" %[^\n]", localizacao);
                getchar(); // Limpar o buffer

                localizacaoValida = 1;
                for (int i = 0; localizacao[i] != '\0'; i++)
                {
                    if (!isalpha(localizacao[i]) && !isspace(localizacao[i]))
                    {
                        localizacaoValida = 0;
                        break;
                    }
                }

                if (!localizacaoValida)
                {
                    printf("A localizacao digitada contem caracteres invalidos.\n");
                }
            } while (!localizacaoValida);

            printf("Digite o horario da agencia: ");
            scanf(" %[^\n]s", horario);
            limpa_buffer();

            Agencia *novaAgencia = criar_agencia(codigo, nome, localizacao, horario);
            inserir_agencia(&raiz_agencias, novaAgencia);

            // Salvar as agências no arquivo
            file = fopen("agencias.txt", "w");
            if (file)
            {
                salvar_agencias(raiz_agencias, file);
                fclose(file);
            }
            break;
        }

        case '2':
        {
            int numero, agenciaNumero;
            char nomeCliente[51], dataAbertura[11], status[10];
            float saldo;

            printf("Digite o numero da conta: ");
            scanf("%d", &numero);
            limpa_buffer();

            printf("Digite o numero da agencia: ");
            scanf("%d", &agenciaNumero);
            limpa_buffer();

            // Verificar se a agência existe
            Agencia *agencia = buscar_agencia(raiz_agencias, agenciaNumero);
            if (agencia == NULL)
            {
                printf("Agencia nao encontrada.\n");
                int escolha;
                printf("1. Criar nova agencia\n2. Ver agencias disponiveis\nEscolha uma opcao: ");
                scanf("%d", &escolha);
                limpa_buffer();

                if (escolha == 1)
                {
                    // Lógica para adicionar nova agência (similar ao case 1)
                    // Verifica se o numero do codigo da agencia fornecido é válido
                    do
                    {
                        printf("Informe o codigo da agencia: ");
                        if (scanf(" %49s", input) != 1)
                        {
                            printf("Entrada invalida. Tente novamente.\n");
                            while (getchar() != '\n')
                            {
                                // Limpa o buffer de entrada para evitar loop infinito
                            }
                        }
                        else if (!entradaContemApenasDigitos(input))
                        {
                            printf("Entrada invalida. Apenas numeros sao permitidos. Tente novamente.\n");
                        }
                        else
                        {
                            sscanf(input, "%d", &codigo);
                            numValido = true;
                        }
                    } while (!numValido);

                    printf("Digite o nome da agencia (apenas letras): ");
                    scanf(" %[^\n]s", nome);
                    limpa_buffer();
                    while (!verificar_somente_letras(nome))
                    {
                        printf("Nome invalido. Digite novamente: ");
                        scanf(" %[^\n]s", nome);
                        limpa_buffer();
                    }

                    printf("Digite a localizacao da agencia (apenas letras): ");
                    scanf(" %[^\n]s", localizacao);
                    limpa_buffer();
                    while (!verificar_somente_letras(localizacao))
                    {
                        printf("Localizacao invalida. Digite novamente: ");
                        scanf(" %[^\n]s", localizacao);
                        limpa_buffer();
                    }

                    printf("Digite o horario da agencia: ");
                    scanf(" %[^\n]s", horario);
                    limpa_buffer();

                    Agencia *novaAgencia = criar_agencia(codigo, nome, localizacao, horario);
                    inserir_agencia(&raiz_agencias, novaAgencia);

                    // Salvar as agências no arquivo
                    file = fopen("agencias.txt", "w");
                    if (file)
                    {
                        salvar_agencias(raiz_agencias, file);
                        fclose(file);
                    }
                }
                else if (escolha == 2)
                {
                    listar_agencias(raiz_agencias);
                }
                break;
            }

            if (agencia)
            {
                printf("Digite o nome do cliente: ");
                scanf(" %[^\n]", nomeCliente);
                limpa_buffer();
                printf("Digite a data de abertura (dd/mm/aaaa): ");
                scanf(" %[^\n]", dataAbertura);
                limpa_buffer();
                printf("Digite o saldo: ");
                scanf("%f", &saldo);
                limpa_buffer();
                printf("Digite o status da conta: ");
                scanf(" %[^\n]", status);
                limpa_buffer();

                // Criar a nova conta
                ContaBancaria *novaConta = criar_conta(numero, agenciaNumero, nomeCliente, dataAbertura, saldo, status);
                inserir_conta(&(agencia->contas), novaConta);
                // Quando for salvar as contas, gravar todas de uma vez no arquivo
                file = fopen("contas.txt", "w"); // Usar "w" para sobrescrever o arquivo
                if (file)
                {
                    Agencia *agenciaAtual = raiz_agencias;
                    while (agenciaAtual != NULL)
                    {
                        salvar_contas(agenciaAtual->contas, file);
                        agenciaAtual = agenciaAtual->direita; // Navegar pela árvore de agências
                    }
                    fclose(file);
                }
            }
            break;
        }
        case '3':
            listar_agencias(raiz_agencias); // Exibir todas as agências
            break;
        case '4':
        {
            int codigo_agencia;
            printf("Digite o codigo da agencia: ");
            scanf("%d", &codigo_agencia);

            // Buscar a agência
            Agencia *agencia = buscar_agencia(raiz_agencias, codigo_agencia);
            if (agencia != NULL)
            {
                // Se a agência foi encontrada, listar as contas
                listar_contas_agencia(agencia->contas, codigo_agencia); // Passar as contas da agência
            }
            else
            {
                printf("Agencia nao encontrada.\n");
            }
            break;
        }
        case '5':

            printf("Programa finalizado com sucesso! Obrigado por usar nosso programa.\n");
            break;
        }
    } while (opcao != '5');

    // Liberar a memória alocada para as agências e suas contas
    liberar_agencias(raiz_agencias);

    return 0;
}
