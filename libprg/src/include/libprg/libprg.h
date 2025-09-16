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
}lista_linear_t;

lista_linear_t *criar_lista_linear(int capacidade);
bool lista_linear_cheia(lista_linear_t *ll);
void inserir_na_lista_linear(lista_linear_t *ll, int valor);

void destruir_lista_linear(lista_linear_t *ll);

#endif //LABORATORIO_LIBPRG_H
