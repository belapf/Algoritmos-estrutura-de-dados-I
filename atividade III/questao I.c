#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeroAlunos;

    // Solicita ao usuário o número de alunos
    printf("Digite o numero de alunos na turma: ");
    scanf("%d", &numeroAlunos);

    // Verifica se o número de alunos é válido
    if (numeroAlunos <= 0) {
        printf("Numero de alunos invalido!\n");
        return 1;
    }

    // Aloca dinamicamente um vetor para armazenar as notas
    double* notas = (double*)malloc(numeroAlunos * sizeof(double));
    if (notas == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // Solicita ao usuário as notas dos alunos
    for (int i = 0; i < numeroAlunos; ++i) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%lf", &notas[i]);
    }

    // Solicita ao usuário os índices dos alunos cujas notas deseja exibir
    int aluno1, aluno2;
    printf("Digite o numero do primeiro aluno (1 a %d): ", numeroAlunos);
    scanf("%d", &aluno1);
    printf("Digite o numero do segundo aluno (1 a %d): ", numeroAlunos);
    scanf("%d", &aluno2);

    // Verifica se os números dos alunos são válidos
    if (aluno1 < 1 || aluno1 > numeroAlunos || aluno2 < 1 || aluno2 > numeroAlunos) {
        printf("Numero de aluno invalido!\n");
        free(notas);
        return 1;
    }

    // Exibe as notas dos alunos especificados
    printf("Nota do aluno %d: %.2f\n", aluno1, notas[aluno1 - 1]);
    printf("Nota do aluno %d: %.2f\n", aluno2, notas[aluno2 - 1]);

    // Libera a memória alocada
    free(notas);

    return 0;
}
