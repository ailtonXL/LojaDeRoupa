#ifndef LISTA_TAREFAS_H
#define LISTA_TAREFAS_H

#include "tarefa.h" // Inclui a definição do TAD Tarefa

/*
** Função: Interface do TAD Lista Encadeada de Tarefas (To-Do List)
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data: 10/06/2025]
** Observações: Define as operações para uma lista encadeada de objetos Tarefa.
*/

// Definição do nó da lista
typedef struct NoListaTarefa {
    Tarefa dados;
    struct NoListaTarefa *prox;
} NoListaTarefa;

// Definição da estrutura da Lista de Tarefas
typedef struct {
    NoListaTarefa *inicio;
    int tamanho;
} ListaTarefas;

// Protótipos das funções
ListaTarefas* criar_lista_tarefas();
void destruir_lista_tarefas(ListaTarefas *lista);
int adicionar_tarefa_inicio(ListaTarefas *lista, Tarefa nova_tarefa); // Adiciona no início da lista 
int adicionar_tarefa_final(ListaTarefas *lista, Tarefa nova_tarefa); // Adiciona no final da lista 
NoListaTarefa* buscar_tarefa_por_descricao(ListaTarefas *lista, const char *descricao); // Retorna o nó, não a Tarefa diretamente
int remover_tarefa(ListaTarefas *lista, const char *descricao); // Remove uma tarefa da lista
void imprimir_lista_tarefas(ListaTarefas *lista);
int lista_tarefas_vazia(ListaTarefas *lista);
int contar_tarefas_recursivo(NoListaTarefa *no_atual); // Função recursiva para contar tarefas 

#endif