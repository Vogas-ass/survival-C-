#ifndef LIST_INVENTORY_H
#define LIST_INVENTORY_H

#include "item.h"

// No para lista encadeada
typedef struct No {
    Item dados;
    struct No* proximo;
} No;

// Operacoes para lista encadeada
void inicializarLista(No** head);
int inserirItemLista(No** head, Item it);
int removerItemLista(No** head, const char* nome);
void listarItensLista(No* head);
int buscarSequencialLista(No* head, const char* nome, int *comparacoes);
void liberarLista(No** head);

#endif
