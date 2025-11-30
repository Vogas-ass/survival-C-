#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/list_inventory.h"

void initListInventory(ListInventory *list) {
    list->head = NULL;
}

void inserirLista(ListInventory *list, Item item) {
    ListNode *n = (ListNode*)malloc(sizeof(ListNode));
    if (!n) { printf("Erro de memória\n"); return; }
    n->dados = item;
    n->next = list->head;
    list->head = n;
    printf("Item inserido na lista.\n");
}

void removerLista(ListInventory *list, const char *nome) {
    ListNode *cur = list->head, *prev = NULL;
    while (cur) {
        if (strcmp(cur->dados.nome, nome) == 0) {
            if (prev) prev->next = cur->next; else list->head = cur->next;
            free(cur);
            printf("Item removido da lista.\n");
            return;
        }
        prev = cur; cur = cur->next;
    }
    printf("Item não encontrado na lista.\n");
}

int buscarLista(const ListInventory *list, const char *nome) {
    ListNode *cur = list->head;
    while (cur) {
        if (strcmp(cur->dados.nome, nome) == 0) {
            printf("Encontrado na lista: %s | %s | %d\n", cur->dados.nome, cur->dados.tipo, cur->dados.quantidade);
            return 1;
        }
        cur = cur->next;
    }
    printf("Não encontrado na lista.\n");
    return 0;
}

void listarLista(const ListInventory *list) {
    printf("\n--- Itens (Lista Encadeada) ---\n");
    ListNode *cur = list->head;
    if (!cur) { printf("(vazia)\n"); return; }
    while (cur) {
        printf("%s | %s | %d\n", cur->dados.nome, cur->dados.tipo, cur->dados.quantidade);
        cur = cur->next;
    }
}

/* selection-like sort: we will create a new sorted list by selecting minimum repeatedly.
   For simplicity and given small sizes, this is fine. */
void selectionSortList(ListInventory *list) {
    if (!list->head || !list->head->next) return;
    ListNode *sorted = NULL;

    while (list->head) {
        ListNode *minPrev = NULL;
        ListNode *minNode = list->head;
        ListNode *prev = list->head;
        ListNode *cur = list->head->next;
        while (cur) {
            if (strcmp(cur->dados.nome, minNode->dados.nome) < 0) {
                minPrev = prev;
                minNode = cur;
            }
            prev = cur; cur = cur->next;
        }
        // remove minNode from list->head
        if (minPrev) minPrev->next = minNode->next; else list->head = minNode->next;
        // insert at front of sorted
        minNode->next = sorted;
        sorted = minNode;
    }
    // reverse sorted to be in ascending order
    ListNode *rev = NULL;
    while (sorted) {
        ListNode *nxt = sorted->next;
        sorted->next = rev;
        rev = sorted;
        sorted = nxt;
    }
    list->head = rev;
}
