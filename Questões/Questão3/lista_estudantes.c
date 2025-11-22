#include "lista_estudantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcpy

/*
** Função: Implementação do TAD Lista Encadeada de Estudantes
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Contém a lógica das operações da lista encadeada para estudantes.
*/

ListaEstudantes* criar_lista_estudantes() {
    ListaEstudantes *nova_lista = (ListaEstudantes*) malloc(sizeof(ListaEstudantes));
    if (nova_lista == NULL) {
        printf("Erro ao alocar memoria para a lista de estudantes.\n");
        return NULL;
    }
    nova_lista->inicio = NULL;
    nova_lista->tamanho = 0;
    return nova_lista;
}

void destruir_lista_estudantes(ListaEstudantes *lista) {
    if (lista != NULL) {
        NoListaEstudante *atual = lista->inicio;
        while (atual != NULL) {
            NoListaEstudante *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        free(lista);
        printf("Lista de estudantes destruida.\n");
    }
}

int lista_estudantes_vazia(ListaEstudantes *lista) {
    return lista == NULL || lista->inicio == NULL;
}

int adicionar_estudante(ListaEstudantes *lista, Estudante novo_estudante) {
    if (lista == NULL) {
        printf("Lista de estudantes nao inicializada.\n");
        return 0; // Falha
    }

    // Verificar se a matrícula já existe
    if (buscar_estudante(lista, novo_estudante.matricula) != NULL) {
        printf("Erro: Estudante com matricula %d ja existe na lista.\n", novo_estudante.matricula);
        return 0;
    }

    NoListaEstudante *novo_no = (NoListaEstudante*) malloc(sizeof(NoListaEstudante));
    if (novo_no == NULL) {
        printf("Erro ao alocar memoria para o novo estudante.\n");
        return 0; // Falha
    }

    novo_no->dados = novo_estudante; // Copia a struct Estudante
    novo_no->prox = NULL;

    if (lista_estudantes_vazia(lista)) {
        lista->inicio = novo_no;
    } else {
        NoListaEstudante *atual = lista->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo_no;
    }
    lista->tamanho++;
    return 1; // Sucesso
}

int remover_estudante(ListaEstudantes *lista, int matricula) {
    if (lista_estudantes_vazia(lista)) {
        printf("Lista de estudantes vazia.\n");
        return 0; // Falha
    }

    NoListaEstudante *atual = lista->inicio;
    NoListaEstudante *anterior = NULL;

    while (atual != NULL && atual->dados.matricula != matricula) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Estudante com matricula %d nao encontrado para remocao.\n", matricula);
        return 0; // Falha: estudante não encontrado
    }

    if (anterior == NULL) { // Remove o primeiro elemento
        lista->inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }
    free(atual);
    lista->tamanho--;
    printf("Estudante com matricula %d removido com sucesso.\n", matricula);
    return 1; // Sucesso
}

Estudante* buscar_estudante(ListaEstudantes *lista, int matricula) {
    if (lista_estudantes_vazia(lista)) {
        return NULL;
    }

    NoListaEstudante *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->dados.matricula == matricula) {
            return &(atual->dados); // Retorna o endereço da struct Estudante dentro do nó
        }
        atual = atual->prox;
    }
    return NULL; // Estudante não encontrado
}

void imprimir_lista_estudantes(ListaEstudantes *lista) {
    if (lista_estudantes_vazia(lista)) {
        printf("Nenhum estudante registrado.\n");
        return;
    }
    printf("--- Estudantes Registrados (%d) ---\n", lista->tamanho);
    NoListaEstudante *atual = lista->inicio;
    while (atual != NULL) {
        imprimir_estudante(&(atual->dados)); // Usa a função de impressão do TAD Estudante
        atual = atual->prox;
    }
}