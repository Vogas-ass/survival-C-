#ifndef ARRAY_INVENTORY_H
#define ARRAY_INVENTORY_H

#include "item.h"

#define MAX_ITENS 10

// Operacoes para inventario em vetor
void inicializarVetor(Item vetor[], int *size);
int inserirItemVetor(Item vetor[], int *size, Item it);
int removerItemVetor(Item vetor[], int *size, const char* nome);
void listarItensVetor(Item vetor[], int size);
int buscarSequencialVetor(Item vetor[], int size, const char* nome, int *comparacoes);

#endif
