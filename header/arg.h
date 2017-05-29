#ifndef ARG_H
#define ARG_H

void imprimirArgv(int argc, char **argv){
  int i;
  printf("ARGC: %d\n", argc);
  for(i = 0; i < argc; i++){
    printf("ARGV[%d] = %s\n", i, argv[i]);
  }
  printf("\n");
}

void help(){
  printf("Comandos aceitos:\n");
  printf(" -d               Executa o programa em modo de decodificador (decoder);\n");
  printf(" -e               Executa programa em modo de codificador (encoder);\n");
  printf(" -f [format]      Indica o formato da imagem.\n");
  printf("                  Valores aceitos: bmp e ppm;\n");
  printf(" -h --help        Mostra a ajuda;\n");
  printf(" -i [input-file]  Indica o arquivo de entrada a ser codificadona imagem;\n");
  printf(" -m [method]      Indica o método de codificação da mensagem.\n");
  printf("                  Valores aceitos: LSB e BPCS;\n");
  printf(" -o [output-file] Indica o arquivo de saída para onde será gravada a mensagem decodificada;\n");
  printf(" -r               Redimensionar a imagem para o menor tamanho possível;\n");
  printf(" -s               Indica que a mensagem decodificada deve ser mostrada na saída padrão.\n");
  printf("                  O uso desta opção inválida o uso da opção -o.\n");
  printf("\n");
  printf("Comandos de codificação: \n");
  printf(" -e, -f [format], -i [input-file], -m [method], -r\n");
  printf("                  Quando uma codificação for acionada, deve-se colocar\n");
  printf("                  um último argumento referindo a imagem que receberá\n");
  printf("                  a mensagem.\n");
  printf("\n");
  printf("Comandos de decodificação: \n");
  printf(" -d, -o [output-file], -s\n");
}

/**
* Essa função verifica se os argumentos passados são válidos.
* O primeiro argumento deve ser, obrigatoriamente, ou -e ou -d.
* Os argumentos -f, -i, -m e -o indicam parametros seguintes.
**/
int verificarArgv(int argc, char **argv){
  // Verifica se o primeiro argumento é válido
  if((strcmp(argv[1], "-d") == 0) || (strcmp(argv[1], "-e") == 0)){
    // Verifica se a quantidade de argumentos é ideal
    int i;

    if(strcmp(argv[1], "-d") == 0){
      for(i = 2; i < argc; i++){
        if((strcmp(argv[i], "-o") == 0)){
          i++;
          continue;
        } else if(strcmp(argv[i], "-s") == 0){
          continue;
        } else {
          printf("Argumento \"%s\" é inválido!\n", argv[i]);
          printf("Argumentos aceitos de decodificação: \n");
          printf(" -o [output-file] Indica o arquivo de saída para onde será gravada a mensagem decodificada;\n");
          printf(" -s               Indica que a mensagem decodificada deve ser mostrada na saída padrão.\n");
          printf("                  O uso desta opção invalida o uso da opção -o.\n");
          return FALSE;
          break;
        }
      }
      return TRUE;
    } else {
      for(i = 2; i < argc; i++){
        if((strcmp(argv[i], "-f") == 0) || (strcmp(argv[i], "-i") == 0) || (strcmp(argv[i], "-m") == 0)){
          i++;
          continue;
        } else if(strcmp(argv[i], "-r") == 0){
          continue;
        } else {
          printf("Argumento \"%s\" é inválido!\n", argv[i]);
          printf("Argumentos aceitos de decodificação: \n");
          printf(" -f [format]      Indica o formato da imagem.\n");
          printf("                  Valores aceitos: bmp e ppm;\n");
          printf(" -i [input-file]  Indica o arquivo de entrada a ser codificadona imagem;\n");
          printf(" -m [method]      Indica o método de codificação da mensagem.\n");
          printf("                  Valores aceitos: LSB e BPCS;\n");
          printf(" -r               Redimensionar a imagem para o menor tamanho possível;\n");
          return FALSE;
          break;
        }
        return TRUE;
      }
    }
  } else {
    printf("Indique como primeiro argumento se o programa deve ser executado em um dos seguinte modos:\n");
    printf(" -d   Executa o programa em modo de decodificador (decoder);\n");
    printf(" -e   Executa programa em modo de codificador (encoder);\n");
    return FALSE;
  }
}

#endif
