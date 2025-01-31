#include <math.h>
#include <stdio.h>

int discriminant(int a, int b, int c){
	return b*b-4*a*c;
}

void afficheRacines(int a, int b, int c){
	int disc = discriminant(a,b,c);
	if (disc > 0) {
		float sq = sqrt(disc);
		printf("Racine 1 : %f\nRacine 2 : %f\n", (-b-sq)/(2*a), (-b+sq)/(2*a));
	} else if (disc == 0) {
		printf("Racine double : %f\n", (-b)/(float) (2*a));
	} else {
		printf("Pas de racine réelle\n");
	}
}

int main(){
	afficheRacines(1, 1, 1);
	afficheRacines(1, 1, -1);
	afficheRacines(-1, 1, -1);
	afficheRacines(-1, 1, 1);
	afficheRacines(1, 2, 1);
	afficheRacines(2, 4, 2);
	return 0;
}
