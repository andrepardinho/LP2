#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void escrever (char f[]) {
    FILE *file = fopen(f, "w");
    char texto[500];

    if (file) {
        printf("Digite uma frase ou 1 caracter para finalizar:\n");
        
        fgets(texto, 500, stdin);

        while(strlen(texto) > 1) {
            fputs(texto, file); //grava uma string no arquivo
            fgets(texto, 500, stdin);
        }

        fclose(file);
    }
    else {
        printf("Erro na abertura do arquivo\n");
    }
}

int main ( ){
    char nome[] = "arquivofputs.txt";

    escrever(nome);

    return 0;
}