#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia, mes, ano;
}Data;

void imprimirData (Data *X) {
    printf("Data: %d/%d/%d\n", X->dia, X->mes, X->ano);
}


int main ( ) {

    Data data;
    Data *p;

    p = &data;

    printf("Endereco de data: %p\n", &data);
    printf("Conteudo de p: %p\n", p);
    
    data.dia = 17;
    data.mes = 10;
    data.ano = 2024;

    imprimirData(p);

    printf("Data: %d/%d/%d\n", data.dia, data.mes, data.ano);

    return 0;
}