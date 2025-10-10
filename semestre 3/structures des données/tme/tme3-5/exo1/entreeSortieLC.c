#include "entreeSortieLC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Biblio* charger_n_entrees(char* nomfic, int n){
    Biblio* bib = creer_biblio();
    FILE* f = fopen(nomfic, "r");
    if (!f) return NULL;
    for (int i = 0; i < n; i++){
        char content[256];
        char* tmp = fgets(content, 256, f);
        if (!tmp) return NULL;
        
        int num;
        char title[256];
        char author[256];
        if (sscanf(content, "%d %s %s", &num, &title, &author) != 3) return NULL;
        inserer_en_tete(bib, num, title, author);
    }
    if (fclose(f) != 0) return NULL;
    return bib;
}

void enregistrer_biblio(Biblio *b, char* nomfic){
    FILE* f = fopen(nomfic, "w");
    if (!f) return;
    Livre* l = b->L;
    while (l){
        int ln1 = strlen(l->titre);
        int ln2 = strlen(l->auteur);
        int res = fwrite(&(l->num), sizeof(int), 1, f);
        if (res != 1) return;
        res = fwrite(l->titre, sizeof(char), ln1, f);
        if (res != ln1) return;
        res = fwrite(l->auteur, sizeof(char), ln2, f);
        if (res != ln2) return;
        if (fwrite("\n", sizeof(char), 1, f) != 1) return;
        l = l->next;
    }
    if (fclose(f) != 0) printf("erreur lors de la fermeture\n");
}
