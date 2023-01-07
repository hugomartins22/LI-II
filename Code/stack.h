/**
 * @file Ficheiro que contém as funções realtivas à Stack essenciais 
 * nomeadamente 
 * initStack,
 * PUSH,
 * POP,
 * printSTACK.
 * 
 * Contém também todas as estrusturas criadas para a resolução dos guiões.
 */

/**
 * \brief stack_type
 * 
 * Apresenta os tipos possiveis na stack
 * 
 */
enum stack_type
{
    T_int,    /**< Representa o tipo de um inteiro **/
    T_char,   /**< Representa o tipo de um char **/
    T_float,  /**< Representa o tipo de um float **/
    T_long,   /**< Representa o tipo de um longo **/
    T_double, /**< Representa o tipo de um double **/
    T_string, /**< Representa o tipo de uma string **/
    T_array,  /**< Representa o tipo de um array **/
    T_block   /**< Representa o tipo de um bloco **/
};

/**
 * \brief struct elemento 
 * 
 * Apresenta o conteudo dos diferentes tipos possiveis
 * 
 */
struct elemento
{
    enum stack_type tipo;
    union
    {
        char val_c;          /**< Representa o conteudo de um struct elemento do tipo char **/
        char *val_s;         /**< Representa o conteudo de um struct elemento do tipo string **/
        int val_i;           /**< Representa o conteudo de um struct elemento do tipo inteiro **/
        long val_l;          /**< Representa o conteudo de um struct elemento do tipo longo **/
        float val_f;         /**< Representa o conteudo de um struct elemento do tipo float **/
        double val_d;        /**< Representa o conteudo de um struct elemento do tipo double **/
        struct stack *val_p; /**< Representa o conteudo de um struct elemento do tipo array **/
        char *val_b;         /**< Representa o conteudo de um struct elemento do tipo bloco **/
    } data;
};

/**
 * \brief Struct var
 * 
 * com um char referente à variável que estamos a utilizar
 * e um elemento que a mesma representa.
 * 
 */
struct var
{
    int index;                /**< Representa o índice da variável **/
    struct elemento elemento; /**< Representa o conteúdo da variável **/
};

/**
 * \brief struct stack
 * 
 * Apresenta a stack como um apontador para a stack
 * 
 */
typedef struct stack *Stack;

/**
 * \brief struct stack
 * 
 * Apresenta o que a stack contém
 * 
 */
struct stack
{
    int top;
    int capacity;
    struct elemento array[20000];
    struct var *vars;
};

/**
 * \brief Função PUSH do programa
 * 
 *que adiciona uma célula à Stack .
 * 
 * @param stack
 * @param n (elemento a adicionar).
 */
void PUSH(struct stack *stack, struct elemento n);

/**
 * \brief Função POP do programa
 * 
 * Função que vai à Stack tirar a última célula.
 * 
 * @returns Um valor elemento .
 */
struct elemento POP(struct stack *stack);

/**
 * \brief Função PRINT_STACK do programa.
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
void PRINT_STACK(struct stack *stack);

/**
 * \brief Função initStack  do programa
 * 
 * inicia a stack
 * 
 * @param ptr_STACK (apontador para a stack)
 * @param ptr_vars (apontador para o array das variáveis)
 */
void initStack(struct stack *ptr_STACK, struct var *ptr_vars);

/**
 * \brief Função PRINT_ARRAY do programa
 * 
 * que impreme o array.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void PRINT_ARRAY(struct stack *stack);

/**
 * \brief Função free_Stack  do programa
 * 
 * liberta a Stack.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void free_Stack(struct stack *stack);
