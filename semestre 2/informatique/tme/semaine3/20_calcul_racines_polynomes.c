#include <stdio.h>
#include <math.h>

int nb_racines(int a, int b, int c){
	float delta = b*b-4*a*c;
	if (delta > 0) return 2;
	else if (delta == 0) return 1;
	return 0;
}

int nb_racines_delta(int a, int b, int c, float*delta){
	*delta = b*b-4*a*c;
	if (*delta > 0) return 2;
	else if (*delta == 0) return 1;
	return 0;
}

int racines(int a, int b, int c, float*r1, float*r2){
	float delta;
	int nb = nb_racines_delta(a, b, c, &delta);
	*r1 = (-b-sqrt(delta))/(2*a);
	*r2 = (-b+sqrt(delta))/(2*a);
	return nb;
}

void affiche_polynome(int a, int b, int c){
	printf("Polynome : ");
	if (a == -1) printf("-");
	else if (a != 1) printf("%d", a);
	printf("x*x");

	if (b != 0) {
		printf(" ");
		if (b == -1) printf("-");
		else if (b != 1 && b > 0) printf("+%d", b);
		else if (b != 1 && b < 0) printf("%d", b);
		printf("x");
	}

	if (c != 0) {
		printf(" ");
		if (c > 0) printf("+%d", c);
		else if (c < 0) printf("%d", c);
	}
	printf("\n");
}

void affiche_racine(int a, int b, int c){
	float r1 = 1.0, r2 = 1.0;

	int nb_r = racines(a, b, c, &r1, &r2);
	if (nb_r == 2) printf("Le polynome a 2 racines : %.3f et %.3f\n", r1, r2);
	else if (nb_r == 1) printf("Le polynome a une racine double : %.3f\n", r1);
	else printf("Le polynome n'a pas de racine reelle.\n");
}

int main(){
	printf("\n\n=========================================================\n\n");
	int a = 4, b = 4, c = 1;
	affiche_polynome(a, b, c);
	affiche_racine(a, b, c);
	printf("\n");

	a = 4; b = 6; c = 1;
	affiche_polynome(a, b, c);
	affiche_racine(a, b, c);
	printf("\n");

	a = -7; b = -5; c = -1;
	affiche_polynome(a, b, c);
	affiche_racine(a, b, c);
	return 0;
}
