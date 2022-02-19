#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

void vet1c(int *v){
	//10^3
	int i;
	for(i = 0; i < 1000; i++)
		v[i] = i;
}

void vet1d(int *v){
	//10^3
	int i;
	for(i = 0; i < 1000; i++)
		v[i] = 1000 - i;
}

void vet1a(int *v){
	//num aleatorio ate 10^3
	int i;
	for(i = 0; i < 1000; i++)
		v[i] = rand() % 1000;
}

void vet2c(int *v){
	//10^4
	int i;
	for(i = 0; i < 10000; i++)
		v[i] = i;
}

void vet2d(int *v){
	//10^4
	int i;
	for(i = 0; i < 10000; i++)
		v[i] = 10000 - i;
}

void vet2a(int *v){
	//valores aleatorios ate 10^4
	int i;
	for(i = 0; i < 10000; i++)
		v[i] = rand() % 10000;
}

void vet3c(int *v){
	//10^5
	int i;
	for(i = 0; i < 100000; i++)
		v[i] = i;
}

void vet3d(int *v){
	//10^5
	int i;
	for(i = 0; i < 100000; i++)
		v[i] = 100000 - i;
}

void vet3a(int *v){
	//valores aleatorios ate 10^5
	int i;
	for(i = 0; i < 100000; i++)
		v[i] = rand() % 100000;
}

void vet4c(int *v){
	//10^6
	int i;
	for(i = 0; i < 1000000; i++)
		v[i] = i;
}

void vet4d(int *v){
	//10^6
	int i;
	for(i = 0; i < 1000000; i++)
		v[i] = 1000000 - i;
}

void vet4a(int *v){
	//valores aleatorios ate 10^6
	int i;
	for(i = 0; i < 1000000; i++)
		v[i] = rand() % 1000000;
}

void imprimeVetor(int *v){
	int i = 0;
	while(v[i]){
		printf("%d ", v[i]);
		i++;
	}
}

void bubbleSort(int *v, int tam){
	int contador, j, aux;
	for(contador = 1; contador < tam; contador++){
		for(j = 0; j < tam -1; j++){
			if(v[j] > v[j + 1]){
				aux = v[j + 1];
				v[j + 1] = v[j];
				v[j] = aux;
			}
		}
	}
}

void criaHeap(int *vet, int i, int f){
	int aux = vet[i];
	int j = i*2 + 1;
	while(j <= f){
		if(j < f)
			if(vet[j] < vet[j + 1])
				j++;
		if(aux < vet[j]){
			vet[i] = vet[j];
			i = j;
			j = 2*i + 1;
		}
		else
			j = f + 1;
	}
	vet[i] = aux;
}

void heapSort(int *vet, int n){
	int i, aux;
	for(i = (n-1)/2; i >= 0; i--)
		criaHeap(vet, i, n-1);
	for(i = n-1; i >= 1; i--){
		aux = vet[0];
		vet[i] = aux;
		criaHeap(vet, 0, i - 1);
	}
}

void insertionSort(int *v, int tam){
    int aux;
    int i;
    int troca;

    for (aux=1; aux < tam; aux++){
        i = aux;

        while (v[i] < v[i-1] && i != 0){ 
            troca = v[i];
            v[i] = v[i-1];
            v[i-1] = troca;
            i--;
        }

    }
}

void quickSort(int *a, int esq, int dir) {
    int i = esq, j = dir, x = a[(esq + dir) / 2], y;
     
    while(i <= j) {
        while(a[i] < x && i < dir) {
            i++;
        }
        while(a[j] > x && j > esq) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > esq)
        quickSort(a, esq, j);
    if(i < dir)
        quickSort(a, i, dir);
}

void calculaTempo(int *v, int tam, char tipo){
	int i, exp = 0;
	for(i = 10; i <= tam; i = i * 10)
		exp++;
		
	float tempo = 0;
	clock_t t;
	if(tipo == 'B'){
		t = clock();
		bubbleSort(v, tam);
		t = clock() - t;
	}else if(tipo == 'I'){
		t = clock();
		insertionSort(v, tam);
		t = clock() - t;
	}else if(tipo == 'Q'){
		t = clock();
		quickSort(v, 0, tam);
		t = clock() - t;
	}else if(tipo == 'H'){
		t = clock();
		heapSort(v, tam);
		t = clock() - t;
	}
	tempo = (double)t/(CLOCKS_PER_SEC/1000);
	printf("\nO vetor 10^%d foi ordenado em %f milissegundos.", exp, tempo);
}
