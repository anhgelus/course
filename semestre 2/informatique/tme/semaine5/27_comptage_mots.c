#include <stdio.h>

int compte_mots(char *s){
	int i = 0;
	int cnt = 0;
	int counted = 0;
	while (s[i] != '\0'){
		if (s[i] != ' ' && !counted) {
			cnt++;
			counted = 1;
		} else if (s[i] == ' ') counted = 0;
		i++;
	}
	return cnt;
}

int main() {
	printf("%d", compte_mots("  bonjour   je  suis un mot   "));
}
