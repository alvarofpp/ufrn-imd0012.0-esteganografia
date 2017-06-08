#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib/global.h"
#include "lib/arg/arg.h"
#include "lib/img/img.h"

int main(int argc, char **argv){
	printArgv(argc, argv);
	if((argc == 1) || (strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)){
		help();
	} else if(validateArgv(argc, argv)){
		if(strcmp(argv[1], "-d") == 0){
		} else {
			if(validateImagem(argv[argc-1])){
				switch(getExtensao(argv[argc-1])){
					case extPPM:
					readingPPM(argv[argc-1]);
					break;
					case extBMP:
					readingBMP(argv[argc-1]);
					break;
				}
			} else {
				exit(EXIT_SUCCESS);
			}
		}
	}

	return 0;
}
