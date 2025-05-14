#include <stdio.h>
#include <string.h>

// Enumeração para os tipos de imagem
typedef enum { JPG, PNG, BMP } TipoImagem;

// Estrutura para armazenar os dados da imagem
typedef struct {
    char nome[100];  // Nome do arquivo
    int altura;      // Altura da imagem
    int largura;     // Largura da imagem
    TipoImagem tipo; // Tipo da imagem (JPG, PNG, BMP)
} Imagem;

// Função para exibir os detalhes da imagem
void Detalhes(Imagem *img) {
    // Converter o tipo da imagem em string
    char *tipoString;
    switch (img->tipo) {
        case JPG: tipoString = "jpg"; break;
        case PNG: tipoString = "png"; break;
        case BMP: tipoString = "bmp"; break;
        default: tipoString = "desconhecido"; break;
    }

    // Exibir os detalhes no formato especificado
    printf("A imagem \"%s\" com tamanho %dx%d tem formato %s\n",
           img->nome, img->largura, img->altura, tipoString);
}

int main() {
    // Criando e inicializando uma variável do tipo Imagem
    Imagem minhaImagem;
    
    // Atribuindo valores manualmente
    strcpy(minhaImagem.nome, "backg.png");
    minhaImagem.largura = 1920;
    minhaImagem.altura = 1080;
    minhaImagem.tipo = PNG;  // Definindo o tipo como PNG

    // Chamando a função Detalhes e passando o endereço da imagem
    Detalhes(&minhaImagem);

    return 0;
}
