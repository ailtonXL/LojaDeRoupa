#include <stdio.h>
#include <stdlib.h>
#include <string.h>




//Para executar o programa, utilizar o comando no bash: gcc estudante.c lista_estudantes.c pilha_historico_notas.c fila_matricula.c deque_atendimento.c ED-lista2-questao03.c -o sistema_estudantes
// ./sistema_estudantes





// Inclusão dos TADs necessários
#include "estudante.h" // TAD Estudante
#include "lista_estudantes.h" // TAD Lista Encadeada de Estudantes
#include "pilha_historico_notas.h" // TAD Pilha para Histórico de Notas
#include "fila_matricula.h" // TAD Fila para Matrícula
#include "deque_atendimento.h" // TAD Deque para Atendimento

/*
** Função: Sistema de Registro de Estudantes
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Programa principal para gerenciar informações de estudantes
** utilizando Listas, Pilhas, Filas e Deques.
*/

// Protótipos de funções auxiliares para o menu (implementadas abaixo)
void exibir_menu();
void adicionar_novo_estudante(ListaEstudantes *lista);
void atualizar_notas_estudante(ListaEstudantes *lista, PilhaHistoricoNotas *pilha_historico);
void gerenciar_matriculas(FilaMatricula *fila_matricula);
void gerenciar_atendimento(DequeAtendimento *deque_atendimento);
void calcular_media_e_imprimir_estudante(ListaEstudantes *lista);
void listar_todos_estudantes(ListaEstudantes *lista);
void buscar_estudante_por_matricula(ListaEstudantes *lista);


int main() {
    // 1. Inicialização: Criar estruturas de dados vazias 
    ListaEstudantes *lista_estudantes = criar_lista_estudantes();
    PilhaHistoricoNotas *pilha_historico = criar_pilha_historico();
    FilaMatricula *fila_matricula = criar_fila_matricula();
    DequeAtendimento *deque_atendimento = criar_deque_atendimento();

    if (!lista_estudantes || !pilha_historico || !fila_matricula || !deque_atendimento) {
        printf("Erro ao inicializar uma ou mais estruturas de dados. Encerrando.\n");
        return 1;
    }

    int opcao;
    do {
        exibir_menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Consome o '\n' pendente após o scanf

        switch (opcao) {
            case 1: // Adição de Estudantes 
                adicionar_novo_estudante(lista_estudantes);
                break;
            case 2: // Atualização de Notas 
                atualizar_notas_estudante(lista_estudantes, pilha_historico);
                break;
            case 3: // Matrícula em Disciplinas 
                gerenciar_matriculas(fila_matricula);
                break;
            case 4: // Atendimento 
                gerenciar_atendimento(deque_atendimento);
                break;
            case 5: // Funções adicionais: Calcular média e imprimir 
                calcular_media_e_imprimir_estudante(lista_estudantes);
                break;
            case 6: // Listar todos os estudantes
                listar_todos_estudantes(lista_estudantes);
                break;
            case 7: // Buscar estudante
                buscar_estudante_por_matricula(lista_estudantes);
                break;
            case 0:
                printf("Saindo do sistema de registro de estudantes.\n");
                break;
            default:
                printf("Opcao invalida. Por favor, tente novamente.\n");
        }
        printf("\nPressione ENTER para continuar...");
        getchar(); // Espera o usuário pressionar Enter
    } while (opcao != 0);

    // Liberar a memória alocada para todas as estruturas antes de sair
    destruir_lista_estudantes(lista_estudantes);
    destruir_pilha_historico(pilha_historico);
    destruir_fila_matricula(fila_matricula);
    destruir_deque_atendimento(deque_atendimento);

    return 0;
}

void exibir_menu() {
    printf("\n--- Sistema de Registro de Estudantes ---\n");
    printf("1. Adicionar novo estudante\n");
    printf("2. Atualizar notas de estudante\n");
    printf("3. Gerenciar fila de matriculas\n");
    printf("4. Gerenciar fila de atendimento (Deque)\n");
    printf("5. Calcular e exibir media de um estudante\n");
    printf("6. Listar todos os estudantes\n");
    printf("7. Buscar estudante por matricula\n");
    printf("0. Sair\n");
}

void adicionar_novo_estudante(ListaEstudantes *lista) {
    Estudante novo_estudante;
    printf("\n--- Adicionar Novo Estudante ---\n");
    printf("Nome: ");
    fgets(novo_estudante.nome, sizeof(novo_estudante.nome), stdin);
    novo_estudante.nome[strcspn(novo_estudante.nome, "\n")] = 0; // Remove '\n'

    printf("Matricula: ");
    scanf("%d", &novo_estudante.matricula);
    getchar(); // Consome o '\n'

    printf("Digite as %d notas do estudante:\n", NUM_NOTAS);
    for (int i = 0; i < NUM_NOTAS; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &novo_estudante.notas[i]);
    }
    getchar(); // Consome o '\n'

    // Chama a função do TAD Lista para adicionar o estudante
    adicionar_estudante(lista, novo_estudante); // Você precisará implementar esta função em lista_estudantes.c
    printf("Estudante adicionado com sucesso!\n");
}

void atualizar_notas_estudante(ListaEstudantes *lista, PilhaHistoricoNotas *pilha_historico) {
    int matricula_busca;
    printf("\n--- Atualizar Notas de Estudante ---\n");
    printf("Digite a matricula do estudante para atualizar as notas: ");
    scanf("%d", &matricula_busca);
    getchar();

    Estudante *estudante_encontrado = buscar_estudante(lista, matricula_busca); // Você precisará implementar esta função em lista_estudantes.c

    if (estudante_encontrado) {
        printf("Estudante encontrado: %s\n", estudante_encontrado->nome);

        // Empilhar o histórico anterior de notas 
        // Você precisará implementar empilhar_notas_historico em pilha_historico_notas.c
        empilhar_notas_historico(pilha_historico, estudante_encontrado->notas);

        printf("Digite as novas %d notas para %s:\n", NUM_NOTAS, estudante_encontrado->nome);
        for (int i = 0; i < NUM_NOTAS; i++) {
            printf("Nota %d: ", i + 1);
            scanf("%f", &estudante_encontrado->notas[i]);
        }
        getchar(); // Consome o '\n'

        printf("Notas atualizadas com sucesso! Historico anterior empilhado.\n");
    } else {
        printf("Estudante com matricula %d nao encontrado.\n", matricula_busca);
    }
}

void gerenciar_matriculas(FilaMatricula *fila_matricula) {
    int opcao_mat;
    int matricula_temp;
    printf("\n--- Gerenciar Fila de Matriculas ---\n");
    printf("1. Adicionar estudante a fila de matricula\n"); // 
    printf("2. Remover estudante da fila de matricula (matriculado)\n"); // 
    printf("3. Mostrar fila de matricula\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao_mat);
    getchar();

    switch (opcao_mat) {
        case 1:
            printf("Matricula do estudante para adicionar a fila: ");
            scanf("%d", &matricula_temp);
            getchar();
            // Você precisará implementar enfileirar_matricula em fila_matricula.c
            enfileirar_matricula(fila_matricula, matricula_temp);
            break;
        case 2:
            // Você precisará implementar desenfileirar_matricula em fila_matricula.c
            matricula_temp = desenfileirar_matricula(fila_matricula);
            if (matricula_temp != -1) { // Supondo -1 para erro/fila vazia
                printf("Estudante com matricula %d removido da fila e matriculado.\n", matricula_temp);
            } else {
                printf("Nao ha estudantes na fila de matricula.\n");
            }
            break;
        case 3:
            // Você precisará implementar imprimir_fila_matricula em fila_matricula.c
            imprimir_fila_matricula(fila_matricula);
            break;
        default:
            printf("Opcao invalida.\n");
    }
}

void gerenciar_atendimento(DequeAtendimento *deque_atendimento) {
    int opcao_at;
    int matricula_temp;
    printf("\n--- Gerenciar Fila de Atendimento (Deque) ---\n");
    printf("1. Adicionar estudante no inicio da fila de atendimento\n"); // 
    printf("2. Adicionar estudante no final da fila de atendimento\n"); // 
    printf("3. Remover estudante do inicio da fila de atendimento\n");
    printf("4. Remover estudante do final da fila de atendimento\n");
    printf("5. Mostrar fila de atendimento\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao_at);
    getchar();

    switch (opcao_at) {
        case 1:
            printf("Matricula do estudante para adicionar no inicio: ");
            scanf("%d", &matricula_temp);
            getchar();
            // Você precisará implementar adicionar_frente_deque em deque_atendimento.c
            adicionar_frente_deque(deque_atendimento, matricula_temp);
            break;
        case 2:
            printf("Matricula do estudante para adicionar no final: ");
            scanf("%d", &matricula_temp);
            getchar();
            // Você precisará implementar adicionar_final_deque em deque_atendimento.c
            adicionar_final_deque(deque_atendimento, matricula_temp);
            break;
        case 3:
            // Você precisará implementar remover_frente_deque em deque_atendimento.c
            matricula_temp = remover_frente_deque(deque_atendimento);
            if (matricula_temp != -1) { // Supondo -1 para erro/deque vazio
                printf("Estudante com matricula %d removido do inicio da fila de atendimento.\n", matricula_temp);
            } else {
                printf("Deque de atendimento vazio.\n");
            }
            break;
        case 4:
            // Você precisará implementar remover_final_deque em deque_atendimento.c
            matricula_temp = remover_final_deque(deque_atendimento);
            if (matricula_temp != -1) {
                printf("Estudante com matricula %d removido do final da fila de atendimento.\n", matricula_temp);
            } else {
                printf("Deque de atendimento vazio.\n");
            }
            break;
        case 5:
            // Você precisará implementar imprimir_deque_atendimento em deque_atendimento.c
            imprimir_deque_atendimento(deque_atendimento);
            break;
        default:
            printf("Opcao invalida.\n");
    }
}

void calcular_media_e_imprimir_estudante(ListaEstudantes *lista) {
    int matricula_busca;
    printf("\n--- Calcular e Exibir Media de Estudante ---\n");
    printf("Digite a matricula do estudante para calcular a media: ");
    scanf("%d", &matricula_busca);
    getchar();

    Estudante *estudante_encontrado = buscar_estudante(lista, matricula_busca); // Reutiliza a busca da lista

    if (estudante_encontrado) {
        float media = calcular_media_estudante(estudante_encontrado); // Esta função já está em estudante.c
        printf("Media de %s (Matricula: %d): %.2f\n", estudante_encontrado->nome, estudante_encontrado->matricula, media);
    } else {
        printf("Estudante com matricula %d nao encontrado.\n", matricula_busca);
    }
}

void listar_todos_estudantes(ListaEstudantes *lista) {
    printf("\n--- Lista de Todos os Estudantes ---\n");
    // Você precisará implementar imprimir_lista_estudantes em lista_estudantes.c
    imprimir_lista_estudantes(lista);
}

void buscar_estudante_por_matricula(ListaEstudantes *lista) {
    int matricula_busca;
    printf("\n--- Buscar Estudante por Matricula ---\n");
    printf("Digite a matricula do estudante para buscar: ");
    scanf("%d", &matricula_busca);
    getchar();

    Estudante *estudante_encontrado = buscar_estudante(lista, matricula_busca);

    if (estudante_encontrado) {
        printf("\nEstudante encontrado:\n");
        imprimir_estudante(estudante_encontrado); // Esta função já está em estudante.c
    } else {
        printf("Estudante com matricula %d nao encontrado.\n", matricula_busca);
    }
}