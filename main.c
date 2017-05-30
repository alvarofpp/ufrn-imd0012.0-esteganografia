#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib/global.h"
#include "lib/arg/arg.h"
#include "lib/img/img.h"

int main(int argc, char **argv){
	imprimirArgv(argc, argv);
	if((argc == 1) || (strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)){
		help();
	} else if(validarArgv(argc, argv)){
		if(strcmp(argv[1], "-d") == 0){
		} else {
			if(validarImagem(argv[argc-1])){

			} else {
				exit(EXIT_SUCCESS);
			}
		}
	}

	return 0;
}
