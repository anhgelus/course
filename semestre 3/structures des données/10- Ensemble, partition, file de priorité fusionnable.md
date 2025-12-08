---
tags:
  - sorbonne
  - informatique
  - structure-des-données
semestre: 3
---
## Ensemble
Opérations sur les ensembles :
- insertion
- suppression
- vérification
- union
- intersection

On utilise une hash table sans valeur pour représenter un ensemble non ordonnée
|> permet d'être en $O(1)$ sur la majorité des opérations, l'union est en $O(n)$ et l'intersection en $O(n_1+n_2)$
|> besoin de réimplémenter la hash table pour enlever la valeur

On peut utiliser des AVL si on cherche à avoir un ordre
|> plus lent que la hash table (on est en $O(\log n)$)