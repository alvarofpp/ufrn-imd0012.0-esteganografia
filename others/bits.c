#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
    Essa função voce pode simplesmente pegar o ponteiro que vai ter as infos do bytes da imagem após
    o cabeçalho (o final do outro código que lê a imagem) ao invés de pegar os dois arquivos como eu
    to fazendo. Essa forma é apenas para minha conferência;
*/
void main(void)
{
  FILE *arq, *mensagem;
  long int i ,j, tamanho1;
  int tamanho2;
  char currentmsg[256];
  
  if ((arq = fopen("copy.bmp", "rb")) != NULL){
    fseek(arq, 0, 2);
    tamanho1 = ftell(arq);
    unsigned char currentpixel[tamanho1];
    fseek(arq, 0, 0);
    fread(&currentpixel, sizeof(unsigned char), tamanho1, arq);
    for(i = 0; i < 10; i++){
      printf("%.2x\n",currentpixel[i]);
        for(j = 7; j >= 0; j--)
          printf("%d", (currentpixel[i]&(1 << j)) >> j);
    printf("\n");
    }
  }
  
  printf("\n");
  printf("----------------------\n");
  printf("----------------------\n");
  printf("----------------------\n");
  printf("\n");
  
  if ((mensagem = fopen("mensagem.txt", "rb")) != NULL){
    fgets(currentmsg, 256, mensagem);
  }
  for(i = 0; i < strlen(currentmsg); i++){
    printf("%c\n", currentmsg[i]); 
    for(j = 7; j >= 0; j--)
      printf("%d", (currentmsg[i]&(1 << j)) >> j);
    printf("\n");
  }

  fclose(mensagem);
  fclose(arq);       
}