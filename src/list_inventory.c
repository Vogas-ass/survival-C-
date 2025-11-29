#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/list_inventory.h"

// Inicializa lista (ponteiro head = NULL)
void inicializarLista(No** head) {
    *head = NULL;
}

// Insere no final
int inserirItemLista(No** head, Item it) {
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) return 0;
    novo->dados = it;
    novo->proximo = NULL;
    if (*head == NULL) {
        *head = novo;
    } else {
        No* p = *head;
        while (p->proximo) p = p->proximo;
        p->proximo = novo;
    }
    return 1;
}

// Remove por nome
int removerItemLista(No** head, const char* nome) {
    No* p = *head;
    No* prev = NULL;
    while (p) {
        if (strcmp(p->dados.nome, nome) == 0) {
            if (prev) prev->proximo = p->proximo;
            else *head = p->proximo;
            free(p);
            return 1;
        }
        prev = p; p = p->proximo;
    }
    return 0;
}

// Listar
void listarItensLista(No* head) {
    printf("\n--- Inventario (Lista) ---\n");
    if (!head) { printf("(vazio)\n"); return; }
    int i = 1;
    for (No* p = head; p; p = p->proximo) {
        printf("%d) %s | %s | qtd: %d\n", i++, p->dados.nome, p->dados.tipo, p->dados.quantidade);
    }
}

// Busca sequencial em lista, retorna 1 se encontrado, 0 caso contrario
int buscarSequencialLista(No* head, const char* nome, int *comparacoes) {
    *comparacoes = 0;
    for (No* p = head; p; p = p->proximo) {
        (*comparacoes)++;
        if (strcmp(p->dados.nome, nome) == 0) return 1;
    }
    return 0;
}

// Liberar lista
void liberarLista(No** head) {
    No* p = *head;
    while (p) {
        No* t = p->proximo;
        free(p);
        p = t;
    }
    *head = NULL;
}
