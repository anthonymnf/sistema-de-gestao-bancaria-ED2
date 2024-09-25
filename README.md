# Sistema de Gestão Bancária

Este projeto implementa um sistema de gestão bancária em linguagem C. Ele permite o cadastro, fornecimento e listagem de clientes em uma agência bancária, usando conceitos de alocação dinâmica, ponteiros, manipulação de arquivos e estruturas de dados como árvores. O sistema foi desenvolvido como parte da disciplina Algoritmos e Estruturas de Dados II.

## 🔥 Introdução

O Sistema de Gestão Bancária tem como objetivo facilitar a manipulação de contas e agências bancárias. Ele permite realizar operações como adicionar e listar contas bancárias e também permite adicionar, listar e buscar agências.

### Funcionalidades:

- Cadastro e gerenciamento de clientes e contas bancárias.
- Busca de agências por número.
- Listagem de contas e de agências.
- Persistência de dados em arquivos de texto.

### ⚙️ Pré-requisitos

Para executar o sistema, você precisa:

- Compilador C (por exemplo, GCC).
- Um ambiente de desenvolvimento (Ex: Visual Studio Code).

### 🔨 Guia de instalação

Siga os seguintes passos para rodar o projeto localmente:

1. Clone o repositório do projeto:

   ```bash
   git clone https://github.com/anthonymnf/sistema-de-gestao-bancaria-ED2.git
   ```

2. Compile o código utilizando o GCC:

   ```bash
   gcc -o sistema *.c
   ```

3. Execute o sistema:

   ```bash
   ./sistema
   ```

4. O sistema criará um arquivo `dados.txt` onde as informações das agências e contas bancárias serão armazenadas e persistidas.

## 🛠️ Executando os testes

Para testar as funcionalidades do sistema, execute o programa e siga as opções do menu interativo. Exemplos de funcionalidades que podem ser testadas:

- Cadastrar uma nova agência e uma nova conta bancária.
- Listar todas as agências cadastradas.
- Buscar a agência pelo código para ver todas as informações cadastradas.

## 📦 Tecnologias usadas:

O projeto foi desenvolvido em linguagem C e utiliza estruturas de dados como árvores e manipulação de arquivos.

- ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

### Bibliotecas e Ferramentas:

- [GCC](https://gcc.gnu.org/) - Para compilação do código.
- Manipulação de arquivos `.txt` para persistência de dados.

## 👷 Autores e funções responsáveis

- **Anthony Matheus Nascimento Freitas** - GitMaster e Desenvolvedor - [anthonymnf](https://github.com/anthonymnf)
- **Diego Nascimento de Oliveira** - Desenvolvedor - [diegonascimento2023](https://github.com/diegonascimento2023)
- **Thallys Araujo de Morais** - Redator e Desenvolvedor - [ThallysAM](https://github.com/ThallysAM)
- **Vicente Bento da Silva Neto** - Apresentador e Desenvolvedor - [boycentex](https://github.com/boycentex)

## 📄 Licença

Este projeto está sob a licença MIT - veja o arquivo [LICENSE.md](./LICENSE.md) para mais detalhes.

## 💭 FAQ - Perguntas frequentes

#### Como os dados são armazenados?

Os dados são armazenados em um arquivo de texto (`dados.txt`) que é atualizado conforme as operações no sistema.

#### Como faço para adicionar uma nova agência?

Você pode adicionar uma nova agência e seus clientes através do menu interativo ao executar o sistema.

## 💡 Suporte

Para suporte, entre em contato pelo email anthonymnf30@gmail.com ou através do [LinkedIn](https://www.linkedin.com/in/anthony-matheus).
