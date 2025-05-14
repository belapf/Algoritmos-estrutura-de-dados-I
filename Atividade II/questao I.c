#include <stdio.h>
#include <string.h>

// Definição da estrutura para representar um peixe
struct Peixe {
    char tipo[50];    // Tipo do peixe (string de até 50 caracteres)
    float peso;       // Peso do peixe em kg (ponto flutuante)
    int comprimento;  // Comprimento do peixe em cm (inteiro)
};

int main() {
    // a) Criando uma variável do tipo Peixe
    struct Peixe meuPeixe;

    // Atribuindo valores à estrutura
    strcpy(meuPeixe.tipo, "Salmao");  // Copiando a string para o campo 'tipo'
    meuPeixe.peso = 2.5;              // Atribuindo valor ao campo 'peso'
    meuPeixe.comprimento = 70;        // Atribuindo valor ao campo 'comprimento'

    // Exibindo os valores da variável 'meuPeixe'
    printf("Informacoes do peixe:\n");
    printf("Tipo: %s\n", meuPeixe.tipo);
    printf("Peso: %.2f kg\n", meuPeixe.peso);
    printf("Comprimento: %d cm\n\n", meuPeixe.comprimento);

    // b) Criando um ponteiro para uma variável do tipo Peixe
    struct Peixe *ptrPeixe = &meuPeixe;

    // Acessando os valores usando o ponteiro
    printf("Acessando os valores atraves do ponteiro:\n");
    printf("Tipo: %s\n", ptrPeixe->tipo);
    printf("Peso: %.2f kg\n", ptrPeixe->peso);
    printf("Comprimento: %d cm\n", ptrPeixe->comprimento);

    return 0;
}

