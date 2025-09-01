cmake_minimum_required(VERSION 4.00)
project(laboratorio C)

set(CMAKE_C_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
        libprg
        GIT_REPOSITORY https://github.com/yanvpp/libprg.git
        GIT_TAG origin/main
        # or GIT_TAG 0.0.1

        # You can reference a local directory instead
        # URL file:///${CMAKE_CURRENT_SOURCE_DIR}/../libprg
)
FetchContent_MakeAvailable(libprg)

add_executable(laboratorio main.c
        laboratorios/lab_2/lab_2.c
        laboratorios/lab_2/header/libprg.h)

# linking libprg
target_link_libraries(laboratorio PUBLIC libprg)