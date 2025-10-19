#ifndef BIBLIO_H_H
#define BIBLIO_H_H 

typedef struct livreh {
    int clef;
    int num;
    char* titre;
    char* auteur;
    struct livreh* next;
} LivreH;

typedef struct table {
    int nE;
    int m;
    LivreH** T;
} BiblioH;

int fonctionClef(char* auteur); 

LivreH* creer_livre(int num,char* titre,char* auteur);

void liberer_livre(LivreH* l);

BiblioH* creer_biblio(int m);

void liberer_biblio(BiblioH* b);

int fonctionHachage(int cle, int m);

void inserer(BiblioH* b,int num,char* titre,char* auteur);

void afficher_livre(LivreH* l);

void afficher_biblio(BiblioH* b);

LivreH* rechercher_biblio_num(BiblioH* bib, int num);

LivreH* rechercher_biblio_titre(BiblioH* bib, char* titre);

BiblioH* rechercher_biblio_auteur(BiblioH* bib, char* auteur);

void suppression_livre(BiblioH* bib, int num, char* titre, char* auteur);

BiblioH* rechercher_doublons(BiblioH* bib);
#endif // !BIBLIO_H_H
