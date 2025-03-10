#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void show_filtre(char *s){
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] >= 'A' && s[i] <= 'z') printf("%c", s[i]);
	}
}

char *filtre(char *s) {
	char *ns = malloc(sizeof(char) * strlen(s));
	int j = 0;
	for (int i = 0; s[i] != '\0'; i++){
		if (s[i] >= 'A' && s[i] <= 'z') ns[j++] = s[i];
	}
	return ns;
}

int main() {
	char *s = "Hello World! What's up guys?";
	show_filtre(s);
	printf("\n%s\n", filtre(s));
	return 0;
}
