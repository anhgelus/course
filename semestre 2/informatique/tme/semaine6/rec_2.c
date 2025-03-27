#include <stdio.h>
int recherche_rec_aux (int* tab, int n,int i, int v) {
    if (i == n) return -1;
    if (tab[i] == v) return i;
    return recherche_rec_aux(tab, n, i+1, v);
}

int recherche_rec (int tab[], int taille, int elem) {
    return recherche_rec_aux (tab, taille, 0, elem);
}

int main() {
	int arr[] = {1, 2, 3};
	printf("%d\n", recherche_rec(arr, 3, 0));
	return 0;
}
