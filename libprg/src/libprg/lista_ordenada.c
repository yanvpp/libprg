//
// Created by aluno on 18/09/2025.
//
#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

    lista_ordenada_t *criar_lista_ordenada(int capacidade) {
        lista_ordenada_t *lo = malloc(sizeof(lista_ordenada_t));

        lo->elementos = malloc(capacidade * sizeof(int));
        lo->tamanho = 0;
        lo->capacidade = capacidade;

        return lo;
    }

    bool lista_ordenada_cheia(lista_ordenada_t *lo) {
        return lo->tamanho = lo->capacidade;
    }

    bool lista_ordenada_vazia(lista_ordenada_t *lo) {
        return lo->tamanho = 0;
    }

