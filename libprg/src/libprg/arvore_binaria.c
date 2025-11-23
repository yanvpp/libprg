//
// Created by aluno on 18/11/2025.
//
#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdbool.h>

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

bool busca_na_arvore(no_arvore *raiz, int valor) {
    if (!raiz) return false;
    if (valor == raiz->valor) return true;
    if (valor < raiz->valor) return busca_na_arvore(raiz->esquerda, valor);
    return busca_na_arvore(raiz->direita, valor);
}

no_arvore* encontrar_no_minimo_arvore(no_arvore *raiz)
{
    no_arvore* atual = raiz;

    while (atual && atual->esquerda)
    {
        atual = atual->esquerda;
    }
    return atual;
}

no_arvore *remover_valor_da_arvore(no_arvore *raiz, int valor) {
    if (!raiz) return NULL;

    if (valor < raiz->valor) {
        raiz->esquerda = remover_valor_da_arvore(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover_valor_da_arvore(raiz->direita, valor);
    } else {
        if (!raiz->esquerda)
        {
            no_arvore *aux = raiz->direita;
            free(raiz);
            return aux;
        }
            if (!raiz->direita) {
            no_arvore *aux = raiz->esquerda;
            free(raiz);
            return aux;
        }
        no_arvore* auxiliar = encontrar_no_minimo_arvore(raiz->direita);

        raiz->valor = auxiliar->valor;

        raiz->direita = remover_valor_da_arvore(raiz->direita, auxiliar->valor);
    }
    return raiz;
}

int maior_valor_arvore(no_arvore *raiz)
{
    if (!raiz) return -1;

    no_arvore* atual = raiz;

    while (atual->direita)
    {
        atual = atual->direita;
    }

    return atual->valor;
}

int menor_valor_arvore(no_arvore *raiz)
{
    if (!raiz) return -1;

    no_arvore* atual = raiz;

    while (atual->esquerda)
    {
        atual = atual->esquerda;
    }

    return atual->valor;
}