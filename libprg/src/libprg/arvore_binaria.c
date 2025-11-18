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
