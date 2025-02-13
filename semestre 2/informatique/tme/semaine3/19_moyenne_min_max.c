#include <stdio.h>
#include <assert.h>
#define VAL1 12
#define VAL2 7
#define VAL3 5
#define VAL4 9

void min_max(int *min, int *max, int v){
	if (v > *max) *max = v;
	if (v < *min) *min = v;
}

void stats(float*moy, int*max, int*min, int a, int b, int c, int d){
	if (a < 0) return;
	int sum = a;
	*min = a;
	*max = a;
	if (b < 0) {
		*moy = a;
		return;
	}
	sum += b;
	min_max(min, max, b);
	if (c < 0) {
		*moy = sum/ (float) 2;
		return;
	}
	sum += c;
	min_max(min, max, c);
	if (d < 0){
		*moy = sum/ (float) 3;
		return;
	}
	sum += d;
	min_max(min, max, d);
	*moy = sum/ (float) 4;
}

void afficher_resultat(float moyenne, int min, int max){
	printf("max = %d, min = %d, moy = %.2f\n",max,min,moyenne);
}

int main(){
	float moy = -1;
	int min, max = -1;

	stats(&moy, &max, &min, VAL1, VAL2, VAL3, VAL4);

	afficher_resultat(moy, min, max);
	return 0;
}
