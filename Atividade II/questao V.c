#include <stdio.h>

int main() {
    int x, *p, **q;
    
    p = &x;  // p recebe o endereço de x
    q = &p;  // q recebe o endereço de p
    
    x = 10;  // Atribuímos o valor 10 para x
    
    // Exibe o valor de x usando o ponteiro duplo q
    printf("Valor de x usando q: %d\n", **q);

    return 0;
}
