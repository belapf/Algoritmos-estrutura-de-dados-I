#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaração de um ponteiro para inteiro
    int *ponteiro;

    // Alocação dinâmica de memória para o ponteiro
    ponteiro = (int *)malloc(sizeof(int));
    if (ponteiro == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    
    *ponteiro = 100; // Armazenando o número 100 na memória alocada

    
    printf("Conteudo inicial: %d\n", *ponteiro); // Mostrando o conteúdo apontado

    
    printf("Digite um novo valor para esse bloco de memoria: "); // Solicitando um novo número inteiro ao usuário
    scanf("%d", ponteiro);

    
    printf("Novo valor: %d\n", *ponteiro); // Mostrando o novo conteúdo apontado

    
    free(ponteiro); // Liberando o espaço alocado dinamicamente

    return 0;
}
