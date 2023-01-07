/**
 * @file Ficheiro que contém as função parse
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
 * \brief Função check_type do programa
 * 
 * recebe um token, um apontador para o resto_num da função e outro apontador para o tipo desse token.
 * Irá verificar o tipo correspondente ao token e atualizar a stack com o elemento correspondente.
 *
 * @param resto_num
 * @param token
 * @param val_tipo 
 */
void check_type(char **resto_num, char **token, int *val_tipo)
{
    char *p = strstr(*token, ".");
    if (p)
    {
        strtod(*token, resto_num);
        *val_tipo = T_double;
    }
    else
    {
        strtol(*token, resto_num, 10);
        *val_tipo = T_long;
    }
}

/**
 * \brief Função convertToDouble
 * 
 * é uma função auxiliar que recebe um elemento e converte-o para Double
 * 
 * @param x 
 * 
 * @returns double, representado pela variável ret.
 */
double convertToDouble(struct elemento x)
{
    double ret;

    ret = 0.0;
    switch (x.tipo)
    {
    case T_int:
        ret = x.data.val_i * 1.0;
        break;
    case T_long:
        ret = x.data.val_l * 1.0;
        break;
    case T_float:
        ret = x.data.val_f * 1.0;
        break;
    case T_double:
        ret = x.data.val_d * 1.0;
        break;
    case T_char:
        ret = (float)x.data.val_c * 1.0;
        break;
    default:
        printf("Deu asneira na função converttoDouble");
        break;
    }
    return ret;
}

/**
 * \brief Função put_token do programa
 *  
 * recebe um token, um apontador para o resto_num da função e outro apontador para a stack.
 * Irá colocar o token respetivo a um elemento na stack.
 *
 * @param resto_num
 * @param token
 * @param val_tipo 
 */
void put_token(struct stack *ptr_STACK, int val_tipo, char *token)
{
    struct elemento val;
    switch (val_tipo)
    {
    case T_int:
        val.tipo = T_int;
        val.data.val_i = atoi(token);
        PUSH(ptr_STACK, val);
        break;
    case T_float:
        val.tipo = T_float;
        val.data.val_f = atof(token);
        PUSH(ptr_STACK, val);
        break;
    case T_char:
        val.tipo = T_char;
        val.data.val_c = atoi(token);
        PUSH(ptr_STACK, val);
        break;
    default:
        put_token2(val, token, ptr_STACK, val_tipo);
        break;
    }
}

/**
 * \brief Função put_token2 do programa
 * 
 * auxiliar à função put_token 
 * 
 * @param ptr_STACK (apontador para a stack)
 * @param token (operando)
 * @param val (struct elemento)
 * @param val_tipo (inteiro)
 */
void put_token2(struct elemento val, char *token, struct stack *ptr_STACK, int val_tipo)
{
    switch (val_tipo)
    {
    case T_double:
        val.tipo = T_double;
        val.data.val_d = atof(token);
        break;
    case T_long:
        val.tipo = T_long;
        val.data.val_l = atol(token);
        break;
    case T_string:
        val.tipo = T_string;
        val.data.val_i = atoi(token);
        break;
    case T_array:
        val.tipo = T_array;
        val.data.val_i = atoi(token);
        break;
    default:
        printf("deus asneira na put_token 2\n");
        break;
    }
    PUSH(ptr_STACK, val);
}

/**
 * \brief Função go_filter do programa
 * 
 * verifica o nosso token e seleciona a função auxiliar correspondente à operação
 * desejada.
 *
 * @param token
 * @param val_tipo 
 */
void go_filter(struct stack *ptr_STACK, char *token)
{
    switch (filter1(token))
    {
    case 0:
        poli_filter(ptr_STACK, token);
        break;
    case 1:
        maths(ptr_STACK, token);
        break;
    case 2:
        manstack(ptr_STACK, token);
        break;
    case 3:
        conversion(ptr_STACK, token);
        break;
    case 4:
        inoutput(ptr_STACK, token);
        break;
    case 5:
        logic(ptr_STACK, token);
        break;
    case 6:
        variables1(ptr_STACK, token);
        break;
    case 7:
        variables2(ptr_STACK, token);
        break;
    default:
        printf("Deu bagalho no go_filter!\n");
        break;
    }
}

/**
 * \brief Função go_filter_array do programa.
 * 
 * Iremos verificar se esse token é o sinal +.
 * Se essa condição se verificar vamos chamar a função check_somma_array 
 * (Verifica as restrições para as ações com somas ou concatenações de arrays).
 * Se não se verificar, chamamos a função check_all_array
 * (Verifica as restrições para as outras operações com arrays). 
 * 
 * @param ptr_STACK Apontador para a stack.
 * @param token Token atual.
 */
void go_filter_array(struct stack *ptr_STACK, char *token)
{
    if (existe_array(ptr_STACK))
    {
        aux_filter_Array1(ptr_STACK, token);
    }
    else if (existe_string(ptr_STACK))
    {
        switch (*token)
        {
        case '+':
            concaString(ptr_STACK);
            break;
        case '*':
            repeteStr(ptr_STACK);
            break;
        case ',':
            tamanho_str(ptr_STACK, POP(ptr_STACK));
            break;
        case '=':
            val_index_Str(ptr_STACK, POP(ptr_STACK));
            break;
        }
    }
    else
    {
        go_filter(ptr_STACK, token);
    }
}

/**
 * \brief Função aux_filter_array1 do programa
 * 
 * contém alguns tokens e direciona para as respetivas operações
 * 
 * @param ptr_STACK (apontador para a stack)
 * @param token (operando)
 */
void aux_filter_Array1(struct stack *ptr_STACK, char *token)
{
    switch (*token)
    {
    case '+':
        concatenarray(ptr_STACK);
        break;
    case '~':
        empurraarray(ptr_STACK);
        break;
    case '*':
        repetearray(ptr_STACK);
        break;
    case ',':
        tamanho_array(ptr_STACK);
        break;
    case '=':;
        buscavalindice(ptr_STACK);
        break;
    default:
        aux_filter_array2(ptr_STACK, token);
        break;
    }
}

/**
 * \brief Função aux_filter_array2 do programa
 * 
 * contém alguns tokens e direciona para as respetivas operações
 * 
 * @param ptr_STACK (apontador para a stack)
 * @param token (operando)
 */
void aux_filter_array2(struct stack *ptr_STACK, char *token)
{

    switch (*token)
    {
    case '<':
        left_elementos(ptr_STACK);
        break;
    case '>':
        right_elementos(ptr_STACK);
        break;
    case '(':
        left_parentesis(ptr_STACK);
        break;
    case ')':
        right_parentesis(ptr_STACK);
        break;
    default:
        printf("Deu asneira na função aux_filter_array2\n");
        break;
    }
}

/**
 * \brief Função existe_arary do programa
 * 
 * Retorna 1 se algum dos  2 elementos que esta no topo da stack for array
 * 
 * @param ptr_STACK (apontador para a stack)
 * 
 * @returns um inteiro
 */
int existe_array(struct stack *ptr_STACK)
{
    if (ptr_STACK->array[ptr_STACK->top].tipo == T_array || ptr_STACK->array[ptr_STACK->top - 1].tipo == T_array)
        return 1;
    return 0;
}

/**
 * \brief Função existe_string do programa
 * 
 * Retorna 1 se algum dos  2 elementos que esta no topo da stack for string
 * 
 * @param ptr_STACK (apontador para a stack)
 */
int existe_string(struct stack *ptr_STACK)
{
    if (ptr_STACK->array[ptr_STACK->top].tipo == T_string || ptr_STACK->array[ptr_STACK->top - 1].tipo == T_string)
        return 1;
    return 0;
}

/**
 * \brief Função parse do programa
 * 
 * Inicia-se um apontador de caracteres (delimitadores).
 * 
 * Posteriormente, através de um ciclo, inicia-se uma nova variável (um apontador de carateres (token)),
 * com a condição de paragem quando esse token for NULL. 
 * A cada iteração o tokeS
 * @param line (Linha a ser tratada)
 */
void parse(char *line)
{
    struct var *vars = malloc(26 * sizeof(struct var));
    struct var *ptr_vars = vars;
    initVars(ptr_vars);

    struct stack STACK;
    struct stack *ptr_STACK = &STACK;
    initStack(ptr_STACK, ptr_vars);
    char *token;
    char *resto;

    char *delimitadores = " \t \n";
    for (token = get_token(delimitadores, cleanLim(line), &resto); strcmp(token, "") != 0; token = get_token(delimitadores, resto, &resto))
    {

        char *resto_num = "abc";
        int val_tipo;
        check_type(&resto_num, &token, &val_tipo);

        if (strlen(resto_num) == 0)
            put_token(ptr_STACK, val_tipo, token);
        else if (*token == '[')
        {
            pinta_array(token);
            struct elemento val;
            val.tipo = T_array;
            struct stack *new_stack = malloc(sizeof(struct stack));
            initStack(new_stack, ptr_STACK->vars);
            val.data.val_p = new_stack;
            put_array(ptr_STACK, token, &val);
        }
        else if (*token == '{')
        {
            struct elemento blocko;
            blocko.tipo = T_block;
            blocko.data.val_b = token;
            PUSH(ptr_STACK, blocko);
        }
        else if (*token == '"')
        {
            criaStr(ptr_STACK, token);
        }
        else if (*token == 'S' || *token == 'N')
        {
            manhosos_filter(ptr_STACK, token);
        }
        else
        {
            go_filter(ptr_STACK, token);
        }
    }
    PRINT_STACK(ptr_STACK);
}

/**
 * \brief Função initVars do programa
 * 
 * prepara um array para definir as variáveis e os seus respetivos valores.
 * 
 * @param ptr_STACK 
 */
void initVars(struct var *ptr_vars)
{
    struct elemento val;
    val.tipo = T_int;
    struct var var_tmp;

    for (int i = 0; i < 6; i++)
    {
        val.data.val_i = 10 + i;
        var_tmp.index = i;
        var_tmp.elemento = val;
        *(ptr_vars + i) = var_tmp;
    }
    val.data.val_i = 0;
    var_tmp.index = 23;
    var_tmp.elemento = val;
    *(ptr_vars + 23) = var_tmp;
    var_tmp.elemento = val;
    val.data.val_i = 1;
    var_tmp.index = 24;
    var_tmp.elemento = val;
    *(ptr_vars + 24) = var_tmp;
    var_tmp.elemento = val;
    val.data.val_i = 2;
    var_tmp.index = 25;
    var_tmp.elemento = val;
    *(ptr_vars + 25) = var_tmp;
    var_tmp.elemento = val;
}

/**
 * \brief Função put_array do programa.
 * 
 * Responsável por colocar o array na STACK.
 * 
 * @param ptr_STACK Apontador para a stack.
 * @param token Token atual.
 */
void put_array(struct stack *ptr_STACK, char *token, struct elemento *ptr_elem)
{
    parse_array(token, ptr_elem->data.val_p);
    PUSH(ptr_STACK, *ptr_elem);
}

/**
 * \brief Função pinta_array do programa.
 * 
 * Recebe um apontador para a STACK e um token.
 * Iremos verificar se o topo da stack é array.
 * Se essa condição se verificar vamos chamar a função manarray. 
 * (Aplica as operações com arrays).
 * Se não se verificar, chamamos a função go_filter
 * (Aplica as operações dos guiões 1/2/3). 
 * 
 * @param pointer Apontador para a stack.
 * @param line Token atual.
 */
void pinta_array(char *line)
{

    char copi[10000];
    int j = 0, i = 2;
    while (line[i + 2] != '\0')
    {
        copi[j] = line[i];
        i++;
        j++;
    }
    copi[j] = '\0';
    strcpy(line, copi);
}

/**
 * \brief Função check_array do programa.
 * 
 * Recebe um apontador para a Stack e um token.
 * Inicializa um apontador para uma string 
 * para testar se o token pertence a algum desses símbolos, 
 * se pertence retorna 1, caso contrário, 0.
 * 
 * @param ptr_STACK Apontador para a Stack
 * @param token Token atual
 * 
 * @return Um inteiro, pode ser 0 ou 1.
 */
int check_array(char *token)
{
    char *arrays = "+~<>()*=,#/N";
    while (*arrays)
    {
        if (*token == *arrays)
        {
            return 1;
        }
        arrays++;
    }
    return 0;
}

/**
 * \brief Função isDelim do programa.
 * 
 * Recebe o caractere c e incializa uma variável do tipo inteiro a 0.
 * Percorrendo os delimitadores, se c pertencer a essa lista devolve 1,
 * caso contrário, 0.
 * 
 * @param c Caracter c
 * @param delim Apontador para delimitadores
 * 
 * @return bRet que corresponde a 0 ou 1
 */
int isDelim(char c, char *delim)
{
    int bRet = 0;

    for (int i = 0; delim[i]; i++)
    {
        if (delim[i] == c)
            bRet = 1;
    }
    return bRet;
}

/**
 * \brief Função isLim do programa.
 * 
 * testa se o token é um delimitador.
 * 
 * @param token
 * 
 * @return 0 ou 1
 */
int isLim(char token)
{
    if (token == ' ' || token == '\n' || token == '\t')
    {
        return 1;
    }
    else
        return 0;
}

/**
 * \brief Função cleanLim do programa.
 * 
 * remove os delimitadores da linha recebida.
 * 
 * @param line
 * 
 * @return line
 */
char *cleanLim(char line[])
{
    int i, j;
    int found_string = 0;
    for (i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == '"')
        {
            if (found_string == 0)
            {
                found_string = 1;
            }
            else
            {
                found_string = 0;
            }
        }
        if (isLim(line[i]) && isLim(line[i + 1]) && found_string == 0)
        {
            for (j = i; line[j] != '\0'; j++)
            {
                line[j] = line[j + 1];
            }
            line[j] = '\0';
            i--;
        }
    }
    return line;
}

/**
 * \brief Função get_token do programa.
 * 
 * 
 * @param delim Apontador para delimitadores
 * @param line Apontador para a linha que será lida
 * @param rest
 * 
 * @return bRet que corresponde a 0 ou 1
 */
char *get_token(char *delim, char *line, char **rest)
{

    int i, bTratado = 0;

    for (i = 0; line[i] && isDelim(line[i], delim) == 0 && bTratado == 0; i++)
    {
        if (line[i] == '[')
        {
            int nParentesis = 1;
            int j;

            for (j = 1; nParentesis > 0 && line[i + j]; j++)
            {
                if (line[i + j] == ']')
                    nParentesis--;
                if (line[i + j] == '[')
                    nParentesis++;
            }
            if (nParentesis > 0)
            {
                printf("Falta ]");
            }
            else
            {
                line[i + j] = 0;
                *rest = line + i + j + 1;
                bTratado = 1;
            }
        }
        else if (line[i] == '{')
        {
            int nChaves = 1;
            int j;

            for (j = 1; nChaves > 0 && line[i + j]; j++)
            {
                if (line[i + j] == '}')
                    nChaves--;
                if (line[i + j] == '{')
                    nChaves++;
            }
            if (nChaves > 0)
            {
                printf("Falta }");
            }
            else
            {
                line[i + j] = 0;
                *rest = line + i + j + 1;
                bTratado = 1;
            }
        }
        else if (line[i] == '"')
        {
            int nAspas = 1;
            int j;

            for (j = 1; nAspas > 0 && line[i + j]; j++)
            {
                if (line[i + j] == '"')
                    nAspas--;
            }
            if (nAspas > 0)
            {
                printf("Falta Fechar Aspas");
            }
            else
            {
                line[i + j] = 0;
                *rest = line + i + j + 1;
                bTratado = 1;
            }
        }
    }

    if (bTratado == 0)
    {
        if (isDelim(line[i], delim))
        {
            line[i] = 0;
            *rest = line + i + 1;
        }
        else
        {
            *rest = line + i;
        }
    }
    return line;
}
