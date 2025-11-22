#ifndef LISTA_ESTUDANTES_H
#define LISTA_ESTUDANTES_H

#include "estudante.h" // Inclui a definição do TAD Estudante

/*
** Função: Interface do TAD Lista Encadeada de Estudantes
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Define as operações para uma lista encadeada de objetos Estudante.
*/

// Definição do nó da lista
typedef struct NoListaEstudante {
    Estudante dados;
    struct NoListaEstudante *prox;
} NoListaEstudante;

// Definição da estrutura da Lista de Estudantes
typedef struct {
    NoListaEstudante *inicio;
    int tamanho;
} ListaEstudantes;

// Protótipos das funções
ListaEstudantes* criar_lista_estudantes();
void destruir_lista_estudantes(ListaEstudantes *lista);
int adicionar_estudante(ListaEstudantes *lista, Estudante novo_estudante);
int remover_estudante(ListaEstudantes *lista, int matricula);
Estudante* buscar_estudante(ListaEstudantes *lista, int matricula);
void imprimir_lista_estudantes(ListaEstudantes *lista);
int lista_estudantes_vazia(ListaEstudantes *lista);

#endif