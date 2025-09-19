#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "question1.h"

/* j'ai fait le choix d'allouer un tableau et de le renvoyer, car ca me semble plus naturel de proceder comme ça */
int *alloue_tableau(int n){
    return (int *)malloc(sizeof(int)*n);
}

int *desalloue_tableau(int *t, int n){
    free(t);
}

void remplir_tableau(int *t, int n, int V){
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        t[i] = rand()%V;
    }
}

void afficher_tableau(int *t, int n){
    printf("[");
    for (int i = 0; i < n; i++){
        printf("%d ", t[i]);
    }
    printf("]\n");
}
