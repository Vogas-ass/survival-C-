#ifndef ARRAY_INVENTORY_H
#define ARRAY_INVENTORY_H

#include "item.h"

#define MAX_ARRAY_ITEMS 100

typedef struct {
    Item itens[MAX_ARRAY_ITEMS];
    int tamanho;
} ArrayInventory;

/* inicializa inventário em array */
void initArrayInventory(ArrayInventory *inv);
/* operações principais */
void inserirArray(ArrayInventory *inv, Item item);
void removerArray(ArrayInventory *inv, const char *nome);
int buscarArray(const ArrayInventory *inv, const char *nome); /* retorna índice ou -1 */
void listarArray(const ArrayInventory *inv);

/* ordenação e busca */
void bubbleSortArray(ArrayInventory *inv);
int binarySearchArray(const ArrayInventory *inv, const char *chave);

#endif // ARRAY_INVENTORY_H
