#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no* proximo;
} no_t;

no_t* criar_lista_encadeada(int valor)
{
    no_t* no = malloc(sizeof(no_t)); // cria um nó
    no->valor = valor; // o valor do nó passa a ser o valor que a função recebeu
    no->proximo = NULL; // o último nó da lista sempre apontará para NULL

    return no; // retorna o nó criado
}

no_t* criar_lista_encadeada_circular(int valor)
{
    no_t* no = malloc(sizeof(no_t)); // aloca memória para criar o nó
    no->valor = valor; // o valor do nó passa a ser o valor que a função recebeu
    no->proximo = no; // o último nó da lista sempre apontará para o primeiro elemento

    return no; // retorna o nó criado
}

no_t* inicio_lista_encadeada(no_t** inicio)
{
    if (inicio) // se o início for diferente de NULL -- Se a lista não for vazia
    {
        return *inicio; // retorna o valor armazenado aonde o início está apontando
    }
    return NULL; // caso a lista esteja vazia, retorna NULL
}


void adicionar_na_lista_encadeada(no_t** inicio, int valor)
{
    no_t* novo_no = criar_lista_encadeada(valor); // cria a lista encadeada (nó)
    novo_no->proximo = *inicio; // o novo nó passa a apontar para o elemento que já existia
    *inicio = novo_no; // e o início passa a apontar para o novo nó
}

void adicionar_na_lista_encadeada_circular(no_t** inicio, int valor)
{
    no_t* novo_no = criar_lista_encadeada_circular(valor); // cria a lista encadeada circular (nó)
    novo_no->proximo = *inicio; // o novo nó passa a apontar para o elemento que já existia

    no_t* ultimo = *inicio; // o início passa a ser o último

    if (*inicio == NULL) // se a lista estiver vazia
    {
        *inicio = novo_no; // o ínicio é igual ao novo nó criado
        novo_no->proximo = novo_no; // o primeiro nó aponta para si mesmo
        return;
    }

    while (ultimo->proximo != *inicio) // enquanto o endereço do próximo do último for diferente do endereço do inicial
    {
        // enquanto o próximo do último for diferente do & do primeiro
        ultimo = ultimo->proximo; // passa para o próximo
    }

    ultimo->proximo = novo_no; // o último passa a apontar para o elemento recém adcionado
    *inicio = novo_no; // e o início passa a ser o nó recém adicionado
}

no_t* buscar_na_lista_encadeada(no_t** inicio, int valor)
{
    no_t* atual = *inicio; // o atual passa a ser o inicio

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

void listar_lista_encadeada(no_t** inicio)
{
    no_t* atual = *inicio; // o atual é o início

    while (atual) // enquanto o atual for diferente de NULL
    {
        no_t* proximo = atual->proximo; // o próximo é igual ao próximo do atual
        printf("\t%d", atual->valor); // imprime o valor do atual
        atual = proximo; // o atual passa a ser o próximo
    }
}

void remover_da_lista_encadeada(no_t** inicio, int valor)
{
    no_t* atual = *inicio; // o atual passa a ser o inicio
    no_t* anterior = NULL; // o anterior passa a ser o NULL

    while (atual) // enquanto o atual for diferente de NULL
    {
        if (atual->valor == valor) // se o valor do atual for igual ao valor solicitado
        {
            if (anterior) // se tiver anterior
            {
                anterior->proximo = atual->proximo; // o próximo do anterior será o próximo do atual
            }
            else // se não tiver anterior
            {
                *inicio = atual->proximo; //o iníncio passa a ser o próximo do atual
            }
            free(atual); // libera o local da memória do elemento removido ~~ remove o elemento
            break; // se achou, quebra o while
        }
        anterior = atual; // o anterior passa a ser o atual
        atual = atual->proximo; // o atual passa a ser o próximo do anterior (o próximo elemento)
    }
}

void destruir_lista_encadeada(no_t** inicio)
{
    // no_t *atual = *inicio;
    // no_t *proximo = atual->proximo;
    //
    // while (proximo) { // enquanto o atual for diferente de nulo
    //     free(atual); // limpa o local onde o atual está apontando, não a variável "atual"
    //     atual = proximo; // o atual passa a ser o próximo
    //     proximo = atual->proximo; // o proximo passa a ser o próximo do atual
    // }
    // free (atual); // limpa o valor antes do NULL

    // da maneira que fiz em cima funciona também, mas abaixo está uma forma com menos linhas, mais eficiente

    no_t* atual = *inicio; // o atual passa a ser o início

    while (atual) // enquanto o atual for diferente de NULL ~~ enquanto tiver elementos
    {
        no_t* proximo = atual->proximo; // o próximo passa a ser o próximo do atual
        free(atual); // limpa o local onde o atual está apontando, não a variável "atual"
        atual = proximo; // o atual passa a ser o próximo
    }
}

int tamanho_da_lista_encadeada(no_t* inicio)
{
    int quantidade_de_elementos = 0;
    no_t* atual = inicio;

    for (int i = 0; atual; i++) // enquanto o atual for diferente de nulo
    {
        atual = atual->proximo; // passa para o próximo
        quantidade_de_elementos++; // aumenta a quantidade de elementos
    }

    return quantidade_de_elementos; // retorna a quantidade de elementos
}

void destruir_lista_encadeada_circular(no_t** inicio)
{
    if (*inicio == NULL) // se a lista já estiver vazia
    {
        return; // apenas retorna
    }

    no_t* atual = *inicio; // o atual passa a ser o início

    while (atual) // enquanto o atual for diferente de NULL ~~ enquanto tiver elementos
    {
        no_t* proximo = atual->proximo; // o próximo passa a ser o próximo do atual
        free(atual); // limpa o local onde o atual está apontando, não a variável "atual"
        if (proximo == *inicio) break; // se o próximo for o início, interrompe e encerra o código
        atual = proximo; // o atual passa a ser o próximo
    }
}

int limitar_na_lista_encadeada(no_t** inicio, int posicao)
{
    int tamanho_da_lista = tamanho_da_lista_encadeada(*inicio);

    if (posicao < 0) // se a posição desejada for menor que zero
    {
        return 0; // retorna a posição zero
    }

    if (posicao > tamanho_da_lista) // se a posição desejada for maior que zero
    {
        return tamanho_da_lista; // retorna a última posição da lista
    }

    return posicao; // caso contrário, retorna a própria posição
}

void adicionar_na_posicao_da_lista_encadeada(no_t** inicio, int valor, int posicao)
{
    no_t* atual = *inicio; // o nó atual passa a ser o início
    int indice = limitar_na_lista_encadeada(inicio, posicao); // indice limitado para inserção

    if (indice == 0)
    {
        no_t* novo_no = criar_lista_encadeada(valor); // cria um novo nó
        novo_no->proximo = *inicio; // o próximo do nó criado será o início
        *inicio = novo_no; // o início passa a ser o novo nó
        return; // retorna
    }

    no_t* novo_no = criar_lista_encadeada(valor); // cria um novo nó com o valor desejado

    for (int i = 0; i < indice - 1; i++) // enquanto não estiver na posição desejada
    {
        atual = atual->proximo; // percorre a lista encadeada até encontrar a posição
    }

    novo_no->proximo = atual->proximo; // o próximo do nó criado passa a ser o próximo do atual
    atual->proximo = novo_no; // o próximo do atual passa a ser o nó criado
}

bool lista_encadeada_vazia(no_t** inicio)
{
    return tamanho_da_lista_encadeada(*inicio) == 0;
}

no_t* buscar_na_posicao_da_lista_encadeada(no_t** inicio, int posicao)
{
    if (posicao < 0) return NULL; // se a posição for menor que zero, retorna nulo

    no_t* atual = *inicio; // o atual passa a ser o início

    for (int i = 0; atual; i++) // enquanto não estiver na posição
    {
        if (i == posicao) return atual; // se encontrar a posição, retorna o elemento dela
        atual = atual->proximo; // se não encontrar, passa para o próximo
    }

    return NULL; // se não encontrar, retorna nulo
}

void remover_da_posicao_da_lista_encadeada(no_t** inicio, int posicao)
{
    if (lista_encadeada_vazia(inicio)) return; // se a lista estiver vazia, não faz nada

    if (posicao < 0) return; // se a posição for menor que zero, não faz nada
    if (posicao > tamanho_da_lista_encadeada(*inicio)) return; // se a posição for maior que o tamanho da lista, não faz nada

    no_t* no_para_remover = NULL; // cria um nó auxiliar para ser apagado

    if (posicao == 0) // se o índice for igual a zero, remove o primeiro elemento
    {
        no_para_remover = *inicio; // guarda o endereço do nó a ser removido
        *inicio = (*inicio)->proximo; // o início da lista passa para o segundo elemento
    }
    else
    {
        no_t* anterior = *inicio; // o atual é o início

        for (int i = 0; i < posicao - 1; i++) // enquanto posicao do anterior != posicao - 1
        {
            anterior = anterior->proximo; // passa para o próximo
        }

        no_para_remover = anterior->proximo; // quando chegar, o nó para remover se torna o próximo do anterior
        anterior->proximo = no_para_remover->proximo; // e o próximo do anterior se torna o próximo do nó para remover
    }

    free(no_para_remover); // libera a memória do nó auxiliar
}

int tamanho_da_lista_encadeada_circular(no_t* inicio)
{
    if (inicio == NULL) return 0; // se a lista estiver vazia, retorna o tamanho como 0

    int quantidade_de_elementos = 0; // contador
    no_t* atual = inicio; // nó auxiliar para percorrer

    for (int i = 0; atual->proximo != inicio; i++) // enquanto o próximo do atual for diferente do início
    {
        atual = atual->proximo; // passa para o próximo
        quantidade_de_elementos++; // aumenta a quantidade de elementos
    }

    return quantidade_de_elementos + 1; // retorna a quantidade de elementos + 1, pois o último não é contado no laço for
}

void adicionar_na_posicao_da_lista_encadeada_circular(no_t** inicio, int valor, int posicao)
{
    if (*inicio == NULL) // se a lista estiver vazia
    {
        adicionar_na_lista_encadeada_circular(inicio, valor); // insere na primeira posição
        return; // retorna
    }

    int tamanho_da_lista = tamanho_da_lista_encadeada_circular(*inicio); // tamanho da lista encadeada circular
    int indice = posicao; // variável auxiliar
    if (indice < 0) indice = 0; // se a posição for menor que zero, o índice se torna 0
    if (indice > tamanho_da_lista) indice = tamanho_da_lista; // se a posição for maior que o tamanho da lista, o índice se torna o último elemento dela

    no_t* atual = *inicio; // nó auxiliar
    no_t* novo_no = criar_lista_encadeada_circular(valor);

    for (int i = 0; i < indice - 1; i++) // enquanto não encontrar o anterior da posição alvo
    {
        atual = atual->proximo; // passa para o próximo
    }

    novo_no->proximo = atual->proximo; // o próximo do nó criado será o próximo do atual
    atual->proximo = novo_no; // o próximo do atual será o nó criado
}