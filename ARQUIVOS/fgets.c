#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void escrever (char f[]) {
    FILE *file = fopen(f, "w");
    char texto[500];

    if (file) {
        printf("Digite uma frase ou 1 caracter para finalizar:\n");
        
        fgets(texto, 500, stdin);

        while(strlen(texto) > 2) {
            fputs(texto, file); //grava uma string no arquivo
            fgets(texto, 500, stdin);
        }

        fclose(file);
    }
    else {
        printf("Erro na abertura do arquivo\n");
    }
}

ler (char f[]) {
    FILE *file = fopen(f, "r");
    char texto[500];

    if (file) {
        printf("\nConteudo lido do arquivo:\n");
        
        while (!feof(file)) {

            if (fgets(texto, 500, file))
                printf("%s", texto);
        }

        fclose(file);
    }
    else {
        printf("Erro na abertura do arquivo\n");
    }
}

int main ( ){
    char nome[] = "arquivofgets.txt";

    //escrever(nome);
    ler(nome);

    return 0;
}