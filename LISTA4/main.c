#include <stdio.h>
#include <stdlib.h>

//Q01: Função que aloca uma imagem 1D
unsigned char* alocaImagem1D (int nLin, int nCol) {

    unsigned char *img = (unsigned char *) malloc(nLin * nCol * sizeof(unsigned char));

    return img;
}

//Q02: Função que aloca uma imagem 2D
unsigned char** alocaImagem2D(unsigned char* img1D, int nLin, int nCol) {

    unsigned char** img2D = (unsigned char **) malloc(nLin * sizeof(unsigned char*));

    if (img2D == NULL) {
        return NULL;
    }

    for (int i = 0; i < nLin; i++) {
        img2D[i] = &img1D[i * nCol]; // para cada linha i, img2D[i] aponta para o início da linha i em img1D
    }

    return img2D;
}

//Q03: Função que gera uma imagem cinza
void geraImgGreyFull_D(unsigned char* img, int nLin, int nCol, unsigned char pixel) {
    
    for (int i = 0; i < nLin * nCol; i++) {
        img[i] = pixel;
    }
}

//Q04:
void geraImgGreyFull_2D(unsigned char** img, int nLin, int nCol, unsigned char pixel) {
    for (int i = 0; i < nLin; i++) {
        for (int j = 0; j < nCol; j++) {
            //img[i][j] = pixel;
            *(*(img + i) + j) = pixel;
        }
    }
}


void geraImgGreyFull_2D(unsigned char** img, int nLin, int nCol, unsigned char pixel);
void geraImgGreyB_D(unsigned char** img, int nLin, int nCol);

// Função auxiliar para imprimir uma imagem 2D (matriz)
void imprimeImagem2D(unsigned char** img, int nLin, int nCol) {
    for (int i = 0; i < nLin; i++) {
        for (int j = 0; j < nCol; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }
}

int main ( ) {

    int nLin = 3, nCol = 3;
    
    // Q01: Aloca imagem 1D
    unsigned char* img1D = alocaImagem1D(nLin, nCol);
    if (img1D == NULL) {
        printf("Erro ao alocar memória para img1D\n");
        return 1;
    }

    for (int i = 0; i < nLin * nCol; i++) {
        img1D[i] = i;
        printf("%d ", img1D[i]);
    }
    printf("\n\n");

    // Q02: Aloca imagem 2D
    unsigned char** img2D = alocaImagem2D(img1D, nLin, nCol);
    if (img2D == NULL) {
        printf("Erro ao alocar memória para img2D\n");
        return 1;
    }
    imprimeImagem2D(img2D, nLin, nCol);


    // Q03: Gera imagem cinza
    geraImgGreyFull_D(img1D, nLin, nCol, 128);
    printf("\nImg preenchida com 128:\n");
    for (int i = 0; i < nLin * nCol; i++) {
        printf("%d ", img1D[i]);
    }

    // Q04: Gera imagem cinza 2D
    geraImgGreyFull_2D(img2D, nLin, nCol, 255);
    printf("\n\nImg2D preenchida com 255:\n");
    imprimeImagem2D(img2D, nLin, nCol);


    return 0;
}