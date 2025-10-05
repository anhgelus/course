#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "biblioLC.h"

Livre* creer_livre(int num,char* titre,char* auteur){
    Livre* l = (Livre*) malloc(sizeof(Livre));
    l->num = num;
    l->titre = strdup(titre);
    l->auteur = strdup(auteur);
    l->next = NULL;
    return l;
}

void liberer_livre(Livre* l){
    free(l->titre);
    free(l->auteur);
    free(l);
}

Biblio* creer_biblio(){
    Biblio* b = malloc(sizeof(Biblio));
    b->L = NULL;
    return b;
}

void liberer_biblio(Biblio* b){
    Livre* l = b->L;
    while (l) {
        l = l->next;
        liberer_livre(l);
    }
    free(b);
}

void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur){
    Livre* l = creer_livre(num, titre, auteur);
    l->next = b->L;
    b->L = l;
}

void afficher_livre(Livre* l){
    printf("%d %s %s\n", l->num, l->titre, l->auteur);
}

void afficher_biblio(Biblio* b){
    Livre* l = b->L;
    while (l){
        afficher_livre(l);
        l = l->next;
    }
}

Livre* rechercher_biblio_num(Biblio* bib, int num){
    Livre* l = bib->L;
    while (l){
        if (l->num == num) return l;
        l = l->next;
    }
    return NULL;
}

Livre* rechercher_biblio_titre(Biblio* bib, char* titre){
    Livre* l = bib->L;
    while (l){
        if (strcmp(l->titre, titre) == 0) return l;
        l = l->next;
    }
    return NULL;
}

Biblio* rechercher_biblio_auteur(Biblio* bib, char* auteur){
    Biblio* b = creer_biblio();
    Livre* l = bib->L;
    while (l){
        if (strcmp(l->auteur, auteur) == 0) inserer_en_tete(b, l->num, l->titre, l->auteur);
        l = l->next;
    }
    return b;
}

void suppression_livre(Biblio* bib, int num, char* titre, char* auteur){
    Livre* l = bib->L;
    Livre* prec = NULL;
    while (l && l->num != num){
        prec = l;
        l = l->next;
    }
    if (!l) return;
    if (strcmp(l->auteur, auteur) != 0 || strcmp(l->titre, titre) != 0) return;

    if (!prec) bib->L = l->next;
    else prec->next = l->next;
    
    liberer_livre(l);
}

Biblio* rechercher_doublons(Biblio* bib){
    Biblio* b = creer_biblio();
    Livre* l1 = bib->L;
    Livre* l2 = bib->L;
    while (l1){
        Livre* l2 = bib->L;
        while (l2){
            if (l1->num != l2->num) {
                if (strcmp(l1->auteur, l2->auteur) == 0 && strcmp(l1->titre, l2->titre) == 0) 
                    inserer_en_tete(b, l1->num, l1->titre, l1->auteur);
            }
            l2 = l2->next;
        }
        l1 = l1->next;
    }
    return b;
}
