#include <stdio.h>
#include <stdlib.h>

int main() {
    int quantidade;

    // Solicita ao usuário a quantidade de inteiros que deseja armazenar
    printf("Quantos numeros inteiros deseja armazenar? ");
    scanf("%d", &quantidade);

    // Aloca dinamicamente memória para o vetor de inteiros
    int *vetor = (int *)malloc(quantidade * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Preenche o vetor com valores fornecidos pelo usuário
    for (int i = 0; i < quantidade; i++) {
        printf("Digite o valor para a posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }

    // Exibe os valores armazenados no vetor
    printf("\nValores armazenados no vetor:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Posicao %d: %d\n", i, vetor[i]);
    }

    
    free(vetor); // Libera a memória alocada dinamicamente

    return 0;
}
