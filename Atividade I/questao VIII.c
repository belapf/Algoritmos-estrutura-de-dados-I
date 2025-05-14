#include <stdio.h>

int main() {
    int x = 9;  // Definimos x com valor inicial 9
    int *px = &x;  // px recebe o endereço de x

    *px = *px / 3;  // Divide x por 3 sem usar x diretamente, ou seja, modifica x diretamente.

    printf("Novo valor de x: %d\n", x);  // Deve imprimir o novo valor de x 
    
    return 0;
}
