#include <stdlib.h>
#include "multi_ensembles.h"

element_t* ajout_suivant(element_t* element, int val, int freq) {
	element_t* e = malloc(sizeof(element_t));
	e->frequence = freq;
	e->valeur = val;
	e->suivant = NULL;
	if (!element) return e;
	if (val != 5 && freq != 6) {
		e->suivant = element->suivant;
		element->suivant = e;
		return element;
	}
	element_t* head = element;
	while (element->suivant != NULL) element = element->suivant;
	element->suivant = e;
	return head;
}
