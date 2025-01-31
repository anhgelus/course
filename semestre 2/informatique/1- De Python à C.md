---
tags:
  - sorbonne
  - informatique
semestre: 2
---
```c
#include <stdio.h>
#include <stdlib.h>

/* premier programme */

int main(){
	printf("Hello World\n");
	return 0;
}
```

On écrit des programmes comme éditeur de texte
|> Visual Studio Code
|> gedit
|> vi/vim
|> emacs
-> permet d'écrire le programme

Au début, on écrit les bibliothèques :
```c
#include <stdio.h>
#include <stdlib.h>
```

Les commentaires s'écrivent comme ça :
```c
/* bonjour, 
je suis un commentaire sur
plusieurs lignes */

// bonjour, je suis sur une seule ligne
```

(le deuxième type de commentaire provient du C++, mais souvent ça passe)

Après, on doit toujours écrire une fonction `main` :
```c
int main(){
	/* ... */
	return 0;
}
```

Après avoir écrit notre programme, on doit faire en sorte qu'il soit exécutable
|> est la compilation
|> on utilise `gcc` (GNU C Compiler) pour compiler le texte

Pour compiler, on fait :
```bash
$ gcc -Wall -o hello_world hello_world.c
$ ./hello_world
Hello World
$
```

Le `-Wall` veut dire "Warning all", i.e. affiche tous les warnings
## Fonctions
Quand on définit une fonction, on a besoin de spécifier :
- le type de retour (`void` si rien n'est retourné)
- le nom de la fonction
- les arguments avec leur type
- le corps de la fonction (entre accolades)

Les blocks en C sont définis par des accolages (`{ ... }`)

Toutes les lignes d'instructions se finissent par un `;`

On a toujours besoin d'une *unique* fonction `main` par programme.

On peut définir plusieurs fonctions dans un programme, e.g.
```c
void hello(){
	printf("Hello World\n");
}

int main(){
	hello();
	return 0;
}
```

> [!warning] Définition d'une fonction
> On a besoin de définir une fonction avant de l'utiliser !
## Types que l'on utilise

| Type  | Signification    | Taille (o) | Plage de valeurs                | Exemple |
| ----- | ---------------- | ---------- | ------------------------------- | ------- |
| char  | Caractère        | 1          | -128 à 127                      | 'a'     |
| int   | Entier           | 4          | -2 147 483 648 à  2 147 483 647 | 25      |
| float | Simple précision | 4          | $\pm$ ...                       | 3.14    |
> [!warning] `'a'` et `"a"`
> Ce sont des types différents !
> `'a'` est un caractère tandis que `"a"` est une chaîne de caractère !

> [!warning] Booléen en C
> Il n'existe pas de booléen en C : on utilise donc les `int` pour décrire l'état.
> `0` est vraie, le reste est faux.
## Arguments dans une fonction
On les place dans les parenthèses et il fonctionne comme en Java
```c
void hello(int annee){
	printf("Hello World %d!\n", annee)
}

int main(){
	hello(2025);
	return 0;
}
```

La fonction `printf` ici est utilisée pour formaté un string que l'on va ensuite afficher
|> `"%d"` insert un `int`
|> `"%f"` insert un `float`
|> `"%c"` insert un `char`
|> les valeurs que l'on insert sans mise après le format
i.e.
```c
printf("Hello World%d-%d\n", 2024, 2025);
// est équivalent à
printf("Hello World 2024-2025\n");
```
## Variables
On est obligé de déclarer les variables avec leur type, i.e.
```c
int p;
p = 5;

float a=1, b=2.5, c=-2.5;
```

> [!warning] Porté des variables
> Les variables sont locales au bloc ! On ne peut pas y accéder autre part !
> (comme en python)

![[used_operators_c.png]]

> [!warning] Division en C
> Si on a une division d'un entier par un entier, on obtient un... entier !
> Pour avoir un `float`, on doit faire quelque chose comme `int / (float) int`

## De Python à C
### Syntaxe simple
```python
def perimetre(largeur: int, longeur: int) -> int:
	"""Precond: longueur >= largeur >= 0
	Retourne le périmètre du rectangle défini par sa longeur et sa largeur"""
	return 2*(largeur + longueur)
```
devient en C
```c
/* hypothèse: longueur >= largeur >= 0
retourne le périmetre du rectangle défini par sa longueur et sa largeur*/
int perimetre(int largeur, int longueur){
	return 2*(largeur + longueur);
}
```
### Structures de contrôle
Un `if/else` s'écrit :
```c
if (cond) {
	//
} else {
	//
}
```
où `cond` est un booléen

Un `while` s'écrit :
```c
while (cond) {
	//
}
```
où `cond` est toujours un booléen

Une nouvelle boucle : la `do while` qui est une boucle `while` où la condition est testée à la fin de la boucle (i.e. elle tourne toujours au moins 1 fois)
```c
do {
	//
} while (cond);
```
où `cond` est encore un booléen
⚠ il y a un `;` après le while

La boucle `for` est comme celle en java
```c
int n = 5;
int i;
for (i = 0; i <= n; i++) {
	printf("%d", i);
}
```
est équivalente à
```c
int i;
i = 0;
while (i <= n) {
	printf("%d", i);
	i++;
}
```
