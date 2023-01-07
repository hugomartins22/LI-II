/**
 * @file Ficheiro que contém as funções relativas ao guião 2 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include "g1.h"
#include "g2.h"
#include "g3.h"
#include "g4.h"
#include "parse.h"
#include <assert.h>

/**
 * \brief Função dollarfunction do programa
 * 
 * recebe como parâmetros um apontador para a struct stack 
 * e devolve o valor apontado para esse índice.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void dollarfunction(struct stack *ptr_STACK)
{

    struct elemento x = POP(ptr_STACK);
    int i = (x.data.val_i);
    struct elemento y = (*ptr_STACK).array[(*ptr_STACK).top - i];
    PUSH(ptr_STACK, y);
}

/**
 * \brief Função maths do programa
 * 
 * efetua o cálculo das operações aritméticas.
 * 
 * @param ptr_STACK (apontador para a stack)
 * @param token (operando)
 */
void maths(struct stack *ptr_STACK, char *token)
{
    switch (*token)
    {
    case '(':
        decrement(ptr_STACK);
        break;
    case ')':
        increment(ptr_STACK);
        break;
    case '~':
        complement(ptr_STACK);
        break;
    default:
        call_operator(ptr_STACK, token);
        break;
    }
}

/**
 * \brief Função manstack do programa
 * 
 * efetua o cálculo das operações para manipulação da Stack.
 * 
 * @param ptr_STACK (apontador para a stack)
 * @param token (operando)
 */
void manstack(struct stack *ptr_STACK, char *token)
{
    switch (*token)
    {
    case '_':
        double_top(ptr_STACK);
        break;
    case ';':
        POP(ptr_STACK);
        break;
    case '\\':
        switch_top(ptr_STACK);
        break;
    case '@':
        rotate_elem(ptr_STACK);
        break;
    case '$':
        dollarfunction(ptr_STACK);
        break;
    }
}

/**
 * \brief Função conversion do programa
 * 
 *  efetua a conversão dos elementos da Stack para um dado tipo.
 * 
 * @param ptr_STACK (apontador para a stack)
 * @param token (operando)
 */
void conversion(struct stack *ptr_STACK, char *token)
{
    switch (*token)
    {
    case 'i':
        convert_i(ptr_STACK);
        break;
    case 'f':
        convert_f(ptr_STACK);
        break;
    case 'c':
        convert_c(ptr_STACK);
        break;
    case 's':
        convert_s(ptr_STACK);
        break;
    }
}

/**
 * \brief Função inoutput do programa
 * 
 * é responsável pelas ações de in/output.
 * 
 * @param ptr_STACK (apontador para a stack)
 * @param token (operando)
 */
void inoutput(struct stack *ptr_STACK, char *token)
{
    switch (*token)
    {
    case 'l':
        read_line(ptr_STACK);
        break;
    case 't':
        read_all_lines(ptr_STACK);
        break;
    }
}

/**
 * \brief Função logic do programa
 * 
 * é responsável pelas ações de lógica e condições.
 * 
 * @param ptr_STACK (apontador para a stack)
 * @param token (operando)
 */
void logic(struct stack *ptr_STACK, char *token)
{
    switch (*token)
    {
    case '>':
        greater(ptr_STACK);
        break;
    case '<':
        smaller(ptr_STACK);
        break;
    case '=':
        equal(ptr_STACK);
        break;
    case '!':
        no(ptr_STACK);
        break;
    case '?':
        ifthenelse(ptr_STACK);
        break;
    default:
        efunction(ptr_STACK, (token + 1));
        break;
    }
}

/**
 * \brief Função double_top do programa
 * 
 * é responsável por duplica os dois elementos do topo da stack.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void double_top(struct stack *ptr_STACK)
{
    struct elemento x = POP(ptr_STACK);
    PUSH(ptr_STACK, x);
    PUSH(ptr_STACK, x);
}

/**
 * \brief Função switch_top do programa
 * 
 * é responsável por trocar os dois elementos do topo da stack.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void switch_top(struct stack *ptr_STACK)
{
    struct elemento x = POP(ptr_STACK);
    struct elemento y = POP(ptr_STACK);
    PUSH(ptr_STACK, x);
    PUSH(ptr_STACK, y);
}

/**
 * \brief Função rotate_elem do programa
 * 
 * é responsável por rodar os três elementos do topo da stack.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void rotate_elem(struct stack *ptr_STACK)
{
    struct elemento x = POP(ptr_STACK);
    struct elemento y = POP(ptr_STACK);
    struct elemento z = POP(ptr_STACK);
    PUSH(ptr_STACK, y);
    PUSH(ptr_STACK, x);
    PUSH(ptr_STACK, z);
}

/**
 * \brief Função convert_i do programa
 * 
 * é responsável por converter o elemento do topo da stack para int.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void convert_i(struct stack *ptr_STACK)
{
    struct elemento val = POP(ptr_STACK);
    switch (val.tipo)
    {
    case T_int:
        break;
    case T_float:
        val.tipo = T_int;
        val.data.val_i = (int)val.data.val_f;
        break;
    case T_double:
        val.tipo = T_int;
        val.data.val_i = (int)val.data.val_d;
        break;
    case T_long:
        val.tipo = T_int;
        val.data.val_i = (int)val.data.val_l;
        break;
    case T_string:
        val.tipo = T_int;
        val.data.val_i = atoi(val.data.val_s);
        break;
    case T_char:
        val.tipo = T_int;
        val.data.val_i = (int)(val.data.val_c);
        break;
    default:
        printf("Deu bagulho na função convert_i\n");
        break;
    }
    PUSH(ptr_STACK, val);
}

/**
 * \brief Função convert_f do programa
 * 
 * é responsável por converter o elemento do topo da stack para float.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void convert_f(struct stack *ptr_STACK)
{
    struct elemento val = POP(ptr_STACK);
    switch (val.tipo)
    {
    case T_int:
        val.tipo = T_float;
        val.data.val_f = (float)val.data.val_i;
        break;
    case T_float:
        break;
    case T_double:
        val.tipo = T_float;
        val.data.val_f = (float)val.data.val_d;
        break;
    case T_long:
        val.tipo = T_float;
        val.data.val_f = (float)val.data.val_l;
        break;
    case T_string:
        val.tipo = T_float;
        val.data.val_f = atof(val.data.val_s);
        break;
    default:
        printf("Deu bagulho na função convert_f\n");
        break;
    }
    PUSH(ptr_STACK, val);
}

/**
 * \brief Função convert_c do programa
 * 
 * é responsável por converter o elemento do topo da stack para char.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void convert_c(struct stack *ptr_STACK)
{
    struct elemento val = POP(ptr_STACK);
    switch (val.tipo)
    {
    case T_int:
        val.tipo = T_char;
        val.data.val_c = (int)val.data.val_i;
        break;
    case T_float:
        val.tipo = T_char;
        val.data.val_c = (int)val.data.val_f;
        break;
    case T_double:
        val.tipo = T_char;
        val.data.val_c = (int)val.data.val_d;
        break;
    case T_long:
        val.tipo = T_char;
        val.data.val_c = (int)val.data.val_l;
        break;
    default:
        printf("Deu bagulho na função convert_c\n");
        break;
    }
    PUSH(ptr_STACK, val);
}

/**
 * \brief Função convert_s do programa
 * 
 * é responsável por converter o elemento do topo da stack para string.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void convert_s(struct stack *ptr_STACK)
{
    struct elemento val = POP(ptr_STACK);
    switch (val.tipo)
    {
    case T_int:
        val.tipo = T_string;
        sprintf(val.data.val_s, "%d", val.data.val_i);
        break;
    case T_float:
        val.tipo = T_string;
        sprintf(val.data.val_s, "%f", val.data.val_f);
        break;
    case T_double:
        val.tipo = T_string;
        sprintf(val.data.val_s, "%f", val.data.val_d);
        break;
    case T_long:
        val.tipo = T_string;
        sprintf(val.data.val_s, "%ld", val.data.val_l);
        break;
    case T_char:
        val.tipo = T_string;
        sprintf(val.data.val_s, "%c", val.data.val_c);
        break;
    default:
        printf("Deu bagulho na função convert_s\n");
        break;
    }
    PUSH(ptr_STACK, val);
}

/**
 * \brief Função read_line do programa
 * 
 * é responsável por ler uma linha.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void read_line(struct stack *ptr_STACK)
{
    struct elemento x;
    x.tipo = T_string;
    x.data.val_s = malloc(1000 * sizeof(char));
    assert(fgets(x.data.val_s, 1000, stdin) != NULL);

    if ((strlen(x.data.val_s) > 0) && (x.data.val_s[strlen(x.data.val_s) - 1] == '\n'))
        x.data.val_s[strlen(x.data.val_s) - 1] = '\0';

    PUSH(ptr_STACK, x);
}

/**
 * \brief Função read_all_lines do programa
 * 
 * é responsável por ler todas as linhas 
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void read_all_lines(struct stack *ptr_STACK)
{
    struct elemento total;
    total.tipo = T_string;
    total.data.val_s = malloc(10000 * sizeof(char));
    assert(fgets(total.data.val_s, 10000, stdin) != NULL);

    struct elemento x;
    x.tipo = T_string;
    x.data.val_s = malloc(10000 * sizeof(char));
    while (fgets(x.data.val_s, 10000, stdin) != NULL)
    {
        if ((strlen(x.data.val_s) == 1))
        {
            x.data.val_s[strlen(x.data.val_s) - 1] = '\0';
            mystrcat4(total.data.val_s, x.data.val_s);
            free(x.data.val_s);
            break;
        }

        mystrcat4(total.data.val_s, x.data.val_s);
    }
    PUSH(ptr_STACK, total);
}

/**
 * \brief Função decrement do programa
 * 
 * é responsável por decrementar um elemento.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void decrement(struct stack *ptr_STACK)
{
    struct elemento x = POP(ptr_STACK);
    x.data.val_l--;
    PUSH(ptr_STACK, x);
}

/**
 * \brief Função increment do programa
 * 
 * é responsável por incrementar um elemento.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void increment(struct stack *ptr_STACK)
{
    struct elemento x = POP(ptr_STACK);
    x.data.val_l++;
    PUSH(ptr_STACK, x);
}

/**
 * \brief Função complement do programa
 * 
 * é responsável por transformar o elemento em complemento para 2.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void complement(struct stack *ptr_STACK)
{
    struct elemento x = POP(ptr_STACK);
    (x.data.val_l) = ~(x.data.val_l);
    PUSH(ptr_STACK, x);
}

/**
 * \brief Função call_operator do programa
 * 
 * é responsável por chamar a função operador.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void call_operator(struct stack *ptr_STACK, char *token)
{
    struct elemento x = POP(ptr_STACK);
    struct elemento y = POP(ptr_STACK);
    PUSH(ptr_STACK, operador(x, y, token));
}