#include <assert.h>

int alternative(int n1, int n2, int n3){
	int res;
	if (n1 > 8) res = 3;
	else if (n3 == 20) res = 2;
	else if (n2 >= 10 && n3 >= 10) res = 1;
	else res = 0;
	return res;
}

int main(){
	assert(alternative(-4, 3, 20) == 2); // teste de la branche n3 == 20
	assert(alternative(9,-2,20) == 3); // teste de la branche n1 > 8
	assert(alternative(-5, 15, 1098765) == 1); // teste de la branche n2 >= 10 && n3 >= 10
	assert(alternative(4, 8, 23) == 0); // teste des autres cas
	return 0;
}
