#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adresse {
    int numero;
    char* rue;
    int code_postal;
} Adresse;

Adresse* creer_adresse(int n, char* r, int c) {
    Adresse* new = (Adresse*) malloc(sizeof(Adresse));

    new->numero = n;
    /* l'erreur dans ce code etait que new->rue n'etait pas assez grand pour contenir 'r'
     * de plus, le pointeur n'allait pas etre persistant, donc on a besoin de rajouter un malloc
     * pour la regler, je l'ai donc initialisee
     */
    new->rue = (char*) malloc(sizeof(char)*strlen(r));
    strcpy(new->rue, r);
    new->code_postal = c;

    return new;
}

int main(void) {
    Adresse* maison = creer_adresse(12, "manoeuvre", 15670);
    
    printf("Adresse courante : %d rue %s %d France\n", maison->numero, maison->rue, maison->code_postal);
    
    return 0;
}

