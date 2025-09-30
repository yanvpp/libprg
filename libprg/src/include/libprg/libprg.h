#ifndef LABORATORIO_LIBPRG_H
#define LABORATORIO_LIBPRG_H
#include <stdbool.h>

//|-- PILHA --|

typedef struct pilha
{
    int *elementos;
    int topo;
    int capacidade;
} pilha_t;

pilha_t *criar_pilha(int capacidade);
int empilhar_pilha(pilha_t *p, int valor);
int desempilhar_pilha(pilha_t *p);
int topo_pilha(pilha_t *p);
int *listar_pilha(pilha_t *p);
int tamanho_pilha(pilha_t *p);
void destruir_pilha(pilha_t *p);

//|-- FILA --|

typedef struct fila {
    int* elementos;
    int capacidade;
    int tamanho;
    int inicio;
    int fim;
}fila_t;

fila_t* criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);
void desenfileirar(fila_t *f);
int inicio_fila(fila_t *f);
int fim_fila(fila_t *f);
int tamanho_fila(fila_t *f);
bool fila_cheia(fila_t *f);
bool fila_vazia(fila_t *f);
void destruir_fila(fila_t *f);

//|-- LISTA LINEAR --|

typedef struct lista_linear {
    int *elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
}lista_linear_t;

lista_linear_t *criar_lista_linear(int capacidade, bool ordenada);
bool lista_cheia(lista_linear_t *ll);
bool lista_vazia(lista_linear_t *ll);
void inserir_na_lista(lista_linear_t *ll, int valor);
int buscar_na_lista(lista_linear_t *ll, int valor);
void remover_da_lista(lista_linear_t *ll, int valor);
void destruir_lista(lista_linear_t *ll);

// |-- LISTA ENCADEADA --|

typedef struct no no_t;

no_t *criar_lista_encadeada(int valor);
void adicionar_na_lista_encadeada(no_t **inicio, int valor);
no_t* buscar_na_lista_encadeada(no_t **inicio, int valor);
void remover_da_lista_encadeada(no_t **inicio, int valor);
void destruir_lista_encadeada(no_t *no);

#endif //LABORATORIO_LIBPRG_H
