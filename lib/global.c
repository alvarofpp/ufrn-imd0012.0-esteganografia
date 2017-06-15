/**
* Descobrir o tamanho da palavra.
* Recebe um ponteiro com uma palavra e um valor inteiro usado para contagem.
* Retorna o tamanho da palavra usando recursão.
*/
int lenPalavra(char *palavra, int i)
{
	if(palavra[i] == '\0')
	{
		return 0;
	}
	return 1 + lenPalavra(palavra, (i+1));
}
