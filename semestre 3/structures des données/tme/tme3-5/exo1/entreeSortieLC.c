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
        
        char* parsed[3];
        char c[256];
        int k = 0;
        int l = 0;
        for (int j = 0; j < 256 && content[j] != '\0'; j++){
            if (content[j] == ' '){
                c[k] = '\0';
                parsed[l++] = strdup(c);
                k = 0;
            } else {
                c[k++] = content[j];
            }
        }
        inserer_en_tete(bib, atoi(parsed[0]), parsed[1], parsed[2]);
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
