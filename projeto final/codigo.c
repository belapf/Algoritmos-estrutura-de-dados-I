#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Definição das categorias do cardápio
typedef enum {
    ENTRADA, PRINCIPAL, SOBREMESA, BEBIDA
} Categoria;



// Definição do status dos pedidos
typedef enum {
    PENDENTE, EM_PREPARO, PRONTO, ENTREGUE
} StatusPedido;



// Estrutura para representar um item do cardápio
typedef struct ItemCardapio {
    char *nome;
    char *descricao;
    float preco;
    Categoria categoria;
    struct ItemCardapio *proximo;
} ItemCardapio;



// Estrutura para representar um pedido
typedef struct Pedido {
    int id;
    char *cliente;
    ItemCardapio **itens;
    int quantidadeItens;
    StatusPedido status;
    struct Pedido *proximo;
} Pedido;



// Listas dinâmicas
ItemCardapio *cardapio = NULL;
Pedido *pedidos = NULL;



// Funções auxiliares
void adicionarItem(char *nome, char *descricao, float preco, Categoria categoria) {
    ItemCardapio *novoItem = (ItemCardapio *)malloc(sizeof(ItemCardapio));
    novoItem->nome = strdup(nome);
    novoItem->descricao = strdup(descricao);
    novoItem->preco = preco;
    novoItem->categoria = categoria;
    novoItem->proximo = cardapio;
    cardapio = novoItem;
}



void exibirCardapio() {
    printf("\n==============================\n");
    printf("       CARDAPIO DISPONIVEL     \n");
    printf("==============================\n\n");
    ItemCardapio *atual = cardapio;
    while (atual != NULL) {
        printf("Nome: %s\nDescricao: %s\nPreco: R$%.2f\nCategoria: %d\n", atual->nome, atual->descricao, atual->preco, atual->categoria);
        printf("------------------------------\n");
        atual = atual->proximo;
    }
}



void criarPedido(int id, char *cliente) {
    Pedido *novoPedido = (Pedido *)malloc(sizeof(Pedido));
    novoPedido->id = id;
    novoPedido->cliente = strdup(cliente);
    novoPedido->itens = NULL;
    novoPedido->quantidadeItens = 0;
    novoPedido->status = PENDENTE;
    novoPedido->proximo = pedidos;
    pedidos = novoPedido;
}



void alterarStatusPedido(int id, StatusPedido novoStatus) {
    Pedido *atual = pedidos;
    while (atual != NULL && atual->id != id) {
        atual = atual->proximo;
    }
    if (atual == NULL) {
        printf("Pedido nao localizado!\n");
        return;
    }
    atual->status = novoStatus;
    printf("\n==============================\n");
    printf("   Status do pedido atualizado! \n");
    printf("==============================\n");
}



void exibirPedidos() {
    printf("\n==============================\n");
    printf("         LISTA DE PEDIDOS       \n");
    printf("==============================\n\n");
    Pedido *atual = pedidos;
    while (atual != NULL) {
        printf("Pedido ID: %d\nCliente: %s\nStatus: %d\n", atual->id, atual->cliente, atual->status);
        printf("------------------------------\n");
        atual = atual->proximo;
    }
}



// Menu interativo
void menu() {
    int opcao;
    do {
        printf("\n================================\n");
        printf("        MENU INTERATIVO         \n");
        printf("================================\n");
        printf("1. Adicionar Item ao Cardapio\n");
        printf("2. Exibir Cardapio\n");
        printf("3. Criar Pedido\n");
        printf("4. Exibir Pedidos\n");
        printf("5. Alterar Status do Pedido\n");
        printf("6. Sair\n");
        printf("--------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa buffer



        char nome[50], descricao[100], cliente[50];
        float preco;
        int categoria, id, status;



        switch (opcao) {

            case 1:
                printf("Nome do Item: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;
                printf("Descricao: ");
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strcspn(descricao, "\n")] = 0;
                printf("Preco: ");
                scanf("%f", &preco);
                printf("Categoria (1-Entrada, 2 -Principal, 3-Sobremesa, 4-Bebida): ");
                scanf("%d", &categoria);
                adicionarItem(nome, descricao, preco, (Categoria)categoria);
                printf("\nItem adicionado com sucesso!\n");
                break;

            case 2:
                exibirCardapio();
                break;

            case 3:
                printf("ID do Pedido: ");
                scanf("%d", &id);
                getchar();
                printf("Nome do Cliente: ");
                fgets(cliente, sizeof(cliente), stdin);
                cliente[strcspn(cliente, "\n")] = 0;
                criarPedido(id, cliente);
                printf("\nPedido criado com sucesso!\n");
                break;

            case 4:
                exibirPedidos();
                break;

            case 5:
                printf("ID do Pedido: ");
                scanf("%d", &id);
                printf("Novo Status (1-Pendente, 2-Em Preparo, 3-Pronto, 4-Entregue): ");
                scanf("%d", &status);
                alterarStatusPedido(id, (StatusPedido)status);
                break;

            case 6:
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 6);

}



int main() {
    menu();


    return 0;

}