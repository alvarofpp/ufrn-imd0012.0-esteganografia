#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    
void main(void)
{
    char type[3];
    int numRow, numCol, maxNum, i;
    FILE *oldFile, *newFile;
    long int count;

    oldFile = fopen("imgp6.bmp", "rb");
    if(oldFile == NULL) {
        fprintf(stderr, "Could not open file for reading in binary");
        
    }
    /*
        No caso do BMP ele inicia com BM e depois é tudo binário, 
        dai fiz a comparaçao se os dois caracteres sao BM, se sim
        ele começa a fazer a função. Dai se não for, vc altera para
        pedir outro arquivo ou algo do tipo.
    */
    fscanf(oldFile, "%2s", type);
    type[2] = '\0';
    if(strcmp(type, "BM") != 0) {  //Verifica se é P6
        printf("This file is not of type BMP");
        
    }
    /*
    Verifica o tamanho em bits do arquivo e retorna para formar o array.
    Ele volta para posição 0 do arquivo imagem para que seja tudo inserido
    no array. 
    */
    fseek(oldFile, 0, SEEK_END);
    count = ftell(oldFile);
    unsigned char currentPixel[count*3];
    printf("%ld", count);
    rewind(oldFile);
    
    newFile = fopen("teste.txt", "wb");
  
    /*Print the information to newFile*/
    fseek(oldFile, 0, SEEK_SET);
    for (i = 0; i < count; i++){
        fscanf(oldFile, "%c", currentPixel);
        fprintf(newFile, "%c", *currentPixel);
            
        
    }
    printf("\n");
    fclose(newFile);
    fclose(oldFile);
    
}