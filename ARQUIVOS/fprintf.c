#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void escrever (char f[]) {
    FILE *file = fopen(f, "w");

    if (file) {
        char nome[100];
        int idade;
        float altura;
        int opcao;

        do {
            printf("Digite o nome, idade e altura de uma pessoa:\n");
            scanf("%100[^\n]%d%f", nome, &idade, &altura);
            
            fprintf(file, "%s, %d, %.1f\n", nome, idade, altura);
            
            printf("Digite 1 para continuar ou 0 para sair:\n");
            scanf("%d", &opcao);
            scanf("%c");

        } while (opcao != 0);

        fclose(file);
    }
    else {
        printf("Erro na abertura do arquivo\n");
    }
}


int main ( ){
    char nome[] = "arquivofprintf.txt";

    escrever(nome);

    return 0;
}