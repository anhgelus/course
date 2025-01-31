#include <assert.h>

int somme_carres_while(int m, int n){
	int s = 0, i = m;
	while (i <= n){
		s += i*i;
		i++;
	}
	return s;
}

int somme_carres_for(int m, int n){
	int s = 0;
	for (int i = m; i <= n; i++){
		s += i*i;
	}
	return s;
}

int main(){
	assert(somme_carres_while(0, 5) == somme_carres_for(0, 5));
	assert(somme_carres_while(3, 5) == somme_carres_for(3, 5));
	assert(somme_carres_while(15, 25) == somme_carres_for(15, 25));
	return 0;
}
