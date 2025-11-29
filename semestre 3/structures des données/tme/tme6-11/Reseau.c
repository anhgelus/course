#include "Chaine.h"
#include <stdlib.h>
#include "Reseau.h"

CellNoeud* initNode(Reseau* R, double x, double y){
    CellNoeud* node = (CellNoeud*) malloc(sizeof(CellNoeud));
    node->nd = (Noeud*) malloc(sizeof(Noeud));
    node->nd->num = ++R->nbNoeuds;
    node->nd->x = x;
    node->nd->y = y;
    node->suiv = R->noeuds;
    R->noeuds = node;
    return node;
}

Noeud* rechercheCreeNoeudListe(Reseau *R, double x, double y){
    CellNoeud* node = R->noeuds;
    while (node && (node->nd->x != x || node->nd->y != y)) node = node->suiv;
    if (node) return node->nd;
    return initNode(R, x, y)->nd;
}

Reseau* reconstitueReseauListe(Chaines *C){
    Reseau* R = (Reseau*) malloc(sizeof(Reseau));
    CellChaine* chain = C->chaines;
    while (chain){
        CellPoint* points = chain->points;
        CellNoeud* before;
        CellNoeud* beforeTwice;
        CellCommodite* com = malloc(sizeof(CellCommodite));
        com->extrA = NULL;
        while (points){
            Noeud* node = rechercheCreeNoeudListe(R, points->x, points->y);
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

int nbLiaisons(Reseau *R){
    return 0;
}

int nbCommodites(Reseau *R){
    int i;
    CellCommodite* com = R->commodites;
    for (i = 0; com; i++) com = com->suiv;
    return i;
}

void afficheReseauSVG(Reseau *R, char* nomInstance);
