#ifndef IMG_H
#define IMG_H

/**
* Variáveis globais usados para manipulação de imagem
*/
#define MAX_NOME 256 // Tamanho máximo do nome do arquivo

/**
* Structs
*/
// Struct para salvar as informações da imagem
struct PPM {
  int l; // Linhas
  int c; // Colunas
  int maxColor; // Máximo de valor de cor
  unsigned char **m; // Matriz
  char *nomeArquivo; // Nome do arquivo
};

/**
* Typedef referente aos structs acima
*/
typedef struct PPM PPM;

/**
* Funções dos comandos por argumento
*/
int inputFile(char nomeArquivo[MAX_NOME]); // -i [input-file]
#include "commands.c"

/**
* Funções de manipulação/ajuda
*/
void lerComentario(FILE *arq); // Pula as linhas comentadas
int tamanhoNomeArquivo(char *nomeArquivo, int i);
int verificarExtensao(char *extensao);
#include "manipulated.c"

/**
* Funções de manipulação de imagens de modo geral
*/
int validarImagem(char *nomeImagem); // Validar imagem
#include "img.c"

/**
* Funções de manipulação de PPM
*/
int inputFile(char nomeArquivo[MAX_NOME]); // -i [input-file]
#include "ppm.c"

#endif
