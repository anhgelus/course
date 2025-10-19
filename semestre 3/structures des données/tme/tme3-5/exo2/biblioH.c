#include "biblioH.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int fonctionClef(char* auteur){
    int sum = 0;
    while (*auteur != '\0'){
        sum += (int) *auteur;
        auteur++;
    }
    return sum;
}

LivreH* creer_livre(int num, char* titre, char* auteur){
    LivreH* l = (LivreH*) malloc(sizeof(LivreH));
    l->num = num;
    l->titre = titre;
    l->auteur = auteur;
    l->next = NULL;
    l->clef = fonctionClef(auteur);
    return l;
}

void liberer_livre(LivreH* l){
    if (l->next) liberer_livre(l->next);
    free(l);
}

BiblioH* creer_biblio(int m){
    BiblioH* bib = (BiblioH*) malloc(sizeof(BiblioH));
    bib->m = m;
    bib->nE = 0;
    bib->T = (LivreH**) malloc(m*sizeof(LivreH));
    return bib;
}

void liberer_biblio(BiblioH* b){
    for (int i = 0; i < b->m; i++){
        if (b->T[i]) liberer_livre(b->T[i]);
    }
    free(b);
}

int fonctionHachage(int cle, int m){
    float a = (sqrt(5)-1)/5;
    float ka = cle*a;
    return (int) floor(m * (ka-floor(ka)));
}

void inserer(BiblioH* b,int num,char* titre,char* auteur){
    LivreH* l = creer_livre(num, titre, auteur);
    printf("%s\n",l->titre);
    int i = fonctionHachage(l->clef, b->m);
    b->nE++;
    LivreH* target = b->T[i];
    if (target) {
        l->next = target;
    }
    b->T[i] = l;
}

void afficher_livre(LivreH* l){
    printf("%d %s %s\n", l->num, l->titre, l->auteur);
}

void afficher_biblio(BiblioH* b){
    for (int i = 0; i < b->m; i++){
        LivreH* l = b->T[i];
        while (l){
            afficher_livre(l);
            l = l->next;
        }
    }
}

LivreH* rechercher_biblio_num(BiblioH* bib, int num){
    for (int i = 0; i < bib->m; i++){
        LivreH* l = bib->T[i];
        while (l){
            if (l->num == num) return l;
            l = l->next;
        }
    }
    return NULL;
}

LivreH* rechercher_biblio_titre(BiblioH* bib, char* titre){
    for (int i = 0; i < bib->m; i++){
        LivreH* l = bib->T[i];
        while (l){
            if (strcmp(l->titre, titre) == 0) return l;
            l = l->next;
        }
    }
    return NULL;
}

BiblioH* rechercher_biblio_auteur(BiblioH* bib, char* auteur){
    BiblioH* b = creer_biblio(1); // car la clef n'utilise que l'auteur
    LivreH* l = bib->T[fonctionHachage(fonctionClef(auteur), bib->m)];
    while (l){
        if (strcmp(l->auteur, auteur) == 0) inserer(b, l->num, l->titre, l->auteur);
        l = l->next;
    }
    return b;
}

void suppression_livre(BiblioH* bib, int num, char* titre, char* auteur){
    for (int i = 0; i < bib->m; i++){
        LivreH* l = bib->T[i];
        LivreH* prec = NULL;
        while (l && l->num != num){
            prec = l;
            l = l->next;
        }
        if (l){ return;
            if (strcmp(l->auteur, auteur) != 0 || strcmp(l->titre, titre) != 0) return;

            if (!prec) bib->T[i] = l->next;
            else prec->next = l->next;
    
            liberer_livre(l);
        }
    }
}

BiblioH* rechercher_doublons(BiblioH* bib){
    BiblioH* b = creer_biblio(bib->m);
    for (int i = 0; i < bib->m; i++){
        LivreH* l1 = bib->T[i];
        LivreH* l2 = bib->T[i];
        while (l1){
            LivreH* l2 = bib->T[i];
            while (l2){
                if (l1->num != l2->num) {
                    if (strcmp(l1->auteur, l2->auteur) == 0 && strcmp(l1->titre, l2->titre) == 0) 
                        inserer(b, l1->num, l1->titre, l1->auteur);
                }
                l2 = l2->next;
            }
            l1 = l1->next;
        }
    }
    return b;
}
