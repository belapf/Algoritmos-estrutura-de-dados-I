#include <stdio.h>

int main() {
    // Criação de uma variável do tipo char
    char letra = 'A';
    
    // Criação de um ponteiro que aponta para a variável letra
    char *ponteiro = &letra;
    
    // Modificando o conteúdo da variável usando o ponteiro
    *ponteiro = 'B';
    
    // Mostrando o conteúdo da variável e o conteúdo apontado pelo ponteiro
    printf("Conteudo da variavel: %c\n", letra);  // Exibe 'B'
    printf("Conteudo apontado pelo ponteiro: %c\n", *ponteiro);  // Exibe 'B'
    
    return 0;
}
