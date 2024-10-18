//Vetor é sempre ponteito? Sim, mas não é sempre que um ponteiro é um vetor.

#include <stdio.h>
#include <stdlib.h>

void teste (int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        vet[i] = vet[i] * 2;
    }
}

void imprimir (int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main () {

    int vet[10] = {1,2,3,4,5,6,7,8,9,10};

    imprimir (vet, 10);
    teste (vet, 10);
    imprimir (vet, 10);

    return 0;
}