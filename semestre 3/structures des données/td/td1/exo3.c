#include <stdlib.h>

void main(void){
    /* le cast est très important pour le compilateur et le linter */
    int *t = (int *) malloc(sizeof(int)*5) // car on souhaite un tableau de taille 5
    /* acces à la 4e valeur */
    int four = *(t+3)
    free(t)

    /* pour recuperer la taille d'un tableau, on est oblige de la garder qlq part en memoire
     * on peut stocker la taille du tableau dans la premiere case (pas une bonne idee)
     * on rajoute un caractere de fin (pas une bunne idee non plus, de mon pov en tout cas)
     * on construit un struct contenant le tableau et sa taille
     */
}
