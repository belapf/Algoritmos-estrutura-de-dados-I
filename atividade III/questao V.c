#include <stdio.h>
#include <stdlib.h>

// Definição da enumeração para a situação da disciplina
enum Situacao {
    Aprovado,
    Trancado,
    Reprovado,
};

// Definição da estrutura Aluno
struct Aluno {
    char identificador[50]; // Pode ser nome ou matrícula
    unsigned int codigo_disciplina;
    enum Situacao situacao;
};

// Função para exibir os dados de um aluno
void exibirAluno(struct Aluno* aluno) {
    printf("\nDados do Aluno:\n");
    printf("Identificador: %s\n", aluno->identificador);
    printf("Codigo da Disciplina: %u\n", aluno->codigo_disciplina);
    printf("Situacao: ");
    switch (aluno->situacao) {
        case Aprovado:
            printf("Aprovado\n");
            break;
        case Trancado:
            printf("Trancado\n");
            break;
        case Reprovado:
            printf("Reprovado\n");
            break;
    }
}

int main() {
    int numAlunos;

    // Solicita ao usuário o número de alunos
    printf("Digite o numero de alunos: ");
    scanf("%d", &numAlunos);
    getchar(); // Limpar o buffer do teclado

    // Aloca dinamicamente memória para o vetor de alunos
    struct Aluno* alunos = (struct Aluno*)malloc(numAlunos * sizeof(struct Aluno));
    if (alunos == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // Leitura dos dados do primeiro aluno
    printf("\nDigite os dados do primeiro aluno:\n");
    printf("Identificador (nome ou matricula): ");
    fgets(alunos[0].identificador, sizeof(alunos[0].identificador), stdin);
    // Remover o caractere de nova linha, se presente
    size_t len = strlen(alunos[0].identificador);
    if (len > 0 && alunos[0].identificador[len - 1] == '\n') {
        alunos[0].identificador[len - 1] = '\0';
    }
    printf("Codigo da Disciplina: ");
    scanf("%u", &alunos[0].codigo_disciplina);
    printf("Situacao (0 - Aprovado, 1 - Trancado, 2 - Reprovado): ");
    int situacao;
    scanf("%d", &situacao);
    alunos[0].situacao = (enum Situacao)situacao;
    getchar(); // Limpar o buffer do teclado


    exibirAluno(&alunos[0]); // Exibe os dados do primeiro aluno utilizando a função
    
    
    free(alunos); // Libera a memória alocada

    return 0;
}
