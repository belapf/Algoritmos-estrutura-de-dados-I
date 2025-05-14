#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nomes[MAX][50];
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

void Adicionar(Fila *fila, char *nome) {
    if (Cheia(fila)) {
        printf("Fila cheia! Nao e possivel adicionar mais clientes.\n");
        return;
    }
    strcpy(fila->nomes[fila->tras], nome);
    fila->tras++;
    printf("Cliente %s adicionado a fila.\n", nome);
}

void Atender(Fila *fila) {
    if (Vazia(fila)) {
        printf("Nenhum cliente na fila para atendimento.\n");
        return;
    }
    printf("Atendendo %s\n", fila->nomes[fila->frente]);
    fila->frente++;
}

void Exibir(Fila *fila) {
    if (Vazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila atual: [");
    for (int i = fila->frente; i < fila->tras; i++) {
        printf("%s", fila->nomes[i]);
        if (i < fila->tras - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    Fila fila;
    Inicializar(&fila);
    int opcao;
    char nome[50];
    
    do {
        printf("\n1 - Adicionar Cliente\n");
        printf("2 - Atender Cliente\n");
        printf("3 - Exibir Fila\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao) {
            case 1:
                printf("Digite o nome do cliente: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;
                Adicionar(&fila, nome);
                break;
            case 2:
                Atender(&fila);
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
