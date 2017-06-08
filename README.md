# esteganografia_c
Realizar esteganografia em linguagem C. Projeto da matéria de Introdução as Técnias de Programação, 2017.1, IMD - UFRN.

## Arquivos
- main.c - Arquivo principal
- *lib* - Contêm as bibliotecas de código desenvolvidas para o projeto
  - *arg* - Funções e variáveis referentes a validação dos argumentos passados
    - arg.h - Header
    - arg.c - Funções
  - *img* - Funções e variáveis referentes a manipulação de imagem
    - img.h - Header
    - commands.c - Funções dos comandos por argumento
    - helper.c - Funções de ajuda
    - img.c - Funções de manipulação de imagens de modo geral
    - ppm.c - Funções de manipulação de PPM
    - bmp.c - Funções de manipulação de BMP
  - global.h - Variáveis globais para todo o código
- *image* - Contêm as imagens que foram usadas para testes nesse trabalho
