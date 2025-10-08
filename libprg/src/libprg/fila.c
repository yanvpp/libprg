#include <stdbool.h>
#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct fila // define a estrutura fila
{
    int* elementos; // elementos da fila
    int capacidade; // capacidada da fila
    int tamanho; // tamanho da fila
    int inicio; // elemento que está no início da fila
    int fim; // elemento que está no fim da fila
} fila_t;

fila_t* criar_fila(int capacidade)
{
    fila_t* f = malloc(sizeof(fila_t)); // aloca memória para criar a fila

    f->elementos = malloc(capacidade * sizeof(int)); // aloca memória para os elementos da fila
    f->inicio = 0; // inicia o início da fila como 0 (ainda não tem elementos)
    f->tamanho = 0; // inicia o tamanho da fila como zero (ainda não tem elementos)
    f->fim = 0; // inicia o fim da fila como 0 (ainda não tem elementos)
    f->capacidade = capacidade; // a capacidade é igual a que for recebida pela função

    return f; // retorna a fila criada
}

void enfileirar(fila_t* f, int valor)
{
    if (fila_cheia(f))
    {
        // se a fila estiver cheia
        exit(EXIT_FAILURE); // retorna um erro
    }
    f->elementos[f->fim] = valor; // caso contrário, adiciona um elemento no fim da fila
    f->fim++; // o fim passa uma casa para frente
    f->tamanho++; // e o tamanho da fila aumenta
}

void desenfileirar(fila_t* f)
{
    if (fila_vazia(f))
    {
        // se a fila estiver vazia
        exit(EXIT_FAILURE); // retorna um erro
    }
    f->inicio++; // passa o início uma casa para frente
    f->tamanho--; // o tamanho diminui
}

int inicio_fila(fila_t* f)
{
    if (!fila_vazia(f))
    {
        // se a fila não estiver vazia
        return f->elementos[f->inicio]; // retorna o elemento que está no início
    }
    return -1; // se estiver vazia, retorna que não tem elementos
}

int fim_fila(fila_t* f)
{
    if (!fila_vazia(f))
    {
        // se a fila não estiver vazia
        return f->elementos[f->fim - 1]; // retorna o elemento que está no fim dela
    }
    return -1; // caso contrário, retorna que está vazia
}

int tamanho_fila(fila_t* f)
{
    // if (fila_vazia(f)) {
    //     return 0;
    // } else if (fila_cheia(f)) {
    //     return f->capacidade;
    // } else if ((f->fim > f->inicio) || (f->fim == f->inicio)) {
    //     return f->fim;
    // }
    // return f->inicio;

    return f->tamanho; // retorna o tamanho da fila
}

bool fila_cheia(fila_t* f)
{
    return f->tamanho == f->capacidade; // se o tamanho for igual a capacidade significa que a fila está cheia
}

bool fila_vazia(fila_t* f)
{
    return f->tamanho == 0; // se o tamanho for zero, retorna que a fila está vazia
}

void listar_fila(fila_t* f)
{
    for (int i = 0; i < f->fim; i++) // enquanto i for menor que o fim da fila
    {
        printf("\t%d", f->elementos[i]); // imprime na tela os elementos da fila
    }
}

void destruir_fila(fila_t* f)
{
    free(f->elementos); // libera a memória alocada para os elementos da fila
    free(f); // libera a memória alocada para a fila
}
