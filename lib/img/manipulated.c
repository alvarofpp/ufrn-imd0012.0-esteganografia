/**
* Ler e pula as linhas marcadas como comentário
*/
void lerComentario(FILE *arq){
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
int tamanhoNomeArquivo(char nomeArquivo[MAX_NOME], int i){
	if(nomeArquivo[i] == '\0'){
		return 0;
	}

	return 1 + tamanhoNomeArquivo(nomeArquivo, (i+1));
}

/**
* Verificar extensão do arquivo
*/
int verificarExtensao(char *extensao){
	if(strcmp(extensao, "ppm") == 0){
		return 1;
	} else {
		return 2;
	}
}
