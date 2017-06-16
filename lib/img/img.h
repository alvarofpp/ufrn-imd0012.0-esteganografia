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

// Struct e typedef para salvar as informações da imagem BMP
typedef struct
{
  unsigned char fileMarker1[2]; /* 'BM' */
  unsigned char bfSize[4]; /* File's size */
  unsigned char unused1[2];
  unsigned char unused2[2];
  unsigned int imageDataOffset[4]; /* Offset to the start of image data */
} BMPFileHeader;

typedef struct
{
  unsigned int biSize; /* Size of the info header - 40 bytes */
  signed int width; /* Width of the image */
  signed int height; /* Height of the image */
  unsigned short planes;
  unsigned short bitPix;
  unsigned int biCompression;
  unsigned int biSizeImage; /* Size of the image data */
  int biXPelsPerMeter;
  int biYPelsPerMeter;
  unsigned int biClrUsed;
  unsigned int biClrImportant;
} BMPInfoHeader;

/**
* Funções de manipulação de imagens de modo geral
*/
int getExtensao(char *extensao); // Pegar extensão do arquivo
bool checkExtensao(char *extensao); // Checar a extensão do arquivo
bool validateImagem(char *nomeImagem); // Validar imagem
#include "img.c"

/**
* Funções de manipulação de PPM
*/
void readingPPMBin(char *nomeArquivo); // Leitura de PPM P6
void readingPPMAscii(char *nomeArquivo); // Leitura de PPM P3
void readingPPM(char *nomeArquivo); // Primeira etapa da leitura da imagem
bool encodingPPM(char* fileCode, char* fileName);
#include "ppm.c"

/**
* Funções de manipulação de BMP
*/
void readBitmapHeaders(char* nomeImagem, BMPFileHeader *fileheader, BMPInfoHeader *infoheader);
void verification(BMPFileHeader *fileheader, BMPInfoHeader *infoheader);
bool encodingBMP(char* fileCode, char* fileName, BMPFileHeader *fileheader, BMPInfoHeader *infoheader);
#include "bmp.c"

#endif
