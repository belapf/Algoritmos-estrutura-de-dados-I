#include <stdio.h> 

int main() { 

    int valor = 10, *temp, soma = 0; 
    temp = &valor; 
    *temp = 20; 
    temp = &soma; 
    *temp = valor; 
    
    printf("valor: %d\nsoma: %d\n", valor, soma); 
    
    return 0; 
} 

