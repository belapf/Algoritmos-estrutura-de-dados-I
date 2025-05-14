#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
int Vazia(Pilha *pilha) {
    return pilha -> topo == -1;
}

// Função para empilhar um caractere
void Empilhar(Pilha *pilha, char caractere) {
    if (pilha -> topo < MAX - 1) {
        pilha -> itens[++(pilha->topo)] = caractere;
    }
}

// Função para desempilhar um caractere
char Desempilhar(Pilha *pilha) {
    if (!Vazia(pilha)) {
        return pilha->itens[(pilha->topo)--];
    }
    return '\0';
}

// Função para verificar a precedência dos operadores
int Precedencia(char operador) {
    if (operador == '+' || operador == '-') return 1;
    if (operador == '*' || operador == '/') return 2;
    return 0;
}

// Função para converter infixo para pós-fixo
void infixoParaPosfixo(char *expressao) {
    Pilha pilha;
    Inicializar(&pilha);
    
    for (int i = 0; expressao[i] != '\0'; i++) {
        char atual = expressao[i];
        
        if (isdigit(atual)) { // Se for um número, imprime
            printf("%c ", atual);
        } else if (atual == '(') {
            Empilhar(&pilha, atual);
        } else if (atual == ')') {
            while (!Vazia(&pilha) && pilha.itens[pilha.topo] != '(') {
                printf("%c ", Desempilhar(&pilha));
            }
            Desempilhar(&pilha); // Remove '('
        } else if (atual == '+' || atual == '-' || atual == '*' || atual == '/') {
            while (!Vazia(&pilha) && Precedencia(pilha.itens[pilha.topo]) >= Precedencia(atual)) {
                printf("%c ", Desempilhar(&pilha));
            }
            Empilhar(&pilha, atual);
        }
    }
    
    while (!Vazia(&pilha)) {
        printf("%c ", Desempilhar(&pilha));
    }
    printf("\n");
}

int main() {
    char expressao[MAX];
    
    printf("Digite uma expressao matematica na notacao infixa: ");
    fgets(expressao, MAX, stdin);
    
    printf("Notacao pos-fixa: ");
    infixoParaPosfixo(expressao);
    
    return 0;
}
