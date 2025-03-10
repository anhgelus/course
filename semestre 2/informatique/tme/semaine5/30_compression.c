#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 2
#define MAX 15

int init_tab(int tab[MAX+1]) {
	int size = rand()%(MAX-MIN+1)+MIN;
	for (int i = 0; i < size; i++) {
		tab[i] = rand()%2;
	}
	tab[size] = -1;
	return size;
}

void compress_tab(int tab_brut[], int tab_compress[]){
	int j = 0;
	int last = -1;
	int cnt = 0;
	for (int i = 0; tab_brut[i] != -1; i++) {
		if (last == -1 || tab_brut[i] != last) {
			if (last != -1) {
				int id = j++;
				tab_compress[id*2] = cnt;
				tab_compress[id*2+1] = last;
			}
			last = tab_brut[i];
			cnt = 0;
		}
		cnt++;
	}
	if (last != -1) {
		int id = j++;
		tab_compress[id*2] = cnt;
		tab_compress[id*2+1] = last;
	}
	tab_compress[j*2] = -1;
}

int compare(int tab_brut[], int tab_compress[]){
	int j = 0;
	for (int i = 0; tab_compress[i] != -1; i += 2) {
		int n = tab_compress[i];
		int v = tab_compress[i+1];
		for (int cnt = 0; cnt < n; cnt++) {
			if (tab_brut[j++] != v) return 0;
		}
	}
	return 1;
}

int main(){
	srand(time(NULL));
	int tab[MAX+1] = {};
	int tab_compress[MAX+1] = {};
	init_tab(tab);
	compress_tab(tab, tab_compress);
	for (int i = 0; tab[i] != -1; i++) printf("%d, ", tab[i]);
	printf("\n");
	for (int i = 0; tab_compress[i] != -1; i += 2) printf("%d:%d, ", tab_compress[i], tab_compress[i+1]);
	printf("\n");
	printf("%s", compare(tab, tab_compress) ? "True" : "False");
	return 0;
}
