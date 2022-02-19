#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void){
	Lista* l1 = lst_cria();
	l1 = lst_insere_ordenado(l1,21);
	l1 = lst_insere_ordenado(l1,42);
	l1 = lst_insere_ordenado(l1,33);
	l1 = lst_insere_ordenado(l1,65);
	l1 = lst_insere_ordenado(l1,11);
	l1 = lst_insere_ordenado(l1,17);
	
	Lista* l2 = lst_cria();
	l2 = lst_insere_ordenado(l2,23);
	l2 = lst_insere_ordenado(l2,40);
	l2 = lst_insere_ordenado(l2,7);
	
	Lista* l3=lst_soma_p(l1,l2);
	lst_imprime(l3);
	
	printf("\n");
	
	Lista* l4=lst_conc_sem_primos(l1,l2);
	lst_imprime(l4);
	
	
	lst_libera(l1); lst_libera(l2);
	lst_libera(l3); lst_libera(l4);
	system("PAUSE");
	return 0;
}
