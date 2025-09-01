#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

pilha_t *criar_pilha(int capacidade) {
    pilha_t *p = malloc(sizeof(pilha_t));

    p->elementos = malloc(capacidade * sizeof(int));
    p->topo = -1;
    p->capacidade = capacidade;

    return p;
}
