/**
 * @file Ficheiro que contém as funções relativas ao guião 5
 */

/**
 * \brief Função criaBlock do programa
 * 
 * que cria o bloco e envia-o para a stack.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void criaBlock(struct stack *ptr_STACK, char *token);

/**
 * \brief Função tilfunction do programa
 * 
 * aplica a operação do bloco a um elemento
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void tilfunction(struct stack *ptr_STACK);

/**
 * \brief Função pinta_block do programa
 * 
 * prepara o bloco para as operações 
 * 
 * @param line (string que contem o bloco)
 */
char *pinta_block(char *line);

/**
 * \brief Função percentagem_function do programa
 * 
 * aplica o bloco a um array /string
 * 
 * @param line (string que contem o bloco)
 */
void percentagem_function(struct stack *ptr_STACK);

/**
 * \brief Função convert_elem_s do programa
 * 
 * converte o elemento dado para string
 * 
 * @param val (struct elemento)
 */
void convert_elem_s(struct elemento val);

/**
 * \brief Função convert_arr_string do programa
 * 
 * converte o elemento dado do tipo array para string
 * 
 * @param arr (struct elemento)
 * @param s (string resultado)
 */
void convert_arr_string(struct elemento arr, char *s);

/**
 * \brief Função filter_function do programa
 * 
 * Executa um bloco e devolve os verdadeiros
 * 
 * @param ptr_stack (apontador para a stack)
 */
void filter_function(struct stack *ptr_STACK);

/**
 * \brief Função w_function do programa
 * 
 * Executa o bloco enquanto ele deixar um truthy
 * no topo da stack
 * 
 * @param ptr_stack (apontador para a stack)
 */
//void w_function(struct stack *ptr_STACK);

/**
 * \brief Função filter_function do programa
 * 
 * Executa um bloco e devolve os verdadeiros
 * 
 * @param ptr_stack (apontador para a stack)
 */
void filter_function(struct stack *ptr_STACK);

/**
 * \brief Função convert_elem_s do programa
 * 
 * converte o elemento dado para string
 * 
 * @param val (struct elemento)
 */
void convert_elem_s(struct elemento val);

/**
 * \brief Função convert_arr_strin do programa
 * 
 * converte o elemento dado do tipo array para string
 * 
 * @param arr (struct elemento)
 * @param s (string resultado)
 */
void convert_arr_string(struct elemento arr, char *s);

/**
 * \brief Função dollar_block do programa
 * 
 * ordena usando o bloco
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void dollar_block(struct stack *ptr_STACK);

/**
 * \brief Função merge do programa
 * 
 * Dá merge de dois arrays na ordem correta 
 * 
 * @param arr (array)
 * @param l (int)
 * @param m (int)
 * @param r (int)
 * @param bloco (string)
 * @param final (apontador para uma stack)
 */
void merge(struct elemento arr[], int l, int m, int r, char *bloco, struct stack *final);

/**
 * \brief Função mergeSort do programa
 * 
 * Realiza a função de ordenação.
 * 
 * @param arr (array)
 * @param l (int)
 * @param r (int)
 * @param bloco (string)
 * @param final (apontador para uma stack)
 */
void mergeSort(struct elemento arr[], int l, int r, char *bloco, struct stack *final);

/**
 * \brief Função checka do programa
 * 
 * Compara dois elementos em relação à operação realizada pelo bloco e retorna 1 se se verificar .0 Caso contrário.
 * 
 * @param fst (struct elemento)
 * @param snd (struct elemento)
 * @param bloco (string)
 * @param final (apontador para uma stack)
 */
int checka(struct elemento fst, struct elemento snd, char *bloco, struct stack *final);

/**
 * \brief Função fold_function do programa
 * 
 * Aplica o fold a um array/string
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void fold_function(struct stack *ptr_STACK);

/**
 * \brief Função change_string do programa
 * 
 * que recebe um elemento e coloca o seu valor numa string s 
 * 
 * 
 * @param token (operador)
 * @param s (string)
 */
void change_string(struct elemento y, char *s);