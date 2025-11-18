//
// Created by aluno on 18/11/2025.
//
#include "libprg/libprg.h"
#include <stdlib.h>

typedef struct arvore_binaria {
    int valor;
    struct arvore_binaria *esquerda;
    struct arvore_binaria *direita;
}no_arvore;

no_arvore *criar_no_arvore(int valor) {
    no_arvore *no = (no_arvore *)malloc(sizeof(no_arvore));
    no->valor = valor;
    no->esquerda = no->direita = NULL;
    return no;
}

void destruir_no_arvore(no_arvore *no) {
    if (no) {
        destruir_no_arvore(no->esquerda);
        destruir_no_arvore(no->direita);
        free(no);
    }
}

no_arvore *inserir_na_arvore(no_arvore *raiz, int valor) {
    if (!raiz) return criar_no_arvore(valor);
    if (valor < raiz->valor) {
        raiz->esquerda = inserir_na_arvore(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_na_arvore(raiz->direita, valor);
    }
    return raiz;
}