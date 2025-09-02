#ifndef LABORATORIO_LIBPRG_H
#define LABORATORIO_LIBPRG_H

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

#endif //LABORATORIO_LIBPRG_H