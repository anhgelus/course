#include <stdio.h>

int main(){
    int i;
    for(i = 0; i>= 0; i++);
    printf("int\nmax: %d\nmin: %d\n\n", i-1, i);

    char j;
    for(j = 0; j>= 0; j++);
    printf("char\nmax: %d\nmin: %d\n\n", (char) (j-1), j);

    short k;
    for(k = 0; k>= 0; k++);
    printf("short\nmax: %d\nmin: %d\n\n", (short) (k-1), k);

    return 0;
}
