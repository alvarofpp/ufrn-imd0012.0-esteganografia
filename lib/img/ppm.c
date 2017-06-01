/**
* Ler arquivo de imagem PPM.
* Retorna FALSE se deu algo errado e TRUE se deu tudo certo
*/
int readingPPM(char nomeImagem[MAX_NOME]){
	FILE *arq; // Arquivo
	arq = fopen(nomeImagem, "r"); // Declara ponteiro de imagem

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

	int teste;
	//fscanf(arq, "%d", &teste);
	fread(&teste, sizeof(int), 1, arq);

	printf("\nANTES	\n");
	printf("AEIOU: %d\n", teste);
	printf("DEPOIS	\n");

	// Verifica qual tipo de PPM a imagem é
	if(strcmp(cabecalho, "P3") == 0){
	} else {
	}

	fclose(arq); // Fecha ponteiro
	return TRUE;
}
