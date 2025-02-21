#include <stdio.h>
#include <stdlib.h>

int *fusion(int *tab1, int t1, int *tab2, int t2) {
	int *ntab = malloc(sizeof(int) * (t1+t2));
	int i_1 = 0;
	int i_2 = 0;
	for (int i = 0; i < t1+t2; i++) {
		if (i_1 < t1 && i_2 < t2) ntab[i] = tab1[i_1] < tab2[i_2] ? tab1[i_1++] : tab2[i_2++];
		else if (i_1 < t1) ntab[i] = tab1[i_1++];
		else ntab[i] = tab2[i_2++];
	}
	return ntab;
}

int main() {
	int tab1[6] = {1, 2, 4, 5, 7, 8};
	int tab2[5] = {0, 0, 3, 6, 9};
	int *ntab = fusion(tab1, 6, tab2, 5);
	for (int i = 0; i < 5+6; i++) printf("%d- %d\n", i, ntab[i]);
	return 0;
}
