#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct lista_linear {
    int *elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
}lista_linear_t;

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
    int i;

    for (i = ll->tamanho; i > 0 && ll->elementos[i - 1] > valor; i--)
    {
        ll->elementos[i] = ll->elementos[i - 1];
    }
    ll->elementos[i] = valor;
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
    int inicio = 0, fim = ll->tamanho - 1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        if (valor == ll->elementos[meio])
        {
            return meio;
        }
        if (ll->elementos[meio] < valor)
        {
            inicio = meio + 1;
        } else
        {
            fim = meio - 1;
        }
    }
    return -1;
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
            for (int i = index; i < ll->tamanho - 1; i++)
            {
                ll->elementos[i] = ll->elementos[i + 1];
            }
        }
        else
        {
            ll->elementos[index] = ll->elementos[ll->tamanho - 1];
        }
        ll->tamanho--;
    }

    int tamanho_lista_linear(lista_linear_t *ll)
    {
       return ll->tamanho;
    }

    void listar_lista_linear(lista_linear_t *ll)
    {
        for (int i = 0; i < ll->tamanho; i++)
        {
            printf("\t%d", ll->elementos[i]);
        }
    }

    int inicio_lista_linear(lista_linear_t *ll)
    {
        return ll->elementos[0];
    }


    void destruir_lista(lista_linear_t* ll)
    {
        free(ll->elementos);
        free(ll);
    }