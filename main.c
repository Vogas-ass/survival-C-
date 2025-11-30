#include <stdio.h>
#include <string.h>
#include "../include/item.h"
#include "../include/array_inventory.h"
#include "../include/list_inventory.h"
#include "../include/sorts.h"
#include "../include/utils.h"
#include "../include/components.h"

/* menu-driven main */
int main(void) {
    ArrayInventory arrayInv;
    ListInventory listInv;

    initArrayInventory(&arrayInv);
    initListInventory(&listInv);

    int opc = -1;

    while (opc != 0) {
        printf("\n===== MENU =====\n");
        printf("1 – Inserir no Array\n");
        printf("2 – Remover do Array\n");
        printf("3 – Buscar no Array\n");
        printf("4 – Listar Array\n");
        printf("5 – Inserir na Lista\n");
        printf("6 – Remover da Lista\n");
        printf("7 – Buscar na Lista\n");
        printf("8 – Listar Lista\n");
        printf("9 – Ordenar Array por Nome (Bubble)\n");
        printf("10 – Ordenar Lista por Nome (Selection)\n");
        printf("11 – Busca Binária no Array Ordenado\n");
        printf("12 – Demo: Componentes (cadastrar + listar)\n");
        printf("0 – Sair\n");
        printf("Escolha: ");
        if (scanf("%d", &opc) != 1) { limparBuffer(); opc = -1; continue; }
        limparBuffer();

        switch (opc) {
            case 1: {
                Item it;
                printf("Nome: "); fgets(it.nome, sizeof(it.nome), stdin); it.nome[strcspn(it.nome, "\n")] = 0;
                printf("Tipo: "); fgets(it.tipo, sizeof(it.tipo), stdin); it.tipo[strcspn(it.tipo, "\n")] = 0;
                printf("Quantidade: "); if (scanf("%d", &it.quantidade)!=1) it.quantidade=0; limparBuffer();
                inserirArray(&arrayInv, it);
                break;
            }
            case 2: {
                char nome[30];
                printf("Nome a remover: "); fgets(nome, sizeof(nome), stdin); nome[strcspn(nome, "\n")] = 0;
                removerArray(&arrayInv, nome);
                break;
            }
            case 3: {
                char nome[30];
                printf("Nome a buscar: "); fgets(nome, sizeof(nome), stdin); nome[strcspn(nome, "\n")] = 0;
                int idx = buscarArray(&arrayInv, nome);
                if (idx >= 0) printf("Encontrado no array (indice %d): %s | %s | %d\n", idx, arrayInv.itens[idx].nome, arrayInv.itens[idx].tipo, arrayInv.itens[idx].quantidade);
                break;
            }
            case 4:
                listarArray(&arrayInv);
                break;
            case 5: {
                Item it;
                printf("Nome: "); fgets(it.nome, sizeof(it.nome), stdin); it.nome[strcspn(it.nome, "\n")] = 0;
                printf("Tipo: "); fgets(it.tipo, sizeof(it.tipo), stdin); it.tipo[strcspn(it.tipo, "\n")] = 0;
                printf("Quantidade: "); if (scanf("%d", &it.quantidade)!=1) it.quantidade=0; limparBuffer();
                inserirLista(&listInv, it);
                break;
            }
            case 6: {
                char nome[30];
                printf("Nome a remover: "); fgets(nome, sizeof(nome), stdin); nome[strcspn(nome, "\n")] = 0;
                removerLista(&listInv, nome);
                break;
            }
            case 7: {
                char nome[30];
                printf("Nome a buscar: "); fgets(nome, sizeof(nome), stdin); nome[strcspn(nome, "\n")] = 0;
                buscarLista(&listInv, nome);
                break;
            }
            case 8:
                listarLista(&listInv);
                break;
            case 9:
                bubbleSortArray(&arrayInv);
                printf("Array ordenado por nome.\n");
                break;
            case 10:
                selectionSortList(&listInv);
                printf("Lista ordenada por nome.\n");
                break;
            case 11: {
                char chave[30];
                printf("Nome a buscar (binária): "); fgets(chave, sizeof(chave), stdin); chave[strcspn(chave, "\n")] = 0;
                bubbleSortArray(&arrayInv);
                int pos = binarySearchArray(&arrayInv, chave);
                if (pos >= 0) printf("Encontrado no array (indice %d).\n", pos);
                else printf("Não encontrado.\n");
                break;
            }
            case 12: {
                int n = 3;
                Componente comp[n];
                cadastrarComponentes(comp, n);
                listarComponentes(comp, n);
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    }
    return 0;
}
