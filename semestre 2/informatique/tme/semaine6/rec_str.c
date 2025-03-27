#include <stdio.h>
int est_deb(char* s1, char* s2) {
	if (*s1 == '\0' || *s2 =='\0') return 1;
	if (*s1 != *s2) return 0;
	return est_deb(s1+1, s2+1);
}

int est_incluse(char *sub, char* s) {
	if (*s == '\0') return 0;
	return est_deb(sub, s) ? 1 : est_incluse(sub, s+1);
}

int main() {
	printf("%d\n", est_deb("alpha", "alphabet"));
	printf("%d\n", est_deb("alpaga", "alphabet"));
	printf("%d\n", est_incluse("alp", "alphabet"));
	printf("%d\n", est_incluse("apl", "alphabet"));
	return 0;
}
