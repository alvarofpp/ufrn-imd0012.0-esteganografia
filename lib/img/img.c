/**
* Cria um struct de Imagem.
* Recebe os valores do struct Imagem.
* Retorna ums struct Imagem
*/
Imagem createImagem(enum magic_number mgc, enum extensao ext, int l, int c, int **matriz, char nomeArquivo[MAX_NOME]){

}

/**
* Ler arquivos de imagem.
* Retorna FALSE se deu algo errado e TRUE se deu tudo certo
*/
int reading(Imagem *picture){
	FILE *arq; // Arquivo
	arq = fopen(picture->nomeArquivo, "r");
	// Verifica se o arquivo existe
	if (arq == NULL){
		fprintf(stderr, "Arquivo inexistente! \n");
		return FALSE;
	}

	int i, j; // Contadores
	else{//le o cabeçalho e verifica se não tem nada fora do normal para a extensão do arquivo;
		fscanf(arq, "%s", picture->mgc);
		if (picture->mgc != 3){
			fprintf(stderr, "Archive with wrong format \n");
			fclose(arq);
			return FALSE;
		}
		else
			fscanf(arq, "%d %d %d", &picture->l, &picture->c, &picture->mAX);
			if(picture->mAX > MAX){//verifica se o arquivo e maior do que deveria
				fprintf(stderr, "This archive is bigger than it should! \n");
				fclose(arq);
				return FALSE;
			}
			else
				for(i = 0; i < picture->l; i++)
					for(j = 0; j < picture->c; j++)
						fscanf(arq, " %d ", &picture->matriz[i][j]);
	}//para mostrar a msg em bits usa-se o terminal(Usando o hexdump no arquivo txt).
	fclose(arq);
	return TRUE;
}
