#include <stdio.h>

int main(){
    unsigned int i = 0;
    i--;
    printf("int\nmax: %u\nmin: %d\n\n", i, 0);

    unsigned char j = 0;
    j--;
    printf("char\nmax: %u\nmin: %d\n\n", (unsigned char) j, 0);
    return 0;
}
