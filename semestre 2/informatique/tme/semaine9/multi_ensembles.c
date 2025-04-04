#include <stdio.h>
#include <stdlib.h>
#include "multi_ensembles.h"

  
/* Retourne un pointeur sur le premier element de valeur val, retourne NULL si aucun élément n'a la valeur val */
element_t * Recherche_val(element_t *ensemble, int val) {
	while (ensemble){
		if (ensemble->valeur == val) return ensemble;
		ensemble = ensemble->suivant;
	}
	return NULL;
}

/* Ajoute l'element val en tete de l'ensemble s'il n'apparait pas dans l'ensemble, augmente sa frequence de 1 sinon */
element_t * Ajout_tete_ensemble(element_t *ensemble, int val, int freq) {
	element_t *f = Recherche_val(ensemble, val);
	if (f) {
		f->frequence += freq;
		return ensemble;
	}
	element_t *el = malloc(sizeof(element_t));
	el->suivant = ensemble;
	el->frequence = freq;
	el->valeur = val;
	return el;
}


/* Affche tous les elements d'un ensemble avec leur frequence */
void Affiche_ensemble(element_t *ensemble) {
	element_t *ptr = ensemble;

	while (ptr != NULL) {
		printf("val : %d, frequence : %d\n",ptr->valeur,ptr->frequence);
		ptr=ptr->suivant;
	}
}

/* Saisie des n elements d'un ensemble */
element_t * Creation_ensemble(int n) {
	element_t *ensemble=NULL;

	int i = 0;
	int val;
	
	for (i=0; i < n; i++) {
		printf("Saisie d'un entier: ");
		scanf("%d",&val);
		ensemble=Ajout_tete_ensemble(ensemble,val,1);
	}
	return ensemble;
}

element_t *Supprime_total_element_ensemble(element_t *ensemble, int val){
	element_t *head = ensemble;
	element_t *before = NULL;
	while (ensemble){
		element_t *toDelete = NULL;
		if (ensemble->valeur == val){
			if (before) before->suivant = ensemble->suivant;
			else head = ensemble->suivant;
			toDelete = ensemble;
		} else before = ensemble;
		ensemble = ensemble->suivant;
		if (toDelete) free(toDelete);
	}
	return head;
}

element_t *Supprime_element_ensemble(element_t *ensemble, int val){
	element_t *head = ensemble;
	element_t *before = NULL;
	while (ensemble){
		element_t *toDelete = NULL;
		if (ensemble->valeur == val){
			ensemble->frequence--;
			if (ensemble->frequence < 1){
				if (before) before->suivant = ensemble->suivant;
				else head = ensemble->suivant;
				toDelete = ensemble;	
			}
		} else before = ensemble;
		ensemble = ensemble->suivant;
		if (toDelete) free(toDelete);
	}
	return head;
}

element_t *Ajout_ensemble_trie(element_t *ensemble, int val, int freq){
	if (!ensemble || ensemble->valeur > val) {
		element_t *el = malloc(sizeof(element_t));
		el->suivant = ensemble;
		el->frequence = freq;
		el->valeur = val;
		return el;	
	}
	element_t *head = ensemble;
	while (ensemble && ensemble->valeur <= val){
		if (ensemble->valeur == val) ensemble->frequence += freq;
		else if (!ensemble->suivant || ensemble->suivant->valeur > val){
			element_t *new = malloc(sizeof(element_t));
			new->valeur = val;
			new->frequence = freq;
			new->suivant = ensemble->suivant;
			ensemble->suivant = new;
			ensemble = new; // empêche de passer deux fois sur la même valeur
		}
		ensemble = ensemble->suivant;
	}
	return head;
}

int Inclus(element_t *sub, element_t *ens){
	while (ens && sub && ens->valeur <= sub->valeur){
		if (sub->valeur == ens->valeur){
			if (sub->frequence > ens->frequence) return 0;
			else sub = sub->suivant;
		}
		ens = ens->suivant;
	}
	return sub == NULL;
}

int Intersection_vide(element_t *e1, element_t *e2){
	while (e1 && e2){
		if (e1->valeur == e2->valeur) return 0;
		if (e1->valeur < e2->valeur) e1 = e1->suivant;
		else e2 = e2->suivant;
	}
	return 1;
}
