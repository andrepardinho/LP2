#include <stdio.h>
#include <stdlib.h>

// malloc() -> aloca uma quantidade de bytes na memória. Retorna um ponteiro para o primeiro byte alocado ou NULL se não conseguir alocar memória.

int main ( ) {
    
    int *x;

    // x = (int *) malloc(sizeof(int));
    x = calloc(1, sizeof(int));

    if (x) {
        printf("MEMORIA ALOCADA\n");
        printf("Valor de x: %d\n", *x);
        *x = 10;
        printf("Valor de x: %d\n", *x);
    }
    else {
        printf("Erro: Memória insuficiente\n");
    }

    return 0;
}