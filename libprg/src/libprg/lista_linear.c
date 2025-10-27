#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct lista_linear // define a estrutura da lista linear
{
    int* elementos; // elementos da lista linear
    int tamanho; // tamanho da lista linear
    int capacidade; // capacidade da lista linear
    bool ordenada; // "a lista é ordenada ou não?"
} lista_linear_t;

lista_linear_t* criar_lista_linear(int capacidade, bool ordenada)
{
    lista_linear_t* ll = malloc(sizeof(lista_linear_t)); // aloca memória para a lista linear

    ll->elementos = malloc(capacidade * sizeof(int)); // aloca memória para os elementos da lista linear
    ll->tamanho = 0; // inicia o tamanho da lista linear como zero, pois está vazia
    ll->capacidade = capacidade; // a capacidade da lista é igual à recebida pela função
    ll->ordenada = ordenada; // define se a lista é ou não ordenada

    return ll; // retorna a lista
}

bool lista_cheia(lista_linear_t* ll)
{
    return ll->tamanho == ll->capacidade; // se o tamanho for igual a capacidade, a lista está cheia
}

bool lista_vazia(lista_linear_t* ll)
{
    return ll->tamanho == 0; // se o tamanho for igual a zero, a lista está vazia
}

void inserir_na_lista_nao_ordenada(lista_linear_t* ll, int valor)
{
    ll->elementos[ll->tamanho] = valor; // insere um valor no array elementos na posição fim da lista
    ll->tamanho++; // aumenta o tamanho da lista
}

void inserir_na_lista_ordenada(lista_linear_t* ll, int valor)
{
    int i;

    for (i = ll->tamanho; i > 0 && ll->elementos[i - 1] > valor; i--) // inicia i = tamanho da lista
    // procura na lista, de trás para frente, um elemento maior que o valor a ser inserido
    {
        ll->elementos[i] = ll->elementos[i - 1]; // desloca o elemento maior que o valor a ser inserido para a direita
    }
    ll->elementos[i] = valor; // insere o valor na posição que foi desocupada
    ll->tamanho++; // aumenta o tamanho da lista
}

void inserir_na_lista(lista_linear_t* ll, int valor)
{
    if (lista_cheia(ll)) // se a lista estiver cheia
    {
        int* novo = realloc(ll->elementos, sizeof(int) * ll->capacidade * 2); // auxiliar para segurança

        if (!novo) exit(EXIT_FAILURE); // se não realocou corretamente, retorna erro

        ll->elementos = novo; // se realocou corretamente, implementa o novo tamanho
        ll->capacidade *= 2; // dobra a capacidade
    }

    if (ll->ordenada) // e se a lista for ordenada
    {
        inserir_na_lista_ordenada(ll, valor); // chama a função que insere na ordenada
    }
    else
    {
        inserir_na_lista_nao_ordenada(ll, valor); // caso contrário, chama a função que insere na não ordenada
    }
}

int busca_binaria(lista_linear_t* ll, int valor)
{
    int inicio = 0, fim = ll->tamanho - 1; // define o início como 0 e o fim como a última posição da lista

    while (inicio <= fim) // enquanto o início for menor que o fim
    {
        int meio = inicio + (fim - inicio) / 2; // o meio será o meio da fila

        if (valor == ll->elementos[meio]) // se o valor que está no meio for igual ao valor que estamos buscando
        {
            return meio; // retorna o índice do meio
        }
        if (ll->elementos[meio] < valor) // se o valor que está no meio for menor que o valor
        {
            inicio = meio + 1; // separa a metade da frente da lista e reinicia o processo
        }
        else
        {
            fim = meio - 1; // separa a metada de trás da lista e reinicia o processo
        }
    }
    return -1; // retorna que não encontrou o elemento
}

int busca_linear(lista_linear_t* ll, int valor)
{
    for (int index = 0; index < ll->tamanho; index++) //enquanto o índice for menor que o tamanho da lista
    {
        if (ll->elementos[index] == valor) // se o elemento na posição do indíce for igual ao valor
        {
            return index; // retorna o índice
        }
    }
    return -1; // caso não encontre, retorna que não encontrou
}

int buscar_na_lista(lista_linear_t* ll, int valor)
{
    if (!lista_vazia(ll)) // se a lista não está vazia
    {
        if (ll->ordenada) // se a lista for ordenada
        {
            return busca_binaria(ll, valor); // retorna o que a função busca binária retornar
        }
        return busca_linear(ll, valor); // retorna o que a função busca linear retornar
    }
    return -1; // retorna que não encontrou o elemento
}

void remover_da_lista(lista_linear_t* ll, int valor)
{
    if (lista_vazia(ll)) // se a lista estiver vazia
    {
        return; // retorna e não faz nada
    }

    int index = buscar_na_lista(ll, valor); // o índice passa a ser o local aonde o valor está armazenado

    if (index == -1) // se o índice for igual a -1
    {
        return; // retorna e não faz nada, pois o elemento não foi encontrado
    }

    if (ll->ordenada) // se a lista for ordenada
    {
        for (int i = index; i < ll->tamanho - 1; i++) // inicia i como o valor do índice
        // enquanto ele for menor que o último elemento da lista
        {
            ll->elementos[i] = ll->elementos[i + 1]; // recua os elementos para preencher o espaço vazio
        }
    }
    else // caso não seja ordenada
    {
        ll->elementos[index] = ll->elementos[ll->tamanho - 1];
        // o local do elemento removido passa a armazenar o que estava no fim da lista
    }
    ll->tamanho--; // diminui o tamanho
}

int tamanho_lista_linear(lista_linear_t* ll)
{
    return ll->tamanho; // retorna o tamanho da lista
}

void listar_lista_linear(lista_linear_t* ll)
{
    for (int i = 0; i < ll->tamanho; i++) // enquanto i for menor que o tamanho
    {
        printf("\t%d", ll->elementos[i]); // imprime no terminal todos os elementos da lista
    }
}

int inicio_lista_linear(lista_linear_t* ll)
{
    if (lista_vazia(ll)) return -1; // se a lista estiver vazia, retorna -1

    return ll->elementos[0]; // retorna o elemento que está no início da lista
}

int buscar_na_posicao_da_lista(lista_linear_t* ll, int posicao)
{
    if (posicao < 0 || posicao > tamanho_lista_linear(ll) - 1) return -1; // se a posição for inválida, não faz nada

    return ll->elementos[posicao]; // se for válida, retorna o valor que está na posição desejada
}

int limitar_posicao_na_lista(lista_linear_t* ll, int posicao)
{
    if (posicao > ll->tamanho) return ll->tamanho - 1; // se a posição for maior que o tamanho, insere no final
    if (posicao < 0) return 0; // se a posição for menor que zero, insere na posição 0
    return posicao; // caso contrário, retorna a própria posição
}

void inserir_na_posicao_da_lista(lista_linear_t* ll, int valor, int posicao)
{
    int indice = limitar_posicao_na_lista(ll, posicao); // local para adicionar

    if (!ll->ordenada) // se não for ordenada
    {
        inserir_na_lista_nao_ordenada(ll, ll->elementos[indice]); // coloca o valor que está na posição no fim da lista
        ll->elementos[indice] = valor; // insere o valor desejado na posição desejada
    }
    else
    {
        inserir_na_lista_ordenada(ll, valor); // se for ordenada, insere na lista ordenada
    }
}

void remover_na_posicao_da_lista(lista_linear_t* ll, int posicao)
{
    if (posicao < 0 || posicao > tamanho_lista_linear(ll) - 1) return; // se a posição for inválida, não faz nada

    if (ll->ordenada) // se a lista for ordenada
    {
        for (int i = posicao; i < ll->tamanho - 1; i++) // a partir da posição até o fim da lista
        {
            ll->elementos[i] = ll->elementos[i + 1]; // desloca os elementos da direita para a esquerda
        }
    } else // se não for ordenada
    {
        ll->elementos[posicao] = ll->tamanho - 1; // substitui o elemento da posição pelo último elemento da lista
    }

    ll->tamanho--; // diminui 1 do tamanho
}

void destruir_lista(lista_linear_t* ll)
{
    free(ll->elementos); // libera a memória alocada pelos elementos da lista
    free(ll); // libera a memória alocada pela lista
}