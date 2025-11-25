#ifndef LABORATORIO_LIBPRG_H
#define LABORATORIO_LIBPRG_H
#include <stdbool.h>

//|-- PILHA --|

typedef struct pilha pilha_t;

pilha_t* criar_pilha(int capacidade);
void empilhar_pilha(pilha_t* p, int valor);
int desempilhar_pilha(pilha_t* p);
int topo_pilha(pilha_t* p);
int* listar_pilha(pilha_t* p);
int tamanho_pilha(pilha_t* p);
void destruir_pilha(pilha_t* p);
void empilhar_na_posicao(pilha_t *p, int valor, int posicao);
int limitar_posicao_da_pilha(pilha_t* p, int posicao);
bool pilha_cheia(pilha_t *p);
bool pilha_vazia(pilha_t* p);
int buscar_na_posicao_da_pilha(pilha_t* p, int posicao);
void desempilhar_na_posicao(pilha_t* p, int posicao);
void imprimir_pilha(pilha_t *p);

// |-- FILA --|

typedef struct fila fila_t;

fila_t* criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);
void desenfileirar(fila_t* f);
int inicio_fila(fila_t* f);
int fim_fila(fila_t* f);
int tamanho_fila(fila_t* f);
bool fila_cheia(fila_t* f);
bool fila_vazia(fila_t* f);
void listar_fila(fila_t *f);
void destruir_fila(fila_t* f);

// |-- LISTA LINEAR --|

typedef struct lista_linear lista_linear_t;

lista_linear_t* criar_lista_linear(int capacidade, bool ordenada);
bool lista_cheia(lista_linear_t* ll);
bool lista_vazia(lista_linear_t* ll);
void inserir_na_lista(lista_linear_t* ll, int valor);
int buscar_na_lista(lista_linear_t* ll, int valor);
void remover_da_lista(lista_linear_t* ll, int valor);
int tamanho_lista_linear(lista_linear_t* ll);
void listar_lista_linear(lista_linear_t *ll);
int inicio_lista_linear(lista_linear_t *ll);
void destruir_lista(lista_linear_t* ll);
int buscar_na_posicao_da_lista(lista_linear_t* ll, int posicao);
void inserir_na_posicao_da_lista(lista_linear_t* ll, int valor, int posicao);
void remover_na_posicao_da_lista(lista_linear_t* ll, int posicao);

// |-- LISTA ENCADEADA --|

typedef struct no no_t;

no_t* criar_lista_encadeada(int valor);
void adicionar_na_lista_encadeada(no_t** inicio, int valor);
int primeiro_elemento_lista_encadeada(no_t** inicio);
no_t* primeiro_no_lista_encadeada(no_t** inicio);
no_t* buscar_na_lista_encadeada(no_t** inicio, int valor);
void listar_lista_encadeada(no_t **inicio);
void remover_da_lista_encadeada(no_t** inicio, int valor);
void destruir_lista_encadeada(no_t** inicio);
no_t* criar_lista_encadeada_circular(int valor);
void adicionar_na_lista_encadeada_circular(no_t** inicio, int valor);
void destruir_lista_encadeada_circular(no_t **inicio);
void adicionar_na_posicao_da_lista_encadeada(no_t** inicio, int valor, int posicao);
int tamanho_da_lista_encadeada(no_t* inicio);
int limitar_na_lista_encadeada(no_t** inicio, int posicao);
bool lista_encadeada_vazia(no_t** inicio);
no_t* buscar_na_posicao_da_lista_encadeada(no_t** inicio, int posicao);
void remover_da_posicao_da_lista_encadeada(no_t** inicio, int posicao);
int tamanho_da_lista_encadeada_circular(no_t* inicio);
void adicionar_na_posicao_da_lista_encadeada_circular(no_t** inicio, int valor, int posicao);
no_t* ultimo_no_da_lista_encadeada_circular(no_t* inicio);

// |-- LISTA ENCADEADA DUPLA --|

typedef struct no_duplo no_duplo_t;

no_duplo_t* criar_lista_encadeada_dupla(int valor);
void adicionar_na_lista_encadeada_dupla(no_duplo_t **inicio, int valor);
no_duplo_t* buscar_na_lista_encadeada_dupla(no_duplo_t** inicio, int valor);
void remover_da_lista_encadeada_dupla(no_duplo_t** inicio, int valor);
void adicionar_na_posicao_da_lista_encadeada_dupla(no_duplo_t** inicio, int valor, int posicao);
void remover_da_posicao_da_lista_encadeada_dupla(no_duplo_t** inicio, int posicao);
no_duplo_t* buscar_na_posicao_da_lista_encadeada_dupla(no_duplo_t** inicio, int posicao);
int tamanho_da_lista_encadeada_dupla(no_duplo_t* inicio);

// |-- ALGORITMOS DE ORDENAÇÃO --|

void bubble_sort(int* vetor, int tamanho);
void insertion_sort(int* vetor, int tamanho);
void selection_sort(int* vetor, int tamanho);
void merge_sort(int* vetor, int esquerda, int direita);
void quick_sort(int* vetor, int esquerda, int direita);

// |-- ÁRVORE BINÁRIA --|

typedef struct arvore_binaria no_arvore;

no_arvore *criar_arvore(int valor);
void destruir_arvore(no_arvore *raiz);
no_arvore *inserir_na_arvore(no_arvore *raiz, int valor);
bool busca_na_arvore(no_arvore *raiz, int valor);
no_arvore* encontrar_no_minimo_arvore(no_arvore *raiz);
no_arvore *remover_valor_da_arvore(no_arvore *raiz, int valor);
int maior_valor_arvore(no_arvore *raiz);
int menor_valor_arvore(no_arvore *raiz);
int altura_arvore(no_arvore *raiz);
void imprimir_arvore_em_ordem(no_arvore *raiz);
void imprimir_arvore_em_pre_ordem(no_arvore *raiz);
void imprimir_arvore_em_pos_ordem(no_arvore *raiz);
// void imprimir_arvore_por_niveis(no_arvore *raiz);


// |-- ÁRVORE AVL --|

typedef struct arvore_avl_t no_avl_t;

no_avl_t* rotacao_avl_esquerda(no_avl_t* v);
no_avl_t* rotacao_avl_direita(no_avl_t* v);

#endif //LABORATORIO_LIBPRG_H
