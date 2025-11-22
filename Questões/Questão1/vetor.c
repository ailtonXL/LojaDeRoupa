#include "vetor.h"
#include <stdio.h>
#include <stdlib.h> // Para malloc, realloc, free

/*
** Função: Implementação do TAD Vetor de Inteiros Dinâmico
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Contém a lógica das operações do TAD Vetor.
*/

// Implementação da função de criação do vetor
Vetor* criar_vetor(int capacidade_inicial) {
    Vetor *novo_vetor = (Vetor*) malloc(sizeof(Vetor));
    if (novo_vetor == NULL) {
        printf("Erro ao alocar memoria para o vetor!\n");
        return NULL;
    }
    novo_vetor->elementos = (int*) malloc(capacidade_inicial * sizeof(int));
    if (novo_vetor->elementos == NULL) {
        printf("Erro ao alocar memoria para os elementos do vetor!\n");
        free(novo_vetor);
        return NULL;
    }
    novo_vetor->tamanho = 0;
    novo_vetor->capacidade = capacidade_inicial;
    return novo_vetor;
}

// Implementação da função de inserção de um elemento
void inserir_elemento(Vetor *v, int elemento) {
    if (v == NULL) {
        printf("Vetor nao inicializado.\n");
        return;
    }
    // Se o vetor estiver cheio, dobra a capacidade
    if (v->tamanho == v->capacidade) {
        int nova_capacidade = v->capacidade * 2;
        int *novos_elementos = (int*) realloc(v->elementos, nova_capacidade * sizeof(int));
        if (novos_elementos == NULL) {
            printf("Erro ao realocar memoria para o vetor.\n");
            return;
        }
        v->elementos = novos_elementos;
        v->capacidade = nova_capacidade;
        printf("Capacidade do vetor aumentada para %d.\n", v->capacidade);
    }
    v->elementos[v->tamanho] = elemento;
    v->tamanho++;
}

// Implementação da função de remoção de um elemento
int remover_elemento(Vetor *v, int posicao) {
    if (v == NULL || v->tamanho == 0 || posicao < 0 || posicao >= v->tamanho) {
        printf("Erro: Vetor vazio ou posicao invalida.\n");
        return -1; // Indica erro
    }
    int elemento_removido = v->elementos[posicao];
    // Desloca os elementos para a esquerda
    for (int i = posicao; i < v->tamanho - 1; i++) {
        v->elementos[i] = v->elementos[i + 1];
    }
    v->tamanho--;
    return elemento_removido;
}

// Implementação da função de consulta de um elemento em uma determinada posição
int consultar_elemento(Vetor *v, int posicao) {
    if (v == NULL || posicao < 0 || posicao >= v->tamanho) {
        printf("Erro: Vetor vazio ou posicao invalida para consulta.\n");
        return -99999; // Valor para indicar erro (assumindo que -99999 não é um valor válido no vetor)
    }
    return v->elementos[posicao];
}

// Implementação da função de impressão dos elementos do vetor
void imprimir_vetor(Vetor *v) {
    if (v == NULL || v->tamanho == 0) {
        printf("Vetor vazio.\n");
        return;
    }
    printf("Elementos do vetor (Tamanho: %d, Capacidade: %d): [", v->tamanho, v->capacidade);
    for (int i = 0; i < v->tamanho; i++) {
        printf("%d", v->elementos[i]);
        if (i < v->tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Implementação da função de remoção do vetor inteiro
void destruir_vetor(Vetor *v) {
    if (v != NULL) {
        free(v->elementos); // Libera a memória alocada para os elementos
        free(v);            // Libera a memória alocada para a estrutura do vetor
        printf("Vetor destruido com sucesso.\n");
    }
}