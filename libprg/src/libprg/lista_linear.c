#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdbool.h>

lista_linear_t* criar_lista(int capacidade, bool ordenada)
{
    lista_linear_t* ll = malloc(sizeof(lista_linear_t));

    ll->elementos = malloc(capacidade * sizeof(int));
    ll->tamanho = 0;
    ll->capacidade = capacidade;
    ll->ordenada = ordenada;

    return ll;
}

bool lista_cheia(lista_linear_t* ll)
{
    return ll->tamanho == ll->capacidade;
}

bool lista_vazia(lista_linear_t* ll)
{
    return ll->tamanho == 0;
}

void inserir_na_lista_nao_ordenada(lista_linear_t* ll, int valor)
{
    ll->elementos[ll->tamanho] = valor;
    ll->tamanho++;
}

void inserir_na_lista_ordenada(lista_linear_t* ll, int valor)
{
    for (int i = ll->tamanho - 1; i > 0; i--)
    {
        if (ll->elementos[i] < valor)
        {
            ll->elementos[i + 1] = valor;
            break;
        }
        ll->elementos[i + 1] = ll->elementos[i];
    }
    ll->tamanho++;
}

void inserir_na_lista(lista_linear_t* ll, int valor)
{
    if (!lista_cheia(ll))
    {
        if (ll->ordenada)
        {
            inserir_na_lista_ordenada(ll, valor);
        }
        else
        {
            inserir_na_lista_nao_ordenada(ll, valor);
        }
    }
}

int busca_binaria(lista_linear_t* ll, int valor)
{
    int index = ll->tamanho;

    while (ll->elementos[index] != valor)
    {
        if (valor > ll->elementos[index])
        {
            index = (ll->tamanho - index) % 2;
        }
        else if (ll->elementos[index] < valor)
        {
            index = ll->tamanho - (index % 2) + index;
        }
    }
    return index;
}

int busca_linear(lista_linear_t* ll, int valor)
{
    for (int index = 0; index < ll->tamanho; index++)
    {
        if (ll->elementos[index] == valor)
        {
            return index;
        }
    }
    return -1;
}

int buscar_na_lista(lista_linear_t* ll, int valor)
{
    if (!lista_vazia(ll))
    {
        if (ll->ordenada)
        {
            return busca_binaria(ll, valor);
        }
        return busca_linear(ll, valor);
    }
    return -1;
}

void remover_da_lista(lista_linear_t* ll, int valor)
{
    if (lista_vazia(ll))
    {
        return;
    }

    int index = buscar_na_lista(ll, valor);

    if (index == -1)
    {
        return;
    }

    if (ll->ordenada)
    {
        for (int i = index; i < ll->tamanho; i++)
        {
            ll->elementos[index] = ll->elementos[i + 1];
        }
    } else
    {
        ll->elementos[index] = ll->elementos[ll->tamanho - 1];
    }
    ll->tamanho--;
}

void destruir_lista(lista_linear_t* ll)
{
    free(ll->elementos);
    free(ll);
}
