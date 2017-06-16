/**
* Ler a imagem BMP e salva as informações dela
* Recebe o nome do arquivo de iamgem e dois structs usados na manipulação de BMP
*/
void readBitmapHeaders(char* nomeImagem, BMPFileHeader *fileheader, BMPInfoHeader *infoheader)
{
  FILE* arq; // Ponteiro usado para leitura

  arq = fopen(nomeImagem, "rb"); // Ler a imagem em binário

  // Ler as informações do BMP
  fread(fileheader, sizeof(BMPFileHeader), 1, arq);
  fread(infoheader, sizeof(BMPInfoHeader), 1, arq);

  fclose(arq);
}

/**
* Verifica as informações de bitPix e Compression da imagem BMP
* Receve dois structs com informações BMP
*/
void verification(BMPFileHeader *fileheader, BMPInfoHeader *infoheader)
{
  int bitPix = (short)infoheader->bitPix;
  int biCompression = (int16_t)infoheader->biCompression;

  fprintf(stderr, "Valor do bitPix: %d \n", abs(bitPix));
  fprintf(stderr, "Valor do Compression: %d \n", abs(biCompression));
}

/*
* Esconde a mensagem na imagem BMP escolhida
* Recebe o arquivo que conterá o texto, a imagem, o arquivo de saída e dois structs com as informações BMP
* Retorna TRUE caso tudo der certo e FALSE caso aconteça algum erro
*/
bool encodingBMP(char* fileCode, char* fileName, BMPFileHeader *fileheader, BMPInfoHeader *infoheader)
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
  out = fopen("codificado.bmp", "wb+");

  // Verificar se os arquivos existem
  if (!out || !img || !code)
  {
    fprintf(stderr,"Erro ao abrir um dos arquivos!\n");
    return false;
  }

  // Criando a string de array do tamanho da quantidade de pixels
  size_t rowSize = (infoheader->bitPix * infoheader->width + 31)/32 * 4;
  size_t pixelArraySize = rowSize * abs(infoheader->height);
  char* pixelArray = (char*)malloc(pixelArraySize);

  // Lendo a imagem e o arquivo txt
  fseek(img, *fileheader->imageDataOffset, SEEK_CUR);
  fread(pixelArray, sizeof(char), 1, img);
  fseek(code, 0, SEEK_SET);
  fread(coding, sizeof(char), 1, code);

  // Fazendo as trocas de bits
  // Percorre a string do code
  for (int i = 0; i < strlen(coding); i++){
    // Percorre cada bit do char
    for (int j = 8; j >= 0; j--){
      result1 = maskbit & coding[i];
      coding[i]&(1 << j) >> j;
      // Pecorre 8 char para esconder no último o bit de cada bit do segundo for
      for (int k = 0; k < 8 ; k++){
        result2 = maskbit & pixelArray[k];
        if (result1 != 0){
          if (result1 != result2){
            pixelArray[k] = pixelArray[k] ^ maskbit;
          }
        }
        else {
          if(result1 != result2)
          pixelArray[k] = pixelArray[k] | maskbit;
        }
      }
    }
  }

  // Escrevendo tudo isso na imagem nova
  fwrite(fileheader, sizeof(BMPInfoHeader), 1, out);
  fwrite(infoheader, sizeof(BMPFileHeader), 1, out);
  fwrite(pixelArray, sizeof(char), 1, out);

  // Fecha os ponteiros
  fclose(out);
  fclose(img);
  fclose(code);
  return true;
}
