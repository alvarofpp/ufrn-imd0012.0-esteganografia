/**
* Ler arquivo de imagem PPM.
* Retorna FALSE se deu algo errado e TRUE se deu tudo certo
*/
int reading(char nomeImagem[MAX_NOME]){
	PPM ppm;
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

	// Verifica qual tipo de PPM a imagem é
	if(strcmp(cabecalho, "P3") == 0){
		lerComentario(arq);
	} else {

	}

	fclose(arq); // Fecha ponteiro
	return TRUE;
}
