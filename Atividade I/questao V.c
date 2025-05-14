#include <stdio.h>

int main() {
    int x = 68, y; 
    int *p; 
    p = &x; 
    y = *p + 200; // y recebe 68 + 200 = 268

    // Exibição dos valores
    printf("Valor de x: %d\n", x);
    printf("Endereco de x: %p\n", (void*)&x);
    printf("Valor de p (endereco de x): %p\n", (void*)p);
    printf("Valor apontado por p (*p): %d\n", *p);
    printf("Valor de y: %d\n", y);

    return 0;
}
