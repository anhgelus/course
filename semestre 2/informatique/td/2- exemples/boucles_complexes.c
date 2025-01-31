#include <stdio.h>
#include <assert.h>

void afficheBilletsPieces(int m){
	int r = m;
	int billets = r/5;
	r = r%5;
	int pieces2 = r/2;
	r = r%2;
	int pieces1 = r;
	printf("%d€ = %d * 5€ + %d * 2€ + %d * 1€", m, billets, pieces2, pieces1);
}

void afficheBilletsPiecesMultiple(int m){
	for (int billets = m/5; billets >= 0; billets--){
		int av = m - billets*5;
		for (int p2 = av/2; p2 >= 0; p2--){
			int av2 = av - p2*2;
			assert(billets*5+p2*2+av2 == m);
			printf("%d€ = %d*5€ + %d*2€ + %d*1€\n", m, billets, p2, av2);
		}
	}
}

int main(){
	afficheBilletsPiecesMultiple(23);
	return 0;
}
