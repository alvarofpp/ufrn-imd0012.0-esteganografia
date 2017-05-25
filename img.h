#ifndef img_h
#define img_h

#define TRUE 1
#define FALSE 0
#define MAX_NOME 256 //tamanho máximo do nome do arquivo
#define MAX 1080 //tamanho máximo da imagem
//Tratamento da imagem?
enum magic_number {P1 = 1, P2 = 2, P3 = 3, P4 = 4, P5 = 5, P6 = 6}; // Número mágico que indica a extensão e a codificação do arquivo
enum extensao {PBM = 1, PGM = 2, PPM = 3}; // Extensão do arquivo
enum encondig {ASCII, BINARY}; // Codificação do arquivo

// Struct para salvar as informações da imagem, seguido do seu typedef
struct Imagem {

  enum magic_number mgc; //
  enum extensao ext; 
  int l; //linhas
  int c; //colunas
  int mgcAX;
  int **matriz; //tamanho da imagem
  char nomeArquivo[1000];
};
//Struct para salvar a codificação dentro do arquivo
struct EnCode
{
	enum enconding enc;
	char enc[MAX_NOME];
};
typedef struct Imagem Imagem;
typedef struct EnCode Code;
//int comparandoenum(Imagem *image.ext);//compara o enum e retorna se ele foi lido certo ou não
int reading(Imagem *picture) //Le o arquivo em PPM; 
int escondendo(Imagem *picture, Code *coding);//esconde a string dentro da imagem.

#endif
