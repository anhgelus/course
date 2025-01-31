---
tags:
  - sorbonne
  - informatique
semestre: 1
---
Problème de nos structures de données : comment on représente des structures non ordonnées ?
|> les séquences ont forcément un ordre
|> exemple de structure de données sans ordre : les ensembles mathématiques

> [!fail] Problèmes des listes
> pour ce type de structure de données
> - ordonnées
> - occurrences multiples
> - besoin de parcourir toute la liste
## Ensembles
Ensembles :
- il n'y a pas d'ordre
- il n'y a pas de doublon
- l'appartenance est efficace

Ensemble = collection d'objets distincts, ses objets s'appellent les éléments de l'ensemble
```python
s: Set[T] = {e1, e2, ..., ei}
```
où `T` est un type immutable (e.g., entiers, strings) et $\forall ei$ de type `T` (si un `ei` est égal à un autre `ei`, alors il est retiré)
|> l'ensemble doit être homogène

> [!warning] Mutabilité des ensembles
> Un ensemble est mutable, mais il contient des éléments immutable
> |> on ne peut pas avoir d'ensemble de liste

L'accès direct à partir de la clef est bien plus efficace que l'accès par indice classique

Pour créer un ensemble, on utilise `set()` !
```python
ens: Set[T] = set()
```

On teste l'appartenance d'un élément à un ensemble avec l'opérateur booléen `in` :
```python
elem in ensemble
```
La non appartenance se note :
```python
elem not in ensemble
```

Pour ajouter des éléments, on utilise :
```python
ens.add(elem)
```
où `ens` est un `Set[T]` et `elem` est un `T`

Pour retirer des éléments, on fait :
```python
ens.remove(elem)
```
où `ens` est un `Set[T]` et `elem` est un `T`

> [!tip] Efficacité
> `ens.add` est plus efficace que `l.append`, de même pour `ens.remove` (sachant que remove n'a pas d'équivalence sur les listes)

On itère dessus en parcourant forcément par élément (car non ordonné !)
```python
ens: Set[T] = set()
e: T
for e in ens:
	...
```

> [!info] Simulation sur les ensembles
> On choisit un ordre arbitraire pour faire la simulation de boucle

Opérateurs spéciaux booléens
- `<` est équivalent à $\subset$
- `<=` est équivalent à $\subset\lor =$ 
- `>` est l'inverse de `<`
- etc.

Opérateurs spéciaux ensemblistes
- `|` représente $\cup$
- `&` représente $\cap$
- `-` est la différence (i.e. `e1 - e2` = $E_1\backslash E_2$)
- `+` est l'addition (i.e. `e1+e2` = $E_1+E_2$)

On essaye d'utiliser un maximum ces opérateurs car :
- ils sont plus élégants
- ils sont parfois légèrement plus efficace

On peut faire des compréhensions avec les ensembles, e.g.
```python
{exp for e in seq if pred}
```
où `exp` est une expression, `seq` un itérable et `pred` un prédicat
## Dictionnaire
Sont des tableaux associatifs
|> prend des clefs *immutable* qui sont forcément associés à une valeur

Les clefs forment un ensemble

Création d'un dictionnaire :
```python
dictionnaire: Dict[str, str] = {
	"hello": "world",
	"what's": "up"
}
```

Pour set et get :
```python
dico["hello"] = "world"
s: str = dico["hello"] # s contient "world"
```
où `dico` est de type `Dict[str, str]`

Deux manière d'itérer sur les dictionnaires :
```python
# sur les clefs
for key in dico:
	# ...
for key, value in dico.items():
	# ...
```
où `dico` est un dictionnaire

Voir le diapo pour voir comment on fait une simulation

On peut aussi faire des compréhensions avec les dictionnaires ! E.g.
```python
{exp1:exp2 for e in seq if pred}
```
où `exp1` et `exp2` sont deux expressions, `seq` un itérable et `pred` un prédicat