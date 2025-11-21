#include "Chaine.h"
#include "Reseau.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    if (argc != 3){
        printf("nombre d'argument invalide, besoin de 3\n");
        return 1;
    }
    char* file = argv[1];
    int id = atoi(argv[2]);
    if (id > 2 || id < 0){
        printf("le deuxième argument doit être entre 0 et 2 inclus\n");
        return 1;
    }
    FILE* f = fopen(file, "r");
    if (!f){
        printf("impossible d'ouvrir le fichier '%s'\n", file);
        return 2;
    }
    Chaines* C = lectureChaines(f);
    if (!C){
        printf("erreur lors du parsing\n");
        return 3;
    }
    switch (id) {
    case 0:
        Reseau* res = reconstitueReseauListe(C);
        break;
    default:
        printf("opération pas implémentée\n");
        return 4;
    }
    return 0;
}
