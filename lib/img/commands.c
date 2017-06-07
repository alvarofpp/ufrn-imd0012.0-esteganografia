/**
* -i [input-file]
* Ler o arquivo de entrada com a mensagem.
* Incompleto
*/
int inputFile(char *nomeArquivo){
	FILE *arq;
	arq = fopen(nomeArquivo, "r"); // Abre ponteiro de arquivo

	// Verifica se o arquivo existe
	if (arq == NULL)
	{
		fprintf(stderr, "Arquivo de entrada não existe!\n");
		return FALSE;
	}

	// Ler as palavras do arquivo
	char texto[100];
	while(fscanf(arq, "%s", texto) != EOF)
	{
		printf("%s\n", texto);
	}

	fclose(arq); // Fecha ponteiro de arquivo

	return TRUE;
}
