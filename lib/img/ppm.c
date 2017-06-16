/**
* Ler, especificamente, imagem PPM P3.
* Recebe um ponteiro com o nome da imagem.
*/
void readingPPMAscii(char *nomeImagem)
{
  FILE *arq; // Arquivo
  arq = fopen(nomeImagem, "r"); // Declara ponteiro de imagem

  // Lê o cabeçalho
  char cabecalho[2];
  fscanf(arq, "%s", cabecalho);

  // Criar struct para manipulação de PPM e coloca as informações padrões
  PPM ppm;
  fscanf(arq, "%d %d", &ppm.c, &ppm.l);
  fscanf(arq, "%d", &ppm.maxColor);

  // Contadores
  int i, j;

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
void readingPPMBin(char *nomeImagem)
{
  int numRow, numCol, maxNum; // Informações do arquivo de entrada
  // Contadores
  int i;
  long int count;

  FILE *oldFile; // Arquivo
  oldFile = fopen(nomeImagem, "rb"); // Declara o ponteiro da imagem

  // Lê o cabeçalho
  char cabecalho[2]; // Cabeçalho da imagem
  fscanf(oldFile, "%s", cabecalho);

  // Verifica o tamanho em bits do arquivo e retorna para formar o array
  fseek(oldFile, 0, SEEK_END);
  count = ftell(oldFile);
  unsigned char currentPixel[count*3];
  printf("%ld\n", count);
  rewind(oldFile);

  FILE *newFile; // Novo arquivo
  newFile = fopen("teste.ppm", "wb"); // Escrita em binário no arquivo

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
void readingPPM(char *nomeImagem)
{
  FILE *arq; // Arquivo
  arq = fopen(nomeImagem, "r"); // Declara ponteiro de imagem

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
}


/*
* Esconde a mensagem na imagem BMP escolhida
* Recebe o arquivo que conterá o texto, a imagem, o arquivo de saída e dois structs com as informações BMP
* Retorna TRUE caso tudo der certo e FALSE caso aconteça algum erro
*/
bool encodingPPM(char* fileCode, char* fileName)
{
  // Arquivos que serão usados
  FILE* img; // Imagem
  FILE* code; // Texto
  FILE* out; // Saída

  unsigned int maskbit = 0x00000001, result1, result2; // Máscara para verificar o último bit e os resultados das operações com os bits
  char coding[256]; // String para receber a mensagem

  // Abrir o ponteiro de cada arquivo
  code = fopen(fileCode, "rb");
  img = fopen(fileName, "rb");
  out = fopen("codificado.ppm", "wb+");

  // Verificar se os arquivos existem
  if (!out || !img || !code)
  {
    fprintf(stderr,"Erro ao abrir um dos arquivos!\n");
    return false;
  }

  // Criando a string de array do tamanho da quantidade de pixels
  fseek(img, 0, 3);
	long int tamanhodoarquivo = ftell(img);
	char texto[tamanhodoarquivo];
	fseek(img, 11, SEEK_CUR); // A partir do 11º byte que começa o array de pixels
	fread(texto, sizeof(char), 1, img);

  // Lendo a imagem
  fread(texto, sizeof(char), 1, img);
  // Lendo o arquivo txt
  fseek(code, 0, SEEK_SET);
  fread(coding, sizeof(char), 1, code);

  int i, j, k; // Contadores
  // Fazendo as trocas de bits
  // Percorre a string do code
  for (i = 0; i < strlen(coding); i++){
    // Percorre cada bit do char
    for (j = 8; j >= 0; j--){
      result1 = maskbit & coding[i];
      coding[i]&(1 << j) >> j;
      // Pecorre 8 char para esconder no último o bit de cada bit do segundo for
      for (k = 0; k < 8 ; k++){
        result2 = maskbit & texto[k];
        if (result1 != 0){
          if (result1 != result2){
            texto[k] = texto[k] ^ maskbit;
          }
        }
        else {
          if(result1 != result2)
          texto[k] = texto[k] | maskbit;
        }
      }
    }
  }

  // Escrevendo tudo isso na imagem nova
  fwrite(texto, sizeof(char), 1, out);

  // Fecha os ponteiros
  fclose(out);
  fclose(img);
  fclose(code);

  return true;
}
