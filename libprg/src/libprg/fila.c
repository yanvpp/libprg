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

    if (fila_cheia(f) && f->inicio == 0) {
        exit(EXIT_FAILURE);
    } else if (fila_cheia(f) && f->inicio != 0) {
        f->fim = (f->fim + 1) % f->capacidade;
        exit(EXIT_SUCCESS);
    } else {
        f->elementos[f->fim] = valor;
        f->fim++;
    }
}

int desenfileirar(fila_t *f) {
    if ((f->inicio < f->capacidade) && !fila_vazia(f)) {
        int elemento = f->elementos[f->inicio];
        f->inicio++;
        return elemento;
    } else if (f->inicio == f->capacidade) {
        return f->inicio = (f->inicio + 1) % f->capacidade;
    }
    return -1;
}

int inicio_fila(fila_t *f) {
    if (!fila_vazia(f)) {
        return f->elementos[f->inicio];
    }
    return -1;
}

int fim_fila(fila_t *f){
    if (!fila_vazia(f)) {
        return f->elementos[f->fim];
    }
    return -1;
}

int tamanho_fila(fila_t *f){
    if (fila_vazia(f)) {
        return 0;
    } else if (fila_cheia(f)) {
        return f->capacidade;
    } else if ((f->fim > f->inicio) || (f->fim == f->inicio)) {
        return f->fim;
    }
    return f->inicio;
}

bool fila_cheia(fila_t *f) {
    return f->tamanho >= f->capacidade;
}

bool fila_vazia(fila_t *f) {
    return f->tamanho < f->capacidade;
}

void destruir_fila(fila_t *f){
    free(f->elementos);
    free(f);
}
