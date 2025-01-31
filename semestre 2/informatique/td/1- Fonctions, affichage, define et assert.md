---
tags:
  - sorbonne
  - informatique
  - td
semestre: 2
---
Pour afficher des valeurs en C, on utilise `printf`:

| Format | Type                             |
| ------ | -------------------------------- |
| `%d`   | `int`                            |
| `%f`   | `float`                          |
| `%.xf` | `float` et affiche `x` virgule⋅s |
| `%c`   | `char`                           |
| `%s`   | une chaîne de caractères         |

> [!warning] Booléen en C
> On n'oublie pas que les booléens n'existent pas en C !
> Ils sont remplacés par des entiers où 0 est false et tous les autres valeurs est vrai.
> Donc, `1 == 1` vaut `1` et `1 == 0` vaut `0` !

On peut créer des constantes en C grâce à `#define` :
```c
#define ZERO 0
```
