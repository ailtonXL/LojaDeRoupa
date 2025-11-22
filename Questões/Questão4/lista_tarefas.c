#include "lista_tarefas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
** Função: Implementação do TAD Lista Encadeada de Tarefas (To-Do List)
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data: 10/06/2025]
** Observações: Contém a lógica das operações da lista encadeada para tarefas.
*/

ListaTarefas* criar_lista_tarefas() {
    ListaTarefas *nova_lista = (ListaTarefas*) malloc(sizeof(ListaTarefas));
    if (nova_lista == NULL) {
        printf("Erro ao alocar memoria para a lista de tarefas.\n");
        return NULL;
    }
    nova_lista->inicio = NULL;
    nova_lista->tamanho = 0;
    return nova_lista;
}

void destruir_lista_tarefas(ListaTarefas *lista) {
    if (lista != NULL) {
        NoListaTarefa *atual = lista->inicio;
        while (atual != NULL) {
            NoListaTarefa *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        free(lista);
        printf("Lista de tarefas destruida.\n");
    }
}

int lista_tarefas_vazia(ListaTarefas *lista) {
    return lista == NULL || lista->inicio == NULL;
}

int adicionar_tarefa_inicio(ListaTarefas *lista, Tarefa nova_tarefa) {
    if (lista == NULL) {
        printf("Lista de tarefas nao inicializada.\n");
        return 0;
    }
    NoListaTarefa *novo_no = (NoListaTarefa*) malloc(sizeof(NoListaTarefa));
    if (novo_no == NULL) {
        printf("Erro ao alocar memoria para o novo no da tarefa.\n");
        return 0;
    }
    novo_no->dados = nova_tarefa;
    novo_no->prox = lista->inicio;
    lista->inicio = novo_no;
    lista->tamanho++;
    printf("Tarefa '%s' adicionada no inicio da To-Do List.\n", nova_tarefa.descricao);
    return 1;
}

int adicionar_tarefa_final(ListaTarefas *lista, Tarefa nova_tarefa) {
    if (lista == NULL) {
        printf("Lista de tarefas nao inicializada.\n");
        return 0;
    }
    NoListaTarefa *novo_no = (NoListaTarefa*) malloc(sizeof(NoListaTarefa));
    if (novo_no == NULL) {
        printf("Erro ao alocar memoria para o novo no da tarefa.\n");
        return 0;
    }
    novo_no->dados = nova_tarefa;
    novo_no->prox = NULL;

    if (lista_tarefas_vazia(lista)) {
        lista->inicio = novo_no;
    } else {
        NoListaTarefa *atual = lista->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo_no;
    }
    lista->tamanho++;
    printf("Tarefa '%s' adicionada no final da To-Do List.\n", nova_tarefa.descricao);
    return 1;
}

NoListaTarefa* buscar_tarefa_por_descricao(ListaTarefas *lista, const char *descricao) {
    if (lista_tarefas_vazia(lista)) {
        return NULL;
    }
    NoListaTarefa *atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->dados.descricao, descricao) == 0) {
            return atual; // Retorna o ponteiro para o nó
        }
        atual = atual->prox;
    }
    return NULL; // Tarefa não encontrada
}

int remover_tarefa(ListaTarefas *lista, const char *descricao) {
    if (lista_tarefas_vazia(lista)) {
        printf("Lista de tarefas vazia.\n");
        return 0;
    }

    NoListaTarefa *atual = lista->inicio;
    NoListaTarefa *anterior = NULL;

    while (atual != NULL && strcmp(atual->dados.descricao, descricao) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Tarefa '%s' nao encontrada para remocao.\n", descricao);
        return 0; // Falha: tarefa não encontrada
    }

    if (anterior == NULL) { // Remove o primeiro elemento
        lista->inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }
    free(atual); // Libera a memória do nó
    lista->tamanho--;
    printf("Tarefa '%s' removida com sucesso da To-Do List.\n", descricao);
    return 1; // Sucesso
}

void imprimir_lista_tarefas(ListaTarefas *lista) {
    if (lista_tarefas_vazia(lista)) {
        printf("To-Do List vazia.\n");
        return;
    }
    printf("--- To-Do List (%d Tarefas) ---\n", lista->tamanho);
    NoListaTarefa *atual = lista->inicio;
    while (atual != NULL) {
        imprimir_tarefa(&(atual->dados));
        atual = atual->prox;
    }
}

int contar_tarefas_recursivo(NoListaTarefa *no_atual) {
    if (no_atual == NULL) {
        return 0;
    }
    return 1 + contar_tarefas_recursivo(no_atual->prox);
}