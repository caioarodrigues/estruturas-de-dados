#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"
#include "lista.h"

int main(void){
	ArvB* arv_1 = arvb_cria_vazia();
	arv_1=arvb_insere(arv_1,43);
	arv_1=arvb_insere(arv_1,51);
	arv_1=arvb_insere(arv_1,21);
	arv_1=arvb_insere(arv_1,4);
	arv_1=arvb_insere(arv_1,45);
	arv_1=arvb_insere(arv_1,29);
	arv_1=arvb_insere(arv_1,3);
	arv_1=arvb_insere(arv_1,23);
	
	ArvB* arv_2 = arvb_cria_vazia();
	arv_2=arvb_insere(arv_2,45);
	arv_2=arvb_insere(arv_2,26);
	arv_2=arvb_insere(arv_2,23);
	arv_2=arvb_insere(arv_2,31);
	arv_2=arvb_insere(arv_2,47);
	
	Lista* L1=arvs_elem_comuns_lista(arv_1,arv_2);
	lst_imprime(L1);
	Lista* L2=arvs_elem_camadas_lista(arv_1,arv_2);
	lst_imprime(L2);
	
	lst_libera(L1); 
	lst_libera(L2);
	arvb_libera(arv_1); 
	arvb_libera(arv_2);
	
	system("PAUSE");
	return 0;
}
