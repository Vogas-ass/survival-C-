#include <stdio.h>
#include <string.h>
#include "../include/array_inventory.h"

void initArrayInventory(ArrayInventory *inv) {
    inv->tamanho = 0;
}

void inserirArray(ArrayInventory *inv, Item item) {
    if (inv->tamanho >= MAX_ARRAY_ITEMS) {
        printf("Inventário cheio (array).\n");
        return;
    }
    inv->itens[inv->tamanho++] = item; /* cópia simples */
    printf("Item inserido no array.\n");
}

void removerArray(ArrayInventory *inv, const char *nome) {
    int pos = buscarArray(inv, nome);
    if (pos < 0) { printf("Item não encontrado no array.\n"); return; }
    for (int i = pos; i < inv->tamanho - 1; i++) inv->itens[i] = inv->itens[i+1];
    inv->tamanho--;
    printf("Item removido do array.\n");
}

int buscarArray(const ArrayInventory *inv, const char *nome) {
    for (int i = 0; i < inv->tamanho; i++) {
        if (strcmp(inv->itens[i].nome, nome) == 0) return i;
    }
    return -1;
}

void listarArray(const ArrayInventory *inv) {
    printf("\n--- Itens (Array) ---\n");
    if (inv->tamanho == 0) { printf("(vazio)\n"); return; }
    for (int i = 0; i < inv->tamanho; i++) {
        printf("%d) %s | %s | %d\n", i+1, inv->itens[i].nome, inv->itens[i].tipo, inv->itens[i].quantidade);
    }
}

/* bubble sort por nome */
void bubbleSortArray(ArrayInventory *inv) {
    int n = inv->tamanho;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(inv->itens[j].nome, inv->itens[j+1].nome) > 0) {
                Item tmp = inv->itens[j];
                inv->itens[j] = inv->itens[j+1];
                inv->itens[j+1] = tmp;
            }
        }
    }
}

/* busca binária assume array ordenado por nome */
int binarySearchArray(const ArrayInventory *inv, const char *chave) {
    int lo = 0, hi = inv->tamanho - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int cmp = strcmp(inv->itens[mid].nome, chave);
        if (cmp == 0) return mid;
        if (cmp < 0) lo = mid + 1; else hi = mid - 1;
    }
    return -1;
}
