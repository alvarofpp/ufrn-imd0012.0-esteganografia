#ifndef ARG_H
#define ARG_H

/**
* Funções referentes a argumentação
**/
void help(); // Mensagem de ajuda
void printArgv(int argc, char **argv); // Mostrar os argumentos inseridos pelo terminal
int validateArgv(int argc, char **argv); // Essa função verifica se os argumentos passados são válidos
#include "arg.c"

/**
* Funções dos comandos por argumento
*/
int getParametro(int argc, char **argv, char *argumento);
#include "commands.c"

#endif
