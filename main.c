#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib/global.h"
#include "lib/arg/arg.h"
#include "lib/img/img.h"

int main(int argc, char **argv)
{
	// Verifica se a função help() foi chamada ou se nenhum argumento foi passado
	if((argc == 1) || (strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0))
	{
		help();
	}
	// Válida os argumentos passados
	else if(validateArgv(argc, argv))
	{
		// Verifica se a imagem é válida
		if(!validateImagem(argv[argc-1]))
		{
			exit(EXIT_SUCCESS);
		}

		// Verifica se o modo selecionado é de decodificação ou codificação
		if(strcmp(argv[1], "-d") == 0)
		{
		}
		else
		{
			int input;
			// Aciona a codificação dependendo da extensão do arquivo
			switch(getExtensao(argv[argc-1]))
			{
				case extPPM:
					readingPPM(argv[argc-1]);
					input = getParametro(argc, argv, "-i"); // Arquivo com o texto
					encodingPPM(argv[input], argv[argc-1]);
				break;
				case extBMP:
				readingBMP(argc, argv);
				break;
			}
		}
	}

	return 0;
}
