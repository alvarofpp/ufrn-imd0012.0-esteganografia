/**
* Pega o código "enum ext" da extensão da imagem.
* Recebe um ponteiro com o nome da imagem.
* Retorna o valor "enum ext" referente a extensão da imagem.
*/
int getExtensao(char *nomeImagem)
{
	int tamanho = lenPalavra(nomeImagem, 0);

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
* Verificar se a extensão da imagem é válida ou não.
* Recebe um ponteiro com os caracteres da extensão da imagem.
* Retorna TRUE se for válido ou FALSE se não for válido.
*/
bool checkExtensao(char *extensao)
{
	if((strcmp(extensao, "ppm") == 0) || (strcmp(extensao, "bmp") == 0))
	{
		return true;
	}
	return false;
}

/**
* Validar a imagem inserida pelo usuário. Verifica a extensão e o tamanho do nome da imagem.
* Recebe um ponteiro com o nome da imagem.
* Retorna TRUE para imagem válida e FALSE para não válida.
*/
bool validateImagem(char *nomeImagem)
{
	// Verifica se o arquivo existe
	FILE *arq; // Arquivo
	arq = fopen(nomeImagem, "r"); // Declara ponteiro de imagem
	if (arq == NULL)
	{
		fprintf(stderr, "Imagem inexistente! \n");
		return false;
	}

	// Verifica o tamanho do nome da imagem
	int tamanho = lenPalavra(nomeImagem, 0);
	if(tamanho > MAX_NOME)
	{
		printf("Nome de imagem inválido! Deve conter, no máximo, %d caracteres.\n", MAX_NOME);
		return false;
	}

	printf("Tamanho do nome do arquivo %s: %d\n", nomeImagem, tamanho);

	// Pega os últimos 3 caracteres do nome da imagem
	char *extensao = malloc(3*sizeof(char));
	extensao[0] = nomeImagem[tamanho-3];
	extensao[1] = nomeImagem[tamanho-2];
	extensao[2] = nomeImagem[tamanho-1];

	// Verifica a extensão da imagem
	if(!checkExtensao(extensao))
	{
		printf("Extensão de imagem inválida! O programa só aceita imagens de extensão .ppm e .bmp.\n");
		return false;
	}

	printf("Extensão %s (codigo: %d)\n", extensao, checkExtensao(extensao));

	return true;
}
