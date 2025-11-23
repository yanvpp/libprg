//
// Created by aluno on 13/11/2025.
//
#include <stdlib.h>

#include "libprg/libprg.h"

void bubble_sort(int* vetor, int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++) // para revisar a lista, partindo de cada elemento dela
    {
        for (int j = 0; j < tamanho - 1; j++) // para organizar a cada passagem
        {
            if (vetor[j] > vetor[j + 1]) // se o elemento for maior que o seu sucessor
            {
                int aux = vetor[j]; // cria um auxiliar para organização
                vetor[j] = vetor[j + 1]; // passa o elemento da frente para trás
                vetor[j + 1] = aux; // passa o elemento que estava na frente para trás
            }
        }
    }
}

void insertion_sort(int* vetor, int tamanho)
{
    for (int i = 1; i < tamanho; i++) // para percorrer o vetor e verificar a organização
    {
        int aux = vetor[i]; // auxiliar para armazenar o valor
        int j = i - 1; // define a posição para a comparação

        while (j >= 0 && vetor[j] > aux)
        // enquanto j não estiver na posição inicial do vetor e o valor da posição for maior que o auxiliar
        {
            vetor[j + 1] = vetor[j]; // passa o elemento para trás
            j--; // retrocede uma casa para comparação
        }

        vetor[j + 1] = aux; // adiciona o elemento no buraco
    }
}

void selection_sort(int* vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++) // para percorrer o vetor
    {
        int index_menor = i; // auxiliar para as comparações

        for (int j = i + 1; j < tamanho; j++) // percorre o por completo a cada passagem do i
        {
            if (vetor[j] < vetor[index_menor]) // se o elemento na posição j for menor que o menor valor que temos
            {
                index_menor = j; // o menor valor passa a ser o elemento da posição j
            }
        }

        if (index_menor != i) // se havia algum valor menor que o de referência
        {
            int aux = vetor[i]; // guarda o elemento da posição i do vetor
            vetor[i] = vetor[index_menor]; // o elemento da posição i passa a ser o menor valor que encontramos no vetor
            vetor[index_menor] = aux; // o elemento na posição em que estava o menor passa a ser o elemento que removemos
        }
    }
}

void merge(int* vetor, int esquerda, int meio, int direita)
{
    int i, j, k;

    int vetor_esquerda = meio - esquerda + 1;
    int vetor_direita = direita - meio;

    int *l = malloc(vetor_esquerda * sizeof(int));
    int *r = malloc(vetor_direita * sizeof(int));

    for (i = 0; i < vetor_esquerda; i++)
    {
        l[i] = vetor[esquerda + i];
    }
    for (j = 0; j < vetor_direita; j++)
    {
        r[j] = vetor[meio + 1 + j];
    }

    i = 0, j = 0; k = esquerda;

    while (i < vetor_esquerda && j < vetor_direita)
    {
        if (l[i] <= r[j])
        {
            vetor[k] = l[i];
            i++;
        } else
        {
            vetor[k] = r[j];
            j++;
        }
        k++;
    }

    while (i < vetor_esquerda) {
        vetor[k] = l[i];
        i++;
        k++;
    }

    while (j < vetor_direita) {
        vetor[k] = r[j];
        j++;
        k++;
    }

    free(l);
    free(r);
}

void merge_sort(int* vetor, int esquerda, int direita)
{
    int meio = (esquerda + direita) / 2;

    if (esquerda < direita)
    {
        merge_sort(vetor, esquerda, meio);
        merge_sort(vetor, meio + 1, direita);

        merge(vetor, esquerda, meio, direita);
    }
}

int particiona(int* vetor, int esquerda, int direita)
{
    int pivo = vetor[direita];
    int i = esquerda - 1;

    for (int j = esquerda; j <= direita; j++)
    {
        if (vetor[j] <= pivo)
        {
            i++;
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }

    int aux = vetor[i + 1];
    vetor[i + 1] = vetor[direita];
    vetor[direita] = aux;

    return i + 1;
}

void quick_sort(int* vetor, int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int pi = particiona(vetor, esquerda, direita);

        quick_sort(vetor, esquerda, pi - 1);
        quick_sort(vetor, pi + 1, direita);
    }
}