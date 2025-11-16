//
// Created by aluno on 13/11/2025.
//
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