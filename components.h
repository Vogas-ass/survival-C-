#ifndef COMPONENTS_H
#define COMPONENTS_H

typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

void cadastrarComponentes(Componente comp[], int *n);
void listarComponentes(Componente comp[], int n);

#endif
