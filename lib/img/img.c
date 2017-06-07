/**
* Validar a imagem inserida pelo usuário. Verifica a extensão e o tamanho do nome da imagem.
* Recebe um ponteiro com o nome da imagem.
* Retorna TRUE para imagem válida e FALSE para não válida.
*/
int validateImagem(char *nomeImagem){
	// Verifica o tamanho do nome da imagem
	int tamanho = lenNomeArquivo(nomeImagem, 0);
	if(tamanho > MAX_NOME)
	{
		printf("Nome de imagem inválido! Deve conter, no máximo, %d caracteres.\n", MAX_NOME);
		return FALSE;
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
		return FALSE;
	}

	printf("Extensão %s (codigo: %d)\n", extensao, checkExtensao(extensao));

	return TRUE;
}
