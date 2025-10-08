#include "libprg/libprg.h"
#include <stdlib.h>

typedef struct pilha // definindo a struct pilha
{
    int* elementos; // elementos da pilha
    int topo; // topo da pilha (último elemento adicionado)
    int capacidade; // quantidade máxima de elementos na pilha
} pilha_t;

pilha_t* criar_pilha(int capacidade)
{
    pilha_t* p = malloc(sizeof(pilha_t)); // aloca memória para a pilha ser criada

    p->elementos = malloc(capacidade * sizeof(int)); // aloca memória para os elementos
    p->topo = -1; //o topo passa a ser -1 (pilha vazia, pois o primiero índice é zero)
    p->capacidade = capacidade; // quantidade máxima de elementos na pilha

    return p; // retorna a estrutura pilha criada
}

int empilhar_pilha(pilha_t* p, int valor)
{
    if (p->topo < p->capacidade - 1) // se a pilha ainda tiver espaço
    {
        p->topo++; // o topo passa uma casa para frente
        p->elementos[p->topo] = valor; // o novo elemento é adicionado no topo
        return 1; // retorna que a operação foi bem sucedida
    }
    return 0; // retorna que a operação não foi concluída com sucesso
}

int desempilhar_pilha(pilha_t* p)
{
    if (p->topo >= 0) // se a pilha não estiver vazia
    {
        int elemento = p->elementos[p->topo]; // armazena o elemento que está no topo em outra variável
        p->topo--; // o topo retorna uma casa
        return elemento; // retorna o valor que estava no topo
    }
    return -1; // retorna que a pilha está vazia
}

int topo_pilha(pilha_t* p)
{
    if (p->topo >= 0) // se a pilha não estiver vazia
    {
        return p->elementos[p->topo]; // retorna o elemento que está no topo da pilha
    }
    return -1; // retorna que a pilha está vazia
}

int* listar_pilha(pilha_t* p)
{
    int* copia_do_elemento = malloc(sizeof(int) * (p->topo + 1));
    // aloca memória para o array com a cópia dos elementos da pilha
    for (int i = 0; i <= p->topo; i++) // enquanto i for menor que o topo
    {
        copia_do_elemento[i] = p->elementos[i]; // copia os elementos que estão na pilha para o novo array
    }
    return copia_do_elemento; // retorna o array com os mesmos elementos da pilha
}

int tamanho_pilha(pilha_t* p)
{
    if (p->topo >= 0) // se a pilha não estiver vazia
    {
        return p->topo + 1; // retorna o tamanho da pilha
    }
    return -1; // se estiver vazia, retorna que está vazia
}

void destruir_pilha(pilha_t* p)
{
    free(p->elementos); // libera a memória alocada pelos elementos da pilha
    free(p); // libera a memória alocada para a pilha
}
