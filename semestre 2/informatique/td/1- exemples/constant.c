#include <stdio.h>

#define TNORMAL 11.4
#define TMOINS 4.5
#define TMOINS26S 4.9
#define TMOINS26WE 7.9
#define TMATIN 7.1

float prixPlace(int age, int jour, float h){
	if (age < 14) return TMOINS;
	if (age < 26 && jour < 6) return TMOINS26S;
	if (h < 11 && h > 8) return TMATIN;
	if (age < 26) return TMOINS26WE;
	return TNORMAL;
}

int main(){
	printf("%.2f€ prix pour %d ans le %de jour de la semaine à %.1fh\n", prixPlace(13, 5, 13), 13, 5, 13.0);
	printf("%.2f€ prix pour %d ans le %de jour de la semaine à %.1fh\n", prixPlace(14, 5, 13), 14, 5, 13.0);
	printf("%.2f€ prix pour %d ans le %de jour de la semaine à %.1fh\n", prixPlace(14, 6, 13), 14, 6, 13.0);
	printf("%.2f€ prix pour %d ans le %de jour de la semaine à %.1fh\n", prixPlace(14, 6, 10), 14, 6, 10.0);
	printf("%.2f€ prix pour %d ans le %de jour de la semaine à %.1fh\n", prixPlace(28, 6, 10), 28, 6, 10.0);
	printf("%.2f€ prix pour %d ans le %de jour de la semaine à %.1fh\n", prixPlace(28, 6, 15), 28, 6, 15.0);
	return 0;
}

