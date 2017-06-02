#ifndef IMG_H
#define IMG_H

/**
* Variáveis globais usados para manipulação de imagem
*/
#define MAX_NOME 256 // Tamanho máximo do nome do arquivo

/**
* Structs
*/
// Struct e typedef para salvar as informações da imagem PPM
typedef struct {
    int r, g, b;
} pixel;

typedef struct {
  int l; // Linhas
  int c; // Colunas
  int maxColor; // Máximo de valor de cor
  pixel **matriz; // Matriz
} PPM;

/**
* Funções dos comandos por argumento
*/
int inputFile(char nomeArquivo[MAX_NOME]); // -i [input-file]
#include "commands.c"

/**
* Funções de manipulação/ajuda
*/
void readComentario(FILE *arq); // Pula as linhas comentadas
int tamanhoNomeArquivo(char *nomeArquivo, int i);
int getExtensao(char *extensao);
int checkExtensao(char *extensao);
#include "helper.c"

/**
* Funções de manipulação de imagens de modo geral
*/
int validateImagem(char *nomeImagem); // Validar imagem
#include "img.c"

/**
* Funções de manipulação de PPM
*/
int readingPPM(char nomeArquivo[MAX_NOME]); // -i [input-file]
#include "ppm.c"

#endif
