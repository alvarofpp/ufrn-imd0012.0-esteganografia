#include <stdio.h>
#include <string.h>
#include "lib/global.h"
#include "lib/arg/arg.h"
#include "lib/img/img.h"

int main(int argc, char **argv){
	imprimirArgv(argc, argv);
	if((argc == 1) || (strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)){
		help();
	} else if(verificarArgv(argc, argv)){
		printf("hue\n");
	}

	/*
	Imagem *img; //struct do formato imagem
	char inserir[MAX_NOME]; //string para recolher a info do usuário
	img.nomeArquivo = scanf("%s", &inserir); //colhendo o nome do arquivo para dentro do struct imagem.
	entering(img); //passando o struct para a função que lê o arquivo PPM

	*/
	return 0;
}
