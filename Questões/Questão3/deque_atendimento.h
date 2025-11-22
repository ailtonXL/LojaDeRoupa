#ifndef DEQUE_ATENDIMENTO_H
#define DEQUE_ATENDIMENTO_H

/*
** Função: Interface do TAD Deque para Atendimento de Estudantes
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Define as operações para um deque de matrículas de estudantes.
*/

// Estrutura para um nó do deque (lista duplamente encadeada)
typedef struct NoDequeAtendimento {
    int matricula_estudante;
    struct NoDequeAtendimento *prox;
    struct NoDequeAtendimento *ant;
} NoDequeAtendimento;

// Estrutura do Deque
typedef struct {
    NoDequeAtendimento *frente;
    NoDequeAtendimento *re_final;
    int tamanho;
} DequeAtendimento;

// Protótipos das funções
DequeAtendimento* criar_deque_atendimento();
void destruir_deque_atendimento(DequeAtendimento *deque);
int adicionar_frente_deque(DequeAtendimento *deque, int matricula);
int adicionar_final_deque(DequeAtendimento *deque, int matricula);
int remover_frente_deque(DequeAtendimento *deque); // Retorna a matrícula removida, ou -1 se erro
int remover_final_deque(DequeAtendimento *deque);  // Retorna a matrícula removida, ou -1 se erro
int deque_atendimento_vazio(DequeAtendimento *deque);
void imprimir_deque_atendimento(DequeAtendimento *deque);

#endif