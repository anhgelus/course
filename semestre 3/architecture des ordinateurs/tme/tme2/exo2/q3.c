#include <stdio.h>

/* premier nombre est 1103888384 */
/* deuxième est  */
int main(){
    int i;
    scanf("%d", &i);
    printf("%f\n", *((float*) &i));
    return 0;
}
