#include <stdio.h>
#include <stdlib.h>
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
    return pilha->topo == -1;
}

// Função para empilhar um caractere
void Empilhar(Pilha *pilha, char c) {
    if (pilha->topo < MAX - 1) {
        pilha->itens[++(pilha->topo)] = c;
    }
}

// Função para desempilhar um caractere
char Desempilhar(Pilha *pilha) {
    if (!Vazia(pilha)) {
        return pilha->itens[(pilha->topo)--];
    }
    return '\0'; // Retornar caractere nulo caso a pilha esteja vazia
}

// Função para inverter uma string usando pilha
void Inverter(char *string) {
    Pilha pilha;
    Inicializar(&pilha);
    
    int tamanho = strlen(string);
    
    for (int i = 0; i < tamanho; i++) {
        Empilhar(&pilha, string[i]);
    }
    
    for (int i = 0; i < tamanho; i++) {
        string[i] = Desempilhar(&pilha);
    }
}

int main() {
    char entrada[MAX];
    
    printf("Digite uma palavra ou uma frase: ");
    fgets(entrada, MAX, stdin);
    
    // Removendo o caractere de nova linha, se presente
    entrada[strcspn(entrada, "\n")] = 0;
    
    Inverter(entrada);
    
    printf("Texto invertido: %s\n", entrada);
    
    return 0;
}