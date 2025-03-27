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
	int last = -1;
	int cnt = 0;
	int w = 0;
	for (int i = 0; tab_brut[i] != -1; i++) {
		if (last == -1 || tab_brut[i] != last) {
			if (last != -1) {
				if (cnt == 1) {
					tab_compress[w] = last;
				} else {
					tab_compress[w] = cnt;
					tab_compress[++w] = last;
				}
				w++;
			}
			last = tab_brut[i];
			cnt = 0;
		}
		cnt++;
	}
	if (last != -1) {
		if (cnt == 1) {
			tab_compress[w] = last;
		} else {
			tab_compress[w] = cnt;
			tab_compress[++w] = last;
		}
		w++;
	}
	tab_compress[w] = -1;
}

void decompress(int tab_brut[], int tab_compress[]) {
	int i = 0;
	int w = 0;
	while (tab_compress[i] != -1) {
		int v = tab_compress[i];
		if (v < 2) {
			tab_brut[w++] = v;
		} else {
			int ins_v = tab_compress[++i];
			for (int j = 0; j < v; j++) {
				tab_brut[w++] = ins_v;
			}
		}
		for (int j = 0; j < w; j++) printf("%d, ", tab_brut[j]);
		printf("\n");
		i++;
	}
	tab_brut[w] = -1;
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
	int tab1[]={0,0,1,1,1,1,0,1,1,1,0,0,1,0,0,0,0,-1};
	//int tab1[] = {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,-1};
	for (int i = 0; tab1[i] != -1; i++) printf("%d, ", tab1[i]);
	printf("\n");
	int tab2[20];
	compress_tab(tab1,tab2);
	int tab3[20];
	decompress(tab3, tab2);
	int i;
	for (i = 0; tab1[i] != -1 && tab3[i] != -1; i++) {
		printf("%d - %d\n", tab1[i], tab3[i]);
	}
	printf("%d\n", i);
	i = 0;
	while (tab2[i] != -1) {
		int v = tab2[i];
		if (v < 2) {
			printf("%d ", v);
		} else {
			printf("%d:%d ", v, tab2[++i]);
		}
		i++;
	}
	printf("\n");
	/*int tab[MAX+1] = {};
	int tab_compress[MAX+1] = {};
	init_tab(tab);
	compress_tab(tab, tab_compress);
	for (int i = 0; tab[i] != -1; i++) printf("%d, ", tab[i]);
	printf("\n");
	for (int i = 0; tab_compress[i] != -1; i += 2) printf("%d:%d, ", tab_compress[i], tab_compress[i+1]);
	printf("\n");
	printf("%s", compare(tab, tab_compress) ? "True" : "False");*/
	return 0;
}
