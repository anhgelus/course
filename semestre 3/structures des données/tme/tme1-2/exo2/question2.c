#include "question1.h"
#include <stdio.h>

/* Calcule la somme des carrés des différences entre les éléments des tableaux pris deux à deux (version quadratique) */
int diff_quad(int *t, int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            sum += (t[i] - t[j])*(t[i] - t[j]);
        }
    }
    return sum;
}

/* Calcule la somme des carrés des différences entre les éléments des tableaux pris deux à deux (version linéaire)
 *
 * Après diverses simplifications, on obtient que sum(sum(T_i-T_j)^2) est egale à 2 * sum(n*T_i*T_j - T_i^2)
 * */
int diff_lin(int *t, int n){
    int sum = 0;
    int sub_sum = 0;
    for (int i = 0; i < n; i++){
        sum += n*t[i]*t[i];
        sub_sum += t[i];
    }
    return 2 * (sum - sub_sum * sub_sum); 
}

int main(void){
    int n = 10;
    int *t = alloue_tableau(n);
    remplir_tableau(t, n, 100);
    afficher_tableau(t, n);

    printf("quadratique: %d\n",diff_quad(t,n));
    printf("linéaire: %d\n",diff_lin(t,n));

    return 0;
}
