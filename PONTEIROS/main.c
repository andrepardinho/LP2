#include <stdio.h>
#include <stdlib.h>

int main () {
    
    int num = 10;
    int *p;

    p = &num;

    printf("Valor de num: %d\n", num);
    printf("Endereco de num: %p\n", &num);

    printf("Valor de p: %p\n", p);
    printf("Valor apontado por p: %d\n", *p);
    printf("Endereco de p: %p\n", &p);
    
    printf("Tamanho de p: %d\n", sizeof(num));

    return 0;
}