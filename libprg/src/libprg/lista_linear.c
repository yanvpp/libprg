//
// Created by aluno on 16/09/2025.
//

#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

lista_t *criar_lista(int capacidade, bool ordenada) {
    lista_t *l = malloc(sizeof(lista_t));

    l->elementos = malloc(capacidade * sizeof(int));
    l->tamanho = 0;
    l->capacidade = capacidade;
    l->ordenada = ordenada;

    return l;
}

bool lista_cheia(lista_t *l) {
    return l->tamanho == l->capacidade;
}

bool lista_vazia(lista_t *l) {
    return l->tamanho = 0;
}

void inserir_na_lista(lista_t *l, int valor) {
    if (lista_cheia(l)) {
        exit(EXIT_FAILURE);
    }

    if () {

    }

    l->elementos[l->tamanho] = valor;
    l->tamanho++;
}

int buscar_na_lista(lista_t *l, int valor) {
    if (!lista_vazia(l)) {
        for (int index = 0; index < l->tamanho; index++) {
            if (l->elementos[index] == valor) {
                return index;
            }
        }
    }
    return -1;
}

void remover_da_lista(lista_t *l, int valor) {
    int index;

    if (lista_vazia(l)) {
        index = buscar_na_lista(l, valor);
        l->elementos[index] = l->elementos[l->tamanho];
    }
}

void destruir_lista(lista_t *l) {
    free(l->elementos);
    free(l);
}