#ifndef ITEM_H
#define ITEM_H

// Estrutura que representa um item da mochila
typedef struct {
    char nome[30];
    char tipo[20]; // ex: arma, municao, cura, ferramenta
    int quantidade;
} Item;

#endif
