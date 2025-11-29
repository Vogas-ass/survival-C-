#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/item.h"
#include "../include/array_inventory.h"
#include "../include/list_inventory.h"

// limpa buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) ;
}
