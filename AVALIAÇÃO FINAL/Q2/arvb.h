typedef struct arvb ArvB;
typedef struct lista Lista;
/*Fun??o que cria uma ?rvore Bin?ria de Busca Vazia.*/
ArvB *arvb_cria_vazia(void);
/*Testa se uma ?rvore Bin?ria ? vazia.*/
int arvb_vazia(ArvB *a);
/*Fun??o que busca a sub-?rvore que cont?m um inteiro.*/
ArvB *arvb_busca(ArvB *a, int c);
/*Fun??o que imprime os elementos de uma ?rvore.*/
void arvb_imprime(ArvB *a);
/*Fun??o que insere um inteiro em uma ?rvore.*/
ArvB *arvb_insere(ArvB *a, int c);
/*Fun??o que remove um inteiro em uma ?rvore.*/
ArvB *arvb_remove(ArvB *a, int c);
/*Libera o espa?o alocado para uma ?rvore.*/
void arvb_libera(ArvB *a);

int arv_altura(ArvB *a);

Lista* arvs_elem_camadas_lista(ArvB* a, ArvB* b);
Lista* impressao_elem(ArvB* a, int niv, Lista* l);
