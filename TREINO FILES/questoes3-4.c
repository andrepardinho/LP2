#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//QUESTÃO 3:
int guardaImagem(unsigned char** img, int nLin, int nCol, char* fileName) {
    
    FILE *File = fopen(fileName, "wb");
    if (File == NULL) {
        return 0;
    }

    fwrite(&nLin, sizeof(int), 1, File);
    fwrite(&nCol, sizeof(int), 1, File);

    for (int i = 0; i < nLin; i++) {
        fwrite(img[i], sizeof(unsigned char), nCol, File);
    }

    fclose(File);

    return 1;
}

//QUESTÃO 4:
unsigned char** carregaImagem(int* col, int* lin, char* fileName) {

    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        return NULL;
    }

    fread(lin, sizeof(int), 1, file);
    fread(col, sizeof(int), 1, file);

    unsigned char** img = (unsigned char**) malloc(*lin * sizeof(unsigned char*));

    for (int i = 0; i < *lin; i++) {
        img[i] = (unsigned char*) malloc(*col * sizeof(unsigned char));
        if (img[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(img[j]);
            }
            free(img);
            fclose(file);
            return NULL;
        }
    }

    for (int i = 0; i < *lin; i++) {
        fread(img[i], sizeof(unsigned char), *col, file);
    }

    fclose(file);

    return img;
}


int main () {

    //QUESTÃO 3: Testa a função guardaImagem
    srand(time(NULL));

    unsigned char img[10][10] = {0};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            img[i][j] = rand() % 256;
        }
    }

    unsigned char** imagem = (unsigned char**) malloc(10 * sizeof(unsigned char*));

    for (int i = 0; i < 10; i++) {
        imagem[i] = (unsigned char*) malloc(10 * sizeof(unsigned char));
        for (int j = 0; j < 10; j++) {
            imagem[i][j] = img[i][j];
        }
    }

    printf("Questao 3 - Teste da funcao guardaImagem:\n");

    if (guardaImagem(imagem, 10, 10, "imagem.bin")) {
        printf("Imagem salva com sucesso\n");
    }
    else {
        printf("Erro ao salvar imagem\n");
    }

    //QUESTÃO 4: Testa a função carregaImagem
    printf("\nQuestao 4 - Teste da funcao carregaImagem:\n");

    int col, lin;

    unsigned char** imagemCarregada = carregaImagem(&col, &lin, "imagem.bin");
    
    int dadosCorretos = 1;
    if (imagemCarregada == NULL) {
        printf("Erro ao carregar imagem\n");
    }
    else {
        printf("Imagem carregada com sucesso\n");
        for (int i = 0; i < lin; i++) {
            for (int j = 0; j < col; j++) {
                if (imagemCarregada[i][j] != imagem[i][j]) {
                    dadosCorretos = 0;
                    break;
                }
            }
        }
        if (dadosCorretos) {
            printf("Dados lidos corretamente\n");
        }
        else {
            printf("Dados incorretamente\n");
        }

    }

    for (int i = 0; i < 10; i++) {
        free(imagem[i]);
    }
    free(imagem);

    return 0;
}