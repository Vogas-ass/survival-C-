#ifndef SORTS_H
#define SORTS_H

#include "components.h"

// Sorting and searching functions with comparison counters
void bubbleSortNome(Componente arr[], int n, long *comparacoes);
void insertionSortTipo(Componente arr[], int n, long *comparacoes);
void selectionSortPrioridade(Componente arr[], int n, long *comparacoes);

// busca binaria por nome (assume arr ordenado por nome)
int buscaBinariaNome(Componente arr[], int n, const char* chave, long *comparacoes);

#endif
