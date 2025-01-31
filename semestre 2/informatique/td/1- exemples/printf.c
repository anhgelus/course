#include <stdio.h>

float mult(int op1, float op2){
	return op1 * op2;
}

int main(){
	int op1 = 3;
	float op2 = 2.7;

	printf("%d * %f = %f\n", op1, op2, mult(op1, op2));

	return 0;
}
