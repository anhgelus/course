---
tags:
  - sorbonne
  - informatique
  - structure-des-données
semestre: 3
---
Problème de l'AVL
|> besoin de faire des rotations, ce qui transforme tout le graphe
|> concurrence impossible, change beaucoup en mémoire -> est très morcelé (donc défaut de page)
## Arbre rouge-noir
-> ici, on s'occupe de la fragmentation mémoire

Arbre rouge-noir
|> AVL demandant moins de rotations
|> racine est noire
|> fils d'un rouge est noir
**voir le diapo pour les autres specs**

Problème de ces arbres
|> beaucoup de cas à gérer
## Skip lists
-> ici, on s'occupe des la concurrence