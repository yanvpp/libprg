#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct pilha // definindo a struct pilha
{
    int* elementos; // elementos da pilha
    int topo; // topo da pilha (índice do último elemento adicionado)
    int capacidade; // quantidade máxima de elementos na pilha
} pilha_t;

pilha_t* criar_pilha(int capacidade)
{
    pilha_t* p = malloc(sizeof(pilha_t)); // aloca memória para a pilha ser criada

    p->elementos = malloc(capacidade * sizeof(int)); // aloca memória para os elementos
    p->topo = -1; //o topo passa a ser -1 (pilha vazia, pois o primeiro índice é zero)
    p->capacidade = capacidade; // quantidade máxima de elementos na pilha

    return p; // retorna a estrutura pilha criada
}

int empilhar_pilha(pilha_t* p, int valor)
{
    /*if (pilha_cheia(p)) // se a pilha estiver cheia
    {
        realloc(p->elementos, sizeof(int) * p->capacidade * 2); // realoca o tamanho da pilha
        p->capacidade *= 2; // a capacidade é dobrada
    }*/

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

void imprimir_pilha(pilha_t *p)
{
    pilha_t* aux = criar_pilha(p->topo + 1);

    for (int i = 0; i <= p->topo + 1; i++)
    {
        printf("%d\n", topo_pilha(aux));
        desempilhar_pilha(aux);
    }

    destruir_pilha(aux);
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

bool pilha_cheia(pilha_t *p)
{
    return p->topo == p->capacidade; // verifica se a pilha está cheia
}

bool pilha_vazia(pilha_t* p)
{
    return p->topo == 0; // verifica se a pilha está vazia
}

int buscar_na_posicao_da_pilha(pilha_t* p, int posicao)
{
    int indice = limitar_posicao_da_pilha(p, posicao); // valor a ser buscado
    pilha_t *pilha_auxiliar = criar_pilha(p->capacidade); // cria uma pilha auxiliar
    int valor_auxiliar; // variável auxiliar

    while (p->topo > indice) // enquanto o topo for maior que local alvo
    {
        valor_auxiliar = desempilhar_pilha(p); // desempilha da pilha original
        empilhar_pilha(pilha_auxiliar, valor_auxiliar); // empilha na pilha auxiliar
    }

    int valor_na_posicao = topo_pilha(p); // salva o elemento da posição desejada

    while (pilha_auxiliar->topo >= 0) // enquanto o topo da pilha auxiliar for maior ou igual a zero
    {
        valor_auxiliar = desempilhar_pilha(pilha_auxiliar); // desempilha da pilha auxiliar
        empilhar_pilha(p, valor_auxiliar); // reempilha na pilha original
    }

    destruir_pilha(pilha_auxiliar); // destrói a pilha auxiliar para liberar memória

    return valor_na_posicao;
}

int limitar_posicao_da_pilha(pilha_t* p, int posicao)
{
    if (posicao > p->topo) return p->topo; // se a posição for maior que o topo, empilha no próximo do topo
    if (posicao < 0) return 0; // se a posição for menor que zero, empilha no início
}

void empilhar_na_posicao(pilha_t* p, int valor, int posicao)
{
    int indice = limitar_posicao_da_pilha(p, posicao); // local para ser adicionado
    pilha_t* pilha_auxiliar = criar_pilha(p->capacidade); // cria uma pilha auxiliar
    int valor_auxiliar; // variável auxiliar

    while (p->topo >= indice) // enquanto o topo for maior ou igual ao local para ser adicionado
    {
        valor_auxiliar = desempilhar_pilha(p); // desempilha da pilha original
        empilhar_pilha(pilha_auxiliar, valor_auxiliar); // empilha na pilha auxiliar
    }

    empilhar_pilha(p, valor); // agora que o caminho está limpo, empilha o elemento na posição desejada

    while (pilha_auxiliar->topo >= 0) // enquanto o topo da pilha auxiliar for maior ou igual a zero
    {
        valor_auxiliar = desempilhar_pilha(pilha_auxiliar); // desempilha da pilha auxiliar
        empilhar_pilha(p, valor_auxiliar); // reempilha na pilha original
    }

    destruir_pilha(pilha_auxiliar); // destói a pilha auxiliar para liberar memória
}

void desempilhar_na_posicao(pilha_t* p, int posicao)
{
    if (pilha_vazia(p)) return; // se a pilha estiver vazia, não faz nada

    int indice = limitar_posicao_da_pilha(p, posicao); // índice do elemento a ser removido
    pilha_t* pilha_auxiliar = criar_pilha(p->capacidade); // cria uma pilha auxiliar
    int valor_auxiliar; // variável auxiliar

    while (p->topo > indice) // enquanto o topo for igual ao local para ser removido
    {
        valor_auxiliar = desempilhar_pilha(p); // desempilha da pilha original
        empilhar_pilha(pilha_auxiliar, valor_auxiliar); // empilha na pilha auxiliar
    }

    desempilhar_pilha(p); // agora que o caminho está limpo, desempilha o elemento da posição desejada

    while (pilha_auxiliar->topo >= 0) // enquanto o topo da pilha auxiliar for maior ou igual a zero
    {
        valor_auxiliar = desempilhar_pilha(pilha_auxiliar); // desempilha da pilha auxiliar
        empilhar_pilha(p, valor_auxiliar); // reempilha na pilha original
    }

    destruir_pilha(pilha_auxiliar); // destói a pilha auxiliar para liberar memória
}
