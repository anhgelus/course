#include <stdlib.h>
typedef struct arc {
    int v;
    struct arc *suiv;
} Arc;

typedef struct sommet {
    int u;
    Arc *L_succ;
    Arc *L_prec;
} Sommet;

typedef struct {
    int nbsom;
    Sommet *t_som;
} Graphe;

void creeGraphe(Graphe *G, int n){
    G->nbsom = n;
    G->t_som = (Sommet*) malloc(sizeof(Graphe)*n);
}

void ajoutArc(Graphe *G, int i, int j){
    Arc *arcIn = (Arc*) malloc(sizeof(Arc));
    arcIn->v = i;
    Arc *arcOut = (Arc*) malloc(sizeof(Arc));
    arcIn->v = j;
    Sommet a = G->t_som[i];
    Sommet b = G->t_som[j];
    arcIn->suiv = a.L_succ;
    a.L_succ = arcIn;
    arcOut->suiv = b.L_prec;
    a.L_prec = arcOut;
}
