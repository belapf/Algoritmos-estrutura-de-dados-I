#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura "Local"
typedef struct {
    char nome[100];
    char pais[100];
    char continente[100];
} Local;

int main() {
    int quantidade;

    // Pergunta ao usuário quantos locais ele deseja visitar nas próximas férias
    printf("Quantos locais voce deseja visitar nas proximas ferias? ");
    scanf("%d", &quantidade);

    // Alocação dinâmica de memória para o vetor de locais
    Local *locais = (Local *)malloc(quantidade * sizeof(Local));
    if (locais == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    
    getchar(); // Limpar o buffer do teclado após o scanf

    // Loop para armazenar as informações dos locais
    for (int i = 0; i < quantidade; i++) {
        printf("\nLocal %d:\n", i + 1);

        printf("Nome: ");
        fgets(locais[i].nome, sizeof(locais[i].nome), stdin);
        // Remover o caractere de nova linha '\n' do final da string
        locais[i].nome[strcspn(locais[i].nome, "\n")] = '\0';

        printf("Pais: ");
        fgets(locais[i].pais, sizeof(locais[i].pais), stdin);
        locais[i].pais[strcspn(locais[i].pais, "\n")] = '\0';

        printf("Continente: ");
        fgets(locais[i].continente, sizeof(locais[i].continente), stdin);
        locais[i].continente[strcspn(locais[i].continente, "\n")] = '\0';
    }

    // Exibe os locais escolhidos pelo usuário
    printf("\nLocais que voce escolheu visitar nas proximas ferias:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("\nLocal %d:\n", i + 1);
        printf("Nome: %s\n", locais[i].nome);
        printf("Pais: %s\n", locais[i].pais);
        printf("Continente: %s\n", locais[i].continente);
    }

    
    free(locais); // Libera a memória alocada dinamicamente

    return 0;
}
