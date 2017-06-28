#ifndef ARG_H
#define ARG_H

/**
* Funções referentes a argumentação
**/
void help(); // Mensagem de ajuda
bool validateArgv(int argc, char **argv); // Essa função verifica se os argumentos passados são válidos

/**
* Funções dos comandos por argumento
*/
int getParametro(int argc, char **argv, char *argumento);

#endif
