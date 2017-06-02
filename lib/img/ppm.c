/**
* Ler arquivo de imagem PPM.
* Retorna FALSE se deu algo errado e TRUE se deu tudo certo
*/
int readingPPM(char nomeImagem[MAX_NOME]){
	FILE *arq; // Arquivo
	arq = fopen(nomeImagem, "rb"); // Declara ponteiro de imagem

	// Verifica se o arquivo existe
	if (arq == NULL){
		fprintf(stderr, "Imagem inexistente! \n");
		return FALSE;
	}

	// Lê o cabeçalho e verifica se não tem nada fora do normal para a extensão do arquivo
	char cabecalho[2];
	fscanf(arq, "%s", cabecalho);

	// Criar struct para manipulação de PPM e coloca as informações padrões
	PPM ppm;
	fscanf(arq, "%d %d", &ppm.c, &ppm.l);
	fscanf(arq, "%d", &ppm.maxColor);
	int i, j;

	ppm.m = malloc((ppm.l*ppm.c)*sizeof(unsigned char));
	printf("Quantidade de bytes a serem lidos: %d\n", (ppm.l*ppm.c));

	int checkCount = fread(&ppm.m[0], sizeof(unsigned char), (ppm.l*ppm.c)*8, arq);
	printf("(ppm.l*ppm.c): %d | checkCount: %d\n", (ppm.l*ppm.c), checkCount);

	// Verifica se ocorreu a leitura normalmente no arquivo
	if(checkCount < (ppm.l*ppm.c)){
		printf("Erro na leitura da imagem.\n");
		return FALSE;
	}

	for (i = 0; i < checkCount; i++){
		printf("i = %d", i);
		if(ppm.m[i] != '\0' && ppm.m[i] != ' '){
			printf(" -- %c", ppm.m[i]);
		}
		printf("\n");
	}
	printf("hue\n");

	// Verifica qual tipo de PPM a imagem é
	if(strcmp(cabecalho, "P3") == 0){
	} else {
	}

	fclose(arq); // Fecha ponteiro
	return TRUE;
}
