---
tags:
  - sorbonne
  - informatique
  - structure-des-données
semestre: 3
---
Graphe orienté est un couple $G=(S,A)$ où $S$ est un ensemble d'éléments appelés sommets et $A$ es un ensemble de paires orientées de sommets de $S\times S$ appelées arcs
|> nombre de sommets est noté $n$
|> nombre d'arcs est noté $m$

Un sommet est représenté graphiquement par un rond ou un carré numéroté
|> sa valeur est le numéro du rond/carré

Arc est une paire orientée de sommets (appelés les extrémités de l'arcs)
**rattraper**

> [!warning] Circuit = cycle en anglais !

Type de donnée « graphe » représente les graphes orientés en maths

Graphe ne possède pas d'entrée, à l'inverse de toutes les structures précédentes
|> permet de tout représenter

Besoin de choisir quelle implémentation est importante pour optimiser
|> dynamique (ajout et suppression de sommets/arcs fréquent)
|> peu dynamique (le plus fréquent)

**Hypothèses $n$ et $m$ sont quasiment fixés -> est peu dynamique**

Deux implémentations classiques
|> matrice d'adjacence -> $O(1)$, mais beaucoup de places mémoires
|> liste d'adjacence -> $O(n)$, mais prend peu de places
-> d'autres implémentations existent et peuvent être préférables lors de certains algo

**Voir le diapo pour la def de matrices et listes d'adjacence**