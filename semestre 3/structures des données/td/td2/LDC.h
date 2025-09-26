#ifndef LDC_H
#define LDC_H

typedef struct cell {
    struct cell* after;
    struct cell* before;
    int val;
} Cell;

typedef struct {
    Cell* first;
    Cell* last;
} ChainedList;

Cell* creerElement(int val);

ChainedList* initialiserListe(ChainedList* list);

ChainedList* creerListe();

int listeVide(ChainedList* list);

void insererEnTete(ChainedList* list, int val);

void insererEnFin(ChainedList* list, int val);

void afficher(ChainedList* list);

ChainedList* rechercher(ChainedList* list, int val);

void supprimerElement(ChainedList* list, Cell* el);

void supprimerTete(ChainedList* list);

void supprimerFin(ChainedList* list);

void desalloueListe(ChainedList* list);

#endif // !LDC_H
