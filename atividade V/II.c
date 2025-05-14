#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// Busca Sequencial
int buscaSequencial(int array[], int n, int chave) {
    for (int i = 0; i < n; i++) {
        if (array[i] == chave) {
            return i; // Retorna a posição do elemento
        }
    }

    return -1; // Não encontrado
}



// Busca Binária (Requer array ordenado)
int buscaBinaria(int array[], int esquerda, int direita, int chave) {
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        if (array[meio] == chave)
            return meio;
        if (array[meio] < chave)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }

    return -1;
}



// Função para gerar um array ordenado
void gerarArrayOrdenado(int array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = i * 2; // função para garantir valores únicos e ordenados
    }
}



// Função para medir tempo de busca
void medirTempoBusca(int (*busca)(int[], int, int), int array[], int n, int chave, const char *nome) {
    clock_t inicio, fim;
    inicio = clock();
    int resultado = busca(array, n, chave);
    fim = clock();
    printf("%s: Elemento %s encontrado em %f segundos.\n", nome, (resultado != -1) ? "" : "nao", ((double)(fim - inicio)) / CLOCKS_PER_SEC);
}



// Função para medir tempo de busca binária
void medirTempoBuscaBinaria(int (*busca)(int[], int, int, int), int array[], int n, int chave, const char *nome) {
    clock_t inicio, fim;
    inicio = clock();
    int resultado = busca(array, 0, n - 1, chave);
    fim = clock();
    printf("%s: Elemento %s encontrado em %f segundos.\n", nome, (resultado != -1) ? "" : "nao", ((double)(fim - inicio)) / CLOCKS_PER_SEC);
}



// Função para buscar uma palavra em um texto
int buscaPalavra(char *texto, const char *palavra) {
    char *pos = strstr(texto, palavra);
    return (pos != NULL) ? (pos - texto) : -1;
}



// Teste com diferentes tamanhos de array
int main() {
    int tamanhos[] = {1000, 100000, 1000000};
    int chave = 12345; // Elemento a ser buscado

    for (int i = 0; i < 3; i++) {
        int n = tamanhos[i];
        printf("\nTestando com %d elementos:\n", n);
        int *array = (int *)malloc(n * sizeof(int));
        if (!array) {
            printf("Erro ao alocar memoria para %d elementos.\n", n);
            continue;
        }

        gerarArrayOrdenado(array, n);
        
        medirTempoBusca(buscaSequencial, array, n, chave, "Busca Sequencial");
        medirTempoBuscaBinaria(buscaBinaria, array, n, chave, "Busca Binaria");
        free(array);
    }
    


    // Teste com busca de palavra em texto
    char texto[] = "Este é um exemplo de texto totalmente aleatório onde vamos buscar uma palavra especifica.";
    const char *palavra = "palavra";
    clock_t inicio = clock();
    int posicao = buscaPalavra(texto, palavra);
    clock_t fim = clock();
    printf("\nBusca de palavra: '%s' %s encontrada em %f segundos.\n", palavra, (posicao != -1) ? "foi" : "nao foi", ((double)(fim - inicio)) / CLOCKS_PER_SEC);
    

    return 0;
}
