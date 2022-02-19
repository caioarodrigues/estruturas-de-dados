#include <stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(void){
    int a, b, c;
    Lista* l1 = lst_cria();
    l1 = lst_insere_ordenado(l1,14);
    l1 = lst_insere_ordenado(l1,8);
    l1 = lst_insere_ordenado(l1,29);
    l1 = lst_insere_ordenado(l1,12);
    l1 = lst_insere_ordenado(l1,6);
    l1 = lst_insere_ordenado(l1,18);
    l1 = lst_remove_rec(l1,29);
    
    lst_imprime(l1);
    lst_imprime_invertida_rec(l1);
    a=soma(l1);
	b=menores(l1,9); 
	c=num_ndivp(l1,4);
	
    printf("Soma dos valores dos nos %d\n",a);
    printf("Num. nos c/ info < que 9: %d\n",b);
    printf("Num. nos c/ info c/ 4 div. positivos.: %d\n",c);
    
    Lista* l2 = lst_cria();
    l2 = lst_insere_ordenado(l2,8);
    l2 = lst_insere_ordenado(l2,12);
    l2 = lst_insere_ordenado(l2,7);
    Lista* l3=lst_conc(l1,l2);
    printf("\nL3: \n");
    lst_imprime(l3);
    l1=lst_diferenca(l1,l2);
    lst_imprime(l1);
    lst_libera(l1);
    lst_libera(l2);
    lst_libera(l3);
    system("PAUSE");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista{
	int info;
	Lista *prox;
};

Lista* lst_cria(){
	return NULL;
}

int lst_vazia(Lista *l){
	return (l==NULL);
}

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

/* Libera o espaco alocado por uma lista.*/
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

//implementacao funcoes da Q1 abaixo:
int menores(Lista* l, int n){
	int cont = 0;
	while(l != NULL){
		if(l->info < n){
			cont++;
		}
		l = l->prox;
	}
	return cont;
}

int soma(Lista *l){
	int s = 0;
	Lista *lAux = l;
	while(l != NULL){
		s += l->info;
		l = l->prox;
	}
	l = lAux;
	return s;
}

int num_ndivp(Lista* l, int n){
	int i, divs = 0, cont = 0;
	Lista *lcop = l;
	
	while(lcop != NULL){
		for(i = 1; i <= lcop->info; i++){
			if(lcop->info % i == 0){
				cont++;
			}
		}
		if (cont >= n){
			divs++;
		}
		cont = 0;
		lcop = lcop->prox;
	}

	return divs;
}

Lista* lst_conc(Lista* l1, Lista* l2){
	Lista* aux;
	if(l1 == NULL){
		return l2;
	}
	if(l2 == NULL){
		return l1;
	}
	for(aux = l1; aux->prox != NULL; aux = aux->prox);
	aux->prox = l2;
	return l1;
}

Lista* lst_diferenca(Lista* l1, Lista* l2){
	//Se houverem elementos em comum entre l1 e l2, retirar-los de l1
	Lista* aux;
	Lista* aux2;
	for(aux = l1; aux->prox != NULL; aux = aux->prox){
		for(aux2 = l2; aux2->prox != NULL; aux2 = aux2->prox){
			if(aux2->info == aux->info){
				aux->info = 0;
			}
		}
	}
	return l1;
}

#include "lista.c"
typedef struct lista Lista;
/* Cria uma lista vazia.*/
Lista* lst_cria();
/* Testa se uma lista � vazia.*/
int lst_vazia(Lista *l);
/* Insere um elemento no in�cio da lista.*/
Lista* lst_insere(Lista *l, int info);
/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info);
/* Imprime uma lista.*/
void lst_imprime(Lista *l);
/* Remove um elemento de uma lista.*/
Lista* lst_remove(Lista *l, int info);
/* Libera o espa�o alocado por uma lista.*/
void lst_libera(Lista *l);
