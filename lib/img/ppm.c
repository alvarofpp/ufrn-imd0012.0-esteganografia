/**
* Ler arquivo de imagem PPM.
* Retorna FALSE se deu algo errado e TRUE se deu tudo certo
*/
int readingPPM(char nomeImagem[MAX_NOME]){
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


    // Criar struct para manipulação de PPM e coloca as informações padrões
    PPM ppm;
    fscanf(arq, "%d %d", &ppm.c, &ppm.l);
    fscanf(arq, "%d", &ppm.maxColor);

    // Verifica qual tipo de PPM a imagem é
    if(strcmp(cabecalho, "P3") == 0){
        int i, j;

        ppm.matriz = malloc((ppm.l)*sizeof(pixel));
        for(i = 0; i < ppm.l; i++)
            ppm.matriz[i] = malloc((ppm.c)*sizeof(pixel));

        printf("Quantidade de bytes a serem lidos: %d\n", (ppm.l*ppm.c));

        for (i = 0; i < ppm.l; i++) {
            for (j = 0; j < ppm.c; j++) {
                fscanf(arq, "%d", &ppm.matriz[i][j].r);
                fscanf(arq, "%d", &ppm.matriz[i][j].g);
                fscanf(arq, "%d", &ppm.matriz[i][j].b);
            }
        }
        for (i = 0; i < ppm.l; i++) {
            for (j = 0; j < ppm.c; j++) {
                printf("%d %d %d ", ppm.matriz[i][j].r, ppm.matriz[i][j].g, ppm.matriz[i][j].b);
            }
            printf("\n");
        }
    }else {
	if (strcmp(cabecalho, "P6") == 0){
		long int count;   
		fseek(nomeImagem, 0, SEEK_END);
		count = ftell(nomeImagem);
        if (count > 0){
            fseek(oldFile, 0, SEEK_SET);
            unsigned char currentPixel[count*3];
            count = 0;
            while(fread(currentPixel, sizeof(char)*3, 1, oldFile))
                printf("%d %d %d", currentPixel[i]);    
                count++;
        }
        	
		
	
	}	
    }

    fclose(arq); // Fecha ponteiro
    return TRUE;
}