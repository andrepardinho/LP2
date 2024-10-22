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

//Q05: Função que preenche todos os pixels da img com 0
void geraImgGreyB_D(unsigned char** img, int nLin, int nCol) {
    geraImgGreyFull_2D(img, nLin, nCol, 0);
}

//Q06: Questao 5, mas a img fornecida é um ponteiro para um array 1D
void geraImgGreyB_1D(unsigned char* img, int nLin, int nCol) {
    geraImgGreyFull_D(img, nLin, nCol, 0);
}

//Q07: Função que preenche todos os pixels da img com 255
void geraImgGreyW_D(unsigned char** img, int nLin, int nCol) {
    geraImgGreyFull_2D(img, nLin, nCol, 255);
}

geraPixelGrey (unsigned char** img, int nLin, int nCol, int i, int j) {
    if (i >= 0 && i < nLin && j >= 0 && j < nCol) {
        return img[i][j];
    }
    return 0;
}

unsigned char geraPixelGray(int tipo) {
    int valorAleatorio = rand() % 256; // Gera um valor entre 0 e 255

    if (tipo < 0) {
        // Intensidades mais escuras (0-127) têm maior probabilidade
        if (valorAleatorio < 128) {
            return (unsigned char)(valorAleatorio / 2); // Aumenta a probabilidade de valores menores
        } else {
            return (unsigned char)(valorAleatorio);
        }
    } else if (tipo > 0) {
        // Intensidades mais claras (128-255) têm maior probabilidade
        if (valorAleatorio >= 128) {
            return (unsigned char)(128 + (valorAleatorio / 2)); // Aumenta a probabilidade de valores maiores
        } else {
            return (unsigned char)(valorAleatorio);
        }
    } else {
        // Todas as intensidades têm a mesma probabilidade
        return (unsigned char)(valorAleatorio);
    }
}

//Q08: Preenche a imagem com valores aleatórios usando geraPixelGray
 void geraImgGrey_D(unsigned char** img, int nLin, int nCol, int tipo) {
    for (int i = 0; i < nLin; i++) {
        for (int j = 0; j < nCol; j++) {
            img[i][j] = geraPixelGray(tipo);
        }
    }
 }

//Q09: Função que retorna o menor pixel da imagem
 int pixelMax_D(unsigned char** img, int nLin, int nCol) {
    int max = img[0][0];
    for (int i = 0; i < nLin; i++) {
        for (int j = 0; j < nCol; j++) {
            if (img[i][j] > max) {
                max = img[i][j];
            }
        }
    }
    return max;
 }

// Q10: Função que retorna o menor pixel da imagem
 int pixelMin_D(unsigned char** img, int nLin, int nCol) {
    int min = img[0][0];
    for (int i = 0; i < nLin; i++) {
        for (int j = 0; j < nCol; j++) {
            if (img[i][j] < min) {
                min = img[i][j];
            }
        }
    }
    return min;
 }

int* somaPorLinhas_D(unsigned char** img, int nLin, int nCol);
int* somaPorColunas_D(unsigned char** img, int nLin, int nCol);
int somaTotal_R(unsigned char** img, int nLin, int nCol);
int quantosPixelsNaInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten);
int quantosPixelsAbaixoDeInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten);


// Função auxiliar para imprimir uma imagem 2D (matriz)
void imprimeImagem2D(unsigned char** img, int nLin, int nCol) {
    for (int i = 0; i < nLin; i++) {
        for (int j = 0; j < nCol; j++) {
            printf("%3d ", img[i][j]);
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

    // Q05: Gera imagem cinza 2D com 0
    geraImgGreyB_D(img2D, nLin, nCol);
    printf("\n\nImg2D preenchida com 0:\n");
    imprimeImagem2D(img2D, nLin, nCol);

    // Q06: Gera imagem cinza 1D com 0
    geraImgGreyB_1D(img1D, nLin, nCol);
    printf("\n\nImg1D preenchida com 0:\n");
    for (int i = 0; i < nLin * nCol; i++) {
        printf("%d ", img1D[i]);
    }

    // Q08: Gera imagem cinza 2D com valores aleatórios usando geraPixelGray
    geraImgGrey_D(img2D, nLin, nCol, 0);
    printf("\n\nImg2D preenchida com valores aleatorios:\n");
    imprimeImagem2D(img2D, nLin, nCol);


    return 0;
}