#include <stdio.h>
#include <string.h>
#include "../include/array_inventory.h"

// Inicializa vetor
void inicializarVetor(Item vetor[], int *size) {
    *size = 0;
    for (int i = 0; i < MAX_ITENS; ++i) {
        vetor[i].nome[0] = '\0';
        vetor[i].tipo[0] = '\0';
        vetor[i].quantidade = 0;
    }
}

// Insere item no vetor (retorna 1 se ok, 0 se cheio)
int inserirItemVetor(Item vetor[], int *size, Item it) {
    if (*size >= MAX_ITENS) return 0;
    vetor[*size] = it;
    (*size)++;
    return 1;
}

// Remove item por nome (retorna 1 se removido, 0 nao encontrado)
int removerItemVetor(Item vetor[], int *size, const char* nome) {
    for (int i = 0; i < *size; ++i) {
        if (strcmp(vetor[i].nome, nome) == 0) {
            // shift left
            for (int j = i; j < *size - 1; ++j) vetor[j] = vetor[j+1];
            (*size)--;
            vetor[*size].nome[0] = '\0';
            return 1;
        }
    }
    return 0;
}

// Lista itens
void listarItensVetor(Item vetor[], int size) {
    printf("\n--- Inventario (Vetor) ---\n");
    if (size == 0) { printf("(vazio)\n"); return; }
    for (int i = 0; i < size; ++i) {
        printf("%d) %s | %s | qtd: %d\n", i+1, vetor[i].nome, vetor[i].tipo, vetor[i].quantidade);
    }
}

// Busca sequencial e conta comparacoes
int buscarSequencialVetor(Item vetor[], int size, const char* nome, int *comparacoes) {
    *comparacoes = 0;
    for (int i = 0; i < size; ++i) {
        (*comparacoes)++;
        if (strcmp(vetor[i].nome, nome) == 0) return i;
    }
    return -1;
}
