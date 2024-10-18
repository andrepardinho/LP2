#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main ( ) {

    int tam, *vet;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    srand(time(NULL));

    vet = (int *) malloc(tam * sizeof(int));

    if (vet) {
        for (int i = 0; i < tam; i++) {
            *(vet + i) = rand() % 100; // é igual a vet[i]
        }
        for (int i = 0; i < tam; i++) {
            printf("%d ", *(vet + i));
        }

        free(vet);
    }
    else {
        printf("Erro: Memória insuficiente\n");
    }

    return 0;
} 