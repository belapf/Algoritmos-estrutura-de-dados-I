#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int elementos[MAX];
    int frente, tras, tamanho;
} FilaCircular;

void Inicializar(FilaCircular *fila) {
    fila->frente = 0;
    fila->tras = 0;
    fila->tamanho = 0;
}

int Vazia(FilaCircular *fila) {
    return fila->tamanho == 0;
}

int Cheia(FilaCircular *fila) {
    return fila->tamanho == MAX;
}

void Enfileirar(FilaCircular *fila, int elemento) {
    if (Cheia(fila)) {
        printf("Fila cheia! Sobrescrevendo %d.\n", fila->elementos[fila->frente]);
        fila->frente = (fila->frente + 1) % MAX; // Move a frente para sobrescrever
    } else {
        fila->tamanho++;
    }
    fila->elementos[fila->tras] = elemento;
    fila->tras = (fila->tras + 1) % MAX;
    printf("Elemento %d enfileirado.\n", elemento);
}

void Desenfileirar(FilaCircular *fila) {
    if (Vazia(fila)) {
        printf("Fila vazia! Nenhum elemento para remover.\n");
        return;
    }
    printf("Elemento %d desenfileirado.\n", fila->elementos[fila->frente]);
    fila->frente = (fila->frente + 1) % MAX;
    fila->tamanho--;
}

void Exibir(FilaCircular *fila) {
    if (Vazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila atual: [ ");
    for (int i = 0, idx = fila->frente; i < fila->tamanho; i++, idx = (idx + 1) % MAX) {
        printf("%d ", fila->elementos[idx]);
    }
    printf("]\n");
}

int main() {
    FilaCircular fila;
    Inicializar(&fila);
    int opcao, elemento;
    
    do {
        printf("\n1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Exibir Fila\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o elemento: ");
                scanf("%d", &elemento);
                Enfileirar(&fila, elemento);
                break;
            case 2:
                Desenfileirar(&fila);
                break;
            case 3:
                Exibir(&fila);
                break;
            case 4:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);
    
    return 0;
}
