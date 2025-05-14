#include <stdio.h>
#include <string.h>

// Definindo o tipo de dado Tigela
typedef struct {
    char estado[10]; // Pode ser "cheia" ou "vazia"
    char tipo[10];   // Pode ser "sopa" ou "canja"
} Tigela;

// Função Fome que altera o estado da Tigela para "vazia"
void Fome(Tigela *t) {
    strcpy(t->estado, "vazia"); // Alterando o estado para "vazia"
}

int main() {
    // Criando uma Tigela cheia de sopa
    Tigela minhaTigela = {"cheia", "sopa"};
    
    // Criando um ponteiro para a Tigela
    Tigela *ponteiro = &minhaTigela;
    
    // Mostrando o estado da tigela antes da janta
    printf("Antes da janta: Estado = %s, Tipo de alimento = %s\n", ponteiro->estado, ponteiro->tipo);
    
    // Chamando a função Fome para alterar o estado da tigela
    Fome(ponteiro);
    
    // Mostrando o estado da tigela depois da janta
    printf("Depois da janta: Estado = %s, Tipo de alimento = %s\n", ponteiro->estado, ponteiro->tipo);
    
    return 0;
}
