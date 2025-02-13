#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_VALEURS 20
#define VMIN -20
#define VMAX 20

int valeur_aleatoire(int min, int max){
	return min + rand()%(max+1-min);
}

void pos_neg_zero(int *neg, int *zero, int *pos, int v){
	if (v > 0) (*pos)++;
	else if (v < 0) (*neg)++;
	else (*zero)++;
}

int main(){
	srand(time(NULL));
	int neg = 0, pos = 0, zero = 0;
	for (int i = 0; i < NB_VALEURS; i++){
		int v = valeur_aleatoire(VMIN, VMAX);
		pos_neg_zero(&neg, &zero, &pos, v);
	}
	printf("valeurs:\n\t- positives: %d\n\t- nulles: %d\n\t- négatives: %d\n", pos, zero, neg);
	return 0;
}

