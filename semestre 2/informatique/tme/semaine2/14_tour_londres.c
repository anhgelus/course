#include <assert.h>
#define ADU 22.7
#define KID 10.75
#define FAMILLY 57.8
#define MAX_ADU_FAMILLY 2
#define MAX_KID_FAMILLY 3
#define COMPARE_FLOAT_PRECISION 0.00001

float prixEntree(int adus, int kids){
	int max_familly = 0;
	int r_adus = adus;
	int r_kids = kids;
	do {
		r_adus -= MAX_ADU_FAMILLY;
		r_kids -= MAX_KID_FAMILLY;
		max_familly++;	
	} while (r_adus > 0 || r_kids > 0);
	float min = -1;
	for (int f = 0; f <= max_familly; f++){
		int r_adus = adus - MAX_ADU_FAMILLY*f;
		int r_kids = kids - MAX_KID_FAMILLY*f;
		float t = f*FAMILLY;
	    if (r_adus > 0) t += r_adus * ADU;
	    if (r_kids > 0) t += r_kids * KID;
		if (min == -1 || t < min) {
			min = t;
		}
	}
	return min;
}

int compareFloat(float f1, float f2, float eps){
	/* Prend trois floats (f1, f2 et eps) et renvoie |f1-f2|<eps ; est une comparaison de deux
	 * floats à epsilon près */
	float diff = f1 - f2;
	if (diff < 0) diff = - diff;
	return diff < eps;
}

int main(){
	assert(compareFloat(prixEntree(2, 3), FAMILLY, COMPARE_FLOAT_PRECISION));
	assert(compareFloat(prixEntree(2, 2), FAMILLY, COMPARE_FLOAT_PRECISION));
	assert(compareFloat(prixEntree(2, 1), 2*ADU + KID, COMPARE_FLOAT_PRECISION));
	assert(compareFloat(prixEntree(6, 3), 4*ADU + FAMILLY, COMPARE_FLOAT_PRECISION));
	assert(compareFloat(prixEntree(1, 3), 1*ADU + 3*KID, COMPARE_FLOAT_PRECISION));
	assert(compareFloat(prixEntree(5, 7), 2*FAMILLY + ADU + KID, COMPARE_FLOAT_PRECISION));
	assert(compareFloat(prixEntree(6, 8), 3*FAMILLY, COMPARE_FLOAT_PRECISION));
	assert(compareFloat(prixEntree(10, 0), 227, COMPARE_FLOAT_PRECISION));
	assert(compareFloat(prixEntree(0, 4), 43, COMPARE_FLOAT_PRECISION));
	return 0;
}
