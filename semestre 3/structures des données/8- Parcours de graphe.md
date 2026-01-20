---
tags:
  - sorbonne
  - informatique
  - structure-des-données
semestre: 3
---
On cherche à apprendre à parcourir tous les chemins possibles
|> permet de savoir si un sommet $r$ est accessible depuis un sommet $s$
Pires cas :
- $r$ n'est pas accessible
- trouver $r$ en dernier
## Sous-parcours
On appelle la racine du parcours est l'endroit où on commence

Un algorithme de « sous-parcours » est un algorithme de parcours commençant à la racine du parcours (noté $r$)
|> formellement, il retourne $L=(s_1,\ldots,s_k)$ telle que :
- $s_1 = r$
- $s1,\ldots,s_k$ est l'ensemble des sommets accessibles à partir de $r$
- pour tout $i\in\{2,\ldots,k\}$, il existe $j\in\{1,\ldots,i-1\}$ telle que $(s_j,s_i)$ est un arc (ou une arête) du graphe (on parlera de bordure)

**Vocabulaire**
- **Sommet visité** = un sommet qui a été ajouté au sous-parcours
- **Sommet non-visité** = un sommet qui n’a pas (encore) été ajouté au sous-parcours
- **Sommet ouvert** = un sommet visité dans un cadre dont tous les descendants (ou sommets accessibles) n’ont pas encore été visités
- **Sommet fermé** = un sommet visité dont tous les descendants (ou sommets accessibles) ont été visités
- **Bordure d’une liste de sommet** = étant donné une liste L de sommets visités, la bordure B(L) est l’ensemble des sommets non-visités qui sont successeurs (ou voisins) d’au moins un sommet dans la liste ; formellement, dans le graphe $G = (S, A)$, on a :
 $$ B(L) = \{s\in S\backslash L| \exists t \in L, (t,s)\in A\}~\text{en orienté} $$
 $$ B(L) = \{s\in S\backslash L| \exists t \in L, \{t,s\}\in A\}~\text{en non-orienté} $$

```
L = Liste(r)
Tant que B(L) n'est pas vide :
	Choisir un sommet s dans B(L)
	Ajouter s à la fin de la liste L
Fin Tant que
```
À la fin de ce parcours
|> tous les sommets visités sont fermés
|> un sommet non-visité est inaccessible depuis $r$

Cette algo est en $O(n^2)$ car $B(L)$ est en $O(n)$
|> pas ouf
-> pour éviter d'être aussi lent, on peut facilement mettre à jour B(L) à chaque itération
|> transforme l'algo en $O(n)$
## Parcours
Un algorithme de « parcours » doit parcourir tous les nœuds
|> besoin de relancer l'algo de sous-parcours quand il s'arrête
|> les racines de tous les sous-parcours sont des points de régénération

```
L=Liste(r)
Tant qu’il existe un sommet non-visité :
	Si B(L) est non vide:
		Choisir un sommet s dans B(L)
	Sinon:
		Choisir un sommet s non visité  <--- il n'existe pas de bon choix
	Fin Si
	Ajouter s à la fin de la liste L
Fin Tant que
```
## Stratégie de parcours
Quand on choisit un sommet, on a plusieurs possibilités :
- aléatoire
- profondeur -> va le plus loin possible dans le chemin courant
- largeur -> évite d'aller le plus loin possible
- le plus proche (au sens d'une distance)
- etc

Elles permettent toutes de trouver les sommets accessibles depuis $r$
|> mais les trois dernières donnent des informations sur le graphe !
### Parcours en profondeur
Parcours en profondeur (ou DFS, *deep first search*) est le fait de choisir systématiquement d'explorer un successeur (ou un voisin) du dernier sommet visité ouvert

```
L=Liste(r)
Tant que B(L) n'est pas vide :
	Choisir un sommet s dans B(L) qui est successeur (ou voisin) du dernier sommet ouvert de L
	L = union de L et {s}
Fin Tant que
```

Dans ce type de parcours, la bordure est... une pile !
|> version récursive n'a pas besoin de pile explicite
|> version itérative a besoin d'expliciter la pile (et donc de construire une struct pour)

**voir le code sur les diapos**

Complexité temporelle, chaque ligne de code est exécuté :
- une fois
- au maximum une fois par sommet ($n$)
- au maximum une fois par arcs ou arêtes ($m$ ou $2m$)
-> $O(n+m)$

Occupation mémoire est similaire pour itérative et récursive pour des $n$ pas trop grand
|> par contre, comme récursive n'est pas terminal, elle prendra plus de place pour des $n$ très grands
### Parcours en largeur
```
L = Liste(r)
Tant que B(L) n'est pas vide
	Choisir un sommet s dans B(L) qui est successeur (ou voisin) du premier sommet ouvert de L
	L = union de L et {s}
Fin Tant que
```

Le code *itératif* est similaire au parcours en profondeur
|> on remplace juste la pile par une file

1. Comme dans un ABR
2. Si nœud est remplacé par