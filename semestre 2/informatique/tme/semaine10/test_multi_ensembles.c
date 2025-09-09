#include <stdio.h>
#include "multi_ensembles.h"

element_t *CreationMultiEnsemble(int deb, int n, int freq){
  element_t *liste=NULL;
  int i;
  
  for (i=deb+n-1; i >=deb; i--) {
    liste=Ajout_tete_ensemble(liste,i,freq);
  }
  return liste;
}

int main() {
	element_t *ensemble1= CreationMultiEnsemble(1,20,1);
	element_t *ensemble2= CreationMultiEnsemble(5,10,2);
	Affiche_ensemble(ensemble1);
	printf("====\n");
	Affiche_ensemble(ensemble2);
	printf("====\n");
	Affiche_ensemble(Union(ensemble1, ensemble2));
	printf("====\n");
	Affiche_ensemble(Union_triee(ensemble1, ensemble2));
	printf("====\n");
	Affiche_ensemble(Union_triee_rec(ensemble1, ensemble2));
	return 0;
}
