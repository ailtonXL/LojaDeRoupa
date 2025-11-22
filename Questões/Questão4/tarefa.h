#ifndef TAREFA_H
#define TAREFA_H

/*
** Função: Interface do TAD Tarefa
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data: 10/06/2025]
** Observações: Define a estrutura de uma tarefa para o sistema To-Do List.
*/

typedef struct {
    char descricao[100];
    int prioridade;    // 1 (baixa), 2 (média), 3 (alta)
    int dataVencimento; // formato DDMMYYYY
} Tarefa;

// Funções básicas para Tarefa (se necessário)
void imprimir_tarefa(Tarefa *t);

#endif