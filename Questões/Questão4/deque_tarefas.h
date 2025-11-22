#ifndef DEQUE_TAREFAS_H
#define DEQUE_TAREFAS_H

#include "tarefa.h" // Inclui a definição do TAD Tarefa

/*
** Função: Interface do TAD Deque para Manipulação de Tarefas
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data: 10/06/2025]
** Observações: Define as operações para um deque de objetos Tarefa.
*/

// Estrutura para um nó do deque (lista duplamente encadeada)
typedef struct NoDequeTarefa {
    Tarefa dados;
    struct NoDequeTarefa *prox;
    struct NoDequeTarefa *ant;
} NoDequeTarefa;

// Estrutura do Deque
typedef struct {
    NoDequeTarefa *frente;
    NoDequeTarefa *re_final;
    int tamanho;
} DequeTarefas;

// Protótipos das funções
DequeTarefas* criar_deque_tarefas();
void destruir_deque_tarefas(DequeTarefas *deque);
int adicionar_frente_deque_tarefa(DequeTarefas *deque, Tarefa t);
int adicionar_final_deque_tarefa(DequeTarefas *deque, Tarefa t);
Tarefa* remover_frente_deque_tarefa(DequeTarefas *deque); // Retorna a tarefa removida, ou NULL
Tarefa* remover_final_deque_tarefa(DequeTarefas *deque);  // Retorna a tarefa removida, ou NULL
int deque_tarefas_vazio(DequeTarefas *deque);
void imprimir_deque_tarefas(DequeTarefas *deque);

#endif