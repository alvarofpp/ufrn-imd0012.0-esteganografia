/**
* Definir o número mágico da imagem.
* Retorna um valor ENUM magic_number.
*/
void defineEnum(char *texto, int *val[3]){
	if(strcmp(texto, "P1") == 0){
		*val[0] = P1;
		*val[1] = ASCII;
		*val[2] = PBM;
	} else if(strcmp(texto, "P2") == 0){
		*val[0] = P2;
		*val[1] = ASCII;
		*val[2] = PGM;
	} else if(strcmp(texto, "P3") == 0){
		*val[0] = P3;
		*val[1] = ASCII;
		*val[2] = PPM;
	} else if(strcmp(texto, "P4") == 0){
		*val[0] = P4;
		*val[1] = BINARY;
		*val[2] = PBM;
	} else if(strcmp(texto, "P5") == 0){
		*val[0] = P5;
		*val[1] = BINARY;
		*val[2] = PGM;
	} else if(strcmp(texto, "P6") == 0){
		*val[0] = P6;
		*val[1] = BINARY;
		*val[2] = PPM;
	}
	
}
