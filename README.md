# Sistema de Gestão Bancária

Este projeto implementa um sistema de gestão bancária em linguagem C. Ele permite o cadastro, fornecimento e listagem de clientes em uma agência bancária, usando conceitos de alocação dinâmica, ponteiros, manipulação de arquivos e estruturas de dados como árvores. O sistema foi desenvolvido como parte da disciplina Algoritmos e Estruturas de Dados II.

## 🔥 Introdução

O Sistema de Gestão Bancária foi desenvolvido para simplificar a administração de contas e agências bancárias. Através dele, é possível realizar operações como adicionar e listar tanto contas quanto agências de forma eficiente. Para garantir a persistência dos dados, o sistema armazena as informações em dois arquivos: `agencias.txt`, que contém os registros de todas as agências cadastradas, e `contas.txt`, que armazena os dados das contas bancárias registradas. Isso assegura que nenhuma informação será perdida entre sessões.

### Funcionalidades:

- Cadastro e gerenciamento de clientes e contas bancárias.
- Listagem de agências cadastradas.
- Listagem de todas as contas bancárias cadastradas em uma agência.
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

4. O sistema criará dois arquivos no formato `.txt` onde as informações das agências e contas bancárias serão armazenadas e persistidas.

## 🛠️ Executando os testes

Para testar as funcionalidades do sistema, execute o programa e siga as opções do menu interativo. Exemplos de funcionalidades que podem ser testadas:

- Cadastrar uma nova agência e uma nova conta bancária.
- Listar todas as agências cadastradas.
- Listar todas as contas bancárias cadastradas nessa agência que foi criada.

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

Os dados são armazenados em dois arquivos de texto no formato `.txt` que é atualizado conforme as operações no sistema.

#### Como faço para adicionar uma nova agência?

Você pode adicionar uma nova agência e seus clientes através do menu interativo ao executar o sistema.

## 💡 Suporte

Para suporte, entre em contato pelo email anthonymnf30@gmail.com ou através do [LinkedIn](https://www.linkedin.com/in/anthony-matheus).
