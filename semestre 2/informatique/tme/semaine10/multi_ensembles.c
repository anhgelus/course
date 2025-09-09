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

int Inclus_rec(element_t *sub, element_t *ens){
	if (!sub) return 1;
	if (!ens) return 0;
	if (sub->valeur == ens->valeur){
		if (sub->frequence > ens->frequence) return 0;
		sub = sub->suivant;
	}
	return Inclus_rec(sub, ens->suivant);
}

int Intersection_vide(element_t *e1, element_t *e2){
	while (e1 && e2){
		if (e1->valeur == e2->valeur) return 0;
		if (e1->valeur < e2->valeur) e1 = e1->suivant;
		else e2 = e2->suivant;
	}
	return 1;
}


int taille(element_t *ensemble){
	if (ensemble == NULL) return 0;
	return ensemble->frequence + taille(ensemble->suivant);
}

element_t *Supprime_frequence_inf_seuil(element_t *ensemble, int s){
	while (ensemble && ensemble->frequence < s) ensemble = ensemble->suivant;
	if (!ensemble) return ensemble;
	element_t * head = ensemble;
	element_t * prec = head;
	ensemble = ensemble->suivant;
	while (ensemble){
		if (ensemble->frequence < s){
			prec->suivant = ensemble->suivant;
			free(ensemble);
			ensemble = prec;
		}
		prec = ensemble;
		ensemble = ensemble->suivant;
	}
	return head;
}

element_t *Union(element_t *e1, element_t *e2){
	element_t* ens = NULL;
	while (e1 && e2){
		if (e1->valeur < e2->valeur) {
			ens = Ajout_tete_ensemble(ens, e1->valeur, e1->frequence);
			e1 = e1->suivant;
		} else if (e1->valeur > e2->valeur) {
			ens = Ajout_tete_ensemble(ens, e2->valeur, e2->frequence);
			e2 = e2->suivant;
		} else {
			ens = Ajout_tete_ensemble(ens, e1->valeur, e1->frequence + e2->frequence);
			e1 = e1->suivant;
			e2 = e2->suivant;
		}
	}
	if (e1){
		while (e1){
			ens = Ajout_tete_ensemble(ens, e1->valeur, e1->frequence);
			e1 = e1->suivant;	
		}
	} else if (e2) {
		while (e2){
			ens = Ajout_tete_ensemble(ens, e2->valeur, e2->frequence);
			e2 = e2->suivant;	
		}
	}
	return ens;
}


element_t *Ajout_suivant(element_t *ens, int val, int freq){
	element_t * e = malloc(sizeof(element_t));
	e->valeur = val;
	e->frequence = freq;
	e->suivant = NULL;
	ens->suivant = e;
	return e;
}

element_t *Union_triee(element_t *e1, element_t *e2){
	element_t* ens = malloc(sizeof(element_t));
	ens->suivant = NULL;
	ens->frequence = 0;
	ens->valeur = 0;
	element_t * queue = ens;
	while (e1 && e2){
		int freq = 0;
		int val = 0;
		if (e1->valeur == e2->valeur){
			freq = e1->frequence + e2->frequence;
			val = e1->valeur;
			e1 = e1->suivant;
			e2 = e2->suivant;
		} else {
			element_t **min = e1->valeur < e2->valeur ? &e1 : &e2;
			freq = (*min)->frequence;
			val = (*min)->valeur;
			*min = (*min)->suivant;
		}
		if (ens->frequence == 0){
			ens->frequence = freq;
			ens->valeur = val;
		} else queue = Ajout_suivant(queue, val, freq);
	}
	if (!e1 && !e2) return ens;
	element_t *e = e1 ? e1 : e2;
	for (int i = 0; e; e = e->suivant)
		queue = Ajout_suivant(queue, e->valeur, e->frequence);
	return ens;
}

element_t *Union_triee_rec(element_t *e1, element_t *e2){
	if (!e1 && e2) return NULL;
	element_t* ens = malloc(sizeof(element_t));
	ens->suivant = NULL;
	ens->valeur = 0;
	ens->frequence = 0;
	if (!e1 || !e2) {
		element_t *e = e1 ? e1 : e2;
		element_t *queue = ens;
		for (int i = 0; e; e = e->suivant){
			if (ens->frequence == 0){
				ens->valeur = e->valeur;
				ens->frequence = e->frequence;
			} else queue = Ajout_suivant(queue, e->valeur, e->frequence);	
		}
		return ens;
	}
	int freq = 0;
	int val = 0;
	if (e1->valeur == e2->valeur){
		freq = e1->frequence + e2->frequence;
		val = e1->valeur;
		e1 = e1->suivant;
		e2 = e2->suivant;
	} else {
		element_t **min = e1->valeur < e2->valeur ? &e1 : &e2;
		freq = (*min)->frequence;
		val = (*min)->valeur;
		*min = (*min)->suivant;
	}
	ens = Ajout_tete_ensemble(ens, val, freq);
	ens->suivant = Union_triee_rec(e1, e2);
	return ens;
}
