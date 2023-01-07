/**
 * @file Ficheiro que contém as funçẽs relativas ao parse da Stack
 */

/**
 * \brief Função parse do programa
 * 
 * Inicia-se um apontador de caracteres (delimitadores).
 * 
 * Posteriormente, através de um ciclo, inicia-se uma nova variável (um apontador de carateres (token)),
 * com a condição de paragem quando esse token for NULL. 
 * A cada iteração o token é atualizado.
 * 
 * Através de condições if verifica-se o valor a devolver ao topo da pilha, 
 * se à partida, a string contiver apenas números é imediatamente devolvida, 
 * caso contrário, através da função 'strcmp' verificar-se-à que valor/es 
 * terão que se devolver.
 * 
 * @param line Linha, onde a função parse atuará, e que já foi lida.
 */
void parse(char *line);

/**
 * \brief Função check_type do programa
 * 
 * recebe um token, um apontador para o resto da função e outro apontador para o tipo desse token.
 * Irá verificar o tipo correspondente ao token e atualizar a stack com o elemento correspondente.
 *
 * @param resto
 * @param token
 * @param val_tipo 
 */
void check_type(char **resto, char **token, int *val_tipo);

/**
 * \brief Função filter do programa
 * 
 * recebe um token e devolve o número correspondente ao conjunto de operações onde o mesmo pertence.
 *
 * 
 * @param token (operando)
 * 
 * @returns Um inteiro 
 */
int filter(char *token);

/**
 * \brief Função put_token do programa
 * 
 * recebe um token, um apontador para o resto da função e outro apontador para a stack.
 * Irá colocar o token respetivo a um elemento na stack.
 *
 * @param ptr_STACK (apontador para a stack)
 * @param val_tipo (tipo)
 * @param token (operando)
 */
void put_token(struct stack *ptr_STACK, int val_tipo, char *token);

/**
 * \brief Função go_filter do programa
 * 
 * verifica o nosso token e seleciona a função auxiliar correspondente à operação
 * desejada.
 *
 * @param ptr_STACK
 * @param token (operando)
 */
void go_filter(struct stack *ptr_STACK, char *token);

/**
 * \brief Função get_token do programa.
 * 
 * ---------------------------------------------------------------------------
 * 
 * @param delim Apontador para delimitadores
 * @param line Apontador para a linha que será lida
 * @param rest
 * 
 * @return bRet que corresponde a 0 ou 1
 */
char *get_token(char *delim, char *line, char **rest);

/**
 * \brief Função put_array do programa.
 * 
 * Responsável por colocar o array na STACK.
 * 
 * @param ptr_STACK Apontador para a stack.
 * @param token Token atual.
 * @param ptr_elem Apontador para o elemento
 */
void put_array(struct stack *ptr_STACK, char *token, struct elemento *ptr_elem);

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
 * @param line Token atual.
 */
void pinta_array(char *line);

/**
 * \brief Função check_array do programa.
 * 
 * Recebe um apontador para a Stack e um token.
 * Inicializa um apontador para uma string 
 * para testar se o token pertence a algum desses símbolos, 
 * se pertence retorna 1, caso contrário, 0.
 * 
 * @param token Token atual
 * 
 * @return Um inteiro, pode ser 0 ou 1.
 */
int check_array(char *token);

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
void go_filter_array(struct stack *ptr_STACK, char *token);

/**
 * \brief Função check_soma_array do programa.
 * 
 * Iremos verificar se algum dos elementos do topo é array.
 * Se essa condição se verificar vamos concatenar o array. 
 * (concatenarray).
 * Se não se verificar, chamamos o operador para somar os dois elementos.
 *  
 * @param ptr_STACK Apontador para a stack.
 * @param token Token atual.
 */
void check_soma_array(struct stack *ptr_STACK, char *token);

/**
 * \brief Função check_all_array do programa.
 * 
 * Iremos verificar se o topo da stack é array.
 * Se essa condição se verificar vamos chamar a função manarray. 
 * (Aplica as operações com arrays).
 * Se não se verificar, chamamos a função go_filter
 * (Aplica as operações dos guiões 1/2/3). 
 * 
 * @param ptr_STACK Apontador para a stack.
 * @param token Token atual.
 */
void check_all_array(struct stack *ptr_STACK, char *token);

/**
 * \brief Função cleanLim do programa.
 * 
 * remove os delimitadores da linha recebida.
 * 
 * @param line
 * 
 * @return line
 */
char *cleanLim(char line[]);

/**
 * \brief Função existe_arary do programa
 * 
 * Retorna 1 se algum dos  2 elementos que esta no topo da stack for array
 * 
 * @param ptr_STACK (apontador para a stack)
 * 
 * @returns um inteiro
 */
int existe_array(struct stack *ptr_STACK);

/**
 * \brief Função existe_string do programa
 * 
 * Retorna 1 se algum dos  2 elementos que esta no topo da stack for string
 * 
 * @param ptr_STACK (apontador para a stack)
 */
int existe_string(struct stack *ptr_STACK);

/**
 * \brief Função initVars do programa
 * 
 * prepara um array para definir as variáveis e os seus respetivos valores.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void initVars(struct var *ptr_vars);

/**
 * \brief Função aux_filter_array1 do programa
 * 
 * contém alguns tokens e direciona para as respetivas operações
 * 
 * @param ptr_STACK (apontador para a stack)
 * @param token (operando)
 */
void aux_filter_Array1(struct stack *ptr_STACK, char *token);

/**
 * \brief Função aux_filter_array2 do programa
 * 
 * contém alguns tokens e direciona para as respetivas operações
 * 
 * @param ptr_STACK (apontador para a stack)
 * @param token (operando)
 */
void aux_filter_array2(struct stack *ptr_STACK, char *token);

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
void put_token2(struct elemento val, char *token, struct stack *ptr_STACK, int val_tipo);