#include <stdio.h>

// Função que incrementa um número diretamente usando ponteiro
void Mais(int *numero) {
    (*numero)++; // Modifica diretamente o valor apontado
}

// Função que retorna o valor incrementado sem modificar a variável original
int Incrementa(int numero) {
    return numero + 1; // Retorna um novo valor sem alterar o original
}

int main() {
    int valor;

    // Entrada do usuário
    printf("Digite um valor: ");
    scanf("%d", &valor);

    // Chamada da função Mais (passagem por referência)
    Mais(&valor);
    printf("\nResultado apos Mais: %d", valor);

    // Chamada da função Incrementa (passagem por valor)
    valor = Incrementa(valor);
    printf("\nResultado apos Incrementa: %d\n", valor);

    return 0;
}
