/**
* Pegar código da extensão
*/
int getExtensao(char *nomeImagem){
	int tamanho = tamanhoNomeArquivo(nomeImagem, 0);

	char *extensao = malloc(3*sizeof(char));
	extensao[0] = nomeImagem[tamanho-3];
	extensao[1] = nomeImagem[tamanho-2];
	extensao[2] = nomeImagem[tamanho-1];

	if(strcmp(extensao, "ppm") == 0){
		return extPPM;
	} else {
		return extPPM;
	}
}

/**
* Ler e pula as linhas marcadas como comentário
* FALTA TESTAR
*/
void readComentario(FILE *arq){
	char ver[255];
	fgets(ver, 255, arq);
	if(ver[0] == '#'){
		printf("É um comentário\n");
	} else {
		printf("Não é um comentário\n");
	}
}

/**
* Retorna o tamanho do nome do arquivo usando recursão
*/
int tamanhoNomeArquivo(char *nomeArquivo, int i){
	if(nomeArquivo[i] == '\0'){
		return 0;
	}

	return 1 + tamanhoNomeArquivo(nomeArquivo, (i+1));
}

/**
* Verificar extensão do arquivo
*/
int checkExtensao(char *extensao){
	if((strcmp(extensao, "ppm") == 0) || (strcmp(extensao, "bmp") == 0)){
		return TRUE;
	}
	return FALSE;
}
