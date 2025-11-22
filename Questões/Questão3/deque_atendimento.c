#include "deque_atendimento.h"
#include <stdio.h>
#include <stdlib.h>

/*
** Função: Implementação do TAD Deque para Atendimento de Estudantes
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Contém a lógica das operações do deque para atendimento.
*/

DequeAtendimento* criar_deque_atendimento() {
    DequeAtendimento *novo_deque = (DequeAtendimento*) malloc(sizeof(DequeAtendimento));
    if (novo_deque == NULL) {
        printf("Erro ao alocar memoria para o deque de atendimento.\n");
        return NULL;
    }
    novo_deque->frente = NULL;
    novo_deque->re_final = NULL;
    novo_deque->tamanho = 0;
    return novo_deque;
}

void destruir_deque_atendimento(DequeAtendimento *deque) {
    if (deque != NULL) {
        NoDequeAtendimento *atual = deque->frente;
        while (atual != NULL) {
            NoDequeAtendimento *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        free(deque);
        printf("Deque de atendimento destruido.\n");
    }
}

int deque_atendimento_vazio(DequeAtendimento *deque) {
    return deque == NULL || deque->frente == NULL;
}

int adicionar_frente_deque(DequeAtendimento *deque, int matricula) {
    if (deque == NULL) {
        printf("Deque de atendimento nao inicializado.\n");
        return 0;
    }
    NoDequeAtendimento *novo_no = (NoDequeAtendimento*) malloc(sizeof(NoDequeAtendimento));
    if (novo_no == NULL) {
        printf("Erro ao alocar memoria para novo no do deque.\n");
        return 0;
    }
    novo_no->matricula_estudante = matricula;
    novo_no->ant = NULL;
    novo_no->prox = deque->frente;

    if (deque_atendimento_vazio(deque)) {
        deque->re_final = novo_no;
    } else {
        deque->frente->ant = novo_no;
    }
    deque->frente = novo_no;
    deque->tamanho++;
    printf("Estudante com matricula %d adicionado na frente do deque de atendimento.\n", matricula);
    return 1;
}

int adicionar_final_deque(DequeAtendimento *deque, int matricula) {
    if (deque == NULL) {
        printf("Deque de atendimento nao inicializado.\n");
        return 0;
    }
    NoDequeAtendimento *novo_no = (NoDequeAtendimento*) malloc(sizeof(NoDequeAtendimento));
    if (novo_no == NULL) {
        printf("Erro ao alocar memoria para novo no do deque.\n");
        return 0;
    }
    novo_no->matricula_estudante = matricula;
    novo_no->prox = NULL;
    novo_no->ant = deque->re_final;

    if (deque_atendimento_vazio(deque)) {
        deque->frente = novo_no;
    } else {
        deque->re_final->prox = novo_no;
    }
    deque->re_final = novo_no;
    deque->tamanho++;
    printf("Estudante com matricula %d adicionado no final do deque de atendimento.\n", matricula);
    return 1;
}

int remover_frente_deque(DequeAtendimento *deque) {
    if (deque_atendimento_vazio(deque)) {
        printf("Deque de atendimento vazio.\n");
        return -1; // Indica erro
    }
    NoDequeAtendimento *no_removido = deque->frente;
    int matricula_removida = no_removido->matricula_estudante;
    deque->frente = no_removido->prox;

    if (deque->frente == NULL) { // Se o deque ficou vazio
        deque->re_final = NULL;
    } else {
        deque->frente->ant = NULL;
    }
    free(no_removido);
    deque->tamanho--;
    return matricula_removida;
}

int remover_final_deque(DequeAtendimento *deque) {
    if (deque_atendimento_vazio(deque)) {
        printf("Deque de atendimento vazio.\n");
        return -1; // Indica erro
    }
    NoDequeAtendimento *no_removido = deque->re_final;
    int matricula_removida = no_removido->matricula_estudante;
    deque->re_final = no_removido->ant;

    if (deque->re_final == NULL) { // Se o deque ficou vazio
        deque->frente = NULL;
    } else {
        deque->re_final->prox = NULL;
    }
    free(no_removido);
    deque->tamanho--;
    return matricula_removida;
}

void imprimir_deque_atendimento(DequeAtendimento *deque) {
    if (deque_atendimento_vazio(deque)) {
        printf("Deque de atendimento esta vazio.\n");
        return;
    }
    printf("Deque de Atendimento (tamanho: %d): [", deque->tamanho);
    NoDequeAtendimento *atual = deque->frente;
    while (atual != NULL) {
        printf("%d", atual->matricula_estudante);
        atual = atual->prox;
        if (atual != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}