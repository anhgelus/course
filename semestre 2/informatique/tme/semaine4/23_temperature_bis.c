#include <stdio.h>

void conversion(float *tabC, int *tabF, int n) {
    for (int i = 0; i < n; i++){
        tabC[i] =(float) 5/9 * (tabF[i] - 32);
    }
}

int main() {
   int tabF[31]= {27, 29, 20, 25, 27, 23, 37, 29, 23, 46, 50, 39, 32, 34, 27};
   float tabC[31];
   int i, nb = 15;
   
   /*scanf("%d", &nb);
   for (i = 0; i < nb; i++) {
      scanf("%d", &tabF[i]);
   }*/
   
   conversion(tabC, tabF, 31);
   for (i = 0; i < nb; i++) {
      printf("%.1f  ", tabC[i]);
   }
   printf("\n");
   return 0;
}

