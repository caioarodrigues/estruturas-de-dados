#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"

struct arvb{
	int info;
	ArvB *esq;
	ArvB *dir;
};

ArvB* arvb_cria_vazia(void){
	return NULL;
}

int arvb_vazia(ArvB *a){
	return a==NULL;
}

ArvB *arvb_busca(ArvB *a, int c)
{
    if (arvb_vazia(a))
        return NULL;

    else if (a->info < c)
        return arvb_busca(a->dir, c);

    else if (a->info > c)
        return arvb_busca(a->esq, c);

    else //(a->info == c)
        return a;
}

void arvb_imprime(ArvB *a)
{
    if (!arvb_vazia(a))
    {
        arvb_imprime(a->esq);
        printf("%d ", a->info);
        arvb_imprime(a->dir);
    }
}

ArvB *arvb_insere(ArvB *a, int c)
{
    if (arvb_vazia(a))
    {
        a = (ArvB *)malloc(sizeof(ArvB));
        a->info = c;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (a->info > c)
        a->esq = arvb_insere(a->esq, c);
    else if (a->info < c)
        a->dir = arvb_insere(a->dir, c);
    else
        printf("\nElemento Ja Pertence a Arvore");
    return a;
}

ArvB *arvb_remove(ArvB *a, int c)
{
    if (!arvb_vazia(a))
    {
        if (a->info > c)
            a->esq = arvb_remove(a->esq, c);
        else if (a->info < c)
            a->dir = arvb_remove(a->dir, c);
        else
        {
            ArvB *t;
            if (a->esq == NULL)
            {
                t = a;
                a = a->dir;
                free(t);
            }
            else if (a->dir == NULL)
            {
                t = a;
                a = a->esq;
                free(t);
            }
            else
            {
                t = a->esq;
                while (t->dir != NULL)
                    t = t->dir;
                a->info = t->info;
                t->info = c;
                a->esq = arvb_remove(a->esq, c);
            }
        }
    }
    return a;
}

void arvb_libera(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_libera(a->esq);
		arvb_libera(a->dir);
	 	free(a);
 	}
}

int arv_altura(ArvB *a){
	if(arvb_vazia(a))
		return -1;
	else{
		int hSAE = arv_altura(a->esq);
		int hSAD = arv_altura(a->dir);
		if(hSAE > hSAD)
			return 1+hSAE;
		else
			return 1+hSAD;
	}
}
//item "a"

int folhas_primo(ArvB* a){
	int i;
	int primos = 0;
	if(!arvb_vazia(a)){
		int cont = 0;
		if(arvb_vazia(a->dir) && arvb_vazia(a->esq)){
			for(i = 1; i <= a->info; i++){
				if(a->info % i == 0)
					cont++;
			}
			if(cont == 2)
				primos++;
		}
		return (primos + folhas_primo(a->esq) + folhas_primo(a->dir));
	}	
	return primos;
}

//item "b"

int subarvs_difnull(ArvB* a){
	int cont = 0;
	if(!arvb_vazia(a)){
		if(!arvb_vazia(a->esq) && !arvb_vazia(a->dir)){
			cont++;
			return(cont + subarvs_difnull(a->esq) + subarvs_difnull(a->dir));
		}
	}
	return(cont);
}

//item "c"

int subarvs_ig_alt(ArvB *raiz){
    if (raiz != NULL){
        int i = 0;
        int esq = arv_altura(raiz->esq);
        int dir = arv_altura(raiz->dir);
        if (esq == dir && esq != 0 && dir != 0)
            i = 0;

        return i + subarvs_ig_alt(raiz->esq) + subarvs_ig_alt(raiz->dir);
    }
    else
        return 0;
}

//item "d"
void impressao_arv_niveis(ArvB* a)
{
	int alt = arv_altura(a);
	int i = 1;
	while(i<=alt + 1){
		printf("Elementos pertencentes ao nivel %d: \n", i-1);
		impressao_por_niveis(a, i);
		printf("\n");
		i++;
	}
}

void impressao_por_niveis(ArvB* a, int niv){
	if(!arvb_vazia(a)){
		if (niv == 1)
			printf("%d ", a->info);
		impressao_por_niveis(a->esq, niv-1);
		impressao_por_niveis(a->dir, niv-1);
	}
}
