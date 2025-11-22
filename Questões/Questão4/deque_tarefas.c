#include "deque_tarefas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
** Função: Implementação do TAD Deque para Manipulação de Tarefas
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data: 10/06/2025]
** Observações: Contém a lógica das operações do deque para tarefas.
*/

DequeTarefas* criar_deque_tarefas() {
    DequeTarefas *novo_deque = (DequeTarefas*) malloc(sizeof(DequeTarefas));
    if (novo_deque == NULL) {
        printf("Erro ao alocar memoria para o deque de tarefas.\n");
        return NULL;
    }
    novo_deque->frente = NULL;
    novo_deque->re_final = NULL;
    novo_deque->tamanho = 0;
    return novo_deque;
}

void destruir_deque_tarefas(DequeTarefas *deque) {
    if (deque != NULL) {
        NoDequeTarefa *atual = deque->frente;
        while (atual != NULL) {
            NoDequeTarefa *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        free(deque);
        printf("Deque de tarefas destruido.\n");
    }
}

int deque_tarefas_vazio(DequeTarefas *deque) {
    return deque == NULL || deque->frente == NULL;
}

int adicionar_frente_deque_tarefa(DequeTarefas *deque, Tarefa t) {
    if (deque == NULL) {
        printf("Deque de tarefas nao inicializado.\n");
        return 0;
    }
    NoDequeTarefa *novo_no = (NoDequeTarefa*) malloc(sizeof(NoDequeTarefa));
    if (novo_no == NULL) {
        printf("Erro ao alocar memoria para novo no do deque.\n");
        return 0;
    }
    novo_no->dados = t;
    novo_no->ant = NULL;
    novo_no->prox = deque->frente;

    if (deque_tarefas_vazio(deque)) {
        deque->re_final = novo_no;
    } else {
        deque->frente->ant = novo_no;
    }
    deque->frente = novo_no;
    deque->tamanho++;
    printf("Tarefa '%s' adicionada na frente do deque.\n", t.descricao);
    return 1;
}

int adicionar_final_deque_tarefa(DequeTarefas *deque, Tarefa t) {
    if (deque == NULL) {
        printf("Deque de tarefas nao inicializado.\n");
        return 0;
    }
    NoDequeTarefa *novo_no = (NoDequeTarefa*) malloc(sizeof(NoDequeTarefa));
    if (novo_no == NULL) {
        printf("Erro ao alocar memoria para novo no do deque.\n");
        return 0;
    }
    novo_no->dados = t;
    novo_no->prox = NULL;
    novo_no->ant = deque->re_final;

    if (deque_tarefas_vazio(deque)) {
        deque->frente = novo_no;
    } else {
        deque->re_final->prox = novo_no;
    }
    deque->re_final = novo_no;
    deque->tamanho++;
    printf("Tarefa '%s' adicionada no final do deque.\n", t.descricao);
    return 1;
}

Tarefa* remover_frente_deque_tarefa(DequeTarefas *deque) {
    if (deque_tarefas_vazio(deque)) {
        printf("Deque de tarefas vazio.\n");
        return NULL;
    }
    NoDequeTarefa *no_removido = deque->frente;
    Tarefa *tarefa_removida = (Tarefa*) malloc(sizeof(Tarefa));
    if (tarefa_removida == NULL) {
        printf("Erro ao alocar memoria para tarefa removida.\n");
        return NULL;
    }
    *tarefa_removida = no_removido->dados;
    deque->frente = no_removido->prox;

    if (deque->frente == NULL) { // Se o deque ficou vazio
        deque->re_final = NULL;
    } else {
        deque->frente->ant = NULL;
    }
    free(no_removido);
    deque->tamanho--;
    printf("Tarefa '%s' removida da frente do deque.\n", tarefa_removida->descricao);
    return tarefa_removida; // O chamador deve liberar esta memória!
}

Tarefa* remover_final_deque_tarefa(DequeTarefas *deque) {
    if (deque_tarefas_vazio(deque)) {
        printf("Deque de tarefas vazio.\n");
        return NULL;
    }
    NoDequeTarefa *no_removido = deque->re_final;
    Tarefa *tarefa_removida = (Tarefa*) malloc(sizeof(Tarefa));
    if (tarefa_removida == NULL) {
        printf("Erro ao alocar memoria para tarefa removida.\n");
        return NULL;
    }
    *tarefa_removida = no_removido->dados;
    deque->re_final = no_removido->ant;

    if (deque->re_final == NULL) { // Se o deque ficou vazio
        deque->frente = NULL;
    } else {
        deque->re_final->prox = NULL;
    }
    free(no_removido);
    deque->tamanho--;
    printf("Tarefa '%s' removida do final do deque.\n", tarefa_removida->descricao);
    return tarefa_removida; // O chamador deve liberar esta memória!
}

void imprimir_deque_tarefas(DequeTarefas *deque) {
    if (deque_tarefas_vazio(deque)) {
        printf("Deque de tarefas esta vazio.\n");
        return;
    }
    printf("--- Deque de Tarefas (%d Tarefas) ---\n", deque->tamanho);
    NoDequeTarefa *atual = deque->frente;
    while (atual != NULL) {
        imprimir_tarefa(&(atual->dados));
        atual = atual->prox;
    }
}