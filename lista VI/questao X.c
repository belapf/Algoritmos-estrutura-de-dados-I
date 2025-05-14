#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    int prioridade;
} Paciente;

typedef struct {
    Paciente fila[MAX];
    int tamanho;
} Prioridade;

void Inicializar(Prioridade *fila) {
    fila->tamanho = 0;
}

int Vazia(Prioridade *fila) {
    return fila->tamanho == 0;
}

int Cheia(Prioridade *fila) {
    return fila->tamanho == MAX;
}

void Enfileirar(Prioridade *fila, char *nome, int prioridade) {
    if (Cheia(fila)) {
        printf("Fila cheia!\n");
        return;
    }
    int i = fila->tamanho - 1;
    while (i >= 0 && fila->fila[i].prioridade < prioridade) {
        fila->fila[i + 1] = fila->fila[i];
        i--;
    }
    strcpy(fila->fila[i + 1].nome, nome);
    fila->fila[i + 1].prioridade = prioridade;
    fila->tamanho++;
    printf("Paciente %s com prioridade %d adicionado a fila.\n", nome, prioridade);
}

void Desenfileirar(Prioridade *fila) {
    if (Vazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Atendendo %s\n", fila->fila[0].nome);
    for (int i = 0; i < fila->tamanho - 1; i++) {
        fila->fila[i] = fila->fila[i + 1];
    }
    fila->tamanho--;
}

void Exibir(Prioridade *fila) {
    if (Vazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila de prioridade atual:\n");
    for (int i = 0; i < fila->tamanho; i++) {
        printf("%s (Prioridade: %d)\n", fila->fila[i].nome, fila->fila[i].prioridade);
    }
}

int main() {
    Prioridade fila;
    Inicializar(&fila);
    int opcao, prioridade;
    char nome[50];
    
    do {
        printf("\n1 - Adicionar Paciente\n");
        printf("2 - Atender Paciente\n");
        printf("3 - Exibir Fila\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao) {
            case 1:
                printf("Digite o nome do paciente: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;
                printf("Digite a prioridade: ");
                scanf("%d", &prioridade);
                getchar();
                Enfileirar(&fila, nome, prioridade);
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
