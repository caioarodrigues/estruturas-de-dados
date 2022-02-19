#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"

int main(void){
	
	ArvB* arvA = arvb_cria_vazia();
	arvA=arvb_insere(arvA,43);
	arvA=arvb_insere(arvA,51);
	arvA=arvb_insere(arvA,21);
	arvA=arvb_insere(arvA,4);
	arvA=arvb_insere(arvA,45);
	arvA=arvb_insere(arvA,29);
	arvA=arvb_insere(arvA,3);
	arvA=arvb_insere(arvA,23);
	arvA=arvb_remove(arvA,4);
	printf("Nos subarvs dif null %d\n",subarvs_difnull(arvA));
	printf("Nos subarvs igual alt. %d\n",subarvs_ig_alt(arvA));
	printf("Folhas com val. primos %d\n", folhas_primo(arvA));
	
	printf("------\n");
	impressao_arv_niveis(arvA);
	printf("------\n");
	
	arvb_libera(arvA);
	
	system("PAUSE");
	return 0;
}

