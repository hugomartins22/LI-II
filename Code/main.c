/**
 * @file Ficheiro que contém a função main do programa
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include "parse.h"

/**
 * \brief Função main do programa
 * 
 * Inicia-se a função com uma variável.
 * Posteriormente, usam-se as funções:
 *  . fgets que lê uma string (neste caso, de um input);
 *  . strlen que devolve o tamanho de uma string;
 *  . assert que, por boa prática, verifica se o resultado é o esperado.
 * 
 * @returns O valor 0
 */
int main()
{
    char line[10240];

    assert(fgets(line, 10240, stdin) != NULL);
    assert(line[strlen(line) - 1] == '\n');

    parse(line);
    return 0;
}
