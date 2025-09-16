//
// Created by aluno on 16/09/2025.
//

#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

lista_linear_t *criar_lista_linear(int capacidade) {
    lista_linear_t *ll = malloc(sizeof(lista_linear_t));

    ll->elementos = malloc(capacidade * sizeof(int));
    ll->tamanho = 0;
    ll->capacidade = capacidade;

    return ll;
}

bool lista_linear_cheia(lista_linear_t *ll) {
    return ll->tamanho == ll->capacidade;
}

void inserir_na_lista_linear(lista_linear_t *ll, int valor) {
    if (lista_linear_cheia(ll)) {
        exit(EXIT_FAILURE);
    }
    ll->elementos[ll->tamanho] = valor;
    ll->tamanho++;
}