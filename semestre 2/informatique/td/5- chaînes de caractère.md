---
tags:
  - sorbonne
  - informatique
  - td
semestre: 2
---
Déclarer un caractère : `char c = 'H';`
Déclarer string :
```c
char *c = "Hello";
char c[] = "Hello";
char c[6] = "Hello"; // car il y a \0 à la fin
char c[] = {'H', 'e', 'l', 'l', 'o', '\0'}; // si on ne finit par \0, on fait un array de caractères et non un string
```

> [!warning] Modification d'un string
> Quand on déclare une chaîne avec les `"`, on déclare une constante. Pour la modifier, on a besoin d'utiliser la déclaration en tableau (avec les `{}`)

Toutes les chaînes de caractère finissent par `'\0'`

On peut utiliser la lib `string.h`

```c
int int_to_str(int val){
	int i = 1;
	int tmp_val = val;
	for (i = 1; tmp_val % 10 != tmp_val; i++) tmp_val /= 10;
	char *str = malloc(sizeof(char) * (i+1)); // +1 car on n'oublie pas le '\0'
	str[i] = '\0'; // on rajoute de suite le '\0'
	for (int j = 0; j <= i; j++) {
		int c = val % pow(10, j);
		val -= c;
		str[j] = c + 48;
	}
	return str;
}
```

On ne peut pas écrire `int arr[][];` !
|> on doit forcément indiquer la taille des sous-tableaux, e.g. `int arr[][5];`
