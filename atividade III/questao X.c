#include <stdio.h>
#include <stdlib.h>

// Definição do registro ASCII
typedef struct {
    char caractere;
    int valor;
} ASCII;

// Função que aloca dinamicamente memória para um registro ASCII
ASCII* criarASCII(char caractere, int valor) {
    // Aloca memória para um registro ASCII
    ASCII* novoASCII = (ASCII*)malloc(sizeof(ASCII));
    if (novoASCII == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    // Inicializa os campos do registro
    novoASCII->caractere = caractere;
    novoASCII->valor = valor;
    return novoASCII;
}

int main() { // função principal
    char caractere;
    int valor;

    // Solicitando ao usuário que insira um caractere
    printf("Digite um caractere: ");
    scanf(" %c", &caractere);

    // Solicitando ao usuário que insira um valor inteiro
    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);

    // Chamando a função para criar um registro ASCII
    ASCII* asciiPtr = criarASCII(caractere, valor);

    // Exibindo os valores armazenados no registro
    printf("\nRegistro ASCII criado:\n");
    printf("Caractere: %c\n", asciiPtr->caractere);
    printf("Valor: %d\n", asciiPtr->valor);

    // Liberando a memória alocada dinamicamente
    free(asciiPtr);

    return 0;
}
