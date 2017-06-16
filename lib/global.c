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

void convertIntForByte(int num){
	printf("%d\n", num);
	int i;
	int valor = 128;
	for(i = 0; i < 8; i++)
	{
		if((num - valor) >= 0)
		{
			printf(" 1 ");
			num -= valor;
		}
		else
		{
			printf(" 0 ");
		}
		valor /= 2;
	}
	printf("\n");
}
