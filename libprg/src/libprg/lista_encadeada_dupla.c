//
// Created by aluno on 16/10/2025.
//
#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

no_duplo_t *criar_lista_encadeada_dupla(int valor)
{
    no_duplo_t* no_duplo = malloc(sizeof(no_t)); // cria um nó
    no_duplo->valor = valor; // o valor do nó passa a ser o valor que a função recebeu
    no_duplo->proximo = NULL; // o último nó da lista sempre apontará para NULL ->
    no_duplo->anterior = NULL; // o primeiro nó aponta para o início <-

    return no_duplo; // retorna o nó criado
}

void adicionar_na_lista_encadeada_dupla(no_duplo_t **inicio, int valor) {
    no_duplo_t* novo_no_duplo = criar_lista_encadeada(valor); // cria a lista encadeada (nó)
    novo_no_duplo->proximo = *inicio; // o novo nó passa a apontar para o elemento que já existia
    (*inicio)->anterior = novo_no_duplo; // o anterior do início passa a ser o novo nó
    novo_no_duplo->anterior = NULL; // o nó criado tem como seu anterior o NULL
    *inicio = novo_no_duplo; // e o início passa a ser o novo nó
}



