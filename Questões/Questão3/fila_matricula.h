#ifndef FILA_MATRICULA_H
#define FILA_MATRICULA_H

/*
** Função: Interface do TAD Fila para Matrícula de Estudantes
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Define as operações para uma fila dinâmica de matrículas de estudantes.
*/

// Estrutura para um nó da fila
typedef struct NoFilaMatricula {
    int matricula_estudante;
    struct NoFilaMatricula *prox;
} NoFilaMatricula;

// Estrutura da Fila
typedef struct {
    NoFilaMatricula *frente;
    NoFilaMatricula *re_final;
    int tamanho;
} FilaMatricula;

// Protótipos das funções
FilaMatricula* criar_fila_matricula();
void destruir_fila_matricula(FilaMatricula *fila);
int enfileirar_matricula(FilaMatricula *fila, int matricula);
int desenfileirar_matricula(FilaMatricula *fila); // Retorna a matrícula removida, ou -1 se erro
int fila_matricula_vazia(FilaMatricula *fila);
void imprimir_fila_matricula(FilaMatricula *fila);

#endif