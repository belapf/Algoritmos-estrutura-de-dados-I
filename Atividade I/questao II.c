#include <stdio.h>

int main() {

    int num = 10;  // Declaração de uma variável inteira
    printf("Valor da variavel: %d\n", num); // print do valor da variável 
    printf("Endereco da variavel: %p\n", (void*)&num); // (void*) é usado para compatibilidade com diferentes compiladores.
    
    return 0;
}
