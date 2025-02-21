---
tags:
  - sorbonne
  - informatique
  - td
semestre: 2
---
Pour utiliser du random en C, on a besoin de `stdlib.h`
- `srand` permet de set la seed (on peut utiliser `time(NULL))` qui est dans `time.h` pour utiliser le timestamp actuel)
- `rand` donne un aléatoire entre 0 et `RAND_MAX` (une constante prédéfinie)
