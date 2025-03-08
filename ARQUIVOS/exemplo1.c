/* 
MODOS:

r - leitura
w - escrita
a - escrita no final do arquivo (append)
r+ - leitura e escrita
w+ - leitura e escrita (arquivo é apagado se existir)
a+ - leitura e escrita (escrita no final do arquivo)

*/
#include <stdio.h>
#include <stdlib.h>

void escrever (char f[]) {
    FILE *file = fopen(f, "w");
    char letra;

    if (file) {
        printf("Digite um texo e pressione ENTER para gravar no arquivo\n");
        scanf("%c", &letra);
        while (letra != '\n') {
            fputc(letra, file); //grava um caractere no arquivo
            scanf("%c", &letra);
        }
        fclose(file);
    }
    else {
        printf("Erro na abertura do arquivo\n");
    }
}

void ler(char f[]) {
    FILE *file = fopen(f, "r");
    char letra;

    if (file) {
        printf("\nConteudo lido do arquivo:\n");
        while (!feof(file)) {
            letra = fgetc(file); //lê um caractere do arquivo
            printf("%c", letra);
        }
        
        fclose(file);
    }
    else {
        printf("Erro na abertura do arquivo\n");
    }
}

int main() {

    char nome[] = "arquivo.txt";

    escrever(nome);
    ler(nome);

    return 0;
}