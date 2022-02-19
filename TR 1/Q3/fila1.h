#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct fila{
	int n; //capacidade?
	int ini; 
	int v[N]; //vetor que armazena cada valor
}Fila;

Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->n = 0;
	f->ini = 0;
	return f;
}

void fila_insere(Fila *f, int info){
	int fim;
	if(f->n==N){
		printf("Capacidade da Fila Estourou!!!\n");
		exit(1);
	}
	fim = (f->ini + f->n) % N;
	f->v[fim]= info;
	f->n++;
}

int fila_vazia(Fila *f){
	return f->n==0;
}
	
/*Função que remove um elemento de uma fila.*/
int fila_remove(Fila *f){
	int a;
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	a = f->v[f->ini];
	f->ini = (f->ini+1)%N;
	f->n--;
	return a;
}

void fila_imprime(Fila *f){
	int i; int k;
	for(i = 0; i<f->n;i++){
		k = (f->ini+i) % N;
		printf("%d\n",f->v[k]);
	}
}

void fila_libera(Fila *f){
	free(f);
}

int qtd_primos(Fila* f){
	int i, cont = 0, primos = 0;
	Fila* aux = f;
	while(aux->n <= N){
		for(i = 1; i <= *aux->v; i++){
			if(*aux->v % i == 0){
				cont++;
			}
		}
		if(cont == 2){
			primos++;
		}
		cont = 0;
		aux->n++;
	}
	return primos;
}

Fila* inverte_fila(Fila* f){
	
}
