---
tags:
  - sorbonne
  - informatique
semestre: 2
---
## Tableaux à plusieurs dimensions
Pour déclarer un tableau à deux dimensions, on fait :
```c
T tab[n1][n2];
```
où `n1` et `n2` sont deux entiers naturels non nul et `T` est un type valide.

On a que `tab[0][a] = *(tab+a)` et que `tab[b][a] = *(tab+a+n2*b)` (`n2` étant la taille de tableau à l'intérieur)
|> besoin de connaître la taille des deux lignes !
|> d'une manière plus concrète, on a `tab[4][5]`, donc `tab[2][3] = *(tab+3+2*5)`
## Strings
Un caractère est de type `char` et peut se noter avec un entier ou un caractère ASCII avec `''` (i.e. `'a'`)
|> est enregistré sur un octet : 256 valeurs possibles
|> est affichable avec `%d` (car est un petit int) et `%c`
|> ne contient pas assez de place pour tout afficher : problème pour encoder les accents -> besoin d'utiliser une autre table d'encodage

> [!NOTE] Interprétation des `char`
> En C, on peut remplacer n'importe quelle valeur entière `char` par leur équivalent en caractère

Les chaînes de caractères sont entre `""` (i.e. `"hello world"`) : ce sont des `char[]`
|> se termine ***toujours*** par `\0` (est le 0 ou le null des chaînes de caractères)
|> on peut les déclarer classiquement avec `char s[8] = "bonjour";`
|> on les affiche avec `%s`

> [!info] Le `\0` est sous-entendu avec les guillemets, mais pas quand on déclare manuellement (avec un tableau)

> [!warning] Différence entre strings et tableau de caractère
> Si on n'utilise pas de `\0` dans un tableau, cela devient un array de caractère

> [!error] Initialisation d'un string
> Quand on initialise et assigne un string, on doit bien faire attention à ce que le tableau soit assez grand

> [!warning] On ne peut pas modifier une chaîne de caractère statique
> i.e. `char *p = "hello"` n'est pas modifiable
> 
> Par contre, `char s[] = "hello";`, `char *p = s;` et `p[0] = 'H'` est valide

La bibliothèque de gestion des strings est `string.h`
|> permet de compter la taille d'un string avec `strlen`
|> *voir poly pour les autres fonctions*

> [!warning] Les chaines de caractère sont des arrays !
> Donc, quand on doit renvoyer une nouvelle chaîne de caractères, on doit utiliser `malloc` pour éviter d'avoir un segmentation fault !
