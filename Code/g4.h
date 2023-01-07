/**
 * @file Ficheiro que contém as funçẽs relativas ao guião 4
 */

/**
 * \brief Função concatenarray  do programa
 * 
 * que faz POP de dois elementos, e se pelo menos um deles for array ,concatena-os.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void concatenarray(struct stack *ptr_STACK);

/**
 * \brief Função manarray do programa
 * 
 * que recebe um token e efetua uma operação de acordo com o objetivo desse token.
 * 
 * @param ptr_STACK  (apontador para a stack )
 * @param token (operando)
 */
void manarray(struct stack *ptr_STACK, char *token);

/**
 * \brief Função parse_array  do programa
 * 
 * que lê uma linha e trata diferentes possibilidades, ter um array, ter uma string
 * ou apenas efetuar outras operações, caso não enocntre arrays nem strings.
 * 
 * @param ptr_STACK (apontador para a stack)
 * @param line (uma linha que será tratada)
 */
void parse_array(char *line, struct stack *ptr_STACK);

/**
 * \brief Função empurraarray  do programa
 * 
 * que faz PUSH dos elementos de um array na Stack.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void empurraarray(struct stack *ptr_STACK);

/**
 * \brief Função repetearray  do programa
 * 
 * que repete n-vezes um array e faz PUSH para a stack de um array que contem as n repetições pedidas.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void repetearray(struct stack *ptr_STACK);

/**
 * \brief Função tamanho_array  do programa
 * 
 * que devolve a quantidade de elementos (alfanuméricos) contidos num array.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void tamanho_array(struct stack *ptr_STACK);

/**
 * \brief Função left_elementos do programa
 * 
 * que faz POP de um valor n  e de um array e vai ao array remover n-elementos do início.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void left_elementos(struct stack *ptr_STACK);

/**
 * \brief Função right_elementos do programa
 * 
 * que faz POP de um valor n e de um array e vai ao array remover n-elementos a partir do fim.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void right_elementos(struct stack *ptr_STACK);

/**
 * \brief Função range_array  do programa
 * 
 * que faz POP de um elemento e se esse é um número n devolve um array com 
 * os números inteiros no intervalo [0...(n-1)]
 * 
 * @param ptr_STACK  (apontador para a stack)
 */
void range_array(struct stack *ptr_STACK);

/**
 * \brief Função left_parentesis do programa
 * 
 * que retira o primeiro elemento de um array e coloca na Stack depois do array.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void left_parentesis(struct stack *ptr_STACK);

/**
 * \brief Função right_parentesis do programa
 * 
 * que retira o último elemento de um array e coloca na Stack depois do array.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void right_parentesis(struct stack *ptr_STACK);

/**
 * \brief Função buscavalindice  do programa
 * 
 * que vai ao array buscar um elemento no índice i que lhe damos.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void buscavalindice(struct stack *ptr_STACK);

/**
 * \brief Função criaStr  do programa
 * 
 * que criará uma String.
 * 
 * @param ptr_STACK (apontador para a stack)
 * @param token (operando)
 */
void criaStr(struct stack *ptr_STACK, char *token);

/**
 * \brief Função concaString do programa
 * 
 * que tem por objetivo concatenar duas strings ou uma string e uma caractere.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void concaString(struct stack *ptr_STACK);

/**
 * \brief Função repeteStr  do programa
 * 
 *  faz PUSH de uma string resultado que contem as n repetições da string inicial.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void repeteStr(struct stack *ptr_STACK);

/**
 * \brief Função tamanho_str  do programa
 * 
 * que devolve a quantidade de elementos contidos numa String.
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param x (string)
 */
void tamanho_str(struct stack *ptr_STACK, struct elemento x);

/**
 * \brief Função val_index_Str  do programa
 * 
 * que vai buscar à String um elemento no índice i que lhe damos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 * @param x (indice)
 */
void val_index_Str(struct stack *ptr_STACK, struct elemento x);

/**
 * \brief Função catch_elem_Str do programa
 * 
 * que faz POP de um valor n e de uma string e vai à String remover n-elementos.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void catch_elem_Str(struct stack *ptr_STACK);

/**
 * \brief Função catch_ultimos_Str do programa
 * 
 * que faz POP de um valor n e de uma string e vai à String remover n-elementos a partir do fim.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void catch_ultimos_Str(struct stack *ptr_STACK);

/**
 * \brief Função delete_fst_Str do programa
 * 
 * que retira o primeiro elemento de uma String e coloca na Stack depois do String.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void delete_fst_Str(struct stack *ptr_STACK);

/**
 * \brief Função delete_snd_Str do programa
 * 
 * que retira o último elemento de uma String e coloca na Stack depois da String.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void delete_snd_Str(struct stack *ptr_STACK);

/**
 * \brief Função find_subStr do programa
 * 
 * que procura o índice do início de uma String que contém a outra.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void find_subStr(struct stack *ptr_STACK);

/**
 * \brief Função sub_String do programa
 * 
 * que divide uma String em sub-Strings.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void sub_String(struct stack *ptr_STACK);

/**
 * \brief Função div_WhiteS_Str do programa
 * 
 * que divide uma String por espaços.
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
void div_WhiteS_Str(struct stack *ptr_STACK);

/**
 * \brief Função div_newLines_Str do programa
 * 
 * que divide uma String por novas linhas.
 * 
 * @param ptr_STACK (apontador para a stack)
 */
void div_newLines_Str(struct stack *ptr_STACK);

/**
 * \brief Função mystrcat do programa
 * 
 * que recebe dois caracteres e concatena-os.
 * 
 * @param s1 (caractere)
 * @param s2 (caractere)
 * @param ptr_STACK (apontador para a Stack)
 */
void mystrcat(struct elemento s1, struct elemento s2, struct stack *ptr_STACK);

/**
 * \brief Função mystrcat2 do programa
 * 
 * que recebe um caractere e uma string e concatena-os numa só string.
 * 
 * @param s1 (catactere)
 * @param s2 (string)
 * @param ptr_STACK (apontador para a Stack)
 */
void mystrcat2(struct elemento s1, struct elemento s2, struct stack *ptr_STACK);

/**
 * \brief Função mystrcat3 do programa
 * 
 * que recebe uma string e um caractere e concatena-os numa só string.
 * 
 * @param s1 (string)
 * @param s2 (caractere)
 * @param ptr_STACK (apontador para a Stack)
 */
void mystrcat3(struct elemento s1, struct elemento s2, struct stack *ptr_STACK);

/**
 * \brief Função mystrcat4 do programa
 * 
 * que recebe duas strings e concatena-as.
 * 
 * @param s1 (string)
 * @param s2 (string)
 */
void mystrcat4(char s1[], char s2[]);

/**
 * \brief Função compareStrandSub do programa
 * 
 * que verifica se existe a substring na string inicial
 * 
 * @param ptr_STACK (apontador para a Stack)
 */
int compareStrandSub(char str[], char substr[], int N, int i);

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
void pinta_astring(char aux[], char main[], int j, int i);

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
int isSubstring(char *haystack, char *needle);

/**
 * \brief Função ajudatipo do programa
 * 
 * ajuda nos tipo na função range_array
 * 
 * @param x (Struct elemento)
 */
void ajudatipo(struct elemento x);

/**
 * \brief Função ajuda_elementos do programa
 * 
 * ajuda nos tipo na função right elementos
 * 
 * @param x (Struct elemento)
 */
void ajuda_elementos(struct elemento x);

/**
 * \brief Função concatenarray2 do programa
 * 
 * ajuda nos tipo na função concatenarray
 * 
 * @param x (Struct elemento)
 */
void concatenarray2(struct elemento x, struct elemento y, struct stack *ptr_STACK);

/**
 * \brief Função help_left_elementos do programa
 * 
 * ajuda nos tipo na função left_elementos 
 * 
 * @param x (Struct elemento)
 */
void help_left_elementos(struct elemento x);