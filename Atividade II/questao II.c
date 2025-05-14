#include <stdio.h>
#include <string.h>

// Definição da estrutura Peixe
struct Peixe {
    char tipo[50];
    float peso;
    int comprimento;
};

// Função que recebe um Peixe por valor e exibe seu conteúdo
void exibirPeixe(struct Peixe p) {
    printf("Tipo: %s\n", p.tipo);
    printf("Peso: %.2f kg\n", p.peso);
    printf("Comprimento: %d cm\n", p.comprimento);
}

int main() {
    // Criando e inicializando um peixe
    struct Peixe meuPeixe;
    strcpy(meuPeixe.tipo, "Salmao");
    meuPeixe.peso = 2.5;
    meuPeixe.comprimento = 70;

    // Chamando a função exibirPeixe (passagem por valor)
    exibirPeixe(meuPeixe);

    return 0;
}
