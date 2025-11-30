#ifndef LIST_INVENTORY_H
#define LIST_INVENTORY_H

#include "item.h"

typedef struct ListNode {
    Item dados;
    struct ListNode *next;
} ListNode;

typedef struct {
    ListNode *head;
} ListInventory;

/* inicializa lista */
void initListInventory(ListInventory *list);
/* operações */
void inserirLista(ListInventory *list, Item item);
void removerLista(ListInventory *list, const char *nome);
int buscarLista(const ListInventory *list, const char *nome); /* retorna 1 se encontrado, 0 caso contrário */
void listarLista(const ListInventory *list);

/* ordenação da lista por nome (selection-like) */
void selectionSortList(ListInventory *list);

#endif // LIST_INVENTORY_H
