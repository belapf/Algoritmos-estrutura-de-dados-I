#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000

// Estrutura da pilha
typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

// Função para inicializar a pilha
void Inicializar(Pilha *pilha) {
    pilha -> topo = -1;
}

// Função para verificar se a pilha está vazia
bool Vazia(Pilha *pilha) {
    return pilha -> topo == -1;
}

// Função para empilhar um caractere
void Empilhar(Pilha *pilha, char caractere) {
    if (pilha -> topo < MAX - 1) {
        pilha -> itens [++ ( pilha -> topo)] = caractere;
    }
}

// Função para desempilhar um caractere
char Desempilhar(Pilha *pilha) {
    if (!Vazia(pilha)) {
        return pilha->itens[(pilha->topo)--];
    }
    return '\0'; // Retornar caractere nulo caso a pilha esteja vazia
}

// Função para verificar se os pares de caracteres estão corretos
bool Pares(char ab, char fe) {
    return (ab == '(' && fe == ')') || (ab == '{' && fe == '}') || (ab == '[' && fe == ']');
}

// Função para verificar se a string está balanceada
bool Balanceada(char *expressao) {
    Pilha pilha;
    Inicializar(&pilha);
    
    for (int i = 0; expressao[i] != '\0'; i++) {
        char atual = expressao[i];
        
        if (atual == '(' || atual == '{' || atual == '[') {
            Empilhar(&pilha, atual);
        } else if (atual == ')' || atual == '}' || atual == ']') {
            if (Vazia(&pilha) || !Pares(Desempilhar(&pilha), atual)) {
                return false;
            }
        }
    }
    
    return Vazia(&pilha); // Se a pilha estiver vazia, está balanceada
}

int main() {
    char entrada1[] = "{[()()]}";
    char entrada2[] = "{[(])}";
    
    printf("Entrada: %s\nSaida: %s\n", entrada1, Balanceada(entrada1) ? "Entrada Balanceada" : "Entrada nao Balanceada");
    printf("Entrada: %s\nSaida: %s\n", entrada2, Balanceada(entrada2) ? "Entrada Balanceada" : "Entrada nao Balanceada");
    
    return 0;
}
