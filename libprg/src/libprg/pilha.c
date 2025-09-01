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

int empilhar_pilha(pilha_t *p, int valor)
{
    if (p->topo < p->capacidade - 1)
    {
        p->topo++;
        p->elementos[p->topo] = valor;
        return 1;
    }
    else
    {
        return 0;
    }
}
