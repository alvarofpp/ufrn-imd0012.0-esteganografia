#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

/**
* Mostrar os argumentos inseridos pelo terminal. Usados apenas para testes.
* Recebe uma variável com a quantidade de argumentos e outra com os argumentos.
**/
void printArgv(int argc, char **argv)
{
  int i; // Contador
  printf("ARGC: %d\n", argc);

  // Percorre os argumentos
  for(i = 0; i < argc; i++)
  {
    printf("ARGV[%d] = %s\n", i, argv[i]);
  }

  printf("\n");
}

/**
* Função para mostrar mensagem de ajuda.
**/
void help()
{
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
* Recebe uma variável com a quantidade de argumentos e outra com os argumentos.
* Retorna TRUE caso os argumentos sejam válidos ou FALSE caso algum argumento não seja válido.
**/
bool validateArgv(int argc, char **argv)
{
	int opcao; // Opção passada pelo usuário ao programa.
	int indice; // Usado para pegar argumentos que não são opções, nem argumentos usados em opções.

  // Desativa todas as opções por default
	int dflag =  0;
	int eflag =  0;
	int hflag =  0;
	int rflag =  0;
	int sflag =  0;
  char *farg = NULL;
  char *iarg = NULL;
  char *marg = NULL;
  char *oarg = NULL;

	// Desativa as mensagens de erro da função getopt
	opterr = 0;

  // Faz um loop pegando as opções passadas pelo usuário.
  while((opcao = getopt(argc, argv, "dehrsf:i:m:o:")) != -1)
  {
    // Verifica o argumento passado e habilita a opção escolhida
    switch(opcao)
    {
      case 'd':
      dflag = 1;
      break;
      case 'e':
      eflag = 1;
      break;
      case 'h':
      hflag = 1;
      break;
      case 'r':
      rflag = 1;
      break;
      case 's':
      sflag = 1;
      break;
      case 'f':
      farg = optarg;
      break;
      case 'i':
      iarg = optarg;
      break;
      case 'm':
      marg = optarg;
      break;
      case 'o':
      oarg = optarg;
      break;
      case '?':
      if((optopt == 'f') || (optopt == 'i') || (optopt == 'm') || (optopt == 'o'))
      {
				fprintf(stderr, "Opção '-%c' requer um argumento seguinte.\n", optopt);
      } else if(isprint(optopt)) {
				fprintf(stderr, "Opção '-%c' é desconhecida.\n", optopt);
			} else {
				fprintf(stderr, "Caractere '\\x%x' de opção desconhecido.\n", optopt);
			}
      return false;
    }
  }

  /*
  * Após verificar se os argumentos são válidos, é verificado se eles podem
  * ser usados no contexto. Exemplo: O argumento -f não pode ser usado no contexto
  * de decodificação (-d), portanto a setença é inválida.
  */

  // Verifica se o primeiro argumento é válido
  if((strcmp(argv[1], "-d") == 0) || (strcmp(argv[1], "-e") == 0))
  {
    int i; // Verifica se a quantidade de argumentos é ideal

    if(strcmp(argv[1], "-d") == 0)
    {
      for(i = 2; i < argc; i++)
      {
        if((strcmp(argv[i], "-o") == 0))
        {
          i++;
          continue;
        }
        else if(strcmp(argv[i], "-s") == 0)
        {
          continue;
        }
        else
        {
          printf("Argumento \"%s\" é inválido para decodificação!\n", argv[i]);
          printf("Argumentos aceitos de decodificação: \n");
          printf(" -o [output-file] Indica o arquivo de saída para onde será gravada a mensagem decodificada;\n");
          printf(" -s               Indica que a mensagem decodificada deve ser mostrada na saída padrão.\n");
          printf("                  O uso desta opção invalida o uso da opção -o.\n");
          return false;
          break;
        }
      }
      return true;
    }
    else
    {
      for(i = 2; i < argc; i++)
      {
        if((strcmp(argv[i], "-f") == 0) || (strcmp(argv[i], "-i") == 0) || (strcmp(argv[i], "-m") == 0))
        {
          i++;
          continue;
        }
        else if((strcmp(argv[i], "-r") == 0) || (i = (argc-1)))
        {
          continue;
        }
        else
        {
          printf("Argumento \"%s\" é inválido para codificação!\n", argv[i]);
          printf("Argumentos aceitos de codificação: \n");
          printf(" -f [format]      Indica o formato da imagem.\n");
          printf("                  Valores aceitos: bmp e ppm;\n");
          printf(" -i [input-file]  Indica o arquivo de entrada a ser codificadona imagem;\n");
          printf(" -m [method]      Indica o método de codificação da mensagem.\n");
          printf("                  Valores aceitos: LSB e BPCS;\n");
          printf(" -r               Redimensionar a imagem para o menor tamanho possível;\n");
          return false;
          break;
        }
        return true;
      }
    }
  }
  else
  {
    printf("Indique como primeiro argumento se o programa deve ser executado em um dos seguinte modos:\n");
    printf(" -d   Executa o programa em modo de decodificador (decoder);\n");
    printf(" -e   Executa programa em modo de codificador (encoder);\n");
    return false;
  }
}

/**
* -i [input-file] | -f [format] | -m [metodo] | -o [output-file]
*/
int getParametro(int argc, char **argv, char *argumento)
{
	int i; // Contador

  for(i = 0; i < argc; i++)
  {
		if(strcmp(argv[i], argumento) == 0){
			return i+1;
		}
  }

	return 0;
}
