---
tags:
  - sorbonne
  - informatique
  - td
semestre: 2
---
Quand on fait la pile d'un programme, on procède par étape :
1. on commence le bloc de la première fonction (`main`)
2. dans le bloc, on enregistre et on affiche les valeurs des variables (e.g. `i`)
3. quand on rencontre une nouvelle fonction, on crée un nouveau bloc et on retourne à l'étape 2
4. quand on a fini l'exécution de la fonction, on libère la mémoire dans la pile
5. on continue l'exécution du bloc

