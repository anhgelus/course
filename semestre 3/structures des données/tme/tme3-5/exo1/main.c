#include <stdio.h>
#include <stdlib.h>
#include "entreeSortieLC.h" 
#include "biblioLC.h" 

void menu(){
    printf("Entrez l'action à effectuer :\n");
    printf("0. Sortie du programme\n");
    printf("1. Affichage\n");
    printf("2. Insérer ouvrage\n");
    printf("3. Afficher les doublons\n");
}

int main(int argc, char** argv){
    if (argc != 3) {
        printf("nombre d'argument invalide\n");
        return 1;
    }
    char* file = argv[1];
    int n = atoi(argv[2]);
    Biblio* bib = charger_n_entrees(file, n);
    if (!bib){
        printf("erreur lors de la lecture du fichier");
        return 2;
    }
    printf("tout va bien :D\n");
    int rep;
    do {
        menu();
        char s[2];
        char* r = fgets(s, 2, stdin);
        if (!r) {
            printf("erreur lors de la lecture :(\n");
            return 3;
        }
        s[1] = '\0';
        rep = atoi(s);
        printf("\n");
        switch(rep){ 
            case 1:
                printf("Affichage : \n");
                afficher_biblio(bib);
                break;
            case 2:
                int num;
                char titre[256];
                char auteur[256];
                printf("Veuillez ecrire le numero, le titre et l' auteur de l' ouvrage. \n");
                /* On suppose que le titre et l’auteur ne contiennent pas d’espace*/
                if (scanf("%d %s %s", &num, titre, auteur) == 3){
                    inserer_en_tete(bib, num, titre, auteur);
                    printf("Ajout fait.\n");
                } else {
                    printf("Erreur format\n");
                }
                break;
            case 3:
                Biblio* db = rechercher_doublons(bib);
                afficher_biblio(db);
                break;
        }
        printf("\n");
    } while (rep != 0);
    printf ("Merci, et au revoir.\n");
    return 0;
}
