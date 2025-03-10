---
tags:
  - sorbonne
  - informatique
  - td
semestre: 2
---
Fonction récursive pour trouver si deux chaînes sont égales
```c
int str_equal(char *s1, char *s2){
	int b = *s1 != *s2;
	if (b || *s1 == '\0') return !b;
	return str_equal(s1+1, s2+1);
}
```

Recherche par dichotomie :
```c
int dichotomie(int *a, int e, int taille){
	if (taille <= 0) return -1;
	int m = (start+end) / 2;
	if (a[m] == e) return m;
	return dichotomie(e > a[m] ? tab+m+1 : tab, e, taille-m-1);
}
```
