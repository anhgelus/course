#include "liste_entiers.h"
#include <stdio.h>

int main() {
  cellule_t *ma_liste=list(1, list(3, list(0, NULL)));
  int size = 0;
  cellule_t *t = ma_liste;
  for (size = 0; t; size++) {
	  printf("val %d\n", t->donnee);
	  t = t->suivant;
  }
  printf("size %d\n", size);
  printf("before\n");
  for (int i = 0; i < size; i++) printf("pos %d = %d\n", i, Renvoyer_val_element_pos(i, ma_liste));
  printf("after\n");
  return 0;
}
