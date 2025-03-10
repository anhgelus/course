#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NB_AMIS 4
#define NB_JOURS 7

void init_tab(float tab[NB_AMIS][NB_JOURS]){
	for (int i = 0; i < NB_AMIS; i++) {
		for (int j = 0; j < NB_JOURS; j++) tab[i][j] = 0;
	}
}

void random_tab(float tab[NB_AMIS][NB_JOURS], int j) {
	int a = rand()%NB_AMIS;
	int v = rand()%21+30;
	tab[a][j] = v;
	for (int i = 0; i < NB_AMIS; i++) {
		if (i != a) tab[i][j] = (float) v/(-NB_AMIS+1);
	}
}

void show_tab(float tab[NB_AMIS][NB_JOURS]){
	printf("Jour/Ami||\t");
	for (int i = 0; i < NB_AMIS; i++) printf("%d\t|\t", i+1);
	printf("\n");
	for (int i = 0; i < NB_AMIS*18; i++) printf("-");
	printf("\n");
	for (int j = 0; j < NB_JOURS;j++){
		for (int i = 0; i < NB_AMIS; i++) {
			if (i == 0) printf("%d\t||\t", j+1);
			printf("%.2f\t|\t", tab[i][j]);
			if (i == NB_AMIS-1) printf("\n");
		}	
	}
}

void show_solde(float tab[NB_AMIS][NB_JOURS], int a){
	float s = 0;
	for (int j = 0; j < NB_JOURS; j++) s += tab[a][j];
	printf("Ami %d a pour solde %.02f\n", a, s);
}

int main() {
	float tab[NB_AMIS][NB_JOURS] = {};
	srand(time(NULL));
	init_tab(tab);
	for (int d = 0; d < NB_JOURS; d++)	random_tab(tab, d);
	show_tab(tab);
	for (int i = 0; i < NB_AMIS; i++) show_solde(tab, i);
	return 0;
}

