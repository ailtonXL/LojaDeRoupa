#ifndef PILHA_CONCLUIDAS_H
#define PILHA_CONCLUIDAS_H

#include "tarefa.h" // Inclui a definição do TAD Tarefa

/*
** Função: Interface do TAD Pilha de Tarefas Concluídas
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data: 10/06/2025]
** Observações: Define as operações para uma pilha de tarefas concluídas.
*/

// Estrutura para um nó da pilha
typedef struct NoPilhaConcluida {
    Tarefa dados;
    struct NoPilhaConcluida *prox;
} NoPilhaConcluida;

// Estrutura da Pilha
typedef struct {
    NoPilhaConcluida *topo;
    int tamanho;
} PilhaConcluidas;

// Protótipos das funções
PilhaConcluidas* criar_pilha_concluidas();
void destruir_pilha_concluidas(PilhaConcluidas *pilha);
int empilhar_tarefa_concluida(PilhaConcluidas *pilha, Tarefa t); // Move da lista para a pilha 
Tarefa* desempilhar_tarefa_concluida(PilhaConcluidas *pilha); // Retorna a tarefa removida do topo, ou NULL
int pilha_concluidas_vazia(PilhaConcluidas *pilha);
void imprimir_pilha_concluidas(PilhaConcluidas *pilha);

#endif