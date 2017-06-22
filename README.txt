-> Grupo
Álvaro Ferreira Pires de Paiva
Gabriel Ribeiro Moura da Costa

-> Como executar o código
.Compilação: gcc main.c
.Execução: ./a.out [argumentos]
.Exemplo: ./a.out -e -i image/imgp3.ppm

-> Arquivos
- main.c - Arquivo principal
- lib/ - Contêm as bibliotecas de código desenvolvidas para o projeto
  - arg/ - Funções e variáveis referentes a validação dos argumentos passados
    - arg.h - Header
    - arg.c - Funções referentes aos argumentos
    - commands.c - Funções dos comandos por argumento
  - img/ - Funções e variáveis referentes a manipulação de imagem
    - img.h - Header
    - img.c - Funções de manipulação de imagens de modo geral
    - ppm.c - Funções de manipulação de PPM
    - bmp.c - Funções de manipulação de BMP
  - global.h - Variáveis globais para todo o código
- image/ - Contêm as imagens que foram usadas para testes nesse trabalho

========== CHECKPOINT 2 ==========
-> Grupo
Álvaro Ferreira Pires de Paiva - Refatorou e padronizou os códigos.
Gabriel Ribeiro Moura da Costa - Escreveu a função de leitura de arquivos BMP.

-> Funcionalidades feitas
.Correta leitura de arquivos PPM P6;
.Correta leitura de arquivos BMP.

-> Funcionalidades não feitas
.Todas as funcionalidades pedidas foram feitas.

========== CHECKPOINT 1 ==========
-> Grupo
Álvaro Ferreira Pires de Paiva - Escreveu os códigos usados para validação dos argumentos e arquivos.
Gabriel Ribeiro Moura da Costa - Escreveu os códigos para leitura das imagens.

-> Funcionalidades feitas
.Função "help", para ajudar a entender o programa;
.Validação dos argumentos passados. É verificado se existe um argumento inválido quanto a todos os argumento e argumentos incorretos (um argumento que não deveria ser usado no método de criptagem ou decriptagem, exemplo: ./a.out -d -r, não existe o "-r" para a decriptagem);
.Validação da imagem passada. É verificado o tamanho do nome da imagem e a extensão;
.Em todas as etapas de validação, caso algo não seja válidado, o usuário é informado o que está incorreto.

-> Funcionalidades não feitas
.Correta leitura de PPM P6.
