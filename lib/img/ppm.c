/**
* Ler, especificamente, imagem PPM P3.
* Recebe um ponteiro com o nome da imagem.
*/
void readingPPMAscii(char *nomeImagem){
  FILE *arq; // Arquivo
  int i, j; // Contadores
  PPM ppm; // Struct de manipulação
  char cabecalho[2]; // Cabeçalho

  arq = fopen(nomeImagem, "r"); // Declara ponteiro de imagem

  // Lê o cabeçalho
  fscanf(arq, "%s", cabecalho);

  // Criar struct para manipulação de PPM e coloca as informações padrões
  fscanf(arq, "%d %d", &ppm.c, &ppm.l);
  fscanf(arq, "%d", &ppm.maxColor);

  // Aloca o tamanho necessário
  ppm.matriz = malloc((ppm.l)*sizeof(Pixel));
  for(i = 0; i < ppm.l; i++)
  {
    ppm.matriz[i] = malloc((ppm.c)*sizeof(Pixel));
  }

  printf("Quantidade de bytes a serem lidos: %d\n", (ppm.l*ppm.c));

  // Ler a imagem
  for (i = 0; i < ppm.l; i++)
  {
    for (j = 0; j < ppm.c; j++)
    {
      fscanf(arq, "%d", &ppm.matriz[i][j].r);
      fscanf(arq, "%d", &ppm.matriz[i][j].g);
      fscanf(arq, "%d", &ppm.matriz[i][j].b);
    }
  }

  // Imprime os pixels da imagem lida anteriormente
  for (i = 0; i < ppm.l; i++)
  {
    for (j = 0; j < ppm.c; j++)
    {
      printf("%d %d %d ", ppm.matriz[i][j].r, ppm.matriz[i][j].g, ppm.matriz[i][j].b);
    }
    printf("\n");
  }
}

/**
* Ler, especificamente, imagem PPM P6.
* Recebe um ponteiro com o nome da imagem.
*/
void readingPPMBin(char *nomeImagem){
  int numRow, numCol, maxNum; // Informações do arquivo de entrada
  FILE *oldFile; // Arquivo de leitura
  FILE *newFile; // Arquivo de saída
  char cabecalho[2]; // Cabeçalho
  int i; // Contador
  long int count; // Contador

  // Declara o ponteiro da imagem
  oldFile = fopen(nomeImagem, "rb");

  // Lê o cabeçalho
  fscanf(oldFile, "%s", cabecalho);

  // Verifica o tamanho em bits do arquivo e retorna para formar o array
  fseek(oldFile, 0, SEEK_END);
  count = ftell(oldFile);
  unsigned char currentPixel[count*3];
  printf("%ld\n", count);
  rewind(oldFile);

  // Escrita em binário no arquivo
  newFile = fopen("teste.ppm", "wb+");

  // Imprime a informação no novo Arquivo
  fseek(oldFile, 0, SEEK_SET);
  fread(&currentPixel, sizeof(unsigned char), count, oldFile);
  fwrite(&currentPixel, sizeof(unsigned char), count, newFile);

  // Fecha os ponteiros
  fclose(newFile);
  fclose(oldFile);
}


/**
* Ler arquivo de imagem PPM. Redireciona para as funções correspondentes a cada formato.
* Recebe um ponteiro com o nome da imagem.
* Retorna FALSE se deu algo errado e TRUE se deu tudo certo.
*/
int readingPPM(char *nomeImagem)
{
  FILE *arq; // Arquivo
  arq = fopen(nomeImagem, "r"); // Declara ponteiro de imagem

  // Verifica se o arquivo existe
  if (arq == NULL)
  {
    fprintf(stderr, "Imagem inexistente! \n");
    return FALSE;
  }

  // Lê o cabeçalho e verifica se não tem nada fora do normal para a extensão do arquivo
  char cabecalho[2];
  fscanf(arq, "%s", cabecalho); // Ler cabeçalho
  fclose(arq); // Fecha ponteiro

  // Verifica qual tipo de PPM a imagem é
  if(strcmp(cabecalho, "P3") == 0)
  {
    readingPPMAscii(nomeImagem); // P3
  } else {
    readingPPMBin(nomeImagem); // P6
  }

  return TRUE;
}
