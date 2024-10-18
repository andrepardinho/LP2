//Ponteiro como parâmetro de função

#include <stdio.h>
#include <stdlib.h>

void imprimir (int *num) {
    printf("Valor de num: %d\n", *num);
    
    *num = 10;
}

int main ( ) {
    
    int idade = 21;

    imprimir(&idade);

    printf("Valor no main: %d\n", idade);

    return 0;
}