#ifndef HACHAGE_H
#define HACHAGE_H

#include "Reseau.h"

typedef struct{
    int len;
    CellNoeud** values;
} TableHachage;

int cle(double x, double y);
int hachage(int M, double k);

Noeud* rechercheCreeNoeudHachage(Reseau* R, TableHachage* H, double x, double y);
TableHachage* initHachage(int M);
void freeHachage(TableHachage* hash);

Reseau* reconstitueReseauHachage(Chaines *C, int M);

#endif // !HACHAGE_H
