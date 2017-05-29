#ifndef IMG_H
#define IMG_H

#define MAX_NOME 256 //tamanho máximo do nome do arquivo
#define MAX 1080 //tamanho máximo da imagem
//Tratamento da imagem?
enum magic_number {P1 = 1, P2 = 2, P3 = 3, P4 = 4, P5 = 5, P6 = 6}; // Número mágico que indica a extensão e a codificação do arquivo
enum extensao {PBM = 1, PGM = 2, PPM = 3}; // Extensão do arquivo
enum encondig {ASCII, BINARY}; // Codificação do arquivo

// Struct para salvar as informações da imagem, seguido do seu typedef
struct Imagem {
  enum magic_number mgc; //
  enum extensao ext;
  int l; //linhas
  int c; //colunas
  int mgcAX;
  int **matriz; //tamanho da imagem
  char nomeArquivo[1000];
};

//Struct para salvar a codificação dentro do arquivo
struct Encode
{
	enum enconding enc;
	char enc[MAX_NOME];
};

typedef struct Imagem Imagem;
typedef struct Encode Encode;
//int comparandoenum(Imagem *image.ext);//compara o enum e retorna se ele foi lido certo ou não
int escondendo(Imagem *picture, Encode *coding);//esconde a string dentro da imagem.

//Le o arquivo em PPM;
int reading(Imagem *picture){
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

#endif
