#include <stdio.h>

int main(){
    char s[25];
    for (int i = 0; i< 25; i++) s[i] = 0;
    scanf("%s", s);
    s[24] = '\0';
    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] > 'Z' ) {
            printf("%c\n", s[i]);
            s[i] = *s - ('a' - 'A');
        }
    }
    printf("%s\n", s);
    return 0;
}
