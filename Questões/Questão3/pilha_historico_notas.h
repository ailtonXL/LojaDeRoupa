#ifndef PILHA_HISTORICO_NOTAS_H
#define PILHA_HISTORICO_NOTAS_H

#include "estudante.h" // Para NUM_NOTAS e contexto de notas

/*
** Função: Interface do TAD Pilha para Histórico de Notas
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Define as operações para uma pilha de históricos de notas de estudantes.
*/

// Estrutura para um nó da pilha
typedef struct NoPilhaNotas {
    float notas_anteriores[NUM_NOTAS]; // Armazena as notas de um histórico
    struct NoPilhaNotas *prox;
} NoPilhaNotas;

// Estrutura da Pilha
typedef struct {
    NoPilhaNotas *topo;
    int tamanho;
} PilhaHistoricoNotas;

// Protótipos das funções
PilhaHistoricoNotas* criar_pilha_historico();
void destruir_pilha_historico(PilhaHistoricoNotas *pilha);
int empilhar_notas_historico(PilhaHistoricoNotas *pilha, float *notas);
int desempilhar_notas_historico(PilhaHistoricoNotas *pilha, float *notas_destino); // Copia as notas para notas_destino
int pilha_historico_vazia(PilhaHistoricoNotas *pilha);
void imprimir_topo_historico(PilhaHistoricoNotas *pilha); // Para depuração

#endif