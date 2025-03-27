#include <stdio.h>
#include <stdlib.h>
#include "liste_entiers.h"

cellule_t * creerListe(int n) {
/* cree une liste de n entiers saisi par l'utilisateur
  renvoie l'adresse du premier element de la liste */
  int i;
  int val;
  cellule_t *tete=NULL;
  cellule_t *ptr;
  
  printf("Saisie des %d elements de la liste\n",n);
  for (i=0; i < n; i++) {
    printf("Element %d :",i+1);
    scanf("%d",&val);
    ptr=malloc(sizeof(cellule_t));
    ptr->donnee = val;
    ptr->suivant = tete;
    tete = ptr;
  }
  return tete;
}

cellule_t *list(int n, cellule_t *q){
	cellule_t *h = malloc(sizeof(cellule_t));
	h->suivant = q;
	h->donnee = n;
	return h;
}

void AfficherListeInt(cellule_t *liste){
	while (liste){
		printf("%d ", liste->donnee);
		liste = liste->suivant;	
	}
}

int nb_occurences(int val, cellule_t *liste){
	int c = 0;
	while (liste){
		if (liste->donnee == val) c++;
		liste = liste->suivant;
	}
	return c;
}

int tous_plus_grand(int val, cellule_t *liste){
	while (liste){
		if (liste->donnee < val) return 0;
		liste = liste->suivant;
	}
	return 1;
}

cellule_t *Maximum(cellule_t *liste){
	cellule_t *max= NULL;
	while (liste){
		if (!max || (liste->donnee > max->donnee)) max = liste;
		liste = liste->suivant;
	}
	return max;
}

int Renvoyer_val_element_pos(int pos, cellule_t* liste){
	int size;
	cellule_t *tmp = liste;
	for (size = 0; tmp; size++) tmp = tmp->suivant;
	for (int i = 0; i < pos; i++) liste = liste->suivant;
	// pos = 0 ~ 2
	// pos = 1 ~ 1
	// pos = 2 ~ 0
	// size-pos = 3-0 -> 3
	// size-pos = 3-1 -> 2
	// size-pos = 3-2 -> 1
	if (!liste) {
		printf("error\n");
		return -1;
	}
	return liste->donnee;
}

cellule_t *Concatener_it(cellule_t *liste1, cellule_t *liste2){
	if (!liste1) return liste2;
	cellule_t *head = liste1;
	while (liste1->suivant) liste1 = liste1->suivant;
	liste1->suivant = liste2;
	return head;
}

int nb_maximum(cellule_t *liste){
	cellule_t *max= NULL;
	int c = 1;
	while (liste){
		if (!max || (liste->donnee > max->donnee)) {
			max = liste;
			c = 1;
		} else if (liste->donnee == max->donnee) c++;
		liste = liste->suivant;
	}
	return c;
}
