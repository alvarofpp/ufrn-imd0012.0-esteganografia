#ifndef ARG_H
#define ARG_H

/**
* Funções
**/
void imprimirArgv(int argc, char **argv); // Mostrar os argumentos inseridos pelo terminal
void help(); // Mensagem de ajuda
int verificarArgv(int argc, char **argv); // Essa função verifica se os argumentos passados são válidos
#include "arg.c"

#endif
