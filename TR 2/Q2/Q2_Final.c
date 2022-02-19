#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

/*
as funções vet1c(), vet1d(), vet1a() sao respectivamente para preencher o vetor de 10^3 de forma crescente, decrescente e aleatoria.
de maneira analoga, as funcoes vet2c(), vet2d(), vet2a() servem para os vetores de tamanho 10^4. 
para os vetores de ordem 5, fiz as funcoes vet3c(), vet3d() e vet3a().
e por fim, aos de ordem 6, sao as vet4c(), vet4d() e vet4a().

e aparentemente, os metodos de ordenacao heapsort e quicksort nao estao funcionando da maneira como deveriam
*/
int main(){
	int *v1 = (int *) malloc(1000*sizeof(int)); //10^3
	int *v2 = (int *) malloc(10000*sizeof(int)); //10^4
	int *v3 = (int *) malloc(100000*sizeof(int)); //10^5
	int *v4 = (int *) malloc(1000000*sizeof(int)); //10^6
	
	printf("\nOrganizando BubbleSort crescente...\n");
	vet1c(v1);
	calculaTempo(v1, 1000, 'B');
	imprimeVetor(v1);
	vet1c(v2);
	calculaTempo(v2, 10000, 'B');
	vet1c(v3);
	calculaTempo(v3, 100000, 'B'); 
	vet1c(v4);
	calculaTempo(v4, 1000000, 'B');
	
	printf("\nOrganizando BubbleSort decrescente...\n");
	vet1d(v1);
	calculaTempo(v1, 1000, 'B');
	vet1d(v2);
	calculaTempo(v2, 10000, 'B');	
	vet1d(v3);
	calculaTempo(v3, 100000, 'B');
	vet1d(v4);
	calculaTempo(v4, 1000000, 'B');
	
	printf("\nOrganizando BubbleSort aleatorio...\n");
	vet1a(v1);
	calculaTempo(v1, 1000, 'B');
	vet1a(v2);
	calculaTempo(v2, 10000, 'B');
	vet1a(v3);
	calculaTempo(v3, 100000, 'B');
	vet1a(v4);
	calculaTempo(v4, 1000000, 'B');
	
	printf("\n\nOrganizando InsertionSort crescente...\n");
	vet1c(v1);
	calculaTempo(v1, 1000, 'I');
	vet1c(v2);
	calculaTempo(v2, 10000, 'I');
	vet1c(v3);
	calculaTempo(v3, 100000, 'I');
	vet1c(v4);
	calculaTempo(v4, 1000000, 'I');
	
	printf("\n\nOrganizando InsertionSort decrescente...\n");
	vet1d(v1);
	calculaTempo(v1, 1000, 'I');
	vet1d(v2);
	calculaTempo(v2, 10000, 'I');	
	vet1d(v3);
	calculaTempo(v3, 100000, 'I');
	vet1d(v4);
	calculaTempo(v4, 1000000, 'I');
	
	printf("\n\nOrganizando InsertionSort aleatorio...\n");
	vet1a(v1);
	calculaTempo(v1, 1000, 'I');
	vet1a(v2);
	calculaTempo(v2, 10000, 'I');
	vet1a(v3);
	calculaTempo(v3, 100000, 'I');
	vet1a(v4);
	calculaTempo(v4, 1000000, 'I');
	
	printf("\n\nOrganizando HeapSort crescente...\n");
	vet1c(v1);
	calculaTempo(v1, 1000, 'H');
	vet1c(v2);
	calculaTempo(v2, 10000, 'H');
	vet1c(v3);
	calculaTempo(v3, 100000, 'H');
	vet1c(v4);
	calculaTempo(v4, 1000000, 'H');
	
	printf("\n\nOrganizando HeapSort decrescente...\n");
	vet1d(v1);
	calculaTempo(v1, 1000, 'H');
	vet1d(v2);
	calculaTempo(v2, 10000, 'H');	
	vet1d(v3);
	calculaTempo(v3, 100000, 'H');
	vet1d(v4);
	calculaTempo(v4, 1000000, 'H');
	
	printf("\n\nOrganizando HeapSort aleatorio...\n");
	vet1a(v1);
	calculaTempo(v1, 1000, 'H');
	vet1a(v2);
	calculaTempo(v2, 10000, 'H');
	vet1a(v3);
	calculaTempo(v3, 100000, 'H');
	vet1a(v4);
	calculaTempo(v4, 1000000, 'H');
	
	printf("\n\nOrganizando QuickSort crescente...\n");
	vet1c(v1);
	calculaTempo(v1, 1000, 'Q');
	vet1c(v2);
	calculaTempo(v2, 10000, 'Q');
	vet1c(v3);
	calculaTempo(v3, 100000, 'Q');
	vet1c(v4);
	calculaTempo(v4, 1000000, 'Q');
	
	printf("\n\nOrganizando QuickSort decrescente...\n");
	vet1d(v1);
	calculaTempo(v1, 1000, 'Q');
	vet1d(v2);
	calculaTempo(v2, 10000, 'Q');	
	vet1d(v3);
	calculaTempo(v3, 100000, 'Q');
	vet1d(v4);
	calculaTempo(v4, 1000000, 'Q');
	
	printf("\n\nOrganizando QuickSort aleatorio...\n");
	vet1a(v1);
	calculaTempo(v1, 1000, 'Q');
	vet1a(v2);
	calculaTempo(v2, 10000, 'Q');
	vet1a(v3);
	calculaTempo(v3, 100000, 'Q');
	vet1a(v4);
	calculaTempo(v4, 1000000, 'Q');
	
	return 0;
}
