-> Grupo
Álvaro Ferreira Pires de Paiva (2016039162)
Gabriel Ribeiro Moura da Costa (20170002032)

-> Como executar o código
.Compilação: gcc main.c
.Execução: ./a.out [argumentos]
.Exemplo: ./a.out -e -i code.txt image/imgp3.ppm

-> Arquivos
- main.c - Arquivo principal
- lib/ - Contêm as bibliotecas de código desenvolvidas para o projeto
  - arg/ - Funções e variáveis referentes a validação dos argumentos passados
    - arg.h - Header
    - arg.c - Funções referentes aos argumentos
  - img/ - Funções e variáveis referentes a manipulação de imagem
    - img.h - Header
    - img.c - Funções de manipulação de imagem
  - global.h - Variáveis globais
  - global.c - Funções globais
- image/ - Contêm as imagens que foram usadas para testes nesse trabalho
- build/ - Necessário para a compilação do projeto

========== CHECKPOINT 3 ==========
-> Grupo
Álvaro Ferreira Pires de Paiva - Refatorou, padronizou e implementou os códigos externos.
Gabriel Ribeiro Moura da Costa - Escreveu a função de codificação de arquivos BMP.

-> Funcionalidades feitas
.Codificação de texto em arquivo BMP;

-> Funcionalidades não feitas
.Codificação de texto em arquivo PPM;

-----> Mensagem para o professor <-----
O grupo atesta que não pode seguir todas as orientações passadas pelo professor,
como também implementar todas as funcionalidades pedidas no checkpoint,
devido a semana ter sido bastante "corrida" para o grupo.

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
