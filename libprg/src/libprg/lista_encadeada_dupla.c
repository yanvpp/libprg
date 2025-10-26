//
// Created by aluno on 16/10/2025.
//
#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no_duplo {
    int valor;
    struct no_duplo *anterior;
    struct no_duplo *proximo;
}no_duplo_t;

no_duplo_t *criar_lista_encadeada_dupla(int valor)
{
    no_duplo_t* no_duplo = malloc(sizeof(no_duplo_t)); // cria um nó
    no_duplo->valor = valor; // o valor do nó passa a ser o valor que a função recebeu
    no_duplo->proximo = NULL; // o último nó da lista sempre apontará para NULL ->
    no_duplo->anterior = NULL; // o primeiro nó aponta para o início <-

    return no_duplo; // retorna o nó criado
}

void adicionar_na_lista_encadeada_dupla(no_duplo_t **inicio, int valor) {
    no_duplo_t* novo_no_duplo = criar_lista_encadeada_dupla(valor); // cria a lista encadeada (nó)
    novo_no_duplo->proximo = *inicio; // o novo nó passa a apontar para o elemento que já existia
    (*inicio)->anterior = novo_no_duplo; // o anterior do início passa a ser o novo nó
    novo_no_duplo->anterior = NULL; // o nó criado tem como seu anterior o NULL
    *inicio = novo_no_duplo; // e o início passa a ser o novo nó
}

no_duplo_t* buscar_na_lista_encadeada_dupla(no_t** inicio, int valor)
{
    no_duplo_t* atual = *inicio; // o atual passa a ser o inicio

    while (atual) // enquanto o valor do atual for diferente de nulo - mesmo que while(atual!=NULL)
    {
        if (atual->valor == valor) // se o valor do atual for igual ao valor
        {
            return atual; // retorna o endereço onde o valor está armazenado
        }
        atual = atual->proximo; // caso não entre no if, passa para o próximo elemento da lista
    }
    return NULL; // retorna que não encontrou o valor em nenhum endereço
}

void remover_da_lista_encadeada_dupla(no_duplo_t** inicio, int valor)
{
    no_duplo_t* atual = *inicio; // o atual passa a ser o inicio

    while (atual) // enquanto o atual for diferente de NULL
    {
        if (atual->valor == valor) // se o valor do atual for igual ao valor solicitado
        {
            if ((atual->anterior)) // se tiver anterior
            {
                atual->proximo->anterior = atual->proximo; // o anterior do próximo do atual irá apontar para o próximo do atual
                atual->anterior->proximo = atual->anterior; // o próximo do anterior do atual irá apontar para o anterior do atual
            }
            else // se não tiver anterior
            {
                *inicio = atual->proximo; //o início passa a ser o próximo do atual
                (*inicio)->anterior = NULL; // o anterior do ínicio será o nulo
            }
            free(atual); // libera o local da memória do elemento removido ~~ remove o elemento
            break; // se achou, quebra o while
        }
        atual = atual->proximo; // o atual passa a ser o próximo do atual (o próximo elemento)
    }
}



void remover_da_posicao_da_lista_encadeada_dupla(no_duplo_t** inicio, int valor, int posicao)
{
    if (*inicio == NULL || posicao < 0) return; // se a lista estiver vazia, ou a posição for negativa, não faz nada

    no_duplo_t* no_para_remover = *inicio; // o nó para remoção passa a ser o início

    for (int i = 0; no_para_remover != NULL && i < posicao; i++) // enquanto não chegar na posição solicitada
    {
        no_para_remover = no_para_remover->proximo; // passa para o próximo
    }

    if (no_para_remover == NULL) return; // se a posição for inválida, não faz nada

    if (no_para_remover->anterior != NULL)  // se o anterior do nó para ser removido for nulo
    {
        no_para_remover->anterior->proximo = no_para_remover->proximo; // o anterior do próximo do nó para remover passa a ser o próximo dele
    } else // caso contrário
    {
        *inicio = no_para_remover->proximo; // o início passa a ser o próximo do nó para remover
    }

    if (no_para_remover->proximo != NULL) // se o nó para remover tiver próximo
    {
        no_para_remover->proximo->anterior = no_para_remover->anterior; // o anterior do próximo do nó para remover passa a ser o anterior dele
    }

    free(no_para_remover); // libera a memória do nó para remoção
}

