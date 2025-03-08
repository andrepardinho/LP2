#include <stdio.h>
#include <stdlib.h>

//QUESTÃO 5:
int contaCaracteres(char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        return 0;
    }

    int contador = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        contador++;
        if (contador > 1200) {
            fclose(file);
            return 0;
        }
    }

    fclose(file);
    return contador;
}


int main() {
    char nomeArquivo[] = "resumo.txt";

    int resultado = contaCaracteres(nomeArquivo);

    if (resultado == 0) {
        printf("Limite de 1200 caracters ultrapassado ou arquivo nao pode ser aberto.\n");
    } else {
        printf("O resumo possui %d caracteres.\n", resultado);
    }

    return 0;
}