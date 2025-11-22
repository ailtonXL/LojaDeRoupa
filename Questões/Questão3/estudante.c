#include "estudante.h"
#include <stdio.h>
#include <string.h>

/*
** Função: Implementação do TAD Estudante
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Contém a lógica das funções para manipulação de dados de estudante.
*/

void imprimir_estudante(Estudante *e) {
    if (e == NULL) {
        printf("Estudante invalido.\n");
        return;
    }
    printf("Matricula: %d, Nome: %s, Notas: ", e->matricula, e->nome);
    for (int i = 0; i < NUM_NOTAS; i++) {
        printf("%.1f ", e->notas[i]);
    }
    printf("\n");
}

float calcular_media_estudante(Estudante *e) {
    if (e == NULL) {
        return 0.0;
    }
    float soma = 0.0;
    for (int i = 0; i < NUM_NOTAS; i++) {
        soma += e->notas[i];
    }
    return soma / NUM_NOTAS;
}