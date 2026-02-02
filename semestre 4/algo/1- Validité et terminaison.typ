#import "@local/template:1.0.0": *
#import "@local/callout:1.0.0": *

#show: doc.with(
  authors: (
    (name: "William Hergès", affiliation: "Sorbonne Université", email: "william@herges.fr"),
  ),
  page_title: "Validité et terminaison",
)

= Définitions élémentaires

Un algorithme sert à résoudre un problème.

#defn[
  Un _problème_ $P$ est identifié par un nom, un ensemble de paramètres et une description de la solution.
]

#defn[
  Une _instance d'un problème_ $P$ est une valeur possible pour les paramètres du problème.
]

Définition du problème de tri~:
- nom~: tri
- paramètres~: un entier $n$ et un tableau $"tab"$ de $0$ à $n-1$ de tailles $n$
- solution~: le tableau $"tab"$ trié par ordre croissant

#defn[
  Un _programme_ est composé de~:
  - un ensemble fini de variables
  - des opérations élémentaires portant sur les variables (arithmétiques, logiques, affectations)
  - des structures de contrôle permettant de définir un ordre sur les opérations élémentaires
]

#defn[
  Un _algorithme_ qui résoud un problème $P$ est un programme qui vérifie les deux propriétés suivantes~:
  - *terminaison*~: l'algorithme appliqué à toute instance du problème effectue un nombre fini d'opérations
  - *validité*~: l'algorithme résoud le problème $P$ pour toute instance de $P$
]

Un algorithme doit donc produire une solution en un temps fini qui fonctionne toujours.

On parle aussi de _correction_ pour la validité.

#defn[
  Une _fonction_ est un algorithme qui renvoie une valeur.
]

= Problèmes sur un algorithme

Soit $A$ un algorithme pour résoudre un problème $P$.
- Se termine-t-il~? → terminaison (cette séance)
- Résoud-il $P$~? → validité (cette séance)
- Est-il efficace~? → complexité (séance 3)

== Exemple

Soit le programme
```py
def fibo(n):
  if n == 0:
    return 0
  x = 0
  y = 1
  i = 1
  while i < n:
    z = x+y
    x = y
    y = z
    i = i+1
  return y
```
On cherche à savoir s'il calcule bien le $n$-ième terme de la suite de Fibonacci.

Le corps de boucle est composé d'instructions élémentaires et elle est effecutée $n-1$ fois.
Donc elle se termine pour tout $n$ dans $NN$.

Pour vérifier la correction du programme, on va suivre les variables présentes dans le programme.
Cela revient à faire du débuggage.
Un bon point d'arrêt est en fin de corps de boucle.
Par exemple, on pourrait avoir~:
#table(
  columns: (1fr,) * 3,
  inset: 0.5em,
  align: center,
  stroke: (y: none),
  table.hline(),
  table.header([i], [$x_i$], [$y_i$]),
  table.hline(),
  [1], [0], [1],
  [2], [1], [1],
  [3], [1], [2],
  [4], [2], [3],
  [5], [3], [5],
  [6], [5], [8],
  table.hline(),
)
On obtient alors $8$ pour $n=6$.

Pour la démontrer proprement, on la fait par récurrence.
Soit $cal(P)$ la propriété telle que~:
$ forall i in [|1,n|], quad cal(P)_i: quad x_i = F_(i-1) and y_i = F_i $
On a que $cal(P)_1$ est vérifiée.

Soit $k in NN^*$ tel que $cal(P)_k$ soit vraie.
$ y_(k+1) = x_k + y_k = F_(k)+F_(k-1) = F_(k+1) $
et
$ x_(k+1) = y_k = F_k $
Donc, $cal(P)_(k+1)$ est vraie.

Ainsi, pour tout $n$ dans $NN$, $cal(P)$ est vraie.

_manque la fin de la démo_

== Méthode générale

#warning[
  Nous n'avons pas besoin d'un raisonnement par récurrence pour montrer la terminaison d'un programme.
]

#defn[
  Un _invariant de boucle_ es une propriété qui est vérifiée à chaque exécution du corps de cette boucle.
  Elle est toujours vraie à la fin de la boucle, après avoir incrémentée notre $i$.
]

#warning[
  Tous les invariants ne sont pas utiles~!
]

Pour montrer la validité, on~:
1. détermine un invariant de boucle
2. démontre l'invariant par récurrence sur le nombre d'itérations
3. étudie la sortie de boucle pour conclure sur la validité de la boucle

== Autre exemple

On cherche l'indice de l'élément minimum d'un tableau.
On propose ce programme~:
```py
def RechercheMin(tab):
  imin = 0
  i = 0
  while i < len(tab):
    if tab[i] < tab[imin]:
      imin[i]
    i = i+1
  return imin
```

Notons $n$ la taille de `tab`.

Le nombre d'exécution de ce programme est borné.
En effet, on exécute au maximum $n$ fois le corps de la boucle.

Soit $cal(P)$ la propriété suivante~:
$ forall i in [|0, n|],quad cal(P)_i: quad forall j in [|0, i|], "tab"["imin"_i] <= "tab"[j] $
$cal(P)_0$ est trivialement vraie.

Posons $k$ dans $[|0,n|]$ telle que $cal(P)_k$ soit vraie.
On pose~:
$ "imin"_(k+1) = cases(
  k+1 &"si"& "tab"[k+1] < "tab"["imin"_k],
  "imin"_k &"sinon"&
) $
Or, comme $cal(P)_k$ est vraie, on a $"tab"[i] >= "tab"["imin"_i]$ pour tout $i$ dans $[|0,k|]$.
De plus, on a $"tab"[k+1]>="tab"["imin"_(k+1)]$ et $"tab"["imin"_(k+1)] <= "tab"["imin"_k]$ par définition de
$"imin"_(k+1)$.
Donc $cal(P)_(k+1)$ est vraie.

Ainsi, pour tout $i$ dans $[|0,n|]$, $cal(P)_i$ est vérifiée.

En sortie de boucle, $cal(P)_n$ est vraie et renvoie $"imin"_n$.
Comme $cal(P)_n$ est vraie, $"tab"["imin"_n]$ est le plus petit élément de `tab`.
Alors, le programme est valide.
