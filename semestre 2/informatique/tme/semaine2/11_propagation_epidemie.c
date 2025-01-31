#include <assert.h>
#include <stdio.h>

int jours(int infected, int pop, float percentage){
	int n = 1, c = 0;
	while (n / (float) pop < percentage/100){
		n += infected * n;
		c++;
	}
	return c;
}

float pourcentage(int infected, int pop, int day){
	int n = 1, c = 0;
	while (c < day && n <= pop){
		n += infected*n;
		c++;
	}
	if (n >= pop) return 100;
	return 100*n/ (float) pop;
}

int eps_pres(float a, float b, float eps){
	float v = a - b;
	if (v < 0) v = -v;
	return v < eps;
}

int main(){
	assert(jours(5, 10000, 100) == 6);
	assert(jours(5, 10000, 50) == 5);
	assert(jours(5, 10000, 25) == 5);
	assert(jours(5, 10000, 10) == 4);
	
	assert(eps_pres(pourcentage(5, 10000, 2), 0.36, 0.001));
	assert(eps_pres(pourcentage(5, 10000, 3), 2.16, 0.001));
	assert(eps_pres(pourcentage(5, 10000, 4), 12.96, 0.001));
	assert(eps_pres(pourcentage(5, 10000, 5), 77.76, 0.001));
	assert(eps_pres(pourcentage(5, 10000, 6), 100.00, 0.001));
	return 0;
}
