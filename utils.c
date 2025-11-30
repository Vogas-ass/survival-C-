#include <stdio.h>
#include "../include/utils.h"

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
