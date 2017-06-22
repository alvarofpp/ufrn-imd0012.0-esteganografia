#include <stdio.h>
#include "libreadbmp.h"
#include <stdlib.h>
#include <string.h>


int ReadBitmapHeaders(char* fileLocation, bmp_fileheader *fileheader, bmp_infoheader *infoheader)
{
    FILE* f;
    f = fopen(fileLocation, "rb");

    if (!f)
    {
        printf("Error opening file %s.\n", fileLocation);
        return 1;
    }
    fread(fileheader, sizeof(bmp_fileheader), 1, f);
    fread(infoheader, sizeof(bmp_infoheader), 1, f);

    fclose(f);

    return 0;
}
int Verification(bmp_infoheader *infoheader, bmp_fileheader *fileheader){

	int bitPix = (short)infoheader->bitPix;
	int biCompression = (int16_t)infoheader->biCompression;

	fprintf(stderr, "Valor do bitPix: %d \n", abs(bitPix));
	fprintf(stderr, "Valor do Compression: %d \n", abs(biCompression));


}

int EncodingAndWriting(char* fileCode, char* fileName, char* fileout, bmp_fileheader *fileheader, bmp_infoheader *infoheader){
	FILE* img;
	FILE* code;
	FILE* out;

	unsigned int maskbit = 0x00000001, result1, result2; //mascara para verificar o ultimo bit e os resultados das operações com os bits
	char coding[256]; //string para receber a mensagem

	code = fopen(fileCode, "rb");
	img = fopen(fileName, "rb");
	out = fopen(fileout, "wb+");
	if (!out || !img || !code)
    {
        fprintf(stderr,"Erro ao abrir um dos arquivos!\n");
        return 1;
    }

	/*
	Criando a string de array do tamanho da quantidade de pixels
	*/
	size_t rowSize = (infoheader->bitPix * infoheader->width + 31)/32 * 4
	size_t pixelArraySize = rowSize * abs(infoheader->height);
	char* pixelArray = (char*)malloc(pixelArraySize);
	/*
	Para criar em PPM não precisa você criar esse malloc com essa config, você apenas implenta isso aqui no lugar devido:

	fseek(arquivodeorigem, 0, 3);
	tamanhodoarquivo = ftell(arquivodeorigem);
	char stringquevocecriar[tamanhodoarquivo];
	fseek(arquivodeorigem, 11, SEEK_CUR) - A partir do 11º byte que começa o array de pixels
	fread(stringquevocecriar, sizeof(char), 1, arquivodeorigem);

	Depois faz o mesmo algoritmo para alterar os bits
	*/

	/*
	Lendo a imagem e o arquivo txt
	*/
	fseek(fileName, *fileheader->imageDataOffset, SEEK_CUR);
	fread(pixelArray, sizeof(char), 1, img);
	fseek(fileCode, 0, SEEK_SET);
	fread(coding, sizeof(char), 1, code);

	/*
	Fazendo as trocas de bits - Primeiro for vai pecorrer a string do code
	Segundo for vai pecorrer cada bit de cada char
	Terceiro for vai pecorrer 8 char de para esconder no ultimo bit cada bit do segundo for
	*/

	for (int i = 0; i < strlen(code); i++){
		for (int j = 8; j >= 0; j--){
			result1 = maskbit & code[i];
			code[i]&(1 << j) >> j;
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


	/*
	Escrevendo tudo isso na imagem nova
	*/

   	fwrite(fileheader, sizeof(bmp_fileheader), 1, out);
    fwrite(infoheader, sizeof(bmp_infoheader), 1, out);
    fwrite(pixelArray, sizeof(char), 1, out);
    fclose(out);
	fclose(img);
	fclose(code);
	return 0;
}
int main()
{
    char* fileLocation = "Bmp_format.bmp";
    char* codeFile = "code.txt";
    char* outFile = "out.bmp";
    bmp_fileheader fileheader;
    bmp_infoheader infoheader;

    printf("%d \n", ReadBitmapHeaders(fileLocation, &fileheader, &infoheader));
    Verification(&infoheader, &fileheader);
    Encoding(codeFile, fileLocation, outFile, &fileheader, &infoheader);
}
