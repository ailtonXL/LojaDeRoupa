#include "tarefa.h"
#include <stdio.h>
#include <string.h>

/*
** Função: Implementação do TAD Tarefa
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data: 10/06/2025]
** Observações: Contém a lógica das funções para manipulação de dados de tarefa.
*/

void imprimir_tarefa(Tarefa *t) {
    if (t == NULL) {
        printf("Tarefa invalida.\n");
        return;
    }
    printf("Descricao: %s | Prioridade: %d | Vencimento: %d\n",
           t->descricao, t->prioridade, t->dataVencimento);
}