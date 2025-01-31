#include <assert.h>

int plusGrand(int a, int b, int c){
	int max = a;
	if (max < b){
		max = b;
	}
	if (max < c) {
		max = c;
	}
	return max;
}

int plusGrandParmisCinq(int a, int b, int c, int d, int e){
	return plusGrand(plusGrand(a, b, c), d, e);
}

int main(){
	assert(plusGrand(1, 2, 3) == 3);
	assert(plusGrand(4, 2, 3) == 4);
	assert(plusGrand(4, 5, 3) == 5);
	assert(plusGrandParmisCinq(1, 2, 3, 4, 5) == 5);
	assert(plusGrandParmisCinq(6, 2, 3, 4, 5) == 6);
	assert(plusGrandParmisCinq(6, 7, 3, 4, 5) == 7);
	assert(plusGrandParmisCinq(6, 7, 8, 4, 5) == 8);
	assert(plusGrandParmisCinq(6, 7, 8, 9, 5) == 9);
	return 0;
}
