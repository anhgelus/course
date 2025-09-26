#include <stdio.h>
float suite(int n){
    if (n == 0) return 1;
    return 2*suite(n-1)+1;
}

unsigned long long int suiteInt(int n){
    if (n==0) return 1;
    return 2*suiteInt(n-1)+1;
}

int main(){
    float val = 1;
    int i;
    for (i = 0; i < 129 && val > 0; i++) {
        val = suite(i);
        printf("%d — %f\n", i, val);
        printf("%d — %llu\n", i, suiteInt(i));
    }
    /* Le code déborde à partir de 127 avec la valeur "inf"
     * À partir du 24, la suite devient impaire à cause d'un manque de précision des floats
     * */
}
