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

void inserir_na_lista_nao_ordenada(lista_t *l, int valor) {
    l->elementos[l->tamanho] = valor;
    l->tamanho++;
}

void inserir_na_lista_ordenada(lista_t *l, int valor) {
    for (int i = l->tamanho - 1; i >= 0; i--) {
        if (l->elementos[i] < valor) {
            l->elementos[i+1] = valor;
            break;
        }
        l->elementos[i+1] = l->elementos[i];
    }
    l->tamanho++;
}

void inserir_na_lista(lista_t *l, int valor) {
    if (!lista_cheia(l)) {
        if (l->ordenada) {
            inserir_na_lista_ordenada(l, valor);
        } else {
            inserir_na_lista_nao_ordenada(l, valor);
        }
    }
}

int busca_binaria(lista_t *l, int valor) {
    int index = l->tamanho;

    while (l->elementos[index] != valor) {
        if (valor > l->elementos[index]) {
            index = (l->tamanho - index) % 2;
        } else if (l->elementos[index] < valor) {
            index = l->tamanho - (index % 2) + index;
        }
    }
    return index;
}

int busca_linear(lista_t *l, int valor) {
    for (int index = 0; index < l->tamanho; index++) {
        if (l->elementos[index] == valor) {
            return index;
        }
        return -1;
    }
}

int buscar_na_lista(lista_t *l, int valor) {
    if (!lista_vazia(l)) {
        busca_binaria(l, valor);
    }
        return 0;
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