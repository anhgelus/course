#include <assert.h>
#define ADU 22.7
#define KID 10.75
#define FAMILLY 57.8
#define COMPARE_FLOAT_PRECISION 0.00001

float prixEntree(int adus, int kids){
	float no_familly = adus * ADU + kids * KID;
	float with_familly = FAMILLY;
	int r_adus = adus - 2;
	int r_kids = kids - 3;
	if (r_adus > 0){
		with_familly += r_adus * ADU;
	}
	if (r_kids > 0){
		with_familly += r_kids * KID;
	}
	if (no_familly < with_familly) return no_familly;
	return with_familly;
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
	assert(compareFloat(prixEntree(1, 3), ADU + 3*KID, COMPARE_FLOAT_PRECISION));
	assert(compareFloat(prixEntree(0, 1), KID, COMPARE_FLOAT_PRECISION));
	return 0;
}
