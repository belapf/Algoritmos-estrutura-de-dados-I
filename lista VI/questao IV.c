#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

// Estrutura da pilha para números
typedef struct {
    int itens[MAX];
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

// Função para empilhar um número
void Empilhar(Pilha *pilha, int valor) {
    if (pilha->topo < MAX - 1) {
        pilha->itens[++(pilha->topo)] = valor;
    }
}

// Função para desempilhar um número
int Desempilhar(Pilha *pilha) {
    if (!Vazia(pilha)) {
        return pilha->itens[(pilha->topo)--];
    }
    return 0;
}

// Função para avaliar a expressão pós-fixa
int Posfixa(char *expressao) {
    Pilha pilha;
    Inicializar(&pilha);
    
    for (int i = 0; expressao[i] != '\0'; i++) {
        char atual = expressao[i];
        
        if (isdigit(atual)) { // Se for um número, empilha
            Empilhar(&pilha, atual - '0');
        } else if (atual == '+' || atual == '-' || atual == '*' || atual == '/') {
            int val2 = Desempilhar(&pilha);
            int val1 = Desempilhar(&pilha);
            
            switch (atual) {
                case '+': Empilhar(&pilha, val1 + val2); break;
                case '-': Empilhar(&pilha, val1 - val2); break;
                case '*': Empilhar(&pilha, val1 * val2); break;
                case '/': Empilhar(&pilha, val1 / val2); break;
            }
        }
    }
    
    return Desempilhar(&pilha);
}

int main() {
    char expressao[MAX];
    
    printf("Digite uma expressao em notacao pos-fixa: ");
    fgets(expressao, MAX, stdin);
    
    printf("Resultado: %d\n", Posfixa(expressao));
    
    return 0;
}
