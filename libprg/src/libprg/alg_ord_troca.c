//
// Created by aluno on 13/11/2025.
//
#include "libprg/libprg.h"

void bubble_sort(int* vetor, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) // para revisar a lista, partindo de cada elemento dela
    {
        for (int j = 0; j < tamanho - 1; j++) // para organizar a cada passada
        {
            if (vetor[j] > vetor[j + 1]) // se o elemento for maior que o seu sucessor
            {
                int aux = vetor[j]; // cria um auxiliar para organização
                vetor[j] = vetor[j + 1]; // passa o elemento para frente
                vetor[j + 1] = aux; // passa o elemento que estava na frente para trás
            }
        }
    }
}