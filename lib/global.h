#ifndef GLOBAL_H
#define GLOBAL_H

#define BYTE 8

// Tipos de extensão
enum ext {extPPM = 1, extBMP};

/*
* Funções globais
*/
int lenPalavra(char *palavra, int i); // Descobrir o tamanho da palavra
void convertIntForByte(int num);

#endif
