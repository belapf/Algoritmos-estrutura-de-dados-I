#include <stdio.h>

int main () {
  
    char ch = 'G';
    char *ptr = &ch;
    printf("Endereco de 'ch': %p\n", ptr);
    printf("Valor de 'ch': %c\n", *ptr);

   return 0;
}
