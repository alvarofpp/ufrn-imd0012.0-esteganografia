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
} Pixel;

typedef struct {
  int l; // Linhas
  int c; // Colunas
  int maxColor; // Máximo de valor de cor
  Pixel **matriz; // Matriz
} PPM;

/**
* Funções dos comandos por argumento
*/
int inputFile(char *nomeArquivo); // -i [input-file]
#include "commands.c"

/**
* Funções de manipulação/ajuda
*/
int getExtensao(char *extensao);
int checkExtensao(char *extensao);
int lenNomeArquivo(char *nomeArquivo, int i);
#include "helper.c"

/**
* Funções de manipulação de imagens de modo geral
*/
int validateImagem(char *nomeImagem); // Validar imagem
#include "img.c"


/**
* Funções de manipulação de PPM
*/
void readingPPMBin(char *nomeArquivo); // Leitura de PPM P6
void readingPPMAscii(char *nomeArquivo); // Leitura de PPM P3
int readingPPM(char *nomeArquivo); // Primeira etapa da leitura da imagem
#include "ppm.c"

#endif
