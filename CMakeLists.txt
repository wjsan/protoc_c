cmake_minimum_required(VERSION 3.5)
project(protobuf_c C)

# Adiciona a flag de compilação do C99
set(CMAKE_C_STANDARD 99)

# Adiciona os arquivos do seu projeto
set(SOURCES
    main.c
    test.pb-c.c
    protobuf-c/protobuf-c.c
)

set(HEADERS
    test.pb-c.h
    protobuf-c/protobuf-c.h
)

# Adiciona o executável do seu projeto
add_executable(seu_executavel ${SOURCES} ${HEADERS})
