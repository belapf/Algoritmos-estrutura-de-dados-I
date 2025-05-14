#include <stdio.h>
#include <stdlib.h>

int main() {
    float* peso = (float*)malloc(sizeof(float)); // Aloca memória para um float
    if (peso == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1; // Retorna com erro
    }

    *peso = 30; // Atribui o valor 30 à memória alocada
    printf("Peso: %.2f\n", *peso); // Exibe o valor armazenado

    free(peso); // Libera a memória alocada
    
    return 0;
}
