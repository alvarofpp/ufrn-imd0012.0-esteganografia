#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib/global.h"
#include "lib/arg/arg.h"
#include "lib/img/img.h"

int main(int argc, char **argv)
{
	printArgv(argc, argv); // Mostrar os argumentos passados

	// Verifica se a função help() foi chamada ou se nenhum argumento foi passado
	if((argc == 1) || (strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0))
	{
		help();
		// Válida os argumentos passados
	}
	else if(validateArgv(argc, argv))
	{
		// Verifica se o modo selecionado é de decodificação ou codificação
		if(strcmp(argv[1], "-d") == 0)
		{
		}
		else
		{
			// Verifica se a imagem é válida
			if(!validateImagem(argv[argc-1]))
			{
				exit(EXIT_SUCCESS);
			}

			// Aciona a codificação dependendo da extensão do arquivo
			switch(getExtensao(argv[argc-1]))
			{
				case extPPM:
					readingPPM(argv[argc-1]);
				break;
				case extBMP:
					// Variáveis usadas
					BMPFileHeader fileheader;
					BMPInfoHeader infoheader;

					// Codificação de BMP
					readBitmapHeaders(argv[argc-1], &fileheader, &infoheader);
					verification(&fileheader, &infoheader);
					int input = getParametro(argc, argv, "-i"); // Arquivo com o texto
					int output = getParametro(argc, argv, "-o"); // Arquivo de saída
					encodingAndWriting(argv[input], argv[argc-1], &fileheader, &infoheader);
				break;
			}
		}
	}

	return 0;
}
