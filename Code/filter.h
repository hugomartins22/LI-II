/**
 * @file Ficheiro que contém as funçoẽs que filtram os elementos 
 */

/**
 * \brief Função filter1 do programa
 * 
 * que filtra os elementos da pilha direcionando-os para as operações de acordo com os operadores.
 * 
 * @param token (operador)
 */
int filter1(char *token);

/**
 * \brief Função filter2 do programa
 * 
 * que filtra os elementos da pilha direcionando-os para as operações de acordo com os operadores.
 * 
 * @param token (operador)
 */
int filter2(char *token);

/**
 * \brief Função filter3 do programa
 * 
 * que filtra os elementos da pilha direcionando-os para as operações de acordo com os operadores.
 * 
 * @param token (operador)
 */
int filter3(char *token);

/**
 * \brief Função filter4 do programa
 * 
 * que filtra os elementos da pilha direcionando-os para as operações de acordo com os operadores.
 * 
 * @param token (operador)
 */
int filter4(char *token);

/**
 * \brief Função poli_plus do programa
 * 
 * que opera sobre os elementos segundo a função de + para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param token (operador)
 */
void poli_plus(struct stack *ptr_STACK, char *token);

/**
 * \brief Função poli_barra do programa
 * 
 * que opera sobre os elementos segundo a função de / para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param token (operador)
 */
void poli_barra(struct stack *ptr_STACK, char *token);

/**
 * \brief Função poli_parentesis_left do programa
 * 
 * que opera sobre os elementos segundo a função de ( para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void poli_parentesis_left(struct stack *ptr_STACK);

/**
 * \brief Função poli_parentesis_right do programa
 * 
 * que opera sobre os elementos segundo a função de ) para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void poli_parentesis_right(struct stack *ptr_STACK);

/**
 * \brief Função poli_percentagem do programa
 * 
 * que opera sobre os elementos segundo a função de % para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param token (operador)
 */
void poli_percentagem(struct stack *ptr_STACK, char *token);

/**
 * \brief Função poli_cardinal do programa
 * 
 * que opera sobre os elementos segundo a função de # para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param token (operador)
 */
void poli_cardinal(struct stack *ptr_STACK, char *token);

/**
 * \brief Função poli_til do programa
 * 
 * que opera sobre os elementos segundo a função de ~ para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void poli_til(struct stack *ptr_STACK);

/**
 * \brief Função poli_dollar do programa
 * 
 * que opera sobre os elementos segundo a função de $ para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void poli_dollar(struct stack *ptr_STACK);

/**
 * \brief Função poli_equal do programa
 * 
 * que opera sobre os elementos segundo a função de $ para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void poli_equal(struct stack *ptr_STACK);

/**
 * \brief Função poli_menor do programa
 * 
 * que opera sobre os elementos segundo a função de < para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void poli_menor(struct stack *ptr_STACK);

/**
 * \brief Função poli_maior do programa
 * 
 * que opera sobre os elementos segundo a função de > para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void poli_maior(struct stack *ptr_STACK);

/**
 * \brief Função poli_asterisco do programa
 * 
 * que opera sobre os elementos segundo a função de * para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param token (operador)
 */
void poli_asterisco(struct stack *ptr_STACK, char *token);

/**
 * \brief Função poli_virgula do programa
 * 
 * que opera sobre os elementos segundo a função de , para esses elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void poli_virgula(struct stack *ptr_STACK);

/**
 * \brief Função poli_filter3 do programa
 * 
 * que filtra as operações cujo símbolo pode operar de formas distintas ( < > * , ).
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param token (operador)
 */
void poli_filter3(struct stack *ptr_STACK, char *token);

/**
 * \brief Função poli_filter2 do programa
 * 
 * que filtra as operações cujo símbolo pode operar de formas distintas ( % # ~ $ = ).
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param token (operador)
 */
void poli_filter2(struct stack *ptr_STACK, char *token);

/**
 * \brief Função poli_filter do programa
 * 
 * que filtra as operações cujo símbolo pode operar de formas distintas ( + / ( ) ).
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param token (operador)
 */
void poli_filter(struct stack *ptr_STACK, char *token);

/**
 * \brief Função manhosos_filter do programa
 * 
 * que filtra as operações cujo símbolo pode criar problemas por se assemelharam a variáveis.
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param token (operador)
 */
void manhosos_filter(struct stack *ptr_STACK, char *token);

/**
 * \brief Função isnumber do programa
 * 
 * que testa se ambos os elementos no topo da Stack são números.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int isnumber(struct stack *ptr_STACK);

/**
 * \brief Função haveonearray do programa
 * 
 * que testa se, pelo menos, um dos dois elementos no topo da Stack é array.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int haveonearray(struct stack *ptr_STACK);

/**
 * \brief Função haveonestring do programa
 * 
 * que testa se, pelo menos, um dos dois elementos no topo da Stack é String.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int haveonestring(struct stack *ptr_STACK);

/**
 * \brief Função onlynumber do programa
 * 
 * que testa se o elemento no topo da Stack é um número.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int onlynumber(struct stack *ptr_STACK);

/**
 * \brief Função onlyarray do programa
 * 
 * que testa se o elemento no topo da Stack é um array.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int onlyarray(struct stack *ptr_STACK);

/**
 * \brief Função onlystring do programa
 * 
 * que testa se ambos os elementos no topo da Stack são Strings.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int onlystring(struct stack *ptr_STACK);

/**
 * \brief Função secondarray do programa
 * 
 * que testa se o segundo elemento do topo da Stack é um array.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int secondarray(struct stack *ptr_STACK);

/**
 * \brief Função secondstring do programa
 * 
 * que testa se o segundo elemento do topo da Stack é uma String.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int secondstring(struct stack *ptr_STACK);

/**
 * \brief Função bothstring do programa
 * 
 * que testa se ambos os elementos no topo da Stack são Strings.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int bothstring(struct stack *ptr_STACK);

/**
 * \brief Função stringnumber do programa
 * 
 * que testa se o primeiro e segundo elementos no topo da Stack
 * são uma String e um número, respetivamente.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int stringnumber(struct stack *ptr_STACK);

/**
 * \brief Função equal_type do programa
 * 
 * que testa se os elementos no topo da Stack são do mesmo tipo.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int equal_type(struct stack *ptr_STACK);

/**
 * \brief Função onlyblock do programa
 * 
 * que testa se o elemento do topo da Stack é um bloco.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int onlyblock(struct stack *ptr_STACK);

/**
 * \brief Função manhosos_filter2 do programa
 * 
 * ajuda na função manhosos_filter .
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void manhosos_filter2(struct stack *ptr_STACK, char *token, struct elemento val);