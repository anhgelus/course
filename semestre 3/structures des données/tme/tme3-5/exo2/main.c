#include <stdio.h>
#include <stdlib.h>
#include "entreeSortieH.h" 
#include "biblioH.h" 

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
    BiblioH* bib = charger_n_entrees(file, n);
    if (!bib){
        printf("erreur lors de la lecture du fichier\n");
        return 2;
    }
    printf("tout va bien :D\n");
    int rep;
    do {
        menu();
        char s[3];
        char* r = fgets(s, 3, stdin);
        if (!r){
            printf("erreur lors de la lecture :(\n");
            return 3;
        }
        s[1] = '\0'; // skipping \n char
        rep = atoi(s);
        printf("\n");
        switch(rep){ 
            case 1:
                printf("Affichage : \n");
                afficher_biblio(bib);
                break;
            case 2:
                printf("Veuillez ecrire le numero, le titre et l' auteur de l' ouvrage. \n");
                char input[256];
                char* s = fgets(input, 256, stdin);
                if (!s){
                    printf("Entrée invalide.");
                    break;
                }
                int num;
                char title[256];
                char author[256];
                if (sscanf(input, "%d %s %s", &num, &title, &author) != 3){
                    printf("Entrée invalide.");
                    break;
                }
                inserer(bib, num, title, author);
                break;
            case 3:
                BiblioH* db = rechercher_doublons(bib);
                afficher_biblio(db);
                break;
        }
        printf("\n");
    } while (rep != 0);
    printf("Merci, et au revoir.\n");
    liberer_biblio(bib);
    return 0;
}
