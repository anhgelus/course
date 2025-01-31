#include <assert.h>

int signeSomme(int a, int b){
	if (a > -b){
		return 1;
	} else if (a == -b){
		return 0;
	}
	return -1;
}

int main(){
	assert(signeSomme(2, -1) == 1);
	assert(signeSomme(-1, 1) == 0);
	assert(signeSomme(-2, 1) == -1);
	return 0;
}
