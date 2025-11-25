//
// Created by aluno on 25/11/2025.
//
#include "libprg/libprg.h"
#include <math.h>
#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct arvore_avl_t {
    int valor;
    int altura;
    struct arvore_avl_t *esquerda;
    struct arvore_avl_t *direita;
} no_avl_t;

no_avl_t* criar_arvore_avl(int valor, int altura) {
    no_avl_t* u = (no_avl_t*) malloc(sizeof(no_avl_t));
    u->valor = valor;
    u->altura = altura;
    u->esquerda = NULL;
    u->direita = NULL;
    return u;
}

no_avl_t* inserir_na_arvore_avl(no_avl_t* v, int valor) {

}

no_avl_t* remover_da_arvore_avl(no_avl_t* v, int valor) {

}

no_avl_t* rotacao_avl_esquerda(no_avl_t* v) {
    no_avl_t* u = v->direita;

    v->direita = u->esquerda;

    u->esquerda = v;

    v->altura = max(v->esquerda->altura, v->direita->altura + 1);

    u->altura = max(u->esquerda->altura, u->direita->altura + 1);

    return u;
}

no_avl_t* rotacao_avl_direita(no_avl_t* v) {
    no_avl_t* u = v->esquerda;

    v->esquerda = u->direita;

    u->direita = v;

    v->altura = max(v->direita->altura, v->esquerda->altura + 1);

    u->altura = max(u->direita->altura, u->esquerda->altura + 1);

    return u;
}

no_avl_t* rotacao_dupla_direita(no_avl_t* v) {
    v->esquerda = rotacao_avl_esquerda(v->esquerda);

    return rotacao_avl_direita(v);
}

no_avl_t* rotacao_dupla_esquerda(no_avl_t* v) {
    v->direita = rotacao_avl_esquerda(v->direita);

    return rotacao_avl_direita(v);
}