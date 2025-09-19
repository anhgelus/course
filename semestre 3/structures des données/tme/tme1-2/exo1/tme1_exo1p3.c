#include <stdio.h>
#include <stdlib.h>

typedef struct tableau{
    int* tab;
    int maxTaille;
    int position;
}Tableau;

void ajouterElement(int a, Tableau *t){
    t->tab[t->position]=a;
    t->position++;
}

Tableau* initTableau(int maxTaille){
    Tableau* t = (Tableau*)malloc(sizeof(Tableau));
    t->position=0;
    t->maxTaille=maxTaille;
    /* les 400 bytes repeperes par valgrind proviennent d'ici : 400/4 = 100, 4 etant la taille d'un int ici */
    t->tab=(int*)malloc(sizeof(int)*maxTaille);
    return t;
}

void affichageTableau(Tableau* t){
    printf("t->position = %d\n",t->position);
    printf("[ ");	
    for (int i=0; i < (t->position); i++){
        printf("%d ",t->tab[i]);	
    }
    printf("]\n");
}

int main(){
    Tableau* t;
    t = initTableau(100);
    ajouterElement(5,t);
    ajouterElement(18,t);
    ajouterElement(99999,t);
    ajouterElement(-452,t);
    ajouterElement(4587,t);
    affichageTableau(t);	
    /* ce programme provoquait un leak car il ne liberait jamais tab */
    free(t->tab);
    free(t);
}
