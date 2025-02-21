#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void init_temp(float tab[31]){
	for (int i = 0; i < 31; i++)tab[i] = (float) (rand()%500-200)/10;
}

float moy_temp(float tab[31]){
	float s = 0;
	for (int i = 0; i < 31; i++) s += tab[i];
	return s / 31;
}

float moy_temp_neg(float tab[31]){
	float s = 0;
	int n = 0;
	for (int i = 0; i < 31; i++) {
		if (tab[i] < 0){
			s += tab[i];
			n++;
		}
	}
	if (n == 0) {
		return 1;
	}
	return s/n;
}

int main() {
	srand(time(NULL));
	float tab[31];
	init_temp(tab);
	for (int i = 0; i < 31; i++) printf("%.2f\t", tab[i]);
	printf("\n%.2f\n", moy_temp(tab));
	float v = moy_temp_neg(tab);
	if (v > 0) printf("Aucune température en dessous de zero.");
	else printf("%.2f", v);
	return 0;
}
