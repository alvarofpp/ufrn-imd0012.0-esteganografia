#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    /*
        Definições de variáveis necessárias;
    */
    char type[3];
    int numRow, numCol, maxNum;
    FILE *oldFile, *newFile;
    long int tamanho, i;

    oldFile = fopen("image/imgp3.ppm", "rb");
    if(oldFile == NULL) {
        fprintf(stderr, "Could not open the file");
        return 0;
    }
    /*
        Determina o tamanho do arquivo em quantos bytes e armazena
        numa variável para poder fazer o malloc(em char)
    */
    fseek(oldFile, 0, SEEK_END);
    tamanho = ftell(oldFile);
    if (tamanho > 0)
        printf("Deu certo, Tamanho do arquivo e: %ld \n", tamanho);

    else
        printf("Alguma coisa ta errada ate aqui \n");
    /*
        Abre o arquivo novo e lê o cabeçalho do arquivo velho, aqui voce pode adaptar
        para botar do jeito dos argv, struct, etc
    */
    newFile = fopen("teste.txt", "wb+");
    fseek(oldFile, 0, SEEK_SET);
    /*
    Ve a linha, coluna e numero máximo assumido para cada cor
    (tu pode trocar pelo struct depois quando for adptar no codigo da gente)
    */
    fscanf(oldFile, "%2s", type);
    fscanf(oldFile, "%d", &numCol);
    fscanf(oldFile, "%d", &numRow);
    fscanf(oldFile, "%d", &maxNum);
    type[3] = '\0';
    /*
    Da um print nas infos do arquivo teste pra ver se ta tudo ok
    (esse mesmo arquivo pode
    ser usado para botar os bytes da msg
    e depois converte-lo para ppm ou pbm)
    */
    fprintf(newFile, "%s\n %d %d\n%d\n", type, numCol, numRow, maxNum);

    unsigned char currentPixel[tamanho];
    fseek(oldFile, 1, SEEK_CUR);
    /*
       fread indo para o ponteiro as infos da stream em cada elemento
       com 3 bytes de char(RGB), assim o v[i] tem 3 infos em char de
       cada RGB. Armazena isso dentro do novo
    */
    fread(currentPixel, 3, 1, oldFile);
    /*
        Verifica se tem algo escrito dentro do vetor, garantindo assim
        que o fread funciona dessa forma.
    */
    for (i = 0; i <= tamanho; i++){
        if(currentPixel[i] == '\0' || currentPixel[i] == ' '){
            continue;
        }
        else
            fprintf(newFile, "%c", currentPixel[i]);
    }
    fclose(newFile);
    fclose(oldFile);
    return 0;
}
