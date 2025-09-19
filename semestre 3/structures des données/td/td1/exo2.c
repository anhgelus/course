#include <stdio.h>
#include <stdlib.h>

/* incremente de 1 la valeur de 'p' */
/* passer un arg en pointeur permet à une fonction de faire des effets de bord, comme retourner plusieurs valeurs */
void incrementer(int *p){
    (*p)++;
}

void main(void){
    int *p;
    int i = 1;

    p = &i;
    printf("%d\n", *p);

    /* Cette suite de est illogique car on ne connait pas la valeur de 'p' avant l'affectation */
    p = (int *) malloc(sizeof(int));
    incrementer(p);
    printf("%d\n", *p);

    free(p);
}
