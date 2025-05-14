#include <stdio.h>

// Função para ordenar um vetor usando o algoritmo Bubble Sort
void ordenar(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {  // Percorre o vetor várias vezes
        for (int j = 0; j < tamanho - i - 1; j++) {  // Compara elementos vizinhos
            if (*(vetor + j) > *(vetor + j + 1)) {  // Se estiver fora de ordem, troca
                int temp = *(vetor + j);  // Armazena temporariamente o valor
                *(vetor + j) = *(vetor + j + 1);  // Troca os elementos
                *(vetor + j + 1) = temp;
            }
        }
    }
}

// Função para mesclar e imprimir os vetores ordenados
void imprimirOrdenado(int *vetor1, int *vetor2, int tamanho) {
    int resultado[10]; // Vetor para armazenar os elementos ordenados
    int *p1 = vetor1, *p2 = vetor2, *pRes = resultado;  // Ponteiros auxiliares

    // Copiando os elementos dos dois vetores para o vetor resultado
    for (int i = 0; i < tamanho; i++) {
        *(pRes + i) = *(p1 + i);          // Copia os elementos do primeiro vetor
        *(pRes + i + tamanho) = *(p2 + i); // Copia os elementos do segundo vetor
    }

    // Ordenando o vetor resultante
    ordenar(resultado, tamanho * 2); // Chama a função ordenar

    // Exibindo os elementos ordenados
    printf("Saída: ");
    for (int i = 0; i < tamanho * 2; i++) {
        printf("%d", *(pRes + i));  // Imprime cada número ordenado
        if (i < tamanho * 2 - 1) printf(", ");  // Adiciona vírgulas entre os números
    }
    printf("\n");
}


// Função principal
int main() {
    int vetor1[5] = {2, 5, 9, 8, 3};
    int vetor2[5] = {7, 4, 1, 10, 6};

    imprimirOrdenado(vetor1, vetor2, 5);

    return 0;
}
