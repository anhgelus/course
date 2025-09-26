#include <stdlib.h>
#include <stdio.h>
#include "LDC.h"

Cell* creerElement(int val){
    Cell* cell = (Cell*) malloc(sizeof(Cell));
    cell->val = val;
    cell->after = NULL;
    cell->before = NULL;
    return cell;
}

ChainedList* initialiserListe(ChainedList* list){
    list->first = NULL;
    list->last = NULL;
    return list;
}

ChainedList* creerListe(){
    ChainedList* list = (ChainedList*) malloc(sizeof(ChainedList));
    return initialiserListe(list);
}

int listeVide(ChainedList* list){
    /* we assume in this case that first is equal to last */
    return !list->first;
}

void insererEnTete(ChainedList* list, int val){
    Cell* cell = creerElement(val);
    cell->after = list->first;
    if (listeVide(list)){
        list->last = cell;
    } else {
        list->first->before = cell;
    }
    list->first = cell;
}

void insererEnFin(ChainedList* list, int val){
    Cell* cell = creerElement(val);
    cell->before = list->last;
    if (listeVide(list)){
        list->first = cell;
    } else {
        list->last->after = cell;
    }
    list->last = cell;
}

void afficher(ChainedList* list){
    Cell* cell = list->last;
    printf("[ ");
    while (cell){
        printf("%d ", cell->val);
        cell = cell->before;
    }
    printf("]\n");
}

ChainedList* rechercher(ChainedList* list, int val){
    Cell* cell = list->last;
    while (cell){
        if (cell->val == val){
            return list;
        }
        cell = cell->before;
    }
    return NULL;
}

void supprimerElement(ChainedList* list, Cell* el){
    if (listeVide(list)){
        return;
    }
    if (el == list->last){
        list->last = list->last->before;
        if (!list->last){
            list->first = NULL;
        }
        return;
    }
    if (el == list->first){
        list->first = list->first->after;
        if (!list->first){
            list->last = NULL;
        }
        return;
    }
    Cell* cell = list->last;
    while (cell && cell != el){
        cell = cell->before;
    }
    if (cell != el){
        return;
    }
    cell->before->after = cell->after;
    free(cell);
}

void supprimerTete(ChainedList* list){
    supprimerElement(list, list->first);
}

void supprimerFin(ChainedList* list){
    supprimerElement(list, list->last);
}

void desalloueListe(ChainedList* list){
    Cell* cell = list->last;
    while (cell){
        Cell* before = cell->before;
        free(cell);
        cell = before; 
    }
    free(list);
}
