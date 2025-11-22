#include <stdio.h>
#include "vetor.h" // Inclui a interface do TAD Vetor

/*
** Função: Teste do TAD Vetor de Inteiros Dinâmico
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Programa principal para testar as operações do TAD Vetor.
*/

int main() {
    Vetor *meuVetor;
    int elemento;

    printf("--- Testando TAD Vetor de Inteiros ---\n");

    // 1. Criação do vetor
    meuVetor = criar_vetor(5); // Capacidade inicial de 5
    if (meuVetor == NULL) {
        return 1;
    }
    imprimir_vetor(meuVetor);

    // 2. Inserção de elementos
    printf("\nInserindo elementos...\n");
    inserir_elemento(meuVetor, 10);
    inserir_elemento(meuVetor, 20);
    inserir_elemento(meuVetor, 30);
    inserir_elemento(meuVetor, 40);
    inserir_elemento(meuVetor, 50);
    imprimir_vetor(meuVetor);

    // Inserindo mais um elemento para testar o realloc
    inserir_elemento(meuVetor, 60);
    imprimir_vetor(meuVetor);

    // 3. Consulta de elemento
    printf("\nConsultando elemento na posicao 2: %d\n", consultar_elemento(meuVetor, 2));
    printf("Consultando elemento na posicao 5: %d\n", consultar_elemento(meuVetor, 5));
    printf("Consultando elemento na posicao invalida 10: %d\n", consultar_elemento(meuVetor, 10)); // Teste de erro

    // 4. Remoção de um elemento
    printf("\nRemovendo elemento da posicao 1 (valor %d)...\n", remover_elemento(meuVetor, 1)); // Remove o 20
    imprimir_vetor(meuVetor);

    printf("Removendo elemento da ultima posicao (valor %d)...\n", remover_elemento(meuVetor, meuVetor->tamanho - 1));
    imprimir_vetor(meuVetor);

    // 5. Remoção do vetor inteiro
    printf("\nDestruindo o vetor...\n");
    destruir_vetor(meuVetor);
    // Tentar imprimir após a destruição pode causar erro, pois a memória foi liberada.
    // imprimir_vetor(meuVetor); // Não faça isso!

    return 0;
}