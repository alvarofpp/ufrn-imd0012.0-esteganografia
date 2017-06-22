#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main(void)
{
    char type[3];
    int i, offset;
    FILE *oldFile, *newFile;
    long int count; //contar o tamanho de bytes do arquivo inteiro
    unsigned char currentlocation[5];
    unsigned char valpixel = '$';
    unsigned char compress = '\0';


    oldFile = fopen("test_image.bmp", "rb");
    if(oldFile == NULL) {
        fprintf(stderr, "Não pode abrir em leitura binária\n");

    }
    /*
        No caso do BMP ele inicia com BM e depois é tudo binário,
        dai fiz a comparaçao se os dois caracteres sao BM, se sim
        ele começa a fazer a função. Dai se não for, vc altera para
        pedir outro arquivo ou algo do tipo.
    */
    fscanf(oldFile, "%2s", type);
    type[2] = '\0';
    if(strcmp(type, "BM") != 0) {  //Verifica se é bmp
        printf("This file is not of type BMP \n");
    }
    /*
    Verifica o tamanho em bits do arquivo e retorna para formar o array.
    Ele volta para posição 0 do arquivo imagem para que seja tudo inserido
    no array.
    */
    fseek(oldFile, 0, 2);
    count = ftell(oldFile);
    unsigned char currentPixel[count];
    printf("Extensão da imagem: %ld \n", count);
    rewind(oldFile);

    newFile = fopen("copy.bmp", "wb+");

    /*
    Verifica e valida o arquivo bmp, se é 24 bits e se não tem compressão
    Todo cabeçalho contendo as infos do arquivo bmp tem 54 bytes. Dai cada
    bloco tem suas infos particulares.
    */
    fseek(oldFile, 28, 0);// verifica o bloco de bytes contendo BitCount
    fread(&currentlocation, sizeof(unsigned char), 1, oldFile);
    if (currentlocation[0] != valpixel)
    	fprintf(stderr, "Este arquivo não é um .bmp com 24 bits por píxel\n");

   	fseek(oldFile, 30, 0);//verifica o bloco de bytes contendo BiCompress
   	fread(&currentlocation, sizeof(unsigned char), 1, oldFile);
   	if (currentlocation[0] != compress)
   		fprintf(stderr, "Este arquivo .bmp tem compressão\n");
    fseek(oldFile, 10, 0);
    fread(&offset, sizeof(int), 1, oldFile);
    printf("%d \n", offset);
    /*
    Imprime a informação no novo arquivo bmp
    Esse arquivo bmp vai ter as informações após o cabeçalho
    Essa mesma string é a que será usada para poder modificar os bits
    */
    fseek(oldFile, offset, 1);
   	fread(&currentPixel, sizeof(unsigned char), count, oldFile);
   	fwrite(&currentPixel, sizeof(unsigned char), count, newFile);

    printf("\n");
    fclose(newFile);
    fclose(oldFile);

}
