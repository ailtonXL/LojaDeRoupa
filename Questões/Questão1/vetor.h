#ifndef VETOR_H
#define VETOR_H

/*
** Função: Interface do TAD Vetor de Inteiros Dinâmico
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Define as operações para um vetor de inteiros alocado dinamicamente.
*/

// Definição da estrutura do Vetor
typedef struct {
    int *elementos; // Ponteiro para o array de inteiros
    int tamanho;    // Tamanho atual do vetor
    int capacidade; // Capacidade máxima alocada para o vetor
} Vetor;

// Protótipos das funções (operações do TAD)
Vetor* criar_vetor(int capacidade_inicial);
void inserir_elemento(Vetor *v, int elemento);
int remover_elemento(Vetor *v, int posicao); // Retorna o elemento removido, ou -1 se erro
int consultar_elemento(Vetor *v, int posicao); // Retorna o elemento, ou um valor de erro
void imprimir_vetor(Vetor *v);
void destruir_vetor(Vetor *v); // Libera a memória alocada para o vetor

#endif