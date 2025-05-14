#include <stdio.h>

int main() {
    int x;     // Declaração da variável x
    int *px;   // Declaração do ponteiro px
    
    px = &x;   // px recebe o endereço de x

    printf("Digite um valor para x: ");
    scanf("%d", px); //  px aponta para x

    printf("Valor de x: %d\n", x);
    printf("Endereco de x: %p\n", (void*)&x);
    printf("Valor armazenado no endereco apontado por px: %d\n", *px);

    return 0;
}
