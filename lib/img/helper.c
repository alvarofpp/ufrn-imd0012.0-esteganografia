/**
* Pega o código "enum ext" da extensão da imagem.
* Recebe um ponteiro com o nome da imagem.
* Retorna o valor "enum ext" referente a extensão da imagem.
*/
int getExtensao(char *nomeImagem){
	int tamanho = lenNomeArquivo(nomeImagem, 0);

	char *extensao = malloc(3*sizeof(char));
	extensao[0] = nomeImagem[tamanho-3];
	extensao[1] = nomeImagem[tamanho-2];
	extensao[2] = nomeImagem[tamanho-1];

	if(strcmp(extensao, "ppm") == 0)
	{
		return extPPM;
	} else {
		return extBMP;
	}
}

/**
* Descobrir o tamanho do nome da imagem.
* Recebe um ponteiro com o nome da imagem e um valor inteiro usado para contagem.
* Retorna o tamanho do nome do arquivo usando recursão.
*/
int lenNomeArquivo(char *nomeArquivo, int i){
	if(nomeArquivo[i] == '\0')
	{
		return 0;
	}
	return 1 + lenNomeArquivo(nomeArquivo, (i+1));
}

/**
* Verificar se a extensão da imagem é válida ou não.
* Recebe um ponteiro com os caracteres da extensão da imagem.
* Retorna TRUE se for válido ou FALSE se não for válido.
*/
int checkExtensao(char *extensao){
	if((strcmp(extensao, "ppm") == 0) || (strcmp(extensao, "bmp") == 0))
	{
		return TRUE;
	}
	return FALSE;
}
