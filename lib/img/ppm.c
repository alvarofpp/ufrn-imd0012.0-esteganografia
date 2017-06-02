void readingPPMAscii(char nomeImagem[MAX_NOME]){
    FILE *arq; // Arquivo
    arq = fopen(nomeImagem, "r"); // Declara ponteiro de imagem

    // Lê o cabeçalho
    char cabecalho[2];
    fscanf(arq, "%s", cabecalho);

    // Criar struct para manipulação de PPM e coloca as informações padrões
    PPM ppm;
    fscanf(arq, "%d %d", &ppm.c, &ppm.l);
    fscanf(arq, "%d", &ppm.maxColor);

    int i, j; // Contadores

    ppm.matriz = malloc((ppm.l)*sizeof(pixel));
    for(i = 0; i < ppm.l; i++)
        ppm.matriz[i] = malloc((ppm.c)*sizeof(pixel));

    printf("Quantidade de bytes a serem lidos: %d\n", (ppm.l*ppm.c));

    // Ler e salva as informações do P3
    for (i = 0; i < ppm.l; i++) {
        for (j = 0; j < ppm.c; j++) {
            fscanf(arq, "%d", &ppm.matriz[i][j].r);
            fscanf(arq, "%d", &ppm.matriz[i][j].g);
            fscanf(arq, "%d", &ppm.matriz[i][j].b);
        }
    }
    // Exibe as informações do P3
    for (i = 0; i < ppm.l; i++) {
        for (j = 0; j < ppm.c; j++) {
            printf("%d %d %d ", ppm.matriz[i][j].r, ppm.matriz[i][j].g, ppm.matriz[i][j].b);
        }
        printf("\n");
    }

    fclose(arq); // Fecha ponteiro
}

void readingPPMBin(char nomeImagem[MAX_NOME]){
    FILE *arq; // Arquivo
    arq = fopen(nomeImagem, "rb"); // Declara ponteiro de imagem

    // Lê o cabeçalho
    char cabecalho[2];
    fscanf(arq, "%s", cabecalho);

    // Criar struct para manipulação de PPM e coloca as informações padrões
    PPMBin ppm;
    fscanf(arq, "%d %d", &ppm.c, &ppm.l);
    fscanf(arq, "%d", &ppm.maxColor);

    int i, j; // Contadores

    ppm.matriz = malloc((ppm.l)*sizeof(unsigned char *));

    fseek(arq, 0, SEEK_END);
    unsigned long len = (unsigned long)ftell(arq);
    fseek(arq, SEEK_SET, 0);

    printf("Quantidade de bytes a serem lidos: %ld\n", len);
    int checkCount = fread(&ppm.matriz[0], sizeof(unsigned char), len, arq);

    // Verifica se ocorreu a leitura normalmente no arquivo
    if(checkCount < len){
        printf("Erro na leitura da imagem.\n");
    }

    FILE *newFile;
    for (i = 0; i <= len; i++){
        if(ppm.matriz[i] != '\0' && ppm.matriz[i] != ' '){
            printf("%c\n", ppm.matriz[i]);
        }
    }

    fclose(arq); // Fecha ponteiro
}

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
    fclose(arq); // Fecha ponteiro

    // Verifica qual tipo de PPM a imagem é
    if(strcmp(cabecalho, "P3") == 0){
        readingPPMAscii(nomeImagem);
    } else {
        readingPPMBin(nomeImagem);
    }

    return TRUE;
}
