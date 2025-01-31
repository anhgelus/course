#include <assert.h>

int signeProduit(int a, int b){
	if (a == 0 || b == 0) return 0;
	else if (
		(a < 0 && b > 0) || (a > 0 && b < 0)
	) return -1;
	return 1;
}

int main(){
	assert(signeProduit(0, 0) == 0);
	assert(signeProduit(1, 0) == 0);
	assert(signeProduit(0, -1) == 0);
	assert(signeProduit(1, 1) == 1);
	assert(signeProduit(-1, -1) == 1);
	assert(signeProduit(1, -1) == -1);
	assert(signeProduit(-1, 1) == -1);
	return 0;
}
