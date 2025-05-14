#include <stdio.h>

// Definindo o tipo de dado Horário
typedef struct {
    int horas;   // Campo para armazenar as horas
    int minutos; // Campo para armazenar os minutos
} Horario;

// Função MostrarHorario que exibe o horário no formato HH:MM
void MostrarHorario(Horario *h) {
    printf("Horario: %02d:%02d\n", h->horas, h->minutos);
}

// Função principal
int main() {
    // Declarando uma variável do tipo Horário
    Horario horarioAtual;
    
    // Criando um ponteiro para a variável Horário
    Horario *ponteiro = &horarioAtual;
    
    // Pedindo ao usuário para digitar o horário atual
    printf("Digite o horario atual: ");
    scanf("%d %d", &ponteiro->horas, &ponteiro->minutos);
    
    // Exibindo o horário recebido
    printf("Horario original: ");
    MostrarHorario(ponteiro);
    
    // Incrementando o horário em uma hora
    ponteiro->horas++;
    
    // Se as horas ultrapassarem 23, corrigir para 0 ou seja, o dia seguinte
    if (ponteiro->horas == 24) {
        ponteiro->horas = 0;
    }
    
    // Exibindo o horário corrigido
    printf("Horario apos adicionar uma hora: ");
    MostrarHorario(ponteiro);
    
    return 0;
}
