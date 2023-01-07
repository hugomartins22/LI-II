/**
 * @file Ficheiro que contém as funções da Sack
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include <assert.h>

/**
 * \brief Função POP do programa
 * 
 * Função que vai à Stack tirar a última célula.
 * 
 * @returns Um valor elemento .
 */
struct elemento POP(struct stack *stack)
{
    stack->top--;
    return stack->array[stack->top + 1];
}

/**
 * \brief Função PUSH do programa
 * 
 *que adiciona uma célula à Stack .
 * 
 * @param stack
 * @param n (elemento a adicionar).
 */
void
PUSH(struct stack *stack, struct elemento n)
{

    stack->top++;

    stack->array[stack->top] = n;
}

/**
 * \brief Função PRINSTACK_STACK do programa.
 * 
 * Inicia-se um ciclo for, onde uma variável é incializada também,
 * a condição de paragem ocorre se a variável é maior
 * que o topo da da Stack, a cada iteração incrementa-se a variável.
 * 
 * É imprimido o valor da Stack no índice da variável, de acordo
 * com o seu valor a cada iteração.
 * 
 * @param stack
 */
void PRINT_STACK(struct stack *stack)
{

    for (int i = 0; i <= (*stack).top; i++)
    {
        switch ((*stack).array[i].tipo)
        {
        case T_int:
            printf("%d", (*stack).array[i].data.val_i);
            break;
        case T_long:

            printf("%ld", (*stack).array[i].data.val_l);
            break;
        case T_float:

            printf("%.6g", stack->array[i].data.val_f);
            break;
        case T_double:

            printf("%.6g", stack->array[i].data.val_d);
            break;
        case T_char:

            printf("%c", stack->array[i].data.val_c);
            break;
        case T_string:

            printf("%s", stack->array[i].data.val_s);
            break;
        case T_array:
            PRINT_ARRAY((stack->array[i].data.val_p));
            break;
        case T_block:
            printf("%s", stack->array[i].data.val_b);
            break;
        default:
            printf("FALTA AS STRINGS na print_array!\n");
            break;
        }
    }
    printf("\n");
    free_Stack(stack);
}

/**
 * \brief Função initStack  do programa
 * 
 * que impreme o array.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void PRINT_ARRAY(struct stack *stack)
{
    for (int i = 0; i <= (*stack).top; i++)
    {
        switch ((*stack).array[i].tipo)
        {
        case T_int:

            printf("%d", (*stack).array[i].data.val_i);
            break;
        case T_long:

            printf("%ld", (*stack).array[i].data.val_l);
            break;
        case T_float:

            printf("%.6g", stack->array[i].data.val_f);
            break;
        case T_double:

            printf("%.6g", stack->array[i].data.val_d);
            break;
        case T_char:

            printf("%c", stack->array[i].data.val_c);
            break;
        case T_string:

            printf("%s", stack->array[i].data.val_s);
            break;
        case T_array:

            PRINT_ARRAY((stack->array[i].data.val_p));
            break;
        case T_block:

            printf("%s", stack->array[i].data.val_b);
            break;
        default:
            printf("FALTA AS STRINGS na print_array!\n");
            break;
        }
    }
}

/**
 * \brief Função initStack  do programa
 * 
 * inicia a stack
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void initStack(struct stack *ptr_STACK, struct var *ptr_vars)
{
    ptr_STACK->top = -1;
    ptr_STACK->vars = ptr_vars;
}

/**
 * \brief Função initStack  do programa
 * 
 * liberta a Stack.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void free_Stack(struct stack *ptr_STACK)
{
    for (int i = 0; i < ptr_STACK->top; i++)
    {
        if (ptr_STACK->array[i].tipo == T_array)
            free_Stack(ptr_STACK->array[i].data.val_p);
    }
}
