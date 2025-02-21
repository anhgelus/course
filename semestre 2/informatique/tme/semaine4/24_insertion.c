#include <stdio.h>

int indiceInsert(int *tab, int taille, int nbEl, int el){
	if (nbEl >= taille) return -1; 
	int i = 0;
	while (i < nbEl && tab[i] <= el) {
		if (tab[i] == el) return -1;
		i++;
	}
	return i;
}

int insertElt(int el, int *tab, int taille, int *nb) {
	int ind = indiceInsert(tab, taille, *nb, el);
	if (ind == -1) return 0;
	int prev = 0;
	int set = 0;
	for (int i = ind; i < *nb+1; i++){
		if (set == 0) {
			set = 1;
			prev = tab[i];
			tab[i] = el;
		} else {
			int t = prev;
			prev = tab[i];
			tab[i] = t;
		}
	}
	(*nb)++;
	return 1;
}

int main(){
	int tab[10] = {0, 1, 3, 5};
	int taille = 10;
	int nb = 4;
	printf("%d\n\n", insertElt(-1, tab, taille, &nb));
	for (int i = 0; i < taille; i++){
		printf("%d. %d\n", i, tab[i]);
	}
}
