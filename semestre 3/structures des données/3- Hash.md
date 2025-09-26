---
tags:
  - sorbonne
  - informatique
  - structure-des-données
semestre: 3
---
## Tableaux associatifs
**Rattraper le cours**

Tableaux associatifs peuvent être implémentés à l'aide de deux structures de données :
- les tables de hachage
- arbres binaires de recherche équilibré (cf le futur cours 6)

Ces deux implémentations possèdent chacune leurs avantages

Une table de hachage est une structure de données permettant d'implémenter un tableau associatif par un tableau
|> l'univers $U$ n'est pas forcément que des entiers
|> une fonction de hachage $h:U\to \{0,\ldots,m-1\}$ permet de transformer les $m$ clés en indice du tableau
### Fonction de hachage
Une fonction de hachage peut engendrer des collisions !
|> besoin de bien choisir $h$
|> besoin de choisir un mécanisme de gestion de collisions adapté
|> en pratique, il est impossible d'éviter les collisions car, souvent, $|U| \gg m$

Une fonction de hachage est une bonne fonction quand :
- elle se calcule rapidement
- les collisions sont rares

Une fonction de hachage $h$ se fait souvent en deux étapes :
1. une fonction $f$ de $U$ vers $\mathbb{N}$
2. une fonction $g$ de $\mathbb{N}$ vers $\{0,\ldots,m-1\}$
3. $h$ est ainsi $g\circ f$

Méthodes classiques :
- hachage par division -> $g(x)=x \% m$ (où $m$ est premier pas trop proche d'une puissance de 2)
- hachage par multiplication -> $g(x)=\lfloor m(xA-\lfloor xA\rfloor)\rfloor$ où $A\in]0,1[$ — si $A$ est irrationnel, les clés se répartissent presque uniformément, on dit que le choix de $m$ est non critique ; souvent, on choisit le nombre d'or $A=\varphi-1=\frac{\sqrt 5 - 1}{2}$
### Collision par liste chaînée
Comment gérer les collisions ?
-> on peut faire une liste chaînée
|> au lieu de contenir une unique valeur, on contient une liste chaînée avec toutes les collisions
|> on a besoin de stocker la clé pour pouvoir trouver la bonne valeur
#### Complexité
Soit $m$ la taille de la table de hachage et $n$ est le nombre d'éléments qu'elle contient.

On suppose que $h(k)$ est en $O(1)$.
On suppose que $h$ est uniforme simple -> chaque case de la table a la même chance de recevoir un élément tiré au hasard
On suppose que la table est bien dimensionnée -> $\exists c>0,\quad m=c\times n$

> [!NOTE] Pourquoi ces hypothèses ?
> Si on ne suppose pas que $h(k)$ est uniforme, on se retrouve avec le même comportement qu'une liste chaînée
> 
> Si $h(k)$ n'est pas en $O(1)$, on augmente énormément la complexité.

À cause de ces hypothèses, on a des complexités en moyenne, que l'on note $0_{moy}$.

**Rattraper facteur de charge**

La recherche d'un élément possédant une clé $k$ est en $O_{moy}(1)$
|> $O_{moy}(1+\alpha)=O_{moy}(\alpha)$ car $\alpha$ est la taille moyenne de la liste gérant les collisions et que $O_{moy}(1)$ provient de la complexité de $h$
|> Or, comme $\alpha=\frac{n}{m}$, on a que $O_{moy}\left(\frac{n}{m}\right)=O_{moy}\left(\frac{n}{cn}\right)=O_{moy}(1)$

L'insertion d'un élément (clé $k$, valeur $v$) est en $O_{moy}(1)$
|> on vérifie que l'élément existe dans la liste, ce qui est en $O_{moy}(1)$
|> puis on l'ajoute en tête de liste, ce qui est en $O(1)$

La suppression est aussi en $O(1)$ si la liste est doublement chaînée
|> si elle est simplement chaînée, on est en $O_{moy}(1)$
#### Problème
On a besoin de stocker le pointeur
|> augmente la taille des données
|> mauvaise localité de cache (mémoire pas forcément contiguë)
### Collision par adressage ouvert
Cherche à résoudre les problèmes des listes chaînées

Maintenant, une case une ne contient qu'un élément
**Rattraper cours, j'ai trop faim pour bien prendre en note**

probing quadratic, souvent, $c=d=\frac 12$
## Filtre de Bloom
Permet de tester efficacement si un élément est dans un ensemble
|> permet d'éviter beaucoup de recherches non fructueuses

Structure probabiliste permet de savoir
|> avec certitude si un élément n'est pas présent
|> avec une certaine probabilité si un élément est présent
-> peut donner des faux positifs, mais ne donne pas de faux négatif

**Rattraper cours pour la même raison**
pb dans l'exemple -> les flèches de w doivent arriver sur que des 1