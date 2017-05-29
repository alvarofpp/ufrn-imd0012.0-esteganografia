#ifndef IMG_H
#define IMG_H

/**
* Variáveis globais usados para manipulação de imagem
*/
#define MAX_NOME 256 // Tamanho máximo do nome do arquivo
#define MAX_TAMANHO 1080 // Tamanho máximo da imagem

/**
* ENUMs
*/
enum magic_number {P1 = 1, P2, P3, P4, P5, P6}; // Número mágico, que indica a extensão e a codificação do arquivo
enum extensao {PBM = 1, PGM, PPM}; // Extensão do arquivo
enum enconding {ASCII = 1, BINARY}; // Codificação do arquivo

/**
* Structs
*/
// Struct para salvar as informações da imagem
struct Imagem {
  enum magic_number mgc; // Número mágico
  enum extensao ext; // Extensão do arquivo
  int l; // Linhas
  int c; // Colunas
  int **matriz; // Matriz da imagem
  char nomeArquivo[MAX_NOME]; // Nome do arquivo
};
// Struct para salvar a codificação dentro do arquivo
struct Encode
{
  char nomeArquivo[MAX_NOME]; // Texto do arquivo
  enum enconding enc; // Codificação do arquivo
  int **bytes; // Matriz de bytes
};

/**
* Typedef referente aos structs acima
*/
typedef struct Imagem Imagem;
typedef struct Encode Encode;

/**
* Funções de manipulação de imagem
*/
int hiding(Imagem *picture, Encode *coding); // Esconde a string dentro da imagem
int reading(Imagem *picture); // Ler arquivos de imagem
#include "img.c"

/**
* Funções de definição de valores
*/
void defineEnum(char *texto, int *val[3]); // Define o número mágico, extensão e codificação
#include "define.c"

#endif
