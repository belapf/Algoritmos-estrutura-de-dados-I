#include <stdio.h>

#define NUMERO_CARROS 10

// Definição da estrutura Carro
struct Carro {
    char modelo[20];
    int ano_fabricacao;
    double preco; // preco em reais e centavos, ou seja, ponto flutuante
};

int main() {
    // Inicialização do vetor de carros
    struct Carro carros[NUMERO_CARROS] = {
        {"Vectra", 2009, 58000.00},
        {"Polo", 2008, 45000.00}
    };

    // Ponteiro para o segundo carro
    struct Carro* ponteiroCarro = &carros[1];

    // Exibição dos dados do segundo carro
    printf("Modelo: %s\n", ponteiroCarro->modelo);
    printf("Ano de Fabricacao: %d\n", ponteiroCarro->ano_fabricacao);
    printf("Preco: R$ %.2f\n", ponteiroCarro->preco);

    return 0;
}
