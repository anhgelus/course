#include <assert.h>

void echange(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void tri(int *a, int *b){
	if (*a <= *b) return;
	echange(a,b);
}

void tri_3(int *a, int *b, int *c){
	tri(a, b);
	tri(a, c);
	tri(b, c);
}

int main(){
	int a = 2, b = 5;
	echange(&a, &b);
	assert(a == 5);
	assert(b == 2);
	tri(&a, &b);
	assert(a == 2);
	assert(b == 5);
	int c = 8;
	a = 4; b = 2;
	tri_3(&a, &b, &c);
	assert(a == 2 && b == 4 && c == 8);
	a = 2; b = 4; c = 8;
	tri_3(&a, &b, &c);
	assert(a == 2 && b == 4 && c == 8);
	a = 8; b = 4; c = 2;
	tri_3(&a, &b, &c);
	assert(a == 2 && b == 4 && c == 8);
}
