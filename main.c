#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/item.h"
#include "../include/array_inventory.h"
#include "../include/list_inventory.h"
#include "../include/components.h"
#include "../include/sorts.h"

void limparBuffer(); // prototype from utils.c

int main(void) {
    srand((unsigned int) time(NULL));

    // Inventario - vetor
    Item vet[MAX_ITENS];
    int size = 0;
    inicializarVetor(vet, &size);

    // Inventario - lista
    No* head;
    inicializarLista(&head);

    int opc = 0;
    while (1) {
        printf("\n=== Survival Island - Menu Principal ===\n");
        printf("1) Usar mochila (vetor)\n");
        printf("2) Usar mochila (lista encadeada)\n");
        printf("3) Módulo de componentes / ordenação\n");
        printf("0) Sair\n");
        printf("Escolha: "); if (scanf("%d", &opc) != 1) { limparBuffer(); continue; }
        limparBuffer();

        if (opc == 0) break;

        if (opc == 1) {
            int sub = 0;
            while (1) {
                printf("\n-- Mochila (Vetor) --\n1 Inserir | 2 Remover | 3 Listar | 4 Buscar sequencial | 0 Voltar\nEscolha: ");
                if (scanf("%d", &sub) != 1) { limparBuffer(); continue; }
                limparBuffer();
                if (sub == 0) break;
                if (sub == 1) {
                    if (size >= MAX_ITENS) { printf("Mochila cheia (max %d)\n", MAX_ITENS); continue; }
                    Item it; printf("Nome: "); scanf(" %29[^"]", it.nome); limparBuffer();
                    printf("Tipo: "); scanf(" %19[^"]", it.tipo); limparBuffer();
                    printf("Quantidade: "); scanf("%d", &it.quantidade); limparBuffer();
                    inserirItemVetor(vet, &size, it);
                } else if (sub == 2) {
                    char nome[30]; printf("Nome a remover: "); scanf(" %29[^"]", nome); limparBuffer();
                    if (removerItemVetor(vet, &size, nome)) printf("Removido com sucesso\n"); else printf("Item nao encontrado\n");
                } else if (sub == 3) {
                    listarItensVetor(vet, size);
                } else if (sub == 4) {
                    char nome[30]; printf("Nome a buscar: "); scanf(" %29[^"]", nome); limparBuffer();
                    int comps = 0;
                    int idx = buscarSequencialVetor(vet, size, nome, &comps);
                    printf("Comparacoes: %d\n", comps);
                    if (idx >= 0) printf("Encontrado: %s | %s | qtd %d\n", vet[idx].nome, vet[idx].tipo, vet[idx].quantidade);
                    else printf("Nao encontrado\n");
                }
            }
        } else if (opc == 2) {
            int sub = 0;
            while (1) {
                printf("\n-- Mochila (Lista) --\n1 Inserir | 2 Remover | 3 Listar | 4 Buscar sequencial | 0 Voltar\nEscolha: ");
                if (scanf("%d", &sub) != 1) { limparBuffer(); continue; }
                limparBuffer();
                if (sub == 0) break;
                if (sub == 1) {
                    Item it; printf("Nome: "); scanf(" %29[^"]", it.nome); limparBuffer();
                    printf("Tipo: "); scanf(" %19[^"]", it.tipo); limparBuffer();
                    printf("Quantidade: "); scanf("%d", &it.quantidade); limparBuffer();
                    if (!inserirItemLista(&head, it)) printf("Erro ao inserir (memoria)\n");
                } else if (sub == 2) {
                    char nome[30]; printf("Nome a remover: "); scanf(" %29[^"]", nome); limparBuffer();
                    if (removerItemLista(&head, nome)) printf("Removido com sucesso\n"); else printf("Item nao encontrado\n");
                } else if (sub == 3) {
                    listarItensLista(head);
                } else if (sub == 4) {
                    char nome[30]; printf("Nome a buscar: "); scanf(" %29[^"]", nome); limparBuffer();
                    int comps = 0;
                    int ok = buscarSequencialLista(head, nome, &comps);
                    printf("Comparacoes: %d\n", comps);
                    if (ok) printf("Encontrado\n"); else printf("Nao encontrado\n");
                }
            }
        } else if (opc == 3) {
            // componentes e sorts
            Componente comp[20];
            int ncomp = 0;
            cadastrarComponentes(comp, &ncomp);
            listarComponentes(comp, ncomp);

            int escolha = 0;
            while (1) {
                printf("\n-- Ordenacao / Busca --\n1 Bubble (nome) | 2 Insertion (tipo) | 3 Selection (prioridade) | 4 Busca binaria por nome | 0 Voltar\nEscolha: ");
                if (scanf("%d", &escolha) != 1) { limparBuffer(); continue; }
                limparBuffer();
                if (escolha == 0) break;
                long comps = 0;
                clock_t start, end;
                double t;
                if (escolha == 1) {
                    start = clock();
                    bubbleSortNome(comp, ncomp, &comps);
                    end = clock(); t = (double)(end - start)/CLOCKS_PER_SEC;
                    printf("Bubble sort concluido. Comparacoes: %ld Tempo: %.6f s\n", comps, t);
                    listarComponentes(comp, ncomp);
                } else if (escolha == 2) {
                    start = clock();
                    insertionSortTipo(comp, ncomp, &comps);
                    end = clock(); t = (double)(end - start)/CLOCKS_PER_SEC;
                    printf("Insertion sort concluido. Comparacoes: %ld Tempo: %.6f s\n", comps, t);
                    listarComponentes(comp, ncomp);
                } else if (escolha == 3) {
                    start = clock();
                    selectionSortPrioridade(comp, ncomp, &comps);
                    end = clock(); t = (double)(end - start)/CLOCKS_PER_SEC;
                    printf("Selection sort concluido. Comparacoes: %ld Tempo: %.6f s\n", comps, t);
                    listarComponentes(comp, ncomp);
                } else if (escolha == 4) {
                    char chave[30]; printf("Nome a buscar (binaria) (após ordenar por nome): "); scanf(" %29[^"]", chave); limparBuffer();
                    long compsb = 0;
                    int idx = buscaBinariaNome(comp, ncomp, chave, &compsb);
                    printf("Comparacoes na busca binaria: %ld\n", compsb);
                    if (idx >= 0) printf("Encontrado: %s | %s | %d\n", comp[idx].nome, comp[idx].tipo, comp[idx].prioridade);
                    else printf("Nao encontrado\n");
                }
            }
        }
    }

    // liberar estruturas
    liberarLista(&head);

    return 0;
}
