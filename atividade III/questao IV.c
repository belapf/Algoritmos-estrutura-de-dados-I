#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Carro
struct Carro {
    char modelo[50];
    int ano_fabricacao;
    double preco; // Reais e centavos, ou seja, ponto flutuante 
};

// Função para calcular o valor total dos carros
double calcularValorTotal(struct Carro* carros, int quantidade) {
    double total = 0.0;
    for (int i = 0; i < quantidade; i++) {
        total += carros[i].preco;
    }
    return total;
}

int main() {
    int quantidadeCarros = 2; // Número de carros a serem cadastrados

    // Alocação dinâmica de memória para o vetor de carros
    struct Carro* carros = (struct Carro*)malloc(quantidadeCarros * sizeof(struct Carro));
    if (carros == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // Entrada de dados dos carros
    for (int i = 0; i < quantidadeCarros; i++) {
        printf("Digite os dados do carro %d:\n", i + 1);
        printf("Modelo: ");
        fgets(carros[i].modelo, sizeof(carros[i].modelo), stdin);
        // Remover o caractere de nova linha
        size_t len = strlen(carros[i].modelo);
        if (len > 0 && carros[i].modelo[len - 1] == '\n') {
            carros[i].modelo[len - 1] = '\0';
        }
        printf("Ano de Fabricacao: ");
        scanf("%d", &carros[i].ano_fabricacao);
        printf("Preco: R$");
        scanf("%lf", &carros[i].preco);
        getchar(); // Limpar o buffer do teclado
    }

    // Calcular e exibir o valor total dos carros
    double valorTotal = calcularValorTotal(carros, quantidadeCarros);
    printf("\nValor total dos carros: R$%.2f\n", valorTotal);
   
    free(carros);  // Liberar a memória alocada

    return 0;
}
