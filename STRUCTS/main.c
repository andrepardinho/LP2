#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} BirthDate;

typedef struct { 
    char nome[100];
    int idade;
    BirthDate dataNasc;
    char sexo;
} Pessoa;

void printPessoa(Pessoa p) {
    printf("Nome: %s; Idade: %d; Nascimento: %d/%d/%d; Sexo: %c\n", p.nome, p.idade, p.dataNasc.dia, p.dataNasc.mes, p.dataNasc.ano, p.sexo);
}

//função que le os dados de uma pessoa
Pessoa readPessoa() {
    Pessoa p;
    printf("Digite o nome: ");
    fgets(p.nome, 100, stdin);
    printf("Digite a idade: ");
    scanf("%d", &p.idade);
    printf("Digite o dia de nascimento: ");
    scanf("%d", &p.dataNasc.dia);
    printf("Digite o mes de nascimento: ");
    scanf("%d", &p.dataNasc.mes);
    printf("Digite o ano de nascimento: ");
    scanf("%d", &p.dataNasc.ano);
    printf("Digite o sexo: ");
    scanf(" %c", &p.sexo);
    return p;
}

int main ( ) {

    Pessoa p1;

    strcpy(p1.nome, "Andre Pardinho");
    p1.idade = 21;
    p1.dataNasc = (BirthDate) { 10, 10, 2000 };
    p1.sexo = 'M';

    printPessoa(p1);

    Pessoa p2 = readPessoa();
    printPessoa(p2);

    return 0;
}