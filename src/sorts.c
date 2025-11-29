#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../include/sorts.h"

// Bubble sort por nome (strings)
void bubbleSortNome(Componente arr[], int n, long *comparacoes) {
    *comparacoes = 0;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-1-i; ++j) {
            (*comparacoes)++;
            if (strcmp(arr[j].nome, arr[j+1].nome) > 0) {
                Componente tmp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = tmp;
            }
        }
    }
}

// Insertion sort por tipo (strings)
void insertionSortTipo(Componente arr[], int n, long *comparacoes) {
    *comparacoes = 0;
    for (int i = 1; i < n; ++i) {
        Componente key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            (*comparacoes)++;
            if (strcmp(arr[j].tipo, key.tipo) > 0) {
                arr[j+1] = arr[j];
                j--;
            } else break;
        }
        arr[j+1] = key;
    }
}

// Selection sort por prioridade (int)
void selectionSortPrioridade(Componente arr[], int n, long *comparacoes) {
    *comparacoes = 0;
    for (int i = 0; i < n-1; ++i) {
        int min = i;
        for (int j = i+1; j < n; ++j) {
            (*comparacoes)++;
            if (arr[j].prioridade < arr[min].prioridade) min = j;
        }
        if (min != i) {
            Componente tmp = arr[i]; arr[i] = arr[min]; arr[min] = tmp;
        }
    }
}

// Busca binária por nome (assume arr ordenado por nome). Retorna index ou -1. Conta comparacoes.
int buscaBinariaNome(Componente arr[], int n, const char* chave, long *comparacoes) {
    int l = 0, r = n-1;
    *comparacoes = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        (*comparacoes)++;
        int cmp = strcmp(arr[m].nome, chave);
        if (cmp == 0) return m;
        if (cmp < 0) l = m + 1; else r = m - 1;
    }
    return -1;
}
