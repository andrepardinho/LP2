#include <stdio.h>

void tranferBin2Txt(char* binFileName, char* txtFileName) {
    FILE *binFile = fopen(binFileName, "rb");
    if (binFile == NULL) return;


    FILE *txtFile = fopen(txtFileName, "w");
    if (txtFile == NULL) {
        fclose(binFile);
        return;
    }

    int value = 0;

    while(fread(&value, sizeof(int), 1, binFile) == 1) {
        fprintf(txtFile, "%d\n", value);
    }

    fclose(binFile);
    fclose(txtFile);
}

int main () {
    
    FILE *file = fopen("teste.bin", "wb");
    if (file == NULL) return 1;

    int values[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        fwrite(&values[i], sizeof(int), 1, file);
    }

    fclose(file);

    tranferBin2Txt("teste.bin", "teste.txt");

    return 0;
}