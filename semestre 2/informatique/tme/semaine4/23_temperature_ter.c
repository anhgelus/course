#include <stdio.h>

float moy_temp(float *tab, int nbj){
	float s = 0;
	for (int i = 0; i < nbj; i++) s += tab[i];
	return s / nbj;
}

float moy_temp_gel(float *tab, int nbj){
	float s = 0;
	int n = 0;
	for (int i = 0; i < nbj; i++) {
		if (tab[i] < 0){
			s += tab[i];
			n++;
		}
	}
	if (n == 0) return 1;
	return s/n;
}

int main() {
   float tab[31] = {-4.8, 0.5, 2.2, -4.0, -2.6, -9.7, 8.8, 6.9, -1.8};
   float moy_gel;
   int i, nbj = 9;
   
   /*scanf("%d", &nbj);
   for (i = 0; i < nbj; i++) {
      scanf("%f", &tab[i]);
   }*/
   printf("temperature moyenne sur les %d derniers jours : %.2f\n", nbj, moy_temp(tab, nbj));
   moy_gel = moy_temp_gel(tab, nbj);
   printf("moy_gel %f", moy_gel);
   if (moy_gel <= 0) {
      printf("temperature moyenne sur les jours de gel : %.2f\n", moy_gel);
   }
   else {
      printf("Aucune temperature au-dessous de zero.\n");
   }
   return 0;
}
