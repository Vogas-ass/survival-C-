#include <stdio.h>
#include <string.h>
#include "../include/components.h"

static void lerLinha(char *dest, int tam) {
    if (fgets(dest, tam, stdin)) {
        dest[strcspn(dest, "\n")] = 0;
    } else {
        dest[0] = '\0';
    }
}

void cadastrarComponentes(Componente *comp, int n) {
    for (int i = 0; i < n; ++i) {
        printf("\nComponente %d\n", i+1);
        printf("Nome: "); lerLinha(comp[i].nome, sizeof(comp[i].nome));
        printf("Tipo: "); lerLinha(comp[i].tipo, sizeof(comp[i].tipo));
        printf("Prioridade (1-10): "); if (scanf("%d", &comp[i].prioridade)!=1) comp[i].prioridade=0; limparBuffer();
    }
}

void listarComponentes(Componente *comp, int n) {
    printf("\n--- Componentes ---\n");
    for (int i = 0; i < n; ++i) {
        printf("%d) %s | %s | %d\n", i+1, comp[i].nome, comp[i].tipo, comp[i].prioridade);
    }
}
