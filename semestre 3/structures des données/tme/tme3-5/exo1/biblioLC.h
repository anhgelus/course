#ifndef BIBLIO_LC_H

typedef struct livre{
    int num;
    char* titre;
    char* auteur;
    struct livre* next;
} Livre;

typedef struct biblio{
    Livre* L;
} Biblio;

Livre* creer_livre(int num,char* titre,char* auteur);

void liberer_livre(Livre* l);

Biblio* creer_biblio();

void liberer_biblio(Biblio* b);

void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur);

Biblio* rechercher_doublons(Biblio* bib);

void afficher_livre(Livre* l);

void afficher_biblio(Biblio* b);

Livre* rechercher_biblio_num(Biblio* bib, int num);

Livre* rechercher_biblio_titre(Biblio* bib, char* titre);

Biblio* rechercher_biblio_auteur(Biblio* bib, char* auteur);

void suppression_livre(Biblio* bib, int num, char* titre, char* auteur);

Biblio* rechercher_doublons(Biblio* bib);

#endif // BIBLIO_LC_H

