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
    int valor; // valor armazenado
    struct arvore_binaria* esquerda; // filho esquerdo do nó
    struct arvore_binaria* direita; // filho direito do nó
} no_arvore;

no_arvore* criar_arvore(int valor)
{
    no_arvore* galho = malloc(sizeof(no_arvore)); // aloca memória para armazenar novo nó
    galho->valor = valor; // armazena o valor do novo nó
    galho->esquerda = galho->direita = NULL; // aponta que o novo nó não terá filhos
    return galho; // retorna o novo nó criado
}

void destruir_arvore(no_arvore* raiz)
{
    if (raiz) // se tiver raiz
    {
        destruir_arvore(raiz->esquerda); // chama recursividade para liberar a memória dos nós da esquerda
        destruir_arvore(raiz->direita); // o mesmo com os da direita
        free(raiz); // libera a memória do nó raiz
    }
}

no_arvore* inserir_na_arvore(no_arvore* raiz, int valor)
{
    if (!raiz) return criar_arvore(valor); // se não existir árvore, cria uma
    if (valor < raiz->valor) // se o valor for menor que a raiz
    {
        raiz->esquerda = inserir_na_arvore(raiz->esquerda, valor); // insere na esquerda
    }
    else if (valor > raiz->valor) // se for maior
    {
        raiz->direita = inserir_na_arvore(raiz->direita, valor); // insere na direita
    }
    return raiz; // retorna a raiz da árvore com o novo nó já adicionado
}

bool busca_na_arvore(no_arvore* raiz, int valor)
{
    if (!raiz) return false; // se não existir árvore, retorna falso
    if (valor == raiz->valor) return true; // se o valor do nó atual for igual ao que buscamos, retorna true
    if (valor < raiz->valor) return busca_na_arvore(raiz->esquerda, valor); // se for menor, procura na esquerda
    return busca_na_arvore(raiz->direita, valor); // se for maior, procura na direita
}

no_arvore* encontrar_no_minimo_arvore(no_arvore* raiz)
{
    no_arvore* atual = raiz; // cria um nó auxiliar para percorrer a árvore

    while (atual && atual->esquerda) // enquanto existir o nó atual e ele tiver um filho na esquerda
    {
        atual = atual->esquerda; // passa para a esquerda
    }
    return atual; // quando não tiver esquerda, significa que chegamos no nó mínimo, retornando ele
}

no_arvore* remover_valor_da_arvore(no_arvore* raiz, int valor)
{
    if (!raiz) return NULL; // se não tiver raiz, retorna NULL

    if (valor < raiz->valor) // se o valor a ser removido for menor que o do nó atual
    {
        raiz->esquerda = remover_valor_da_arvore(raiz->esquerda, valor); // procura na esquerda
    }
    else if (valor > raiz->valor) // se for maior,
    {
        raiz->direita = remover_valor_da_arvore(raiz->direita, valor); // procura na direita
    }
    else // quando encontrar
    {
        if (!raiz->esquerda) // se não tiver um filho na esquerda
        {
            no_arvore* aux = raiz->direita; // armazena o valor da direita em um nó auxiliar
            free(raiz); // libera o nó com o valor a ser removido
            return aux; // adiciona o que estava na direita no lugar dele
        }
        if (!raiz->direita) // se não tiver raiz na direita
        {
            no_arvore* aux = raiz->esquerda; // armazena o valor da esquerda em um nó auxiliar
            free(raiz); // libera o nó com o valor a ser removido
            return aux; // adiciona o que estava na direita no lugar dele
        }

        // caso não entre em nenhum caso
        no_arvore* auxiliar = encontrar_no_minimo_arvore(raiz->direita);

        raiz->valor = auxiliar->valor;

        raiz->direita = remover_valor_da_arvore(raiz->direita, auxiliar->valor);
    }
    return raiz; // retorna a raiz da árvore com o elemento removido
}

int maior_valor_arvore(no_arvore* raiz)
{
    if (!raiz) return -1; // se não tiver árvore, retorna -1

    no_arvore* atual = raiz; // armazena

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

int tamanho_arvore(no_arvore* raiz)
{
    if (!raiz) return 0; // se não tiver árvore, retorna tamanho 0
    return 1 + tamanho_arvore(raiz->esquerda) + tamanho_arvore(raiz->direita); // caso contrário, conta os nós
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

void imprimir_arvore_por_lagura(no_arvore* raiz)
{
    if (!raiz) return; // se não tiver árvore, retorna

    int capacidade = tamanho_arvore(raiz); // quantidade de nós da árvore

    no_arvore** fila = malloc(capacidade * sizeof(no_arvore*)); // fila para armazenar os nós

    int inicio = 0, fim = 0; // auxiliares para percorrer a fila

    fila[fim++] = raiz; // coloca a raiz no fim da fila e depois incrementa 1 no fim
    // mesmo que fila[fim] = raiz; fim++

    while (inicio < fim) // enquanto ainda tiverem nós na fila
    {
        no_arvore* atual = fila[inicio++]; // armazena o valor que está no inicio da fila e incrementa 1 no início

        printf("%d\t", atual->valor); // imprime o valor do inicio da fila

        if (raiz->esquerda) fila[fim++] = raiz->esquerda; // se tiver nó à esquerda, armazena ele na fila
        if (raiz->direita) fila[fim++] = raiz->direita; // se tiver nó à direita, armazena ele na fila
    }

    free(fila); // libera a memória alocada para a fila
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

int tamanho_arvore_avl(no_avl_t* v)
{
    if (!v) return 0; // se não tiver árvore, retorna tamanho 0
    return 1 + tamanho_arvore_avl(v->esquerda) + tamanho_arvore_avl(v->direita); // caso contrário, conta os nós
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
    if (!v) return; // se não tiver árvore, retorna

    int capacidade = tamanho_arvore_avl(v); // quantidade de nós da árvore

    no_avl_t** fila = malloc(capacidade * sizeof(no_arvore*)); // fila para armazenar os nós

    int inicio = 0, fim = 0; // auxiliares para percorrer a fila

    fila[fim++] = v; // coloca a raiz no fim da fila e depois incrementa 1 no fim
    // mesmo que fila[fim] = raiz; fim++

    while (inicio < fim) // enquanto ainda tiverem nós na fila
    {
        no_avl_t* atual = fila[inicio++]; // armazena o valor que está no inicio da fila e incrementa 1 no início

        printf("%d\t", atual->valor); // imprime o valor do inicio da fila

        if (v->esquerda) fila[fim++] = v->esquerda; // se tiver nó à esquerda, armazena ele na fila
        if (v->direita) fila[fim++] = v->direita; // se tiver nó à direita, armazena ele na fila
    }

    free(fila); // libera a memória alocada para a fila
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
