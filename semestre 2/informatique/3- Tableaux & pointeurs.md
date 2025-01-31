---
tags:
  - sorbonne
  - informatique
semestre: 2
---
La taille du pointeurs dépend de l'architecture
|> sur une machine 64 bits, il est sur 8 octets ($8\times 8 = 64$)
|> donc, `int *` prend plus de place que `int` !
## Tableaux
Un tableau est une suite de valeurs en mémoire
|> les valeurs  sont toutes du même type

Il y a deux types de tableaux en C :
- tableaux statiques sont de tailles fixes localisés dans la pile (stack) (`float[12]`)
- tableaux dynamiques sont de tailles... dynamiques localisés dans le tas (heap)

On déclare un tableau statique (array) comme ça :
```c
type var[size];
```
e.g.
```c
int tab[12];
```
déclare un tableau contenant 12 entiers

> [!warning] Les indices négatifs n'existent pas !

On assigne une valeur avec 
```c
var[indice] = val;
```
e.g.
```c
tab[0] = 1;
```
assigne `1` dans `tab` à l'indice `0`

On peut déclarer et initialiser un tableau avec les accolades, e.g.
```c
float tab[5] = {0, 1.1, 10.9, 5, 5.6};
```

> [!warning] On ne peut pas assigner plus tard un tableau avec des accolades !

Représentation d'un tableau dans la pile
![[array_stack_c.png]]
ici, `i` est un indice dans une boucle (`for` ici)
Ici c'est `pile (1)` car on écrit c'est la pile à l'étape 1 (écrit en commentaire sur le code donné sur moodle)

Or, les arrays sont des pointeurs !
On a donc que :
```c
int main(){
	int tab[3] = {0, 1, 2};
	int *a = tab+2;
	printf("%d", *a);
	return 0;
}
```
affiche `2` !
Ici, `tab+2` est équivalent à prendre l'adresse de la 3e valeur du tableau
Quand on passe un tableau en paramètre, on obtient en réalité un pointeur
|> tout ce qu'on réalisera avec ce paramètre affectera donc le tableau d'origine !

> [!important] Longueur d'un array
> Il n'existe aucun moyen d'avoir la longueur d'un array en C : on doit passer sa taille en paramètre en plus du tableau (sans spécifier sa taille)

> [!danger] Il n'y a pas d'erreur du style "Index Out Of Bound" en C, donc on doit faire attention à comment on manipule les tableaux
## Macro
On peut définir des raccourcies appelé macro, avec `#define` :
```c
#define N 5
int main(){
	printf("%d\n", N);
	return 0;
}
```
À chaque fois que le programme rencontrera `N`, il remplacera par `5`

> [!danger] On ne met jamais de `;` lors de la définition d'une macro !

Le préprocesseur est la partie du compilateur qui lie les instructions commençant par `#`
## Compréhension plus avancée de la pile
Chaque zone dans la pile appartient à une fonction
|> chaque zone possède ses propres noms : elle n'a pas accès aux autres noms de variables

Pour qu'une fonction puisse accéder aux variables des autres fonctions, on doit utiliser les pointeurs !
## Fonction `scanf`
Elle permet de récupérer l'entrée donnée par l'utilisateur au clavier
|> elle prend 2 paramètres : le⋅s type⋅s et un pointeur
|> le type est par exemple `"%d"`pour un entier ou `"%c"` pour un caractère
|> le pointeur est la variable devant recevoir la variable
|> (elle ajoute automatiquement le `"\n"` après la saisi de l'utilisateur)

```c
int main(){
	char c;
	int i;
	
	printf("Saisir un caractère\n");
	scanf("%c", &c);
	printf("Vous avez saisi %c\n", c);
	
	printf("Saisir un entier\n");
	scanf("%d", &i);
	printf("Vous avez saisi %d\n", i);
	return 0;
}
```
## Arithmétique des pointeurs
Soit `ns` un array d'int de taille 42. Soit `a` un pointeur référencé sur `ns`. En C, on a donc :
```c
int ns[42];
int *a = ns;
```
On a :
`&ns[0]` $\equiv$ `a`
`&ns[1]` $\equiv$ `a+1`
`&ns[2]` $\equiv$ `a+2`
`&ns[3]` $\equiv$ `a+3`
...
et
`ns[0]` $\equiv$ `*a`
`ns[1]` $\equiv$ `*(a+1)`
`ns[2]` $\equiv$ `*(a+2)`
`ns[3]` $\equiv$ `*(a+2)`
...
