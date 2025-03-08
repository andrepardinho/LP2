#include "procimg.h"

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
    
    //Mapear a imagem guardada como array em picture._img. no array de ponteiros em picture.img
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

// Q05: Preenche a imagem em tons de cinza com o valor 0 (preto)
int geraImgGrayB(imgGray img) {
    if (img.img == NULL || img._img == NULL) {
        return 0;
    }

    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            img.img[i][j] = 0; 
        }
    }

    return 1;
}

// Q06: Preenche a imagem em RGB com o valor (0, 0, 0) (preto)
int geraImgRGBB(imgRGB img) {
    if (img.img == NULL || img._img == NULL) {
        return 0;
    }

    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            img.img[i][j].R = 0; 
            img.img[i][j].G = 0; 
            img.img[i][j].B = 0; 
        }
    }

    return 1;
}

// Q07: Preenche a imagem em tons de cinza com o valor 255 (branco)
int geraImgGrayW(imgGray img) {
    if (img.img == NULL || img._img == NULL) {
        return 0;
    }

    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            img.img[i][j] = 255; 
        }
    }

    return 1;
}

// Q08: Preenche a imagem em RGB com o valor (255, 255, 255) (branco)
int geraImgRGBW(imgRGB img) {
    if (img.img == NULL || img._img == NULL) {
        return 0;
    }

    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            img.img[i][j].R = 255; 
            img.img[i][j].G = 255; 
            img.img[i][j].B = 255; 
        }
    }

    return 1;
}

//Função que gera um valor de pixel aleatório 
unsigned char geraPixelGrey(int tipo) {
    int valorAleatorio = rand() % 256; // Gera um valor entre 0 e 255

    if (tipo < 0) {
        // Intensidades mais escuras (0-127) têm maior probabilidade
        if (valorAleatorio < 192) {
            return (unsigned char)(rand() % 128);
        } else {
            return (unsigned char)(128 + rand() % 128);
        }
    } else if (tipo > 0) {
        // Intensidades mais claras (128-255) têm maior probabilidade
        if (valorAleatorio < 192) {
            return (unsigned char)(128 + rand() % 128); // Aumenta a probabilidade de valores maiores
        } else {
            return (unsigned char)(rand() % 128);
        }
    } else {
        // Todas as intensidades têm a mesma probabilidade
        return (unsigned char)(valorAleatorio);
    }
}

// Q09: Preenche a imagem em tons de cinza com valores aleatórios
int geraImgGray(imgGray img, int tipo) {
    if (img.img == NULL || img._img == NULL) {
        return 0;
    }

    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            img.img[i][j] = geraPixelGrey(tipo); // Atribui um valor aleatório ao pixel
        }
    }

    return 1;
}

// Q10: Preenche a imagem em RGB com valores aleatórios
int geraImgRGB(imgRGB img, int tipo) {
    if (img.img == NULL || img._img == NULL) {
        return 0;
    }

    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            // Atribui um valor aleatório a cada canal de cor do pixel
            img.img[i][j].R = geraPixelGrey(tipo); 
            img.img[i][j].G = geraPixelGrey(tipo); 
            img.img[i][j].B = geraPixelGrey(tipo); 
        }
    }

    return 1;
}

/*

// Q11: Função para encontrar o pixel de maior intensidade em uma imagem cinza
int pixelGrayMax(imgGray img) {
    if (img.img == NULL) return -1; // Verifica se a imagem é nula

    int max = 0; // Inicializa o máximo
    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            if (img.img[i][j] > max) {
                max = img.img[i][j]; // Atualiza o máximo se encontrar um valor maior
            }
        }
    }
    return max; // Retorna o valor máximo encontrado
}

// Função para encontrar o pixel de menor intensidade em uma imagem cinza
int pixelGrayMin(imgGray img) {
    if (img.img == NULL) return -1; // Verifica se a imagem é nula

    int min = 255;// Inicializa o mínimo
    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            if (img.img[i][j] < min) {
                min = img.img[i][j]; // Atualiza o mínimo se encontrar um valor menor
            }
        }
    }
    return min; // Retorna o valor mínimo encontrado
}

// Q12: Retorna a maior e menor intensidade de pixel em uma imagem RGB
tRGB pixelRGBMax(imgRGB img) {
    tRGB maxPixel = {0, 0, 0};
    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            if (img.img[i][j].R > maxPixel.R) maxPixel.R = img.img[i][j].R;
            if (img.img[i][j].G > maxPixel.G) maxPixel.G = img.img[i][j].G;
            if (img.img[i][j].B > maxPixel.B) maxPixel.B = img.img[i][j].B;
        }
    }
    return maxPixel;
}

tRGB pixelRGBMin(imgRGB img) {
    tRGB minPixel = {255, 255, 255};
    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            if (img.img[i][j].R < minPixel.R) minPixel.R = img.img[i][j].R;
            if (img.img[i][j].G < minPixel.G) minPixel.G = img.img[i][j].G;
            if (img.img[i][j].B < minPixel.B) minPixel.B = img.img[i][j].B;
        }
    }
    return minPixel;
}

// Q13: Retorna a soma dos elementos de cada linha e de cada coluna de uma img cinza.
int* somaPorLinhasGray(imgGray img) {
    if (img.img == NULL || img._img == NULL) {
        return NULL; // Retorna NULL se a imagem não foi alocada corretamente
    }

    // Aloca um array para armazenar a soma de cada linha
    int* somaLinhas = (int*)calloc(img.nLin, sizeof(int));
    if (somaLinhas == NULL) {
        return NULL;
    }

    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            somaLinhas[i] += img.img[i][j]; // Soma os valores dos pixels
        }
    }

    return somaLinhas; // Retorna o array de somas
}

int* somaPorColunasGray(imgGray img) {
    if (img.img == NULL || img._img == NULL) {
        return NULL; // Retorna NULL se a imagem não foi alocada corretamente
    }

    // Aloca um array para armazenar a soma de cada coluna
    int* somaColunas = (int*)calloc(img.nCol, sizeof(int));
    if (somaColunas == NULL) {
        return NULL;
    }

    for (int j = 0; j < img.nCol; j++) {
        for (int i = 0; i < img.nLin; i++) {
            somaColunas[j] += img.img[i][j]; // Soma os valores dos pixels
        }
    }

    return somaColunas; // Retorna o array de somas
}

// Q14: Retorna a soma dos elementos de cada linha e coluna em uma imagem
tRGB* somaPorLinhasRGB(imgRGB img) {
    if (img.img == NULL || img._img == NULL) {
        return NULL; // Retorna NULL se a imagem não foi alocada corretamente
    }

    // Aloca um array para armazenar a soma de cada linha
    tRGB* somaLinhas = (tRGB*)malloc(img.nLin * sizeof(tRGB));
    if (somaLinhas == NULL) {
        return NULL;
    }

    for (int i = 0; i < img.nLin; i++) {
        // Inicializa a soma de cada canal
        somaLinhas[i].R = 0;
        somaLinhas[i].G = 0;
        somaLinhas[i].B = 0;
        for (int j = 0; j < img.nCol; j++) {
            // Soma os valores dos pixels de cada canal
            somaLinhas[i].R += img.img[i][j].R;
            somaLinhas[i].G += img.img[i][j].G;
            somaLinhas[i].B += img.img[i][j].B;
        }
    }

    return somaLinhas;
}

tRGB* somaPorColunasRGB(imgRGB img) {
    if (img.img == NULL || img._img == NULL) {
        return NULL; // Retorna NULL se a imagem não foi alocada corretamente
    }

    // Aloca um array para armazenar a soma de cada coluna
    tRGB* somaColunas = (tRGB*)malloc(img.nCol * sizeof(tRGB));
    if (somaColunas == NULL) {
        return NULL;
    }

    for (int j = 0; j < img.nCol; j++) {
        // Inicializa a soma de cada canal
        somaColunas[j].R = 0;
        somaColunas[j].G = 0;
        somaColunas[j].B = 0;
        for (int i = 0; i < img.nLin; i++) {
            // Soma os valores dos pixels de cada canal
            somaColunas[j].R += img.img[i][j].R;
            somaColunas[j].G += img.img[i][j].G;
            somaColunas[j].B += img.img[i][j].B;
        }
    }

    return somaColunas; // Retorna o array de somas
}

// Q15: Retorna a soma total dos elementos de uma imagem.
int somaTotalGray(imgGray img) {
    if (img.img == NULL || img._img == NULL) {
        return -1;
    }

    int soma = 0;

    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            soma += img.img[i][j]; // Soma os valores dos pixels
        }
    }

    return soma;
}

// Q16: Retorna a soma total dos elementos de uma imagem por canal
tRGB somaTotalRGB(imgRGB img) {
    tRGB soma = {0, 0, 0};
    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            soma.R += img.img[i][j].R;
            soma.G += img.img[i][j].G;
            soma.B += img.img[i][j].B;
        }
    }
    return soma;
}

// Q17: Função para contar quantos pixels possuem uma intensidade específica em uma imagem em tons de cinza
int quantosPixelsGrayNaInt(imgGray img, uchar inten) {
    int count = 0;

    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            if (img.img[i][j] == inten) {
                count++; // Incrementa o contador se o pixel tiver a intensidade desejada
            }
        }
    }
    return count; // Retorna a quantidade de pixels com a intensidade específica
}

// Q18: Função para contar quantos pixels possuem uma intensidade específica em uma imagem em RGB
 int quantosPixelsRGBNaInt(imgRGB img, tRGB inten) {
    int count = 0;

    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            if (img.img[i][j].R == inten.R &&
                img.img[i][j].G == inten.G &&
                img.img[i][j].B == inten.B) {
                count++; // Incrementa o contador se o pixel RGB tiver a intensidade desejada
            }
        }
    }
    return count; // Retorna a quantidade de pixels com a intensidade RGB específica
}

*/

/*

Nesta lista vamos criar funções para salvar e ler arquivos com imagens. Com esta finalidade foi
proposto o formato hed/img em que a imagem é armazenada em dois arquivos:
● O arquivo com extensão .hed é um arquivo de texto contendo as informações sobre:
○ O tipo de imagem que está armazenada (Gray ou RGB);
○ A quantidade de linhas e colunas da imagem;
○ Uma String de até 80 caracteres com uma descrição da imagem
○ O nome do arquivo binário onde estão a imagem, ou seja, a intensidade de cada
pixel da imagem.
● O arquivo com extensão .img é um arquivo binário contendo a matriz com a intensidade
de cada pixel da imagem

int saveImgGray(imgGray img, char[] desc, char[] fileName) que
salva a imagem nos arquivos com o formato proposto. A função retorna verdadeiro se
os arquivos forem gerados com sucesso e falso caso contrário. A String tipo C desc
contém a descrição da imagem a ser incluída no arquivo de cabeçalho. A String tipo C
fileName tem o nome do arquivo sem extensão.
*/

int saveImgGray(imgGray img, char desc[], char fileName[]) {
    
    if (img.img == NULL || img._img == NULL) {
        return 0;
    }

    // Cria o arquivos .hed e .img
    char hedFileName[100], imgFileName[100];
    strcpy(hedFileName, fileName);
    strcat(hedFileName, ".hed");
    strcpy(imgFileName, fileName);
    strcat(imgFileName, ".img");

    // Abre o arquivo .hed
    FILE *hedFile = fopen(hedFileName, "w");
    if (hedFile == NULL) {
        return 0;
    }

    // Escreve as informações no arquivo .hed
    fprintf(hedFile, "Type: Gray\n");
    fprintf(hedFile, "Size: %dx%d\n", img.nLin, img.nCol);
    fprintf(hedFile, "Desc: %s\n", desc);
    fprintf(hedFile, "Bin file: %s\n", imgFileName);
    fclose(hedFile);

    FILE *imgFile = fopen(imgFileName, "wb");
    if (imgFile == NULL) {
        return 0;
    }

    // Escreve a imagem no arquivo .img
    if (fwrite(img._img, sizeof(uchar), img.nLin * img.nCol, imgFile) != img.nLin * img.nCol) {
        fclose(imgFile);
        return 0;
    }
    fclose(imgFile);

    return 1;
}

int saveImgRGB(imgRGB img, char desc[] ,char fileName[]) {

    if (img.img == NULL || img._img == NULL) {
        return 0;
    }

    char hedFileName[100], imgFileName[100];

    strcpy(hedFileName, fileName);
    strcat(hedFileName, ".hed");
    strcpy(imgFileName, fileName);
    strcat(imgFileName, ".img");

    FILE *headFile = fopen(hedFileName, "w");
    if (headFile == NULL) {
        return 0;
    }

    fprintf(headFile, "Type: RGB\n");
    fprintf(headFile, "Size: %dx%d\n", img.nLin, img.nCol);
    fprintf(headFile, "Desc: %s\n", desc);
    fprintf(headFile, "Bin file: %s\n", imgFileName);
    fclose(headFile);

    FILE *imgFile = fopen(imgFileName, "wb");
    if (imgFile == NULL) {
        return 0;
    }

    if (fwrite(img._img, sizeof(tRGB), img.nLin * img.nCol, imgFile) != img.nLin * img.nCol) {
        fclose(imgFile);
        return 0;
    }
    fclose(imgFile);

    return 1;
}

int loadHead(char fileName[], char desc[]) {
    char hedFileName[100];

    strcpy(hedFileName, fileName);
    strcat(hedFileName, ".hed");

    FILE *hedFile = fopen(hedFileName, "r");
    if (hedFile == NULL) {
        return 0;
    }

    char type[10];
    char binFileName[100];
    int imgType;

    //fscanf retorna o número de itens lidos com sucesso. Ou seja, se o retorno for 1, significa que o fscanf leu corretamente o valor. Se for 0, significa que houve um erro na leitura.

    if(fscanf(hedFile, "Type: %9s\n", type) == 1) {
        if (strcmp(type, "Gray") == 0) {
            imgType = 1;
        } else if (strcmp(type, "RGB") == 0) {
            imgType = 2;
        } else {
            fclose(hedFile);
            return 0;
        }
    } else {
        fclose(hedFile);
        return 0;
    }

    if (fscanf(hedFile, "Size: %*dx%*d\n") != 0) {

    }
    if(fscanf(hedFile, "Desc: %99[^\n]\n", desc) != 1) {
        fclose(hedFile);
        return 0;
    }
    if(fscanf(hedFile, "Bin file: %s\n", binFileName) != 1) {
        fclose(hedFile);
        return 0;
    }

    fclose(hedFile);

    return imgType;
}

imgGray loadImgGray(char fileName[]) {

    imgGray img = {NULL, NULL, 0, 0};

    char hedFileName[100], imgFileName[100];
    strcpy(hedFileName, fileName);
    strcat(hedFileName, ".hed");
    strcpy(imgFileName, fileName);
    strcat(imgFileName, ".img");

    FILE *hedFile = fopen(hedFileName, "r");
    if (hedFile == NULL) {
        return img;
    }

    char type[10];
    char binFileName[100];

    if(fscanf(hedFile, "Type: %9s\n", type) == 1) {
        if (strcmp(type, "Gray") != 0) {
            fclose(hedFile);
            return img;
        }
    } else {
        fclose(hedFile);
        return img;
    }

    if (fscanf(hedFile, "Size: %dx%d\n", &img.nLin, &img.nCol) != 2) {
        fclose(hedFile);
        return img;
    }

    if(fscanf(hedFile, "Desc: %*s\n") != 0) {
        fclose(hedFile);
        return img;
    }

    if(fscanf(hedFile, "Bin file: %s\n", binFileName) != 1) {
        fclose(hedFile);
        return img;
    }

    fclose(hedFile);

    FILE *imgFile = fopen(imgFileName, "rb");
    if (imgFile == NULL) {
        return img;
    }

    img = alocaImagemGray(img.nLin, img.nCol);
    if (img.img == NULL || img._img == NULL) {
        fclose(imgFile);
        return img;
    }

    if (fread(img._img, sizeof(uchar), img.nLin * img.nCol, imgFile) != img.nLin * img.nCol) {
        fclose(imgFile);
        freeImagemGray(&img);
        return img;
    }

    fclose(imgFile);

    return img;

}

imgRGB loadImgRGB(char fileName[]);

int saveImgGrayBin(imgGray img, char fileName[]) {
    
}