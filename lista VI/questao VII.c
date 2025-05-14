#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char documentos[MAX][50];
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

void Adicionar(Fila *fila, char *documento) {
    if (Cheia(fila)) {
        printf("Fila cheia! Nao e possivel adicionar mais documentos.\n");
        return;
    }
    strcpy(fila->documentos[fila->tras], documento);
    fila->tras++;
    printf("Documento %s adicionado a fila de impressao.\n", documento);
}

void Imprimir(Fila *fila) {
    if (Vazia(fila)) {
        printf("Nenhum documento na fila para impressao.\n");
        return;
    }
    printf("Imprimindo %s\n", fila->documentos[fila->frente]);
    fila->frente++;
}

void Exibir(Fila *fila) {
    if (Vazia(fila)) {
        printf("Fila de impressao vazia!\n");
        return;
    }
    printf("Fila atual: [");
    for (int i = fila->frente; i < fila->tras; i++) {
        printf("%s", fila->documentos[i]);
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
    char documento[50];
    
    do {
        printf("\n1 - Adicionar Documento\n");
        printf("2 - Imprimir Documento\n");
        printf("3 - Exibir Fila de Impressao\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao) {
            case 1:
                printf("Digite o nome do documento: ");
                fgets(documento, 50, stdin);
                documento[strcspn(documento, "\n")] = 0;
                Adicionar(&fila, documento);
                break;
            case 2:
                Imprimir(&fila);
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
