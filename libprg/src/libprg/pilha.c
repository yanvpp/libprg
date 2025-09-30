#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    int *elementos;
    int topo;
    int capacidade;
} pilha_t;

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

int desempilhar_pilha(pilha_t *p)
{
    if (p->topo >= 0)
    {
        int elemento = p->elementos[p->topo];
        p->topo--;
        return elemento;
    }
    else
    {
        return -1;
    }
}

int topo_pilha(pilha_t *p)
{
    if (p->topo >= 0)
    {
        return p->elementos[p->topo];
    }
    else
    {
        return -1;
    }
}

int* listar_pilha(pilha_t *p)
{
    int* cc = malloc(sizeof(int) * (p->topo + 1));
    for (int i = 0; i <= p->topo; i++)
    {
        cc[i] = p->elementos[i];
    }
    return cc;
}

int tamanho_pilha(pilha_t *p)
{
    if (p->topo >= 0)
    {
        return p->topo + 1;
    }
    else
    {
        return -1;
    }
}

void destruir_pilha(pilha_t *p)
{
    free(p->elementos);
    free(p);
}