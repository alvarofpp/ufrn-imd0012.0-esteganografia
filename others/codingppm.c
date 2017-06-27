#include <stdio.h>
#include <string.h>
#include "ppm6.h"
#include <stdlib.h>
void main(void){

	unsigned int mask = 1;
	char texto[] = "teste";
	int tamanho = strlen(texto);
	ppm6 ppm;
	FILE *arq;
	FILE *out;

	arq = fopen("imgp6.ppm", "rb");
	out = fopen("out.ppm", "wb+");
	fread(&ppm.format, sizeof(unsigned char), 3, arq);
	printf("%s\n", ppm.format);

	fseek(arq, 3, SEEK_SET);
	fscanf(arq, "%d %d", &ppm.l, &ppm.c);
	printf("%d %d\n", ppm.l, ppm.c);
	
	unsigned char *pixels;
	pixels = malloc((ppm.l)*(ppm.c)*3*(sizeof(unsigned char)));
	
	fseek(arq, 11, SEEK_SET);	
	
	fread(pixels, sizeof(unsigned char), 1, arq);


	for(int i = 0; i < (ppm.l*ppm.c*3); i++){

		for(int j = 0; j < tamanho; j++){
			char t = texto[j];

			for(int k = 7; k >= 0; k--){
				if(((t&mask) == 1) && (!(pixels[i]&mask == 1))){
					pixels[i]^=1;
				}else if(!(pixels[i]&mask == 0)){
					pixels[i]|=1;
				}
				t>>=1;			
			}
		}	
	}
	unsigned char cabecalho[11];
	rewind(arq);
	fseek(arq, 0, SEEK_SET);
	fread(cabecalho, sizeof(unsigned char), 1, arq);
	printf("%d\n", strlen(cabecalho));
	fwrite(cabecalho, 11, sizeof(unsigned char), out);
	//fwrite(pixels, sizeof(unsigned char), 1, out);

	fclose(arq);
	fclose(out);
}