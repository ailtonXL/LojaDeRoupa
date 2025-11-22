#include "fila_matricula.h"
#include <stdio.h>
#include <stdlib.h>

/*
** Função: Implementação do TAD Fila para Matrícula de Estudantes
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Contém a lógica das operações da fila para matrículas.
*/

FilaMatricula* criar_fila_matricula() {
    FilaMatricula *nova_fila = (FilaMatricula*) malloc(sizeof(FilaMatricula));
    if (nova_fila == NULL) {
        printf("Erro ao alocar memoria para a fila de matricula.\n");
        return NULL;
    }
    nova_fila->frente = NULL;
    nova_fila->re_final = NULL;
    nova_fila->tamanho = 0;
    return nova_fila;
}

void destruir_fila_matricula(FilaMatricula *fila) {
    if (fila != NULL) {
        NoFilaMatricula *atual = fila->frente;
        while (atual != NULL) {
            NoFilaMatricula *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        free(fila);
        printf("Fila de matricula destruida.\n");
    }
}

int fila_matricula_vazia(FilaMatricula *fila) {
    return fila == NULL || fila->frente == NULL;
}

int enfileirar_matricula(FilaMatricula *fila, int matricula) {
    if (fila == NULL) {
        printf("Fila de matricula nao inicializada.\n");
        return 0;
    }
    NoFilaMatricula *novo_no = (NoFilaMatricula*) malloc(sizeof(NoFilaMatricula));
    if (novo_no == NULL) {
        printf("Erro ao alocar memoria para novo no da fila.\n");
        return 0;
    }
    novo_no->matricula_estudante = matricula;
    novo_no->prox = NULL;

    if (fila_matricula_vazia(fila)) {
        fila->frente = novo_no;
        fila->re_final = novo_no;
    } else {
        fila->re_final->prox = novo_no;
        fila->re_final = novo_no;
    }
    fila->tamanho++;
    printf("Estudante com matricula %d adicionado a fila de matricula.\n", matricula);
    return 1;
}

int desenfileirar_matricula(FilaMatricula *fila) {
    if (fila_matricula_vazia(fila)) {
        printf("Fila de matricula vazia.\n");
        return -1; // Indica erro
    }
    NoFilaMatricula *no_removido = fila->frente;
    int matricula_removida = no_removido->matricula_estudante;
    fila->frente = no_removido->prox;
    if (fila->frente == NULL) { // Se a fila ficou vazia
        fila->re_final = NULL;
    }
    free(no_removido);
    fila->tamanho--;
    return matricula_removida;
}

void imprimir_fila_matricula(FilaMatricula *fila) {
    if (fila_matricula_vazia(fila)) {
        printf("Fila de matricula esta vazia.\n");
        return;
    }
    printf("Fila de Matricula (tamanho: %d): [", fila->tamanho);
    NoFilaMatricula *atual = fila->frente;
    while (atual != NULL) {
        printf("%d", atual->matricula_estudante);
        atual = atual->prox;
        if (atual != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}