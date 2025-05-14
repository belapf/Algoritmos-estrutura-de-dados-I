#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    int tempoExecucao;
} Processo;

typedef struct {
    Processo processos[MAX];
    int frente, tras;
} Fila;

void Inicializar(Fila *fila) {
    fila->frente = 0;
    fila->tras = 0;
}

int Vazia(Fila *fila) {
    return fila->frente == fila->tras;
}

int Cheia(Fila *fila) {
    return fila->tras == MAX;
}

void Adicionar(Fila *fila, char *nome, int tempoExecucao) {
    if (Cheia(fila)) {
        printf("Fila cheia! Nao e possivel adicionar mais processos.\n");
        return;
    }
    strcpy(fila->processos[fila->tras].nome, nome);
    fila->processos[fila->tras].tempoExecucao = tempoExecucao;
    fila->tras++;
    printf("Processo %s (tempo: %ds) adicionado a fila.\n", nome, tempoExecucao);
}

void ExecutarRoundRobin(Fila *fila, int quantum) {
    while (!Vazia(fila)) {
        Processo processo = fila->processos[fila->frente];
        fila->frente++;
        
        if (processo.tempoExecucao > quantum) {
            printf("Executando %s por %ds\n", processo.nome, quantum);
            processo.tempoExecucao -= quantum;
            Adicionar(fila, processo.nome, processo.tempoExecucao);
        } else {
            printf("Executando %s por %ds (finalizado)\n", processo.nome, processo.tempoExecucao);
        }
    }
}

int main() {
    Fila fila;
    Inicializar(&fila);
    int quantum;
    int opcao, tempo;
    char nome[50];
    
    printf("Defina o tempo de quantum: ");
    scanf("%d", &quantum);
    getchar();
    
    do {
        printf("\n1 - Adicionar Processo\n");
        printf("2 - Executar Round-Robin\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao) {
            case 1:
                printf("Digite o nome do processo: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;
                printf("Digite o tempo de execucao: ");
                scanf("%d", &tempo);
                getchar();
                Adicionar(&fila, nome, tempo);
                break;
            case 2:
                ExecutarRoundRobin(&fila, quantum);
                break;
            case 3:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);
    
    return 0;
}
