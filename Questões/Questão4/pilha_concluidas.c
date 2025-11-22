#include "pilha_concluidas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
** Função: Implementação do TAD Pilha de Tarefas Concluídas
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data: 10/06/2025]
** Observações: Contém a lógica das operações da pilha para tarefas concluídas.
*/

PilhaConcluidas* criar_pilha_concluidas() {
    PilhaConcluidas *nova_pilha = (PilhaConcluidas*) malloc(sizeof(PilhaConcluidas));
    if (nova_pilha == NULL) {
        printf("Erro ao alocar memoria para a pilha de concluidas.\n");
        return NULL;
    }
    nova_pilha->topo = NULL;
    nova_pilha->tamanho = 0;
    return nova_pilha;
}

void destruir_pilha_concluidas(PilhaConcluidas *pilha) {
    if (pilha != NULL) {
        NoPilhaConcluida *atual = pilha->topo;
        while (atual != NULL) {
            NoPilhaConcluida *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        free(pilha);
        printf("Pilha de tarefas concluidas destruida.\n");
    }
}

int pilha_concluidas_vazia(PilhaConcluidas *pilha) {
    return pilha == NULL || pilha->topo == NULL;
}

int empilhar_tarefa_concluida(PilhaConcluidas *pilha, Tarefa t) {
    if (pilha == NULL) {
        printf("Pilha de tarefas concluidas nao inicializada.\n");
        return 0;
    }
    NoPilhaConcluida *novo_no = (NoPilhaConcluida*) malloc(sizeof(NoPilhaConcluida));
    if (novo_no == NULL) {
        printf("Erro ao alocar memoria para novo no da pilha.\n");
        return 0;
    }
    novo_no->dados = t; // Copia a struct Tarefa
    novo_no->prox = pilha->topo;
    pilha->topo = novo_no;
    pilha->tamanho++;
    printf("Tarefa '%s' empilhada como concluida.\n", t.descricao);
    return 1;
}

Tarefa* desempilhar_tarefa_concluida(PilhaConcluidas *pilha) {
    if (pilha_concluidas_vazia(pilha)) {
        printf("Pilha de tarefas concluidas vazia.\n");
        return NULL;
    }
    NoPilhaConcluida *no_removido = pilha->topo;
    Tarefa *tarefa_desempilhada = (Tarefa*) malloc(sizeof(Tarefa));
    if (tarefa_desempilhada == NULL) {
        printf("Erro ao alocar memoria para tarefa desempilhada.\n");
        return NULL;
    }
    *tarefa_desempilhada = no_removido->dados; // Copia os dados da tarefa
    pilha->topo = no_removido->prox;
    free(no_removido);
    pilha->tamanho--;
    printf("Tarefa '%s' desempilhada.\n", tarefa_desempilhada->descricao);
    return tarefa_desempilhada; // O chamador deve liberar esta memória!
}

void imprimir_pilha_concluidas(PilhaConcluidas *pilha) {
    if (pilha_concluidas_vazia(pilha)) {
        printf("Pilha de tarefas concluidas vazia.\n");
        return;
    }
    printf("--- Pilha de Tarefas Concluidas (%d Tarefas) ---\n", pilha->tamanho);
    NoPilhaConcluida *atual = pilha->topo;
    while (atual != NULL) {
        imprimir_tarefa(&(atual->dados));
        atual = atual->prox;
    }
}