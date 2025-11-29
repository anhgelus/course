#include "Hachage.h"
#include "Reseau.h"
#include <math.h>
#include <stdlib.h>

int cle(double x, double y){
    return y + (x+y)*(x+y+1)/2;
}

int hachage(int M, double k){
    float A = (sqrt(5)-1)/2;
    return floor(M*(k*A-floor(k*A)));
}

TableHachage* initHachage(int M){
    TableHachage* hash = malloc(sizeof(TableHachage));
    hash->len = M;
    hash->values = malloc(M*sizeof(CellNoeud));
    for (int i = 0; i < M; i++) hash->values[i] = NULL;
    return hash;
}

/*void freeHachage(TableHachage* hash){
    for (int i = 0; i < hash->len; i++) freeCellHash(hash->values[i]);
    free(hash->values);
    free(hash);
}*/

void insertHachage(TableHachage* H, CellNoeud* cell){
    int key = hachage(H->len, cle(cell->nd->x, cell->nd->y));
    cell->suiv = H->values[key];
    H->values[key] = cell;
}

Noeud* rechercheCreeNoeudHachage(Reseau* R, TableHachage* H, double x, double y){
    int key = cle(x, y);
    CellNoeud* val = H->values[hachage(H->len, key)];
    // je suppose que les clés sont uniques
    while (val && (val->nd->x != x || val->nd->y != y)) val = val->suiv;
    if (val) return val->nd;
    // on a besoin de créer le nœud
    Noeud* node = rechercheCreeNoeudListe(R, x, y);
    CellNoeud* cell = malloc(sizeof(CellNoeud));
    cell->nd = node;
    insertHachage(H, cell);
    return node;
}

Reseau* reconstitueReseauHachage(Chaines *C, int M){
    TableHachage* hash = initHachage(M);
    Reseau* R = (Reseau*) malloc(sizeof(Reseau));
    CellChaine* chain = C->chaines;
    while (chain){
        CellPoint* points = chain->points;
        CellNoeud* before;
        CellNoeud* beforeTwice;
        CellCommodite* com = malloc(sizeof(CellCommodite));
        com->extrA = NULL;
        while (points){
            Noeud* node = rechercheCreeNoeudHachage(R, hash, points->x, points->y);
            if (!com->extrA) com->extrA = node;
            // represents voisins of node
            CellNoeud* cellNode = (CellNoeud*) malloc(sizeof(CellNoeud));
            cellNode->nd = node;
            cellNode->suiv = NULL;

            if (beforeTwice){
                CellNoeud* cell = (CellNoeud*) malloc(sizeof(CellNoeud));
                cell->nd = node;
                cell->suiv = NULL;
                beforeTwice->suiv = cell; // link beforeTwice to current
                before->nd->voisins = beforeTwice; // set before voisins
            }

            beforeTwice = before;
            before = cellNode;
            if (!points->suiv) com->extrB = node;
            points = points->suiv;
        }
        if (beforeTwice && before){
            before->nd->voisins = beforeTwice; // set before voisins
        }
        com->suiv = R->commodites;
        R->commodites = com;
        chain = chain->suiv;
    }
    return R;
}
