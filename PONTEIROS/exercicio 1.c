#include <stdio.h>
#include <stdlib.h>

void maiorMenor (int *vet, int tam, int *maior, int *menor) {

    *menor = *vet;
    *maior = *vet;

    for (int i = 1; i < tam; i++) {
        if (*(vet + i) > *maior) {
            *maior = *(vet + i);
        }
        if (*(vet + i) < *menor) {
            *menor = *(vet + i);
        }
    }
}

int main ( ) {

    int menor, maior;
    int v[10] = {1,22,3,4,5,61,7,48,9,10};

    printf("Menor: %d\tMaior: %d\n", menor, maior);
    maiorMenor(v, 10, &maior, &menor);
    printf("Menor: %d\tMaior: %d\n", menor, maior);
    
    return 0;
}