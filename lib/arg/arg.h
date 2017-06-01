#ifndef ARG_H
#define ARG_H

/**
* Funções
**/
void printArgv(int argc, char **argv); // Mostrar os argumentos inseridos pelo terminal
void help(); // Mensagem de ajuda
int validateArgv(int argc, char **argv); // Essa função verifica se os argumentos passados são válidos
#include "arg.c"

#endif
