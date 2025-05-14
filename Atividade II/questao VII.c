#include <stdio.h>
#include <stdint.h>

// Definição da união Cor
typedef union {
    struct {
        unsigned char r, g, b, a; // Componentes de cor individuais (8 bits cada)
    };
    uint32_t valor; // Representação como um único inteiro de 32 bits
} Cor;

// Função para ler uma cor no formato RGBA
void LerCorRGBA(Cor *c) {
    printf("Digite os valores de R, G, B e A (0-255): ");
    scanf("%hhu %hhu %hhu %hhu", &c->r, &c->g, &c->b, &c->a);
}

// Função para ler uma cor no formato inteiro de 32 bits
void LerCorInt(Cor *c) {
    printf("Digite o valor inteiro de 32 bits da cor: ");
    scanf("%u", &c->valor);
}

int main() {
    Cor cor;

    // Ler e exibir cor no formato RGBA
    LerCorRGBA(&cor);
    printf("Cor em RGBA: R=%d, G=%d, B=%d, A=%d\n", cor.r, cor.g, cor.b, cor.a);
    printf("Cor em inteiro de 32 bits: %u\n\n", cor.valor);

    // Ler e exibir cor no formato inteiro de 32 bits
    LerCorInt(&cor);
    printf("Cor em inteiro de 32 bits: %u\n", cor.valor);
    printf("Cor em RGBA: R=%d, G=%d, B=%d, A=%d\n", cor.r, cor.g, cor.b, cor.a);

    return 0;
}
