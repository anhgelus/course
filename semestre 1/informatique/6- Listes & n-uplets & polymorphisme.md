---
tags:
  - informatique
  - sorbonne
semestre: 1
---
## Liste
Séquence d'un même type
|> s'initialise avec `[]`
|> type `List[T]` où `T` est un type valide (tous les éléments sont de type `T`)
|> pas le droit d'avoir plusieurs types dans une même liste

Principaux problèmes sur les listes :
- réduction = transformer la liste vers un élément plus simple (`bool`, `int`, `str`)
- filtrage = suppression de certains éléments de la liste en fonction d'un critère
- transformation = modification de certains (ou tous les) éléments de la liste (⚠ doit faire la même taille)

Le schéma de transformation `map` applique une même fonction à tous les éléments d'une liste

Le schéma de filtrage `filter` applique un prédicat à tous les éléments et conservent ceux le validant

L'opérateur `+` permet d'ajouter une liste à une autre
|> est plus lourd que le `List[T].append(List[T])`

> [!warning] Mutabilité des listes
> Les listes sont mutables : si on les modifie, alors on modifie la variable mère !
> 
> Ici, on doit créer à chaque fois une nouvelle liste pour éviter de modifier la liste mère
## Polymorphisme
Une fonction peut prendre plusieurs types différents et renvoyer ce type à la fin (e.g., `f(int) -> int` et `f(str) -> str`)
|> pour éviter de faire pleins de fonction, on définit une fonction globale qui prend un paramètre de type `T` et qui renvoie une valeur de type `T`
## n-uplets
Un $n$-uplets est la représentation d'une liste de taille fixée non homogène, par exemple : `HEURE, 13, 44`

Un $n$-uplets est une séquence d'exactement $n$ éléments ordonnées, pouvant être de type différent
|> s'initialise avec `(e_1, ..., e_n)`
|> le type est `Tuple[T_1, ..., T_n]` où $\forall i\in [|1, n|]$, on a $e_i$ de type $T_i$

Pour récupérer les variables d'un $n$-uplets, on fait appel à la déstructuration
```python
u: Tuple[T1, T2] = (value1, value2)
e1, e2 = u
```
on n'a pas besoin de déclarer le type de `e1`, `e2`, etc.

> [!warning] Accès directe et alternative
> On n'a pas le droit d'utiliser l'opérateur `[]` sur les $n$-uplets.
> Par contre, on a le droit d'utiliser la "variable poubelle" `_`, i.e. `e1, _, _, e4 = u`

Les $n$-uplets servent à regrouper des données, à organiser des données et à manipuler des entités avec plusieurs caractéristiques
|> servent principalement dans les paramètres d'une fonction, dans une valeur retour d'une fonction ou dans les listes

On peut déclarer des alias de type avec la syntaxe `Nom = Type`, e.g.
```python
Point = Tuple[float, float]
Nuage = List[Point]
```

> [!warning] Mutabilité des $n$-uplets
> Contrairement aux listes, les $n$-uplets ne sont pas mutables !

> [!tip] Itération sur une liste de $n$-uplets
> On peut déconstruire les $n$-uplets dans une boucle `for` sans avoir besoin de déclarer leur type, e.g.
```python
nuages : Nuage
for (x, y) in nuages:
	print(x, y)
```

