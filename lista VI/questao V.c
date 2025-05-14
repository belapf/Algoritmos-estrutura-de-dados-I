#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define TAMANHO_COMANDO 50

// Estrutura da pilha
typedef struct {
    char itens[MAX][TAMANHO_COMANDO];
    int topo;
} Pilha;

// Função para inicializar a pilha
void Inicializar(Pilha *pilha) {
    pilha->topo = -1;
}

// Função para verificar se a pilha está vazia
int Vazia(Pilha *pilha) {
    return pilha->topo == -1;
}

// Função para empilhar um comando
void Empilhar(Pilha *pilha, char *comando) {
    if (pilha->topo < MAX - 1) {
        strcpy(pilha->itens[++(pilha->topo)], comando);
    }
}

// Função para desempilhar um comando
char* Desempilhar(Pilha *pilha) {
    if (!Vazia(pilha)) {
        return pilha->itens[(pilha->topo)--];
    }
    return NULL;
}

int main() {
    Pilha Desfazer, Refazer;
    Inicializar(&Desfazer);
    Inicializar(&Refazer);
    
    char comando[TAMANHO_COMANDO];
    
    while (1) {
        printf("Digite um comando (ou 'desfazer', 'refazer', 'sair'): ");
        fgets(comando, TAMANHO_COMANDO, stdin);
        comando[strcspn(comando, "\n")] = 0; // Remover o '\n'
        
        if (strcmp(comando, "sair") == 0) {
            break;
        } else if (strcmp(comando, "desfazer") == 0) {
            if (!Vazia(&Desfazer)) {
                char *acao = Desempilhar(&Desfazer);
                Empilhar(&Refazer, acao);
                printf("Acao desfeita: %s\n", acao);
            } else {
                printf("Nada para desfazer.\n");
            }
        } else if (strcmp(comando, "refazer") == 0) {
            if (!Vazia(&Refazer)) {
                char *acao = Desempilhar(&Refazer);
                Empilhar(&Desfazer, acao);
                printf("Acao refeita: %s\n", acao);
            } else {
                printf("Nada para refazer.\n");
            }
        } else {
            Empilhar(&Desfazer, comando);
            // Limpa a pilha de refazer ao adicionar novo comando
            Inicializar(&Refazer);
            printf("Comando armazenado: %s\n", comando);
        }
    }
    
    return 0;
}
