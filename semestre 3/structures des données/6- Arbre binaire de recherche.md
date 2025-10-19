---
tags:
  - sorbonne
  - informatique
  - structure-des-données
semestre: 3
---
Propriété d'ordre dans un arbre permet d'améliorer la recherche de valeurs

Arbre binaire de recherche (ABR) permet de représenter un ensemble ordonné
|> chaque nœud a une valeur plus grande que celles contenues dans son sous-arbre gauche et plus petite que celles dans son sous-arbre droit

On note $h$ sa hauteur

Il s'agit de la même implémentation que pour les btree.

min et max sont plus simples
|> pour le min, on regarde à gauche -> $O(\log n)$
|> pour le max, on regarde à droite -> $O(\log n)$

**Voir diapo pour toutes les implémentations standards**

La vérification s'il s'agit d'un ABR est en $O(n)$

Très efficace si on a besoin d'avoir qlq chose de tout le temps trié
|> très efficace pour rechercher aussi (tjs en $O(h)$)

L'insertion se fait en $O(h)$ -> on recherche où il va

Quand on supprime, on doit remonter une valeur
|> soit on remonte son unique fils, soit on remonte le min de sous-arbre droit
|> pour supprimer un min, on le remplace juste par son unique fils (ou par rien)
-> toujours en $O(h)$

> [!warning] il n'existe pas de relation entre $n$ et $h$ !
## AVL (ABR équilibré)
Cette structure cherche à équilibrer l'ABR pour avoir une relation entre $n$ et $h$
|> besoin de gérer l'insertion et la suppression -> est compliqué de gérer ça

On a donc créer l'AVL qui est un ABR équilibré
|> propriété d'équilibre = la différence des hauteurs des fils gauche et droit de tout nœud ne peut excéder 1
|> on a donc $h=\log n$
-> tout devient en $\log n$ 🎉
|> besoin donc de gérer l'insertion et la suppression pour garder cette propriété

AVL a besoin d'un champ en plus par rapport au BTree -> la hauteur
|> permet d'éviter de recalculer la hauteur des nœuds (qui coûte $O(h)=O(\log n)$)

Lors de la création d'un nœud, on a besoin de calculer la hauteur

Insertion/suppression comme dans un ABR
|> par contre, si ça déséquilibre, on corrige
|> pour corriger, on utilise des rotations *voir le diapo*
-> on ne perd pas en complexité, tout reste en $O(h) = O(\log n)$

*voir le diapo pour le principe précis d'insertion / suppression*
## Tableau associatif
Les AVL peuvent être pertinent pour les tableaux associatifs

Hash est pertinent quand :
- l'ordre des clefs n'est pas pertinent
- on veut une performance constante
- fonction de hachage bien choisie

Parcourt trié est pertinent :
- l'ordre des clefs est important
- trouver le min, le max, le successeur, le prédécesseur...
- faire des recherches par intervalles de clés

AVL consomme moins de RAM et possède un meilleur pire cas