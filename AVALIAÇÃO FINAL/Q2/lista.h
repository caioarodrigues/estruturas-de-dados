typedef struct lista Lista;
typedef struct arvb ArvB;
/* Cria uma lista vazia.*/
Lista* lst_cria();
/* Testa se uma lista é vazia.*/
int lst_vazia(Lista *l);
/* Insere um elemento no início da lista.*/
Lista* lst_insere(Lista *l, int info);
/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info);
/* Imprime uma lista.*/
void lst_imprime(Lista *l);
/* Remove um elemento de uma lista.*/
Lista* lst_remove(Lista *l, int info);
/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista *l);

Lista* lst_insere_ordenado(Lista *l, int info);
void lst_imprime_rec(Lista* l);
void lst_imprime_invertida_rec(Lista* l);
Lista* lst_remove_rec(Lista *l, int info);
void lst_libera_rec(Lista *l);
int lst_igual_rec(Lista *l1,Lista *l2);

Lista* lst_soma_p(Lista* l1, Lista* l2);
Lista* lst_conc_sem_primos(Lista* l1, Lista* l2);
Lista* arvs_elem_comuns_lista(arv_1,arv_2);
