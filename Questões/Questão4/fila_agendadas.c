#include "fila_agendadas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
** Função: Implementação do TAD Fila de Tarefas Agendadas
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data: 10/06/2025]
** Observações: Contém a lógica das operações da fila para tarefas agendadas.
*/

FilaAgendadas* criar_fila_agendadas() {
    FilaAgendadas *nova_fila = (FilaAgendadas*) malloc(sizeof(FilaAgendadas));
    if (nova_fila == NULL) {
        printf("Erro ao alocar memoria para a fila de agendadas.\n");
        return NULL;
    }
    nova_fila->frente = NULL;
    nova_fila->re_final = NULL;
    nova_fila->tamanho = 0;
    return nova_fila;
}

void destruir_fila_agendadas(FilaAgendadas *fila) {
    if (fila != NULL) {
        NoFilaAgendada *atual = fila->frente;
        while (atual != NULL) {
            NoFilaAgendada *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        free(fila);
        printf("Fila de tarefas agendadas destruida.\n");
    }
}

int fila_agendadas_vazia(FilaAgendadas *fila) {
    return fila == NULL || fila->frente == NULL;
}

int enfileirar_tarefa_agendada(FilaAgendadas *fila, Tarefa t) {
    if (fila == NULL) {
        printf("Fila de tarefas agendadas nao inicializada.\n");
        return 0;
    }
    NoFilaAgendada *novo_no = (NoFilaAgendada*) malloc(sizeof(NoFilaAgendada));
    if (novo_no == NULL) {
        printf("Erro ao alocar memoria para novo no da fila.\n");
        return 0;
    }
    novo_no->dados = t;
    novo_no->prox = NULL;

    if (fila_agendadas_vazia(fila)) {
        fila->frente = novo_no;
        fila->re_final = novo_no;
    } else {
        fila->re_final->prox = novo_no;
        fila->re_final = novo_no;
    }
    fila->tamanho++;
    printf("Tarefa '%s' agendada e adicionada a fila.\n", t.descricao);
    return 1;
}

Tarefa* desenfileirar_tarefa_agendada(FilaAgendadas *fila) {
    if (fila_agendadas_vazia(fila)) {
        printf("Fila de tarefas agendadas vazia.\n");
        return NULL;
    }
    NoFilaAgendada *no_removido = fila->frente;
    Tarefa *tarefa_desenfileirada = (Tarefa*) malloc(sizeof(Tarefa));
    if (tarefa_desenfileirada == NULL) {
        printf("Erro ao alocar memoria para tarefa desenfileirada.\n");
        return NULL;
    }
    *tarefa_desenfileirada = no_removido->dados;
    fila->frente = no_removido->prox;
    if (fila->frente == NULL) { // Se a fila ficou vazia
        fila->re_final = NULL;
    }
    free(no_removido);
    fila->tamanho--;
    printf("Tarefa '%s' desenfileirada.\n", tarefa_desenfileirada->descricao);
    return tarefa_desenfileirada; // O chamador deve liberar esta memória!
}

void imprimir_fila_agendadas(FilaAgendadas *fila) {
    if (fila_agendadas_vazia(fila)) {
        printf("Fila de tarefas agendadas esta vazia.\n");
        return;
    }
    printf("--- Fila de Tarefas Agendadas (%d Tarefas) ---\n", fila->tamanho);
    NoFilaAgendada *atual = fila->frente;
    while (atual != NULL) {
        imprimir_tarefa(&(atual->dados));
        atual = atual->prox;
        if (atual != NULL) {
            printf("\n"); // Adiciona nova linha entre as tarefas na fila
        }
    }
    printf("\n");
}