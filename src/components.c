#include <stdio.h>
#include <string.h>
#include "../include/components.h"
#include <time.h>

void cadastrarComponentes(Componente comp[], int *n) {
    printf("\nQuantos componentes deseja cadastrar (max 20)? ");
    int qtd; scanf("%d", &qtd); if (qtd < 1) qtd = 1; if (qtd > 20) qtd = 20;
    *n = qtd;
    for (int i = 0; i < *n; ++i) {
        printf("\nComponente %d\n", i+1);
        printf("Nome: "); scanf(" %29[^"]", comp[i].nome);
        printf("Tipo: "); scanf(" %19[^"]", comp[i].tipo);
        printf("Prioridade (1-10): "); scanf("%d", &comp[i].prioridade);
    }
}

void listarComponentes(Componente comp[], int n) {
    printf("\n--- Componentes (total %d) ---\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d) %s | %s | prioridade: %d\n", i+1, comp[i].nome, comp[i].tipo, comp[i].prioridade);
    }
}
