#define TRUE 1
#define FALSE 0

enum magic_number {P1, P2, P3, P4, P5, P6}; // Número mágico que indica a extensão e a codificação do arquivo
enum extensao {PBM, PGM, PPM}; // Extensão do arquivo
enum encondig {ASCII, BINARY}; // Codificação do arquivo

// Struct para salvar as informações da imagem, seguido do seu typedef
struct Imagem {
  enum magic_number mgc;
  enum extensao ext;
  enum encondig enc;
  int l;
  int c;
  int **matriz;
};

typedef struct Imagem Imagem;
