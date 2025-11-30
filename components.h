#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "item.h"

typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

void cadastrarComponentes(Componente *comp, int n);
void listarComponentes(Componente *comp, int n);

#endif // COMPONENTS_H
