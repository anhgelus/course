#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct{
    int size;
    int* content;
} Matrice;

Matrice* alloue_matrice(int n){
    int** content = (int**) malloc(n*n*sizeof(int));
    Matrice* m = (Matrice*) malloc(sizeof(Matrice));
    m->content = content;
    return m
}

void desalloue_matrice(Matrice* m){
    free(m->content);
    free(m);
}

void remplir_matrice(Matrice* m, int max){
    srand(time(null));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            m->content[i][j] = rand()%max;
        }
    }
}

void affiche_matrice(Matrice* m){
    printf("[");
    for (int i = 0; i < n; i++){
        printf(" [");
        for (int j = 0; j < n; j++){
            printf("%d ", m->content[i][j]);
        }
        printf("]%c", i != n -1 ? '\n' : ' ');
    }
    printf("]\n");
}

Matrice* produit_matrice(Matrice* m1, Matrice* m2){
    if (m1->size != m2->size){
        return NULL;
    }
    Matrice* prod = alloue_matrice(m1->size);
    for (int i = 0; i < m1->size; i++){
        for (int k = 0; k < m1->size; k++){
            prod->content[i][k] = 0;
            for (int j = 0; j < m1->size; j++){
                prod->content[i][k] += m1->content[i][j]*m2->content[j][k];
            }
        }
    }
    return prod;
}

/* Reste en O(n3), mais est plus rapide que produit_matrice car on arrete les boucles plus tot */
Matrice* produit_matrice_trian(Matrice* m_sup, Matrice* m_inf){
    if (m_sup->size != m_inf->size){
        return NULL;
    }
    Matrice* prod = alloue_matrice(m_sup->size);
    for (int i = 0; i < m_sup->size; i++){
        for (int k = 0; k < m_sup->size; k++){
            prod->content[i][k] = 0;
            for (int j = i; j < m_sup->size; j++){
                prod->content[i][k] = m_sup->content[i][j]*m_inf->content[j][k];
            }
        }
    }
    return prod;
}
