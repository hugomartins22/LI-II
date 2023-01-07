/**
 * @file Ficheiro que contém as funções relativas ao guião 4
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
#include "filter.h"
#include <assert.h>

/**
 * \brief Função concatenarray  do programa
 * 
 * que faz POP de dois elementos, e se pelo menos um deles for array ,concatena-os.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void concatenarray(struct stack *ptr_STACK)
{
    struct elemento x = POP(ptr_STACK);
    struct elemento y = POP(ptr_STACK);
    if ((x.tipo == T_array) && (y.tipo == T_array))
    {

        for (int i = 0; i <= x.data.val_p->top; i++)
        {
            PUSH(y.data.val_p, x.data.val_p->array[i]);
        }
        PUSH(ptr_STACK, y);
    }
    else
        concatenarray2(x, y, ptr_STACK);
}

/**
 * \brief Função concatenarray2 do programa
 * 
 * ajuda nos tipo na função concatenarray
 * 
 * @param x (Struct elemento)
 */
void concatenarray2(struct elemento x, struct elemento y, struct stack *ptr_STACK)
{
    if ((x.tipo != T_array) && (y.tipo == T_array))
    {
        PUSH(y.data.val_p, x);
        PUSH(ptr_STACK, y);
    }
    else if ((x.tipo == T_array) && (y.tipo != T_array))
    {
        struct elemento array;
        array.tipo = T_array;
        struct stack *new_stack = malloc(sizeof(struct stack));
        initStack(new_stack, ptr_STACK->vars);
        array.data.val_p = new_stack;
        PUSH(array.data.val_p, y);
        for (int i = 0; i <= x.data.val_p->top; i++)
        {
            PUSH(array.data.val_p, x.data.val_p->array[i]);
        }
        PUSH(ptr_STACK, array);
    }
}

/**
 * \brief Função empurraarray  do programa
 * 
 * que faz PUSH dos elementos de um array na Stack.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void empurraarray(struct stack *ptr_STACK)
{
    struct elemento x = POP(ptr_STACK);
    x.tipo = T_array;
    for (int i = 0; i <= x.data.val_p->top; i++)
    {
        PUSH(ptr_STACK, x.data.val_p->array[i]);
    }
}

/**
 * \brief Função repetearray  do programa
 * 
 * que repete n-vezes um array e faz PUSH para a stack de um array que contem as n repetições pedidas.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void repetearray(struct stack *ptr_STACK)
{
    int n = 0;
    struct elemento x = POP(ptr_STACK);
    struct elemento y = POP(ptr_STACK);

    struct elemento val;
    val.tipo = T_array;
    struct stack *new_stack = malloc(sizeof(struct stack));
    initStack(new_stack, ptr_STACK->vars);
    val.data.val_p = new_stack;

    if (x.tipo == T_int)
    {
        n = x.data.val_i;
    }

    else if (x.tipo == T_long)
    {
        n = x.data.val_l;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= y.data.val_p->top; j++)
        {
            PUSH(new_stack, y.data.val_p->array[j]);
        }
    }
    PUSH(ptr_STACK, val);
}

/**
 * \brief Função parse_array  do programa
 * 
 * que lê uma linha e trata diferentes possibilidades, ter um array, ter uma string
 * ou apenas efetuar outras operações, caso não enocntre arrays nem strings.
 * 
 * @param line (uma linha que será tratada)
 * @param ptr_STACK (apontador para a stack)
 */
void parse_array(char *line, struct stack *ptr_STACK)
{

    char *token;
    char *resto;
    int tamanho = 0;

    int t = strlen(line);

    char *delimitadores = " \t \n";
    for (token = get_token(delimitadores, cleanLim(line), &resto); strcmp(token, "") != 0 && tamanho + 1 < t; token = get_token(delimitadores, resto, &resto))
    {

        tamanho += strlen(token);

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
}

/**
 * \brief Função criaStr  do programa
 * 
 * que criará uma String.
 * 
 * @param ptr_STACK (apontador para a stack)
 * @param token (operando)
 */
void criaStr(struct stack *ptr_STACK, char *token)
{
    int i = 0;
    int size;

    size = strlen(token);

    struct elemento x;
    x.tipo = T_string;
    x.data.val_s = malloc(size * sizeof(char));

    while (token[i + 2] != '\0')
    {
        x.data.val_s[i] = token[i + 1];
        i++;
    }
    x.data.val_s[i] = '\0';

    PUSH(ptr_STACK, x);
}

/**
 * \brief Função tamanho_array  do programa
 * 
 * que devolve a quantidade de elementos (alfanuméricos) contidos num array.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void tamanho_array(struct stack *ptr_STACK)
{
    struct elemento x = POP(ptr_STACK);
    int i = x.data.val_p->top + 1;
    struct elemento n;
    n.tipo = T_int;
    n.data.val_i = i;
    PUSH(ptr_STACK, n);
}

/**
 * \brief Função range_array  do programa
 * 
 * que faz POP de um elemento e se esse é um número n devolve um array com 
 * os números inteiros no intervalo [0...(n-1)]
 * 
 * @param ptr_STACK  (apontador para a stack)
 */
void range_array(struct stack *ptr_STACK)
{
    struct elemento x = POP(ptr_STACK);
    ajudatipo(x);

    struct elemento y;
    y.tipo = T_int;

    struct elemento val;
    val.tipo = T_array;
    struct stack *new_stack = malloc(sizeof(struct stack));
    initStack(new_stack, ptr_STACK->vars);
    val.data.val_p = new_stack;

    for (int i = 0; i < x.data.val_i; i++)
    {
        y.data.val_i = i;
        PUSH(new_stack, y);
    }
    PUSH(ptr_STACK, val);
}

/**
 * \brief Função ajudatipo do programa
 * 
 * ajuda nos tipo na função range_array
 * 
 * @param x (Struct elemento)
 */
void ajudatipo(struct elemento x)
{
    if (x.tipo == T_long)
    {
        x.tipo = T_int;
        x.data.val_i = (int)x.data.val_l;
    }
    else if (x.tipo == T_int)
    {
    }
    else if (x.tipo == T_float)
    {
        x.tipo = T_int;
        x.data.val_i = (int)x.data.val_f;
    }
    else if (x.tipo == T_double)
    {
        x.tipo = T_int;
        x.data.val_i = (int)x.data.val_d;
    }
    else
        printf("Deu erro na função range\n");
}

/**
 * \brief Função buscavalindice  do programa
 * 
 * que vai ao array buscar um elemento no índice i que foi pedido.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void buscavalindice(struct stack *ptr_STACK)
{
    struct elemento x = POP(ptr_STACK);
    if (x.tipo == T_long)
    {
        x.tipo = T_int;
        x.data.val_i = (int)x.data.val_l;
    }
    else if (x.tipo == T_int)
    {
    }
    else if (x.tipo == T_float)
    {
        x.tipo = T_int;
        x.data.val_i = (int)x.data.val_f;
    }
    else if (x.tipo == T_double)
    {
        x.tipo = T_int;
        x.data.val_i = (int)x.data.val_d;
    }
    else
        printf("Deu erro na função buscavalindice\n");

    struct elemento y = POP(ptr_STACK);

    int len = x.data.val_i;

    PUSH(ptr_STACK, y.data.val_p->array[len]);
}

/**
 * \brief Função left_elementos do programa
 * 
 * que faz POP de um valor n  e de um array e vai ao array remover n-elementos do início.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void left_elementos(struct stack *ptr_STACK)
{
    struct elemento x = POP(ptr_STACK);
    struct elemento y = POP(ptr_STACK);

    help_left_elementos(x);
    struct elemento val;
    val.tipo = T_array;
    struct stack *new_stack = malloc(sizeof(struct stack));
    initStack(new_stack, ptr_STACK->vars);
    val.data.val_p = new_stack;
    for (int i = 0; i < x.data.val_i; i++)
    {
        PUSH(new_stack, y.data.val_p->array[i]);
    }
    PUSH(ptr_STACK, val);
}

/**
 * \brief Função help_left_elementos do programa
 * 
 * ajuda nos tipo na função left_elementos 
 * 
 * @param x (Struct elemento)
 */
void help_left_elementos(struct elemento x)
{
    if (x.tipo == T_long)
    {
        x.tipo = T_int;
        x.data.val_i = (int)x.data.val_l;
    }
    else if (x.tipo == T_float)
    {
        x.tipo = T_int;
        x.data.val_i = (int)x.data.val_f;
    }
    else if (x.tipo == T_double)
    {
        x.tipo = T_int;
        x.data.val_i = (int)x.data.val_d;
    }
    else
        printf("Deu erro na função left_elementos\n");
}
/**
 * \brief Função right_elementos do programa
 * 
 * que faz POP de um valor n e de um array e vai ao array remover n-elementos a partir do fim.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void right_elementos(struct stack *ptr_STACK)
{
    struct elemento x = POP(ptr_STACK);
    struct elemento y = POP(ptr_STACK);
    ajuda_elementos(x);

    struct elemento val;
    val.tipo = T_array;
    struct stack *new_stack = malloc(sizeof(struct stack));
    initStack(new_stack, ptr_STACK->vars);
    val.data.val_p = new_stack;

    for (int i = y.data.val_p->top - x.data.val_i + 1; i <= y.data.val_p->top; i++)
    {
        PUSH(new_stack, y.data.val_p->array[i]);
    }
    PUSH(ptr_STACK, val);
}

/**
 * \brief Função ajuda_elementos do programa
 * 
 * ajuda nos tipo na função right elementos
 * 
 * @param x (Struct elemento)
 */
void ajuda_elementos(struct elemento x)
{
    if (x.tipo == T_long)
    {
        x.tipo = T_int;
        x.data.val_i = (int)x.data.val_l;
    }
    else if (x.tipo == T_int)
    {
    }
    else if (x.tipo == T_float)
    {
        x.tipo = T_int;
        x.data.val_i = (int)x.data.val_f;
    }
    else if (x.tipo == T_double)
    {
        x.tipo = T_int;
        x.data.val_i = (int)x.data.val_d;
    }
    else
    {
        printf("Deu erro na função right elementos\n");
    }
}
/**
 * \brief Função right_parentesis do programa
 * 
 * que retira o último elemento de um array e coloca na Stack depois do array.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void right_parentesis(struct stack *ptr_STACK)
{
    struct elemento x = POP(ptr_STACK);
    struct elemento new = POP(x.data.val_p);
    PUSH(ptr_STACK, x);
    PUSH(ptr_STACK, new);
}

/**
 * \brief Função left_parentesis do programa
 * 
 * que retira o primeiro elemento de um array e coloca na Stack depois do array.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void left_parentesis(struct stack *ptr_STACK)
{
    struct elemento x = POP(ptr_STACK);
    struct elemento new = x.data.val_p->array[0];
    for (int i = 0; i < x.data.val_p->top; i++)
    {
        x.data.val_p->array[i] = x.data.val_p->array[i + 1];
    }
    x.data.val_p->top--;
    PUSH(ptr_STACK, x);
    PUSH(ptr_STACK, new);
}

/**
 * \brief Função manarray do programa
 * 
 * que recebe um token e efetua uma operação de acordo com o objetivo desse token.
 * 
 * @param ptr_STACK  (apontador para a stack )
 * @param token (operando)
 */
void manarray(struct stack *ptr_STACK, char *token)
{
    switch (*token)
    {
    case '~':
        empurraarray(ptr_STACK);
        break;
    case '*':
        repetearray(ptr_STACK);
        break;
    case ',':
        tamanho_array(ptr_STACK);
        break;
    case '=':
        buscavalindice(ptr_STACK);
        break;
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
        call_operator(ptr_STACK, token);
        break;
    }
}

/**
 * \brief Função mystrcat do programa
 * 
 * que recebe dois caracteres e concatena-os.
 * 
 * @param s1 (caractere)
 * @param s2 (caractere)
 * @param ptr_STACK (apontador para a Stack)
 */
void mystrcat(struct elemento s1, struct elemento s2, struct stack *ptr_STACK)
{

    char test1 = s1.data.val_c;
    char test2 = s2.data.val_c;
    s1.tipo = T_string;
    s1.data.val_s = malloc(100 * sizeof(char));

    s1.data.val_s[0] = test1;
    s1.data.val_s[1] = test2;
    s1.data.val_s[2] = '\0';

    PUSH(ptr_STACK, s1);
}

/**
 * \brief Função mystrcat2 do programa
 * 
 * que recebe um caractere e uma string e concatena-os numa só string.
 * 
 * @param s1 (catactere)
 * @param s2 (string)
 * @param ptr_STACK (apontador para a Stack)
 */
void mystrcat2(struct elemento s1, struct elemento s2, struct stack *ptr_STACK)
{
    char test1 = s1.data.val_c;
    s1.tipo = T_string;
    s1.data.val_s = malloc(100 * sizeof(char));
    s1.data.val_s[0] = test1;

    mystrcat4(s1.data.val_s, s2.data.val_s);

    PUSH(ptr_STACK, s1);
}

/**
 * \brief Função mystrcat3 do programa
 * 
 * que recebe uma string e um caractere e concatena-os numa só string.
 * 
 * @param s1 (string)
 * @param s2 (caractere)
 * @param ptr_STACK (apontador para a Stack)
 */
void mystrcat3(struct elemento s1, struct elemento s2, struct stack *ptr_STACK)
{
    char test1 = s2.data.val_c;
    s2.tipo = T_string;
    s2.data.val_s = malloc(100 * sizeof(char));
    s2.data.val_s[0] = test1;

    mystrcat4(s1.data.val_s, s2.data.val_s);

    PUSH(ptr_STACK, s1);
}

/**
 * \brief Função mystrcat4 do programa
 * 
 * que recebe duas strings e concatena-as.
 * 
 * @param s1 (string)
 * @param s2 (string)
 */
void mystrcat4(char s1[], char s2[])
{
    int i, j;
    for (i = 0; s1[i] != '\0'; i++)
        ;
    for (j = 0; s2[j] != '\0'; j++)
    {
        s1[i] = s2[j];
        i++;
    }
    s1[i] = '\0';
}

/**
 * \brief Função concaString do programa
 * 
 * que tem por objetivo concatenar duas strings ou uma string e uma caractere.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void concaString(struct stack *ptr_STACK)
{
    struct elemento x = POP(ptr_STACK);
    struct elemento y = POP(ptr_STACK);

    if (y.tipo == T_char && x.tipo == T_char)
    {
        mystrcat(y, x, ptr_STACK);
    }

    else if (y.tipo == T_char && x.tipo == T_string)
    {
        mystrcat2(y, x, ptr_STACK);
    }

    else if (y.tipo == T_string && x.tipo == T_char)
    {
        mystrcat3(y, x, ptr_STACK);
    }

    else if (y.tipo == T_string && x.tipo == T_string)
    {
        mystrcat4(y.data.val_s, x.data.val_s);
        PUSH(ptr_STACK, y);
    }
}

/**
 * \brief Função repeteStr  do programa
 * 
 *  faz PUSH de uma string resultado que contem as n repetições da string inicial.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void repeteStr(struct stack *ptr_STACK)
{
    int i, j;

    struct elemento x = POP(ptr_STACK);
    struct elemento y = POP(ptr_STACK);
    struct elemento copy;
    copy.tipo = T_string;
    copy.data.val_s = malloc(10000 * sizeof(char));
    int t = x.data.val_i * strlen(y.data.val_s);

    for (i = 0, j = 0; i < t; i++, j++)
    {
        if (j == 3)
            j = 0;
        copy.data.val_s[i] = y.data.val_s[j];
    }

    PUSH(ptr_STACK, copy);
}

/**
 * \brief Função tamanho_str  do programa
 * 
 * que devolve a quantidade de elementos contidos numa String.
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param x (string)
 */
void tamanho_str(struct stack *ptr_STACK, struct elemento x)
{
    struct elemento z;
    z.tipo = T_int;
    z.data.val_i = strlen(x.data.val_s);

    PUSH(ptr_STACK, z);
}

/**
 * \brief Função val_index_Str  do programa
 * 
 * que vai buscar à String um elemento no índice i que lhe damos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param x (indice)
 */
void val_index_Str(struct stack *ptr_STACK, struct elemento x)
{
    struct elemento y = POP(ptr_STACK);
    struct elemento z;
    z.tipo = T_char;
    z.data.val_c = y.data.val_s[x.data.val_i];

    PUSH(ptr_STACK, z);
}

/**
 * \brief Função catch_elem_Str do programa
 * 
 * que faz POP de um valor n e de uma string e vai à String remover n-elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void catch_elem_Str(struct stack *ptr_STACK)
{
    struct elemento x = POP(ptr_STACK);
    struct elemento y = POP(ptr_STACK);

    if (x.tipo == T_int)
    {
        y.data.val_s[x.data.val_i] = '\0';
    }
    else if (x.tipo == T_long)
    {
        y.data.val_s[x.data.val_l] = '\0';
    }
    else
        printf("Deu bagulho na função catch_elem_Str\n");
    PUSH(ptr_STACK, y);
}

/**
 * \brief Função catch_ultimos_Str do programa
 * 
 * que faz POP de um valor n e de uma string e vai à String remover n-elementos a partir do fim.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void catch_ultimos_Str(struct stack *ptr_STACK)
{
    int i = 0;
    long j = 0;
    struct elemento x = POP(ptr_STACK);
    struct elemento y = POP(ptr_STACK);

    int len = strlen(y.data.val_s);

    if (x.tipo == T_int)
    {
        while (y.data.val_s[len - x.data.val_i + i])
        {
            y.data.val_s[i] = y.data.val_s[len - x.data.val_i + i];
            i++;
        }
        y.data.val_s[i] = '\0';
    }
    else if (x.tipo == T_long)
    {
        while (y.data.val_s[len - x.data.val_l + j] != '\0')
        {
            y.data.val_s[j] = y.data.val_s[len - x.data.val_l + j];
            j++;
        }
        y.data.val_s[j] = '\0';
    }
    else
        printf("Deu bagulho na função catch_elem_Str\n");

    PUSH(ptr_STACK, y);
}

/**
 * \brief Função delete_fst_Str do programa
 * 
 * que retira o primeiro elemento de uma String e coloca na Stack depois do String.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void delete_fst_Str(struct stack *ptr_STACK)
{

    int i;
    struct elemento y = POP(ptr_STACK);
    int t = strlen(y.data.val_s);
    struct elemento w;
    w.tipo = T_char;
    w.data.val_c = y.data.val_s[0];

    for (i = 0; i < t; i++)
    {
        y.data.val_s[i] = y.data.val_s[i + 1];
    }
    PUSH(ptr_STACK, y);
    PUSH(ptr_STACK, w);
}

/**
 * \brief Função delete_snd_Str do programa
 * 
 * que retira o último elemento de uma String e coloca na Stack depois da String.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void delete_snd_Str(struct stack *ptr_STACK)
{
    struct elemento y = POP(ptr_STACK);
    int t = strlen(y.data.val_s);
    struct elemento w;
    w.tipo = T_char;

    w.data.val_c = y.data.val_s[t - 1];
    y.data.val_s[t - 1] = '\0';

    PUSH(ptr_STACK, y);
    PUSH(ptr_STACK, w);
}

/**
 * \brief Função isSubstring do programa
 * 
 * que testa se uma string é sub-String de outra 
 * e devolve o índice da posição em que se encontra,
 * caso não seja sub-String devolve -1.
 * 
 * @param haystack (string principal)
 * @param needle (substring)
 */
int isSubstring(char *haystack, char *needle)
{
    size_t d;
    int i = 0;
    if (strlen(haystack) >= strlen(needle))
    {
        for (i = strlen(haystack) - strlen(needle); i >= 0; i--)
        {
            int found = 1;
            for (d = 0; d < strlen(needle); d++)
            {
                if (haystack[i + d] != needle[d])
                {
                    found = 0;
                    break;
                }
            }
            if (found == 1)
            {
                return i;
            }
        }
        return -1;
    }
    return -1;
}

/**
 * \brief Função find_subStr do programa
 * 
 * que procura o índice do início de uma String que contém a outra.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void find_subStr(struct stack *ptr_STACK)
{
    struct elemento y = POP(ptr_STACK);
    struct elemento x = POP(ptr_STACK);

    struct elemento z;
    z.tipo = T_int;

    z.data.val_i = isSubstring(x.data.val_s, y.data.val_s);

    PUSH(ptr_STACK, z);
}

/**
 * \brief Função sub_String do programa
 * 
 * que divide uma String em sub-Strings.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void sub_String(struct stack *ptr_STACK)
{
    struct elemento y = POP(ptr_STACK);
    struct elemento x = POP(ptr_STACK);
    int tamanho = strlen(x.data.val_s);
    int t = strlen(y.data.val_s);

    struct elemento val;
    val.tipo = T_array;
    struct stack *new_stack = malloc(sizeof(struct stack));
    initStack(new_stack, ptr_STACK->vars);
    val.data.val_p = new_stack;

    struct elemento string;
    string.tipo = T_string;
    string.data.val_s = malloc(t * sizeof(char));

    int true = 0;
    int i = 0;
    int j = i;
    for (i = 0; x.data.val_s[i] != '\0'; i++)
    {
        true = compareStrandSub(x.data.val_s, y.data.val_s, t, i);
        if (true)
        {
            pinta_astring(string.data.val_s, x.data.val_s, j, i);

            PUSH(val.data.val_p, string);
            string.data.val_s = malloc(tamanho * sizeof(char));
            j = i + t;
        }
    }
    if (i != j)
    {
        pinta_astring(string.data.val_s, x.data.val_s, j, i);
        PUSH(val.data.val_p, string);
    }
    PUSH(ptr_STACK, val);
}

/**
 * \brief Função pinta_astring do programa
 * 
 * que copia a string que estava numa auxiliar para uma string objetivo
 * 
 * @param aux (string auxiliar)
 * @param main (string auxiliar)
 * @param begin (contador)
 * @param j (contador)
 */
void pinta_astring(char *aux, char *main, int begin, int j)
{
    int i;
    for (i = 0; i + begin < j; i++)
    {
        aux[i] = main[i + begin];
    }
    aux[i] = '\0';
}

/**
 * \brief Função compareStrandSub do programa
 * 
 * que verifica se existe a substring na string inicial
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int compareStrandSub(char str[], char substr[], int N, int i)
{
    int j = 0;
    while (str[i] != '\0' && j < N)
    {
        if (str[i] != substr[j])
            return 0;
        j++;
        i++;
    }
    if (substr[j] == '\0')
        return 1;
    return 0;
}

/**
 * \brief Função div_WhiteS_Str do programa
 * 
 * que divide uma String por espaços.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void div_WhiteS_Str(struct stack *ptr_STACK)
{
    struct elemento y = POP(ptr_STACK);

    struct elemento val;
    val.tipo = T_array;
    struct stack *new_stack = malloc(sizeof(struct stack));
    initStack(new_stack, ptr_STACK->vars);
    val.data.val_p = new_stack;

    int t = strlen(y.data.val_s);
    struct elemento string;
    string.tipo = T_string;
    string.data.val_s = malloc(t * sizeof(char));
    int j = 0;

    int count = 0;
    for (int i = 0; i < t; i++)
    {
        if (y.data.val_s[i] == ' ' || y.data.val_s[i] == '\n')
        {
            string.data.val_s[i] = '\0';
            if (strlen(string.data.val_s) != 0)
            {
                count++;

                PUSH(val.data.val_p, string);
            }
            string.data.val_s = malloc(t * sizeof(char));
            j = -1;
        }
        string.data.val_s[j] = y.data.val_s[i];
        j++;
    }
    if (strlen(string.data.val_s) != 0)
    {
        string.data.val_s[j] = '\0';
        PUSH(val.data.val_p, string);
    }
    PUSH(ptr_STACK, val);
}

/**
 * \brief Função div_newLines_Str do programa
 * 
 * que divide uma String por novas linhas.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void div_newLines_Str(struct stack *ptr_STACK)
{
    struct elemento y = POP(ptr_STACK);

    struct elemento val;
    val.tipo = T_array;
    struct stack *new_stack = malloc(sizeof(struct stack));
    initStack(new_stack, ptr_STACK->vars);
    val.data.val_p = new_stack;

    int t = strlen(y.data.val_s);
    struct elemento string;
    string.tipo = T_string;
    string.data.val_s = malloc(t * sizeof(char));
    int j = 0;

    for (int i = 0; i < t; i++)
    {
        if (i == t - 1 && y.data.val_s[i] == '\n')
            break;

        if (y.data.val_s[i] == '\n')
        {
            string.data.val_s[i + 1] = '\0';
            PUSH(val.data.val_p, string);
            string.data.val_s = malloc(t * sizeof(char));
            j = -1;
        }
        string.data.val_s[j] = y.data.val_s[i];
        j++;
    }
    string.data.val_s[j] = '\0';
    PUSH(val.data.val_p, string);
    PUSH(ptr_STACK, val);
}
