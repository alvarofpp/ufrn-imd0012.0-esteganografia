
/**
* Ler arquivo de imagem BMP.
* Recebe um ponteiro com o nome da imagem.
* Retorna FALSE se deu algo errado e TRUE se deu tudo certo.
*/
int readingBMP(char *nomeImagem){
  char cabecalho[2]; // Cabeçalho
  int i, offset; // Contadores
  FILE *oldFile; // Arquivo de leitura
  FILE *newFile; // Arquivo de saída
  long int count; // Contar o tamanho de bytes do arquivo inteiro
  unsigned char currentlocation[5]; // Array de armazenamento de bits
  const unsigned char valpixel = '$'; // Referência em char do que pegar em hexadecimal
  const unsigned char compress = '\0'; // Verificar compressão

  oldFile = fopen(nomeImagem, "rb");
  if (oldFile == NULL)
  {
    fprintf(stderr, "Não pode abrir em leitura binária\n");
    return FALSE;
  }

  // Ler o cabeçalho
  fscanf(oldFile, "%2s", cabecalho);

  // Tamanho em bits do arquivo
  fseek(oldFile, 0, 2);
  count = ftell(oldFile);

  unsigned char currentPixel[count]; // Cria array para armazenar os bits
  printf("Extensão da imagem: %ld \n", count);
  rewind(oldFile); // Volta para a posição 0 do arquivo

  // Novo arquivo
  newFile = fopen("copy.bmp", "wb+");

  // Verifica o bloco de bytes contendo BitCount
  fseek(oldFile, 28, 0);
  fread(&currentlocation, sizeof(unsigned char), 1, oldFile);
  if (currentlocation[0] != valpixel)
  {
    fprintf(stderr, "Este arquivo não é um .bmp com 24 bits por píxel\n");
    return FALSE;
  }

  // Verifica o bloco de bytes contendo BiCompress
  fseek(oldFile, 30, 0);
  fread(&currentlocation, sizeof(unsigned char), 1, oldFile);
  if (currentlocation[0] != compress)
  {
    fprintf(stderr, "Este arquivo .bmp tem compressão\n");
    return FALSE;
  }

  // Tamanho do cabeçalho
  fseek(oldFile, 10, 0);
  fread(&offset, sizeof(int), 1, oldFile);
  printf("%d \n", offset);

  // Imprime as informações no novo arquivo .bmp
  fseek(oldFile, offset, 1);
  fread(&currentPixel, sizeof(unsigned char), count, oldFile);
  fwrite(&currentPixel, sizeof(unsigned char), count, newFile);

  // Fecha os ponteiros de arquivos
  fclose(newFile);
  fclose(oldFile);

  return TRUE;
}
