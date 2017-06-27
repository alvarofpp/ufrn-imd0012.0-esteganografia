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
* Funções de manipulação de imagens de modo geral
*/
int getExtensao(char *extensao); // Pegar extensão do arquivo
bool checkExtensao(char *extensao); // Checar a extensão do arquivo
bool validateImagem(char *nomeImagem); // Validar imagem

/**
* Funções de manipulação de PPM
*/
void readingPPMBin(char *nomeArquivo); // Leitura de PPM P6
void readingPPMAscii(char *nomeArquivo); // Leitura de PPM P3
void readingPPM(char *nomeArquivo); // Primeira etapa da leitura da imagem
bool encodingPPM(char* fileCode, char* fileName);

#endif
