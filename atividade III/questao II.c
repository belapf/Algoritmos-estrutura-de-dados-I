#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura 'balao'
typedef struct {
    char cor[20];
    float diametro;
    float peso;
} balao;

int main() {
    // a) Criando uma variável do tipo 'balao'
    balao meuBalao;

    // b) Alocando dinamicamente uma variável do tipo 'balao'
    balao *ptrBalao = (balao *)malloc(sizeof(balao));
    if (ptrBalao == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Solicitando ao usuário que insira os valores para os membros da estrutura
    printf("Digite a cor do balao: ");
    scanf("%19s", ptrBalao->cor); // Limita a leitura a 19 caracteres para evitar overflow

    printf("Digite o diametro do balao em cm: ");
    scanf("%f", &ptrBalao->diametro);

    printf("Digite o peso do balao em gramas: ");
    scanf("%f", &ptrBalao->peso);

    // Exibindo o conteúdo do registro
    printf("\nDetalhes do balao:\n");
    printf("Cor: %s\n", ptrBalao->cor);
    printf("Diametro: %.2f cm\n", ptrBalao->diametro);
    printf("Peso: %.2f gramas\n", ptrBalao->peso);

    
    free(ptrBalao); // Liberando a memória alocada dinamicamente

    return 0;
}
