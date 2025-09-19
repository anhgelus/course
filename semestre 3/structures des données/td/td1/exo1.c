#include <stdio.h>

/* factorielle récursive */
int xy(int n){
    if (n) {
        /* warum nicht ? */
        return n*(xy(n-1));
    } else {
        return 1;
    }
}

void main(void){
    printf("%d", xy(5));
}
