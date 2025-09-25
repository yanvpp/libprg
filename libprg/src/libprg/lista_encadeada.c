//
// Created by aluno on 25/09/2025.
//
#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

no_t criar_no(int valor) {

    no_t *no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = NULL;

    return *no;
}

