#ifndef ESTUDANTE_H
#define ESTUDANTE_H

/*
** Função: Interface do TAD Estudante
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Define a estrutura de um estudante e funções básicas de manipulação.
*/

#define NUM_NOTAS 3 // Supondo 3 notas por estudante 

typedef struct {
    char nome[50];
    int matricula;
    float notas[NUM_NOTAS];
} Estudante;

// Funções básicas para Estudante (se necessário, pode ser apenas a struct)
void imprimir_estudante(Estudante *e);
float calcular_media_estudante(Estudante *e);

#endif