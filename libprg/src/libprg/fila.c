#include <stdbool.h>
#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

fila_t *criar_fila(int capacidade) {
    fila_t *f = malloc(sizeof(fila_t));

    f->elementos = malloc(capacidade * sizeof(int));
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    f->capacidade = capacidade;

    return f;
}

void enfileirar(fila_t *f, int valor) {
    f->elementos[f->fim] = valor;

    if (fila_cheia(*f) && f->inicio == 0) {
        exit(EXIT_FAILURE);
        //
    } else if (fila_cheia(*f) && f->inicio != 0) {
        f->fim = (f->fim + 1) % f->capacidade;
        exit(EXIT_SUCCESS);
    } else {
        f->fim++;
    }
}

int desenfileirar(fila_t *f) {
    if (!fila_cheia(*f)) {
        int elemento = f->elementos[f->inicio];
        f->inicio++;
        return elemento;
    } else {
        return -1;
    }
}

int inicio_fila(fila_t *f) {
    if (f->inicio >= 0) {
        return f->elementos[f->inicio];
    }
    return -1;
}

//
// fim_fila{
//
// }
//
// tamanho_fila{
//
// }
//
bool fila_cheia(fila_t f) {
    return f.tamanho >= f.capacidade;
}

// destruir_fila{
//
// }
