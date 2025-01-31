---
tags:
  - sorbonne
  - informatique
semestre: 1
---
Commence la deuxième partie du cours : nouvelles données (nouveaux types)
|> on va voir les String, les listes, les ensembles et les dictionnaires -> ce sont des séquences

Actuellement, python est suffisamment expressif (Turing-complet)
|> on peut faire des calculs numériques et logiques complexes
|> notions correction, terminaison et efficacité
## Structure de données
On peut tout représenter par des entiers (codages de Gödel)
|> existence de fonctions bijectives de $\mathbb{N}^m\to\mathbb{N}$
|> tout est codé en bits

Besoin d'une abstraction pour que ce soit plus simple
-> ce sont les structures de données

Une structure de données est une entité informatique qui regroupe et organise des données (ses éléments)
|> interface est un ensemble de primitives qui permettent son utilisation (construction, destruction, utilisation)
|> implémentation est le code implémentant l'interface
## Séquence
Sous-type d'une structure de données
|> elles sont ordonnées, possèdent un nombre de données fini et des données de même type
|> on peut itérer dessus pour tous les lire dans l'ordre
On utilise une séquence pour répéter une action pour chacun de ses éléments dans l'ordre de la séquence
|> la boucle s'arrête toujours

Pour itérer sur une séquence, on écrit :
```python
v: type
for v in seq:
```

`v` est la valeur successive dans la séquence `seq`

> [!warning] On doit déclarer `v` avant la boucle !

Pour récupérer une partie, on peut utiliser `var[m:n]`, attention `n` est exclu
```python
s: str = "01234567"
print(s[2:5]) # "234"
```

Une réduction est la construction d'une information structurellement plus simple en parcourant la séquence

On peut découper une séquence en utilisant `[i:j:n]`
|> `i` est l'indice du début
|> `j` est l'indice de fin *exclu*
|> `n` est le pas entre chaque élément
|> si `i` ou `j` ou `n` est négatif, prend les indices avec un ordre décroissant
|> si `j<i`, alors donne `[]`
|> si `j` est plus grand que la liste, alors donne toute la liste

```python
l = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
l[5:] # == [5, 6, 7, 8, 9]
l[:5] # == [0, 1, 2, 3, 4]
l[2:5] # == [2, 3, 4]
l[::2] # == [0, 2, 4, 6, 8]
l[1::2] # == [1, 3, 5, 7, 9]
l[1:8:3] # == [1, 4, 7]
```
## Intervalle
Séquence d'entiers consécutifs ordonnées par l'ordre standard
i.e. $[|m,n|]$

Pour créer un intervalle $[|m,n[|$, on fait :
```python
m: int
n: int
range(m, n)
```

> [!warning] $n$ est exclu !

> [!info] On peut utiliser `range(n)`
## Chaîne de caractères
Type `str`
Est une séquence

On peut récupérer le caractère lié à un entier avec :
```python
chr(int) -> str
```
Et l'entier lié au caractère avec :
```python
ord(str) -> int
```

L'opérateur `*` est autorisé sur les string :
```python
s: str = "ab"
s = s*3
print(s) # "ababab"
```

L'opérateur `<` (resp. `>`) suit l'ordre lexicographique (resp. l'inverse de cet ordre) :
- suit l'entier associé
- `'Z' < 'a'` est vrai
- `'a' < 'b'` est vrai
- `'a' > '1'` est vrai