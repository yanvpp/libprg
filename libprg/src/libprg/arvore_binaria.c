//
// Created by aluno on 18/11/2025.
//
#include <math.h>
#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct arvore_binaria
{
    int valor;
    struct arvore_binaria* esquerda;
    struct arvore_binaria* direita;
} no_arvore;

no_arvore* criar_arvore(int valor)
{
    no_arvore* galho = malloc(sizeof(no_arvore));
    galho->valor = valor;
    galho->esquerda = galho->direita = NULL;
    return galho;
}

void destruir_arvore(no_arvore* raiz)
{
    if (raiz)
    {
        destruir_arvore(raiz->esquerda);
        destruir_arvore(raiz->direita);
        free(raiz);
    }
}

no_arvore* inserir_na_arvore(no_arvore* raiz, int valor)
{
    if (!raiz) return criar_arvore(valor);
    if (valor < raiz->valor)
    {
        raiz->esquerda = inserir_na_arvore(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->direita = inserir_na_arvore(raiz->direita, valor);
    }
    return raiz;
}

bool busca_na_arvore(no_arvore* raiz, int valor)
{
    if (!raiz) return false;
    if (valor == raiz->valor) return true;
    if (valor < raiz->valor) return busca_na_arvore(raiz->esquerda, valor);
    return busca_na_arvore(raiz->direita, valor);
}

no_arvore* encontrar_no_minimo_arvore(no_arvore* raiz)
{
    no_arvore* atual = raiz;

    while (atual && atual->esquerda)
    {
        atual = atual->esquerda;
    }
    return atual;
}

no_arvore* remover_valor_da_arvore(no_arvore* raiz, int valor)
{
    if (!raiz) return NULL;

    if (valor < raiz->valor)
    {
        raiz->esquerda = remover_valor_da_arvore(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->direita = remover_valor_da_arvore(raiz->direita, valor);
    }
    else
    {
        if (!raiz->esquerda)
        {
            no_arvore* aux = raiz->direita;
            free(raiz);
            return aux;
        }
        if (!raiz->direita)
        {
            no_arvore* aux = raiz->esquerda;
            free(raiz);
            return aux;
        }
        no_arvore* auxiliar = encontrar_no_minimo_arvore(raiz->direita);

        raiz->valor = auxiliar->valor;

        raiz->direita = remover_valor_da_arvore(raiz->direita, auxiliar->valor);
    }
    return raiz;
}

int maior_valor_arvore(no_arvore* raiz)
{
    if (!raiz) return -1;

    no_arvore* atual = raiz;

    while (atual->direita)
    {
        atual = atual->direita;
    }

    return atual->valor;
}

int menor_valor_arvore(no_arvore* raiz)
{
    if (!raiz) return -1;

    no_arvore* atual = raiz;

    while (atual->esquerda)
    {
        atual = atual->esquerda;
    }

    return atual->valor;
}

int altura_arvore(no_arvore* raiz)
{
    if (!raiz) return -1;

    int altura_esquerda = altura_arvore(raiz->esquerda);
    int altura_direita = altura_arvore(raiz->direita);

    if (altura_direita > altura_esquerda) return altura_direita + 1;
    return altura_esquerda + 1;
}

void imprimir_arvore_em_ordem(no_arvore* raiz)
{
    if (raiz)
    {
        imprimir_arvore_em_ordem(raiz->esquerda);
        printf("%d\t", raiz->valor);
        imprimir_arvore_em_ordem(raiz->direita);
    }
}

void imprimir_arvore_em_pre_ordem(no_arvore* raiz)
{
    if (raiz)
    {
        printf("%d\t", raiz->valor);
        imprimir_arvore_em_pre_ordem(raiz->esquerda);
        imprimir_arvore_em_pre_ordem(raiz->direita);
    }
}

void imprimir_arvore_em_pos_ordem(no_arvore* raiz)
{
    if (raiz)
    {
        imprimir_arvore_em_pos_ordem(raiz->esquerda);
        imprimir_arvore_em_pos_ordem(raiz->direita);
        printf("%d\t", raiz->valor);
    }
}

void imprimir_arvore_por_lagura(no_arvore *x)
{
    fila_t* fila = criar_fila(pow(2, altura_arvore(x)));

    while (x) {
        printf("%d\t", x->valor);

        if (x->esquerda) {
            enfileirar(fila, x->esquerda->valor);
        } else if (x->direita) {
            enfileirar(fila, x->direita->valor);
        }

        desenfileirar(fila);
    }

    destruir_fila(fila);
}

// |------------------- ÁRVORE AVL ----------------------|

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct arvore_avl_t
{
    int valor;
    int altura;
    struct arvore_avl_t* esquerda;
    struct arvore_avl_t* direita;
} no_avl_t;

no_avl_t* criar_arvore_avl(int valor, int altura)
{
    no_avl_t* u = malloc(sizeof(no_avl_t));
    u->valor = valor;
    u->altura = altura;
    u->esquerda = NULL;
    u->direita = NULL;
    return u;
}

int altura_arvore_avl(no_avl_t* v)
{
    if (!v) return 0; // se a árvore estiver vazia, retorna tamanho 0
    return v->altura; // caso contrário, retorna a altura
}

int fator_de_balanceamento(no_avl_t* v)
{
    if (!v) return 0; // se a árvore estiver vazia, retorna 0, caso contrário
    return altura_arvore_avl(v->esquerda) - altura_arvore_avl(v->direita);
    // retorna a diferença do tamanho de cada lado
}

no_avl_t* balancear_arvore_avl(no_avl_t* v)
{
    if (!v) return NULL; // se não tiver árvore, retorna nulo

    v->altura = 1 + max(altura_arvore_avl(v->esquerda), altura_arvore_avl(v->direita)); // atualiza a altura

    int fator = fator_de_balanceamento(v); // obtém o fator de balanceamento

    if (fator > 1) // se a subárvore da esquerda for maior

    {
        if (fator_de_balanceamento(v->esquerda) >= 0) // se a "subsubárvore" da esquerda estiver maior
        {
            return rotacao_avl_direita(v);
        }
        return rotacao_dupla_direita(v); // se a da direita estiver maior
    }

    if (fator < -1) // se a subárvore da direita for maior
    {
        if (fator_de_balanceamento(v->direita) <= 0) // se a "subsubárvore" da direita estiver maior
        {
            return rotacao_avl_esquerda(v);
        }
        return rotacao_dupla_esquerda(v); // se a da esquerda for maior
    }

    return v; // retorna a árvore balanceada
}

no_avl_t* inserir_na_arvore_avl(no_avl_t* v, int valor)
{
    if (!v) return criar_arvore_avl(valor, 1); // se não tiver árvore, cria uma

    if (valor < v->valor) // se tiver árvore e o valor for menor que o que temos,
    {
        v->esquerda = inserir_na_arvore_avl(v->esquerda, valor); // insere na subárvore da esquerda
    }
    else if (valor > v->valor) // se for maior
    {
        v->direita = inserir_na_arvore_avl(v->direita, valor); // insere na subárvore da direita
    }
    else // caso o valor já exista
    {
        return v; // retorna o nó existente
    }

    return balancear_arvore_avl(v); // balanceia a árvore antes de devolver
}

no_avl_t* encontrar_no_minimo_arvore_avl(no_avl_t* v)
{
    no_avl_t* atual = v;
    while (atual && atual->esquerda)
    {
        atual = atual->esquerda;
    }
    return atual;
}

no_avl_t* remover_da_arvore_avl(no_avl_t* v, int valor)
{
    if (!v) return NULL;

    if (valor < v->valor)
    {
        v->esquerda = remover_da_arvore_avl(v->esquerda, valor);
    }
    else if (valor > v->valor)
    {
        v->direita = remover_da_arvore_avl(v->direita, valor);
    }

    if (!v->esquerda || !v->direita)
    {
        no_avl_t* aux = v->esquerda ? v->esquerda : v->direita;

        if (!aux)
        {
            aux = v;
            v = NULL;
        }
        else
        {
            v->valor = aux->valor;
            v->esquerda = aux->esquerda;
            v->direita = aux->direita;
            v->altura = aux->altura;

            free(aux);
        }
    }
    else
    {
        no_avl_t* aux = encontrar_no_minimo_arvore_avl(v->direita);
        v->valor = aux->valor;
        v->direita = remover_da_arvore_avl(v->direita, aux->valor);
    }

    if (!v) return NULL;

    return balancear_arvore_avl(v);
}

void imprimir_arvore_avl_em_pre_ordem(no_avl_t* v)
{
    if (v)
    {
        printf("%d\t", v->valor);
        imprimir_arvore_avl_em_pre_ordem(v->esquerda);
        imprimir_arvore_avl_em_pre_ordem(v->direita);
    }
}

void imprimir_arvore_avl_em_ordem(no_avl_t* v)
{
    if (v)
    {
        imprimir_arvore_avl_em_ordem(v->esquerda);
        printf("%d\t", v->valor);
        imprimir_arvore_avl_em_ordem(v->direita);
    }
}

void imprimir_arvore_avl_em_pos_ordem(no_avl_t* v)
{
    if (v)
    {
        imprimir_arvore_avl_em_pos_ordem(v->esquerda);
        imprimir_arvore_avl_em_pos_ordem(v->direita);
        printf("%d\t", v->valor);
    }
}

void imprimir_arvore_avl_por_largura(no_avl_t* v)
{
}

void destruir_arvore_avl(no_avl_t* raiz)
{
    if (raiz)
    {
        destruir_arvore_avl(raiz->esquerda);
        destruir_arvore_avl(raiz->direita);
        free(raiz);
    }
}