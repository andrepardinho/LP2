//Aritimética de ponteiros 

#include <stdio.h>
#include <stdlib.h>

void imprimir (int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", *(vet + i));
    }
    printf("\n");
}

int main () {

    int vet[10] = {1,22,3,4,5,61,7,48,9,10};

    imprimir (vet, 10);

    return 0;
}