#include <stdio.h>

int main() {
    int *ponteiro; // Ponteiro declarado, mas não inicializado

    printf("Tentando acessar um ponteiro nao inicializado...\n");
    printf("Valor apontado por ponteiro: %d\n", *ponteiro); // aqui é para dar erro

    return 0;
}
