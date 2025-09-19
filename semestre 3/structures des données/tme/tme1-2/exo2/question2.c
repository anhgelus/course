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
 * On a que sum(sum(x_ix_j)) = (sum(x_i))^2.
 * En developpant, on obtient : sum(sum(T_i^2-2*T_i*T_j+T_j^2))
 * i.e. : sum(sum(T_i^2))-sum(sum(2*T_i*T_j))+sum(sum(T_j^2))
 * i.e. : sum(sum(T_i^2))-2*sum(sum(T_i*T_j))+sum(sum(T_j^2))
 * i.e. : 2*sum(T_i^2)-2*sum(sum(T_i*T_j))+2*sum(T_j^2)
 * i.e. : 2*sum(T_i^2)-2*(sum(T_i))^2+2*sum(T_j^2)
 * Ainsi : 2*(2*sum(T_i^2)-(sum(T_i))^2)
 * */
int diff_lin(int *t, int n){
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++){
        sum1 += t[i]*t[i];
        sum2 += t[i];
    }
    return 2*(2*sum1-sum2*sum2);
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
