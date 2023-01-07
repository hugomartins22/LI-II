/**
 * @file Ficheiro que contém as funções que filtram os elementos 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include "parse.h"
#include "g1.h"
#include "g2.h"
#include "g3.h"
#include "g4.h"
#include "g5.h"
#include "filter.h"
#include <assert.h>

/**
 * \brief Função filter1 do programa
 * 
 * que filtra os elementos da pilha direcionando-os para as operações de acordo com os operadores.
 * 
 * @param token (operador)
 */
int filter1(char *token)
{
    char *maths = "-&|^";
    char *manstack = "_;\\@";

    while (*maths)
    {
        if (*token == *maths)
        {
            return 1;
        }
        maths++;
    }
    while (*manstack)
    {

        if (*token == *manstack)
        {
            return 2;
        }
        manstack++;
    }
    return filter2(token);
}

/**
 * \brief Função2 filter do programa
 * 
 * que filtra os elementos da pilha direcionando-os para as operações de acordo com os operadores.
 * 
 * @param token (operador)
 */
int filter2(char *token)
{
    char *conversion = "ifcs";
    char *logic = "!?e";

    while (*conversion)
    {
        if (*token == *conversion)
        {
            return 3;
        }
        conversion++;
    }
    while (*logic)
    {
        if (*token == *logic)
            return 5;
        logic++;
    }
    return filter3(token);
}

/**
 * \brief Função filter3 do programa
 * 
 * que filtra os elementos da pilha direcionando-os para as operações de acordo com os operadores.
 * 
 * @param token (operador)
 */
int filter3(char *token)
{
    char *io = "ltp";
    char *variables1 = "ABCDEFGHIJKLMOPQRTUVWXYZ";

    while (*io)
    {
        if (*token == *io)
        {
            return 4;
        }
        io++;
    }

    while (*variables1)
    {
        if (*token == *variables1)
        {
            return 6;
        }
        variables1++;
    }
    return filter4(token);
}

/**
 * \brief Função filter4 do programa
 * 
 * que filtra os elementos da pilha direcionando-os para as operações de acordo com os operadores.
 * 
 * @param token (operador)
 */
int filter4(char *token)
{
    char *variables2 = ":";
    char *blocos = "w";

    while (*variables2)
    {
        if (*token == *variables2)
        {
            return 7;
        }
        variables2++;
    }
    while (*blocos)
    {
        if (*token == *blocos)
        {
            return 8;
        }
        blocos++;
    }
    return 0;
}

/**
 * \brief Função poli_plus do programa
 * 
 * que opera sobre os elementos segundo a função de + para esses elementos.
 * 
 * @param token (operador)
 */
void poli_plus(struct stack *ptr_STACK, char *token)
{
    if (isnumber(ptr_STACK))
    {
        struct elemento x = POP(ptr_STACK);
        struct elemento y = POP(ptr_STACK);
        PUSH(ptr_STACK, operador(x, y, token));
    }
    else if (haveonearray(ptr_STACK))
    {
        concatenarray(ptr_STACK);
    }
    else
    {
        concaString(ptr_STACK);
    }
}

/**
 * \brief Função poli_barra do programa
 * 
 * que opera sobre os elementos segundo a função de / para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param token (operador)
 */
void poli_barra(struct stack *ptr_STACK, char *token)
{
    if (isnumber(ptr_STACK))
    {
        struct elemento x = POP(ptr_STACK);
        struct elemento y = POP(ptr_STACK);
        PUSH(ptr_STACK, operador(x, y, token));
    }
    else if (haveonestring(ptr_STACK))
    {
        sub_String(ptr_STACK);
    }
    else
    {
        printf("Deu merda na condição do poli_filter: /\n");
    }
}

/**
 * \brief Função poli_parentesis_left do programa
 * 
 * que opera sobre os elementos segundo a função de ( para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void poli_parentesis_left(struct stack *ptr_STACK)
{
    if (onlyarray(ptr_STACK))
    {
        left_parentesis(ptr_STACK);
    }
    else if (onlystring(ptr_STACK))
    {
        delete_fst_Str(ptr_STACK);
    }
    else
    {
        decrement(ptr_STACK);
    }
}

/**
 * \brief Função poli_parentesis_right do programa
 * 
 * que opera sobre os elementos segundo a função de ) para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void poli_parentesis_right(struct stack *ptr_STACK)
{
    if (onlyarray(ptr_STACK))
    {
        right_parentesis(ptr_STACK);
    }
    else if (onlystring(ptr_STACK))
    {
        delete_snd_Str(ptr_STACK);
    }
    else
    {
        increment(ptr_STACK);
    }
}

/**
 * \brief Função poli_percentagem do programa
 * 
 * que opera sobre os elementos segundo a função de % para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param token (operador)
 */
void poli_percentagem(struct stack *ptr_STACK, char *token)
{
    if (isnumber(ptr_STACK))
    {
        struct elemento x = POP(ptr_STACK);
        struct elemento y = POP(ptr_STACK);
        PUSH(ptr_STACK, operador(x, y, token));
    }
    else if (secondarray(ptr_STACK))
    {

        percentagem_function(ptr_STACK);
    }
    else if (secondstring(ptr_STACK))
    {
        // Aplicar o bloco a todos os charda string
    }
    else
    {
        printf("Deu asneira na condição do poli_filter: PERCENTAGEM \n");
    }
}

/**
 * \brief Função poli_cardinal do programa
 * 
 * que opera sobre os elementos segundo a função de # para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param token (operador)
 */
void poli_cardinal(struct stack *ptr_STACK, char *token)
{
    if (isnumber(ptr_STACK))
    {
        struct elemento x = POP(ptr_STACK);
        struct elemento y = POP(ptr_STACK);
        PUSH(ptr_STACK, operador(x, y, token));
    }
    else if (onlystring(ptr_STACK))
    {
        find_subStr(ptr_STACK);
    }
    else
    {
        printf("Deu asneira na condição do poli_filter: #\n");
    }
}

/**
 * \brief Função poli_til do programa
 * 
 * que opera sobre os elementos segundo a função de ~ para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void poli_til(struct stack *ptr_STACK)
{
    if (onlyblock(ptr_STACK))
    {
        tilfunction(ptr_STACK);
    }
    else if (onlynumber(ptr_STACK))
    {
        complement(ptr_STACK);
    }
    else if (onlyarray(ptr_STACK))
    {
        empurraarray(ptr_STACK);
    }
    else
    {
        printf("Deu asneira na condição do poli_filter: ~\n Falta fazer a condição dos blocos \n");
    }
}

/**
 * \brief Função poli_dollar do programa
 * 
 * que opera sobre os elementos segundo a função de $ para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void poli_dollar(struct stack *ptr_STACK)
{
    if (onlyblock(ptr_STACK))
    {
        dollar_block(ptr_STACK);
    }
    else if (onlynumber(ptr_STACK))
    {
        dollarfunction(ptr_STACK);
    }
    else
    {
        printf("Deu asneira na condição do poli_filter: $\n Falta fazer a condição dos blocos \n");
    }
}

/**
 * \brief Função poli_equal do programa
 * 
 * que opera sobre os elementos segundo a função de $ para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void poli_equal(struct stack *ptr_STACK)
{
    if (stringnumber(ptr_STACK))
    {
        struct elemento x = POP(ptr_STACK);
        val_index_Str(ptr_STACK, x);
    }
    else if (haveonearray(ptr_STACK))
    {
        buscavalindice(ptr_STACK);
    }
    else
    {
        equal(ptr_STACK);
    }
}

/**
 * \brief Função poli_menor do programa
 * 
 * que opera sobre os elementos segundo a função de < para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void poli_menor(struct stack *ptr_STACK)
{
    if (secondarray(ptr_STACK))
    {
        left_elementos(ptr_STACK);
    }
    else if (bothstring(ptr_STACK))
    {
        smaller(ptr_STACK);
    }
    else if (secondstring(ptr_STACK))
    {
        catch_elem_Str(ptr_STACK);
    }
    else
    {
        smaller(ptr_STACK);
    }
}

/**
 * \brief Função poli_maior do programa
 * 
 * que opera sobre os elementos segundo a função de > para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void poli_maior(struct stack *ptr_STACK)
{
    if (secondarray(ptr_STACK))
    {
        right_elementos(ptr_STACK);
    }
    else if (bothstring(ptr_STACK))
    {
        greater(ptr_STACK);
    }
    else if (secondstring(ptr_STACK))
    {
        catch_ultimos_Str(ptr_STACK);
    }
    else
    {
        greater(ptr_STACK);
    }
}

/**
 * \brief Função poli_asterisco do programa
 * 
 * que opera sobre os elementos segundo a função de * para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param token (operador)
 */
void poli_asterisco(struct stack *ptr_STACK, char *token)
{
    if (onlyblock(ptr_STACK))
    {
        fold_function(ptr_STACK);
    }
    else if (isnumber(ptr_STACK))
    {
        struct elemento x = POP(ptr_STACK);
        struct elemento y = POP(ptr_STACK);
        PUSH(ptr_STACK, operador(x, y, token));
    }
    else if (secondarray(ptr_STACK))
    {
        repetearray(ptr_STACK);
    }
    else if (secondstring(ptr_STACK))
    {
        repeteStr(ptr_STACK);
    }
    else
    {
        printf("Deu asneira na condição do poli_filter: *\n");
    }
}

/**
 * \brief Função poli_virgula do programa
 * 
 * que opera sobre os elementos segundo a função de , para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void poli_virgula(struct stack *ptr_STACK)
{
    if (onlyblock(ptr_STACK))
    {
        filter_function(ptr_STACK);
    }
    if (onlynumber(ptr_STACK))
    {
        range_array(ptr_STACK);
    }
    else if (onlyarray(ptr_STACK))
    {
        tamanho_array(ptr_STACK);
    }
    else if (onlystring(ptr_STACK))
    {
        struct elemento x = POP(ptr_STACK);
        tamanho_str(ptr_STACK, x);
    }
    else
    {
        printf("Deu asneira na condição do poli_filter:\n");
    }
}

/**
 * \brief Função poli_filter3 do programa
 * 
 * que filtra as operações cujo símbolo pode operar de formas distintas ( < > * , ).
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param token (operador)
 */
void poli_filter3(struct stack *ptr_STACK, char *token)
{
    switch (*token)
    {
    case '<':
        poli_menor(ptr_STACK);
        break;

    case '>':
        poli_maior(ptr_STACK);
        break;

    case '*':
        poli_asterisco(ptr_STACK, token);
        break;

    case ',':
        poli_virgula(ptr_STACK);
        break;

    default:
        break;
    }
}

/**
 * \brief Função poli_filter2 do programa
 * 
 * que filtra as operações cujo símbolo pode operar de formas distintas ( % # ~ $ = ).
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param token (operador)
 */
void poli_filter2(struct stack *ptr_STACK, char *token)
{
    switch (*token)
    {
    case '%':
        poli_percentagem(ptr_STACK, token);
        break;

    case '#':
        poli_cardinal(ptr_STACK, token);
        break;

    case '~':
        poli_til(ptr_STACK);
        break;

    case '$':
        poli_dollar(ptr_STACK);
        break;

    case '=':
        poli_equal(ptr_STACK);
        break;
    default:
        poli_filter3(ptr_STACK, token);
        break;
    }
}

/**
 * \brief Função poli_filter do programa
 * 
 * que filtra as operações cujo símbolo pode operar de formas distintas ( + / ( ) ).
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param token (operador)
 */
void poli_filter(struct stack *ptr_STACK, char *token)
{
    switch (*token)
    {
    case '+':
        poli_plus(ptr_STACK, token);
        break;

    case '/':
        poli_barra(ptr_STACK, token);
        break;

    case '(':
        poli_parentesis_left(ptr_STACK);
        break;

    case ')':
        poli_parentesis_right(ptr_STACK);
        break;

    default:
        poli_filter2(ptr_STACK, token);
        break;
    }
}

/**
 * \brief Função manhosos_filter do programa
 * 
 * que filtra as operações cujo símbolo pode criar problemas por se assemelharam a variáveis.
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param token (operador)
 */
void manhosos_filter(struct stack *ptr_STACK, char *token)
{
    struct elemento val;
    val.tipo = T_string;

    if (strcmp(token, "S/") == 0)
    {
        div_WhiteS_Str(ptr_STACK);
    }
    else if (strcmp(token, "N/") == 0)
    {
        div_newLines_Str(ptr_STACK);
    }

    else
    {
        manhosos_filter2(ptr_STACK, token, val);
    }
}

/**
 * \brief Função manhosos_filter2 do programa
 * 
 * ajuda na função manhosos_filter .
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void manhosos_filter2(struct stack *ptr_STACK, char *token, struct elemento val)
{
    if (*token == 'N')
    {
        val.data.val_s = token;
        val.data.val_s[0] = '\n';
        val.data.val_s[1] = '\0';
        PUSH(ptr_STACK, val);
    }
    else if (*token == 'S')
    {
        val.data.val_s = token;
        val.data.val_s[0] = ' ';
        val.data.val_s[1] = '\0';
        PUSH(ptr_STACK, val);
    }
    else
        printf("Deus asneira na função manhosos filter2 ");
}

/**
 * \brief Função isnumber do programa
 * 
 * que testa se ambos os elementos no topo da Stack são números.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int isnumber(struct stack *ptr_STACK)
{
    int tipo1 = ptr_STACK->array[ptr_STACK->top].tipo;
    int tipo2 = ptr_STACK->array[ptr_STACK->top - 1].tipo;
    if (tipo1 != T_array && tipo1 != T_string && tipo1 != T_char && tipo2 != T_array && tipo2 != T_string && tipo2 != T_char)
    {
        return 1;
    }
    return 0;
}

/**
 * \brief Função haveonearray do programa
 * 
 * que testa se, pelo menos, um dos dois elementos no topo da Stack é array.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int haveonearray(struct stack *ptr_STACK)
{
    int tipo1 = ptr_STACK->array[ptr_STACK->top].tipo;
    int tipo2 = ptr_STACK->array[ptr_STACK->top - 1].tipo;
    if (tipo1 == T_array || tipo2 == T_array)
    {
        return 1;
    }
    return 0;
}

/**
 * \brief Função haveonestring do programa
 * 
 * que testa se, pelo menos, um dos dois elementos no topo da Stack é String.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int haveonestring(struct stack *ptr_STACK)
{
    int tipo1 = ptr_STACK->array[ptr_STACK->top].tipo;
    int tipo2 = ptr_STACK->array[ptr_STACK->top - 1].tipo;
    if (tipo1 == T_string || tipo2 == T_string)
    {
        return 1;
    }
    return 0;
}

/**
 * \brief Função onlynumber do programa
 * 
 * que testa se o elemento no topo da Stack é um número.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int onlynumber(struct stack *ptr_STACK)
{
    int tipo1 = ptr_STACK->array[ptr_STACK->top].tipo;
    if (tipo1 != T_array && tipo1 != T_string && tipo1 != T_char)
    {
        return 1;
    }
    return 0;
}

/**
 * \brief Função onlyarray do programa
 * 
 * que testa se o elemento no topo da Stack é um array.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int onlyarray(struct stack *ptr_STACK)
{
    int tipo1 = ptr_STACK->array[ptr_STACK->top].tipo;
    if (tipo1 == T_array)
    {
        return 1;
    }
    return 0;
}

/**
 * \brief Função onlystring do programa
 * 
 * que testa se o elemento no topo da Stack é uma String.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int onlystring(struct stack *ptr_STACK)
{
    int tipo1 = ptr_STACK->array[ptr_STACK->top].tipo;
    if (tipo1 == T_string)
    {
        return 1;
    }
    return 0;
}

/**
 * \brief Função secondarray do programa
 * 
 * que testa se o segundo elemento do topo da Stack é um array.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int secondarray(struct stack *ptr_STACK)
{
    int tipo2 = ptr_STACK->array[ptr_STACK->top - 1].tipo;
    if (tipo2 == T_array)
    {
        return 1;
    }
    return 0;
}

/**
 * \brief Função secondstring do programa
 * 
 * que testa se o segundo elemento do topo da Stack é uma String.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int secondstring(struct stack *ptr_STACK)
{
    int tipo2 = ptr_STACK->array[ptr_STACK->top - 1].tipo;
    if (tipo2 == T_string)
    {
        return 1;
    }
    return 0;
}

/**
 * \brief Função bothstring do programa
 * 
 * que testa se ambos os elementos no topo da Stack são Strings.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int bothstring(struct stack *ptr_STACK)
{
    int tipo1 = ptr_STACK->array[ptr_STACK->top].tipo;
    int tipo2 = ptr_STACK->array[ptr_STACK->top - 1].tipo;
    if (tipo2 == T_string && tipo1 == T_string)
    {
        return 1;
    }
    return 0;
}

/**
 * \brief Função stringnumber do programa
 * 
 * que testa se o primeiro e segundo elementos no topo da Stack
 * são uma String e um número, respetivamente.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int stringnumber(struct stack *ptr_STACK)
{
    int tipo1 = ptr_STACK->array[ptr_STACK->top].tipo;
    int tipo2 = ptr_STACK->array[ptr_STACK->top - 1].tipo;
    if (tipo1 != T_array && tipo1 != T_string && tipo1 != T_char && tipo2 == T_string)
    {
        return 1;
    }
    return 0;
}

/**
 * \brief Função equal_type do programa
 * 
 * que testa se os elementos no topo da Stack são do mesmo tipo.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int equal_type(struct stack *ptr_STACK)
{
    int tipo1 = ptr_STACK->array[ptr_STACK->top].tipo;
    int tipo2 = ptr_STACK->array[ptr_STACK->top - 1].tipo;
    if (tipo1 == tipo2)
    {
        return 1;
    }
    return 0;
}

/**
 * \brief Função onlyblock do programa
 * 
 * que testa se o elemento do topo da Stack é um bloco.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int onlyblock(struct stack *ptr_STACK)
{
    int tipo1 = ptr_STACK->array[ptr_STACK->top].tipo;
    if (tipo1 == T_block)
    {
        return 1;
    }
    return 0;
}