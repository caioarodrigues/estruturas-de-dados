#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct lista Lista;

struct lista {
	int info;
	Lista *prox;
};

/* Cria uma lista vazia.*/
Lista* lst_cria(){
	return NULL;
}

/* Testa se uma lista é vazia.*/
int lst_vazia(Lista *l){
	return (l==NULL);
}

/* Insere um elemento no início da lista.*/
Lista* lst_insere(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	ln->info = info;
	ln->prox = l;
	return ln;
}

/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info){
	Lista* lAux = l;
	while(lAux!=NULL){
		if(lAux->info == info)
			return lAux;
		lAux = lAux->prox;
	}
	return NULL;
}

/* Imprime uma lista.*/
void lst_imprime(Lista *l){
	Lista* lAux = l;
	while(lAux!=NULL){
		printf("Info = %d\n",lAux->info);
		lAux = lAux->prox;
	}
}

Lista* lst_remove(Lista *l, int info){
	if(l!=NULL){
		Lista* lAux = l->prox;
	if(l->info==info){
		free(l);
		return lAux;
	}
	else{
		Lista* lAnt = l;
		while(lAux!=NULL ){
			if(lAux->info == info){
				lAnt->prox = lAux->prox;
				free(lAux);
				break;
			}else{
				lAnt = lAux;
				lAux = lAux->prox;
				}
			}
		}
	}
	return l;
}

/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista *l){
	Lista* lProx;
	while(l!=NULL){
		lProx = l->prox;
		free(l);
		l = lProx;
	}
}

Lista* lst_insere_ordenado(Lista *l, int info){
	Lista *lNew = (Lista*)malloc(sizeof(Lista));
	lNew->info = info;
	if(l==NULL){
		lNew->prox = NULL;
		return lNew;
	}else if(l->info>=info){
		lNew->prox = l;
		return lNew;
	}else{
		Lista *lAnt = l;
		Lista *lProx = l->prox;
		while(lProx!=NULL&&lProx->info<info){
			lAnt = lProx;
			lProx = lProx->prox;
		}
	lAnt->prox = lNew;
	lNew->prox = lProx;
	return l;
	}
}

void lst_imprime_rec(Lista* l){
	if(lst_vazia(l))
		return;
	else{
		printf("info: %d\n",l->info);
		lst_imprime_rec(l->prox);
	}
}

void lst_imprime_invertida_rec(Lista* l){
	if(lst_vazia(l))
		return;
	else{
		lst_imprime_invertida_rec(l->prox);
		printf("info: %d\n",l->info);
}

Lista* lst_remove_rec(Lista *l, int info){
	if(!lst_vazia(l))
		if(l->info==info){
			Lista* lAux = l;
			l = l->prox;
			free(lAux);
			}
			else{
				l->prox = lst_remove_rec(l->prox,info);
				}
	return l;
}

void lst_libera_rec(Lista *l){
	if(!lst_vazia(l)){
		lst_libera_rec(l->prox);
		free(l);
	}
}

int lst_igual_rec(Lista *l1,Lista *l2){
	if(lst_vazia(l1) && lst_vazia(l2))
		return 1;
	else if (lst_vazia(l1) || lst_vazia(l2))
		return 0;
	else
		return (l1->info==l2->info && lst_igual_rec(l1->prox,l2->prox));
	}
}	

// "a"

Lista* lst_soma_p(Lista* l1, Lista* l2){
	
	int tam_l1 = 0, tam_l2 = 0, info;
	Lista* auxl1 = l1;
	Lista* auxl2 = l2;
	Lista* retorno = lst_cria();
	Lista* soma = lst_cria();
	Lista* aux_menor = lst_cria();
	
	//checando o tamanho das listas
	while(!lst_vazia(auxl1)){
		tam_l1++;
		auxl1 = auxl1->prox;
	}
	while(!lst_vazia(auxl2)){
		tam_l2++;
		auxl2 = auxl2->prox;
	}
	
	//cria uma copia de acordo com o maior
	if(tam_l1 >= tam_l2){
		soma = l1;
		aux_menor = l2;
	}
	else{
		soma = l2;
		aux_menor = l1;
	}
	
	//atribui a nova lista, 'retorno' a soma.
	while(!lst_vazia(soma)){
		if(lst_vazia(aux_menor))
			info = 0;
		else{
			info = aux_menor->info;
			aux_menor = aux_menor->prox;
		}
		retorno = lst_insere_ordenado(retorno, info + soma->info);
		soma = soma->prox;
	}	
	return retorno;
}

// "b"
Lista* lst_conc_sem_primos(Lista* l1, Lista* l2){
	Lista* auxl1 = l1;
	Lista* auxl2 = l2;
	Lista* aux = lst_cria();
	int i, j, cont = 0;
	
	while(!lst_vazia(auxl1)){
		for(i = 1; i <= auxl1->info; i++)
			if(auxl1->info % i == 0)
				cont++;
		if(cont > 2)
			aux = lst_insere_ordenado(aux, auxl1->info);
		cont = 0;
		auxl1 = auxl1->prox;
	}
	
	while(!lst_vazia(auxl2)){
		for(j = 1; j <= auxl2->info; j++)
			if(auxl2->info % j == 0)
				cont++;
		if(cont > 2)
			aux = lst_insere_ordenado(aux, auxl2->info);
		cont = 0;
		auxl2 = auxl2->prox;
	}
	return aux;
}

//2 "a"
Lista* arvs_elem_comuns_lista(arv_1,arv_2){
	return NULL;
}

