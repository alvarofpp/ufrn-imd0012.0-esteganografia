#include <stdio.h>
#include <string.h>
#include "img.h"

int reading(Imagem *picture);{
	//usando o metodo em que a string esta inserida em um arquivo, return 0 se deu algo errado, retorna 1 se deu tudo certo
	FILE *arq;
	arq = fopen(picture.nomeArquivo, "r");
	int i, j;
	if (arq == NULL){
		fprintf(stderr, "This should not happen! \n");
		return 0;
	}
	else{//le o cabeçalho e verifica se não tem nada fora do normal para a extensão do arquivo;
		fscanf(arq, "%s", &picture.mgc);
		if (picture->mgc != 3){//testando se realmente funciona o enum e se é dessa forma
			fprintf(stderr, "Archive with wrong format \n");
			fclose(arq);
			return 0;
		}
		else
			fscanf(arq, "%d %d %d", &picture.l, &picture.c, &picture.mAX);
			if(picture.mAX > MAX){//verifica se o arquivo e maior do que deveria 
				fprintf(stderr, "This archive is bigger than it should! \n");
				fclose(arq);
				return 0;
			}
			else
				for(i = 0; i < picture.l; i++)
					for(j = 0; j < picture.c; j++)
						fscanf(arq, " %d ", &matriz[i][j]);
	}//para mostrar a msg em bits usa-se o terminal(Usando o hexdump no arquivo txt).
	fclose(arq);
	return 1;
}

int main(int argc, char **argv){
	Imagem *img; //struct do formato imagem
	char inserir[MAX_NOME]; //string para recolher a info do usuário
	img.nomeArquivo = scanf("%s", &inserir); //colhendo o nome do arquivo para dentro do struct imagem.
	entering(img); //passando o struct para a função que lê o arquivo PPM


  return 0;
}
