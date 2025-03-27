#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void calcule_borne_sup(int *tab, int taille){
	int dec = -1;
	for (int i = 0; i < taille; i++) {
		tab[i] += dec;
		dec = tab[i];
	}
}

int tire_non_equi(int *tab, int taille){
	int tire = rand()%100;
	int i = taille -1;
	/*while (i >= 0) {
		if (tire > tab[i]) break;
		i--;
	}
	i++;*/
	for (i = taille -1; tab[i] >= tire; i--);
	i++;
	printf("%d >= %d\n", tab[i], tire);
	return i;
}

int main() {
	srand(time(NULL));
	int tab[] = {17, 28, 50, 5};
	calcule_borne_sup(tab, 4);
	for (int i = 0; i < 4; i++) printf("%d, ", tab[i]);
	printf("\n");
	printf("%d", tire_non_equi(tab, 4));
	return 0;
}
