#ifndef GLOBAL_H
#define GLOBAL_H

#define TRUE 1
#define FALSE 0

// Tipos de extensão
enum ext {extPPM = 1, extBMP};

/*
* Funções globais
*/
int lenPalavra(char *palavra, int i); // Descobrir o tamanho da palavra
#include "global.c"

#endif
