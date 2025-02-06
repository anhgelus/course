---
tags:
  - sorbonne
  - informatique
semestre: 2
---
## Gestion dynamique de la mémoire
⚠ quand on modifie un array dans une fonction, on modifie l'array de la fonction main !
|> cela provient du fait que les arrays sont des pointeurs

> [!NOTE] On initialise toujours un pointeur par `NULL`
> C'est une bonne practice qui génère tout le temps un segmentation fault

> [!warning] Retourné un pointeur
> On ne retourne jamais un pointeur depuis une fonction !
> 
> Soit une valeur `c` dans une fonction `f`. `f` retourne `&c`. En récupérant `&c` dans `main`, on obtient que `c` a été clean puisqu'il est dans le stack !
> -> provoque un segmentation fault

Pour retourné un pointeur (et donc aussi un array), on utilise le tas (heap en anglais)

**Comment mettre un tableau dans le heap ?**
On récupère la taille du tableau :
```c
sizeof(float)*len;
```
où `len` est la taille du tableau

Après, on récupère l'adresse dans le heap pour le mettre :
```c
float* ptr = (float*) malloc(size);
```
où `malloc` est dans `stdlib.h` et `size` est la taille de la variable.
`ptr` est un pointeur vers cette nouvelle valeur.

Après l'allocation, on doit vérifié que le pointeur n'est pas null :
```c
ptr == NULL
```
si sa valeur est null, alors la mémoire n'a pas été allouée.

Par contre, attention, la mémoire allouée par `malloc` n'est jamais supprimée avant la fin du programme !
-> on utilise `free` pour libérer la mémoire !
```c
free(ptr);
```
où `ptr` est un pointeur dans le heap *qui n'a pas déjà été libéré*, `free` est dans `stdlib.h`

> [!tip] On doit avoir autant de `malloc` que de `free`

On peut aussi initialiser toutes les valeurs à 0 avec `calloc`:
```c
float* ptr = (float*)calloc(n, sizeof(float));
```
où `n` est un entier non null et `calloc` la fonction de `stdlib.h`.
(On vérifie toujours que `ptr != NULL`.)

On peut modifier la taille allouée avec `realloc`:
```c
float* ptr = (float*)realloc(ptr, 10*sizeof(float));
```
où `ptr` est un pointeur et `realloc` la fonction dans `stdlib.h`
## Algorithmiques
Recherche de l'indice de la première valeur dans un tableau
|> on note `x` la valeur à trouver dans `xs` un tableau trié par ordre croissant
|> retourne `i` l'indice de `x`

Quels sont les arguments de cette fonction ? -> `xs`, `x` et la taille de `xs`
Quels sont les sorties ? -> `i` (un int >= -1, où -1 signifie pas trouver)
Quelle méthode employer ? -> dichotomie car le tableau est trié
Comment tester la fonction ? -> avec des valeurs particulières ou en démontrant formellement la fonction
```c
int found(int* arr, int n, int x){
	int i = n >> 1;
	while (arr[i] != x){
		if (x >= n || i <= 0) return -1;
		if (arr[i] > x) i =  i >> 1;
		else if (arr[i] < x) i += i/2;
	}
	return i;
}
```
(on pouvait aussi passer par des pointeurs)

Voir le moodle pour la fonction de trie