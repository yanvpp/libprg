cmake_minimum_required(VERSION 4.00)
project(libprg C)

set(CMAKE_C_STANDARD 17)

set(HEADERS
        "${CMAKE_CURRENT_LIST_DIR}/src/include/libprg/libprg.h"
)

set(SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/src/libprg/pilha.c"
        src/include/libprg/libprg.h
        src/libprg/fila.c
        src/libprg/lista_linear.c
        src/libprg/lista_encadeada.c
        src/libprg/lista_encadeada_dupla.c
        src/libprg/alg_ord_troca.c
        src/libprg/arvore_binaria.c
        src/libprg/dicionario.c
)

add_library(libprg ${SOURCES})

target_include_directories(libprg PUBLIC "${CMAKE_CURRENT_LIST_DIR}/src/include")

source_group(
        TREE "${CMAKE_CURRENT_LIST_DIR}/src/include"
        PREFIX "Header Files"
        FILES ${HEADERS}
)

install(TARGETS libprg DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include)