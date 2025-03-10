#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned char uchar;

// Estrutura de um pixel em RGB
typedef struct { 
    uchar R, G, B;
} tRGB;

// Estrutura de uma imagem em tons de cinza
typedef struct {
    uchar *_img; //ponteiro para um array unidimen que armazena os pixels da imagem em um único bloco de memória
    uchar **img; // ponteiro para um array de ponteiros que apontam para o início de cada linha da imagem. Matriz.
    int nLin, nCol;
} imgGray;

// Estrutura de uma imagem em RGB
typedef struct {
    tRGB *_img; // cada pixel é um tRGB e contem 3 componentes: R, G e B.
    tRGB **img;
    int nLin, nCol;
} imgRGB;

struct imagens {
    imgGray img;
    struct imagens *prox;
};

typedef struct imagens tImagens;

void freeImagemGray(imgGray *picture) {
    if (picture->img != NULL) {
        free(picture->img);
        picture->img = NULL;
    }

    if (picture->_img != NULL) {
        free(picture->_img);
        picture->_img = NULL;
    }
}

void freeImagemRGB(imgRGB *picture) {
    if (picture->img != NULL) {
        free(picture->img);
        picture->img = NULL;
    }

    if (picture->_img != NULL) {
        free(picture->_img);
        picture->_img = NULL;
    }
}

// Q01: Função que aloca uma imagem em tons de cinza
imgGray alocaImagemGray(int nLin, int nCol) {
    imgGray picture;
    picture.nLin = nLin;
    picture.nCol = nCol;

    // Alocando meroria para array unidimensional
    picture._img = (uchar *) malloc(nLin * nCol * sizeof(uchar));
    if (picture._img == NULL) {
        picture.img = NULL; // 
        return picture;
    }

    // Alocando memoria para array de ponteiros
    picture.img = (uchar **) malloc(nLin * sizeof(uchar *));
    if (picture.img == NULL) {
        free(picture._img); //libera mem q foi alocada para o array unidimensional
        picture._img = NULL;
        return picture;
    }
    
    //Mapear a matriz guardada como array em picture._img. no array de ponteiros em picture.img
    for (int i = 0; i < nLin; i++) {
        picture.img[i] = &picture._img[i * nCol];
    }

    return picture;
}

// Q02: Função que aloca uma imagem em RGB
imgRGB alocaImagemRGB(int nLin, int nCol) {
    imgRGB picture;
    picture.nLin = nLin;
    picture.nCol = nCol;

    // Alocando meroria para array unidimensional
    picture._img = (tRGB *) malloc(nLin * nCol * sizeof(tRGB));
    if (picture._img == NULL) {
        picture.img = NULL; // 
        return picture;
    }

    // Alocando memoria para array de ponteiros
    picture.img = (tRGB **) malloc(nLin * sizeof(tRGB *));
    if (picture.img == NULL) {
        free(picture._img);
        picture._img = NULL;
        return picture;
    }

    for (int i = 0; i < nLin; i++) {
        picture.img[i] = &picture._img[i * nCol];
    }

    return picture;
}

// Q03: Preenche a imagem em tons de cinza com um valor de pixel
int geraImgGrayFull(imgGray img, uchar pixel) {
    if (img.img == NULL) {
        return false;
    }

    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            img.img[i][j] = pixel;
        }
    }

    return true;
}

// Q04: Preenche a imagem em RGB com um valor de pixel
int geraImgRGBFull(imgRGB img, tRGB pixel) {
    if (img.img == NULL) {
        return false;
    }

    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            img.img[i][j] = pixel;
        }
    }

    return true;
}



int main () {
    int nLin = 480, nCol = 640;
    
    // Q01: Aloca imagem em tons de cinza
    imgGray picture1 = alocaImagemGray(nLin, nCol);
    if (picture1.img == NULL) {
        printf("Erro ao alocar memoria para img cinza\n");
    }
    else {
        printf("Imagem cinza alocada com sucesso\n");
    }

    int error = 0;
    for (int i = 0; i < nLin; i++) {
        for(int j = 0; j < nCol; j++) {
            picture1.img[i][j] = 10;
            if (picture1.img[i][j] != 10) {
                printf("Erro ao atribuir valor ao pixel na posição [%d, %d]\n", i, j);
                error = 1;
            }
        }
    }

    if (!error) {
        printf("Valores atribuidos com sucesso\n");
    }

    //Libera memoria alocada para a imagem em tons de cinza
    freeImagemGray(&picture1);

    // Q02: Aloca imagem em RGB
    imgRGB picture2 = alocaImagemRGB(nLin, nCol);
    if (picture2.img == NULL) {
        printf("\nErro ao alocar memoria para img RGB\n");
        // return 1;
    }
    else {
        printf("\nImagem RGB alocada com sucesso\n");
    }

    for (int i = 0; i < nLin; i++) {
        for(int j = 0; j < nCol; j++) {
            picture2.img[i][j].R = 11;
            picture2.img[i][j].G = 22;
            picture2.img[i][j].B = 33;
        }
    }

    error = 0;
    for (int i = 0; i < nLin; i++) {
        for(int j = 0; j < nCol; j++) {
            if (picture2.img[i][j].R != 11 || picture2.img[i][j].G != 22 || picture2.img[i][j].B != 33) {
                printf("Erro ao atribuir valor ao pixel na posição [%d, %d]\n", i, j);
                error = 1;
                // return 1;
            }
        }
    }

    if (!error) {
        printf("Valores atribuidos com sucesso\n");
    }

    //Libera memoria alocada para a imagem em RGB
    freeImagemRGB(&picture2);


    // Q03: Preenche a imagem em tons de cinza com um valor de pixel
    printf("\nQuestao 3:\n");
    uchar pixel = 100;

    imgGray picture3 = alocaImagemGray(nLin, nCol);
    if (picture3.img == NULL) {
        printf("\nErro ao alocar memoria para img cinza\n");
    }

    if (geraImgGrayFull(picture3, pixel)) {
        printf("Imagem cinza preenchida com sucesso\n");
    }
    else {
        printf("Erro ao preencher imagem cinza\n");
    }

    // verificar se todos os pixels da imagem estão com o valor 100
    error = 0;
    for (int i = 0; i < nLin; i++) {
        for(int j = 0; j < nCol; j++) {
            if (picture3.img[i][j] != 100) {
                printf("Erro ao atribuir valor ao pixel na posição [%d, %d]\n", i, j);
                error = 1;
                break;
            }
        }
    }
    if (!error) {
        printf("Todos os pixels foram preenchidos com %u\n", pixel);
    }
    
    freeImagemGray(&picture3);


    // Q04: Preenche a imagem em RGB com um valor de pixel
    printf("\nQuestao 4:\n");

    tRGB pixelRGB = {200, 150, 100};

    imgRGB picture4 = alocaImagemRGB(nLin, nCol);
    if (picture4.img == NULL) {
        printf("\nErro ao alocar memoria para img RGB\n");
    }

    if (geraImgRGBFull(picture4, pixelRGB)) {
        printf("Imagem RGB preenchida com sucesso\n");
    }
    else {
        printf("Erro ao preencher imagem RGB\n");
    }

    error = 0;
    for (int i = 0; i < nLin; i++) {
        for(int j = 0; j < nCol; j++) {
            if (picture4.img[i][j].R != 200 || picture4.img[i][j].G != 150 || picture4.img[i][j].B != 100) {
                printf("Erro ao atribuir valor ao pixel na posição [%d, %d]\n", i, j);
                error = 1;
                break;
            }
        }
    }
    if (!error) {
        printf("Todos os pixels foram preenchidos com R=%u, G=%u, B=%u\n", pixelRGB.R, pixelRGB.G, pixelRGB.B);
    }

    freeImagemRGB(&picture4);


    return 0;
}