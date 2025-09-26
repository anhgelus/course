#include "LDC.h"

/* N is the number of guichet */
#define N 15

ChainedList** creerBureauPoste(){
    ChainedList** postes = (ChainedList**) malloc(N*sizeof(ChainedList));
    return postes;
}

void afficherPoste(ChainedList** guichets){
    for (int i = 0; i < N; i++){
        afficher(guichets[i]);
    }
}

ChainedList* ajouterAuGuichet(ChainedList* guichet, int id){
    return insererEnFin(guichet, creerElement(id));
}

ChainedList* appelerAuGuichet(ChainedList* guichet){
    return supprimerTete(guichet);
}

