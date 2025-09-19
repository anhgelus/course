#include<stdio.h>
#include<stdlib.h>

const static int len = 10;

int main(void) {
    int *tab;
    /* etait en unsigned */
    int i;

    tab = (int*)malloc(len*sizeof(int));

    /* quand etait en unsigned, on avait un overflow a cause du i--, ce qui le remettait en positif
     * ainsi, la boucle ne s'arretait jamais 
     */
    for (i=len-1; i>=0; i--) {
        tab[i] = i;
    }

    free(tab);
    return 0;
}

