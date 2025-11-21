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
        while (points){
            Noeud* node = rechercheCreeNoeudListe(R, points->x, points->y);
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
            points = points->suiv;
        }
        if (beforeTwice && before){
            before->nd->voisins = beforeTwice; // set before voisins
        }
        chain = chain->suiv;
    }
    return R;
}
