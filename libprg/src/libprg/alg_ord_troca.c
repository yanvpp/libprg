//
// Created by aluno on 13/11/2025.
//
#include "libprg/libprg.h"

void bubble_sort(int* vetor, int tamanho) {
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

void insertion_sort(int* vetor, int tamanho) {
    for (int i = 1; i < tamanho; i++) // para percorrer o vetor e verificar a organização
    {
        int aux = vetor[i]; // auxiliar para armazenar o valor
        int j = i - 1; // define a posição para a comparação

        while (j >= 0 && vetor[j] > aux) // enquanto j não estiver na posição inicial do vetor e o valor da posição for maior que o auxiliar
        {
            vetor[j + 1] = vetor[j]; // passa o elemento para trás
            j--; // retrocede uma casa para comparação
        }

        vetor[j + 1] = aux; // adiciona o elemento no buraco
    }
}