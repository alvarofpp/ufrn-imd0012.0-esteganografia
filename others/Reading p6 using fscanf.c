#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    
void main(void)
{
    char type[3];
    int numRow, numCol, maxNum, i;
    FILE *oldFile, *newFile;
    long int count;

    oldFile = fopen("imgp6.ppm", "rb");
    if(oldFile == NULL) {
        fprintf(stderr, "Could not open file for reading in binary");
        
    }
    fscanf(oldFile, "%2s", type);
    type[2] = '\0';
    if(strcmp(type, "P6") != 0) {  //Verifica se é P6
        printf("This file is not of type P6");
        
    }
    /*
    Verifica o tamanho em bits do arquivo e retorna para formar o array.
    */
    fseek(oldFile, 0, SEEK_END);
    count = ftell(oldFile);
    unsigned char currentPixel[count*3];
    printf("%ld", count);
    rewind(oldFile);
    
    newFile = fopen("teste.txt", "wb");
  
    /*Print the information to newFile*/
    fseek(oldFile, 0, SEEK_SET);
    for (i = 0; i < 58; i++){
        fscanf(oldFile, "%c", currentPixel);
        fprintf(newFile, "%c", *currentPixel);
            
        
    }
    printf("\n");
    fclose(newFile);
    fclose(oldFile);
    
}