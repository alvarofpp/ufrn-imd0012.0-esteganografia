
/**

* Funções de manipulação de PPM
*/
void readingPPMAscii(char nomeArquivo[MAX_NOME]); // -i [input-file]
void readingPPMBin(char nomeArquivo[MAX_NOME]); // -i [input-file]
int readingPPM(char nomeArquivo[MAX_NOME]); // -i [input-file]

#include "ppm.c"
/**
* -i [input-file]
* Ler o arquivo de entrada.
* Incompleto
*/
int inputFile(char nomeArquivo[MAX_NOME]){
	FILE *arq;
	arq = fopen(nomeArquivo, "r"); // Abre ponteiro de arquivo

	// Verifica se o arquivo existe
	if (arq == NULL){
		fprintf(stderr, "Arquivo de entrada não existe!\n");
		return FALSE;
	}

	// Ler as palavras do arquivo
	char texto[100];
	while(fscanf(arq, "%s", texto) != EOF){
		printf("%s\n", texto);
	}

	fclose(arq); // Fecha ponteiro de arquivo

	return TRUE;
}

/**
* image-file
* Ler a imagem que guardará a mensagem.
*/
int imageFile(char nomeImagem[MAX_NOME]){
	FILE *arq;
	arq = fopen(nomeImagem, "r"); // Abre ponteiro da imagem
	char extensao[3];



	// Verifica se a imagem existe
	if (arq == NULL){
		fprintf(stderr, "Imagem que será usada na criptação não existe!\n");
		return FALSE;
	}

	char code[2];
	int col, lin;
	int max;
	int mgc;

	fscanf(arq, "%s", code);
	fscanf(arq, "%d", &col);
	fscanf(arq, "%d", &lin);
	fscanf(arq, "%d", &max);

	printf("%s\n", code);
	printf("%d %d\n", col, lin);
	printf("%d\n", max);

	fscanf(arq, "%s", code);
	printf("%s\n", code);

	fclose(arq); // Fecha ponteiro de arquivo

	return TRUE;
}
