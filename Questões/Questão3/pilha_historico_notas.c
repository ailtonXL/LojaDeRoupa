#include "pilha_historico_notas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para memcpy

/*
** Função: Implementação do TAD Pilha para Histórico de Notas
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Contém a lógica das operações da pilha para histórico de notas.
*/

PilhaHistoricoNotas* criar_pilha_historico() {
    PilhaHistoricoNotas *nova_pilha = (PilhaHistoricoNotas*) malloc(sizeof(PilhaHistoricoNotas));
    if (nova_pilha == NULL) {
        printf("Erro ao alocar memoria para a pilha de historico.\n");
        return NULL;
    }
    nova_pilha->topo = NULL;
    nova_pilha->tamanho = 0;
    return nova_pilha;
}

void destruir_pilha_historico(PilhaHistoricoNotas *pilha) {
    if (pilha != NULL) {
        NoPilhaNotas *atual = pilha->topo;
        while (atual != NULL) {
            NoPilhaNotas *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        free(pilha);
        printf("Pilha de historico de notas destruida.\n");
    }
}

int pilha_historico_vazia(PilhaHistoricoNotas *pilha) {
    return pilha == NULL || pilha->topo == NULL;
}

int empilhar_notas_historico(PilhaHistoricoNotas *pilha, float *notas) {
    if (pilha == NULL || notas == NULL) {
        printf("Pilha ou notas invalidas para empilhar.\n");
        return 0;
    }
    NoPilhaNotas *novo_no = (NoPilhaNotas*) malloc(sizeof(NoPilhaNotas));
    if (novo_no == NULL) {
        printf("Erro ao alocar memoria para novo no da pilha.\n");
        return 0;
    }
    // Copia o array de notas para o nó da pilha
    memcpy(novo_no->notas_anteriores, notas, NUM_NOTAS * sizeof(float));
    novo_no->prox = pilha->topo;
    pilha->topo = novo_no;
    pilha->tamanho++;
    printf("Historico de notas empilhado.\n");
    return 1;
}

int desempilhar_notas_historico(PilhaHistoricoNotas *pilha, float *notas_destino) {
    if (pilha_historico_vazia(pilha)) {
        printf("Pilha de historico vazia.\n");
        return 0;
    }
    NoPilhaNotas *no_removido = pilha->topo;
    // Copia as notas do topo da pilha para o destino
    memcpy(notas_destino, no_removido->notas_anteriores, NUM_NOTAS * sizeof(float));
    pilha->topo = no_removido->prox;
    free(no_removido);
    pilha->tamanho--;
    printf("Historico de notas desempilhado.\n");
    return 1;
}

void imprimir_topo_historico(PilhaHistoricoNotas *pilha) {
    if (pilha_historico_vazia(pilha)) {
        printf("Pilha de historico de notas vazia.\n");
        return;
    }
    printf("Topo do historico de notas: [");
    for (int i = 0; i < NUM_NOTAS; i++) {
        printf("%.1f", pilha->topo->notas_anteriores[i]);
        if (i < NUM_NOTAS - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}