#ifndef FILA_AGENDADAS_H
#define FILA_AGENDADAS_H

#include "tarefa.h" // Inclui a definição do TAD Tarefa

/*
** Função: Interface do TAD Fila de Tarefas Agendadas
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data: 10/06/2025]
** Observações: Define as operações para uma fila dinâmica de tarefas agendadas.
*/

// Estrutura para um nó da fila
typedef struct NoFilaAgendada {
    Tarefa dados;
    struct NoFilaAgendada *prox;
} NoFilaAgendada;

// Estrutura da Fila
typedef struct {
    NoFilaAgendada *frente;
    NoFilaAgendada *re_final;
    int tamanho;
} FilaAgendadas;

// Protótipos das funções
FilaAgendadas* criar_fila_agendadas();
void destruir_fila_agendadas(FilaAgendadas *fila);
int enfileirar_tarefa_agendada(FilaAgendadas *fila, Tarefa t); // Adiciona tarefa agendada 
Tarefa* desenfileirar_tarefa_agendada(FilaAgendadas *fila); // Retorna a tarefa removida, ou NULL
int fila_agendadas_vazia(FilaAgendadas *fila);
void imprimir_fila_agendadas(FilaAgendadas *fila);

#endif