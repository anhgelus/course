#include "Chaine.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Chaines* lectureChaines(FILE* f){
    char s[256];
    char* err = fgets(s, 256, f);
    if (!err) return NULL;
    int nbChain;
    sscanf(s, "NbChain: %d", &nbChain);

    err = fgets(s, 256, f);
    if (!err) return NULL;
    int gamma;
    sscanf(s, "Gamma: %d", &gamma);

    Chaines* chains = (Chaines*) malloc(sizeof(Chaines));
    chains->nbChaines = nbChain;
    chains->gamma = gamma;
    
    for (int i = 0; i < nbChain; i++){
        err = fgets(s, 256, f);
        if (!err) {
            free(chains); // avoiding a memory leak
            return NULL;
        }
        CellChaine* chain = (CellChaine*) malloc(sizeof(CellChaine));
        chain->points = NULL;
        chain->suiv = chains->chaines; 
        chains->chaines = chain; 
        int nbPoints;
        sscanf(s, "%d %d %s", &chain->numero, &nbPoints, s);
        for (int j = 0; j < nbPoints; j++){
            CellPoint* point = (CellPoint*) malloc(sizeof(CellPoint));
            point->suiv = chain->points;
            chain->points = point;
            if (j < nbPoints-1) sscanf(s, "%lf %lf %s", &point->x, &point->y, s);
            else sscanf(s, "%lf %lf", &point->x, &point->y);
        }
    }
    return chains;
}

void ecrireChaines(Chaines* c, FILE* f){
    fprintf(f, "NbChain: %d\n", c->nbChaines); 
    fprintf(f, "Gamma: %d\n", c->gamma);
    CellChaine** chains = (CellChaine**) malloc(sizeof(CellChaine)*c->nbChaines);
    CellChaine* chain = c->chaines;
    for (int i = 0; i < c->nbChaines; i++){
        chains[i - c->nbChaines - 1] = chain;
        chain = chain->suiv;
    }
}
