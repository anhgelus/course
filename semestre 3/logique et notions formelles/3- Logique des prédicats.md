---
tags:
  - sorbonne
  - philosophie
  - logique-notions-formelles
semestre: 3
---
Différence entre logique propositionnelle et celle des prédicats est la présence des quantificateurs

Sans quantificateur, on ne peut pas bien retranscrire tous les arguments

- Tous les philosophes sont des mammifères
- Descartes est un philosophe
-> Descartes est un mammifère

La version formelle est "`p` et `q`, donc `r`"
|> impossible de vérifier formellement
-> la logique des prédicats décompose les énoncés atomiques pour se libérer de ce problème

"Léon voit la Tour Eiffel"
|> deux désignateurs/termes : "Léon" et "Tour Eiffel"
|> prédicat "voit" relie les deux
-> on touche au langage non logique

L'arité est le nombre de termes utilisés par un prédicat
|> unaire, binaire, ternaire, 4-aire...
|> on indique l'arité en exposant, i.e. $A^2$ indique que le prédicat $A$ est binaire

Pour écrire "Thomas aime Marie", on ***doit*** l'écrire comme ça :
- $A^2$ : ...aime...
- $t$ : Thomas
- $m$: Marie
- $A^2tm$

> [!warning] L'ordre est important !

$\forall$ permet de traduire les "tous"
$\exists$ permet de traduire les "certains", "il existe"...

Les quantificateurs sont toujours utilisés comme ça :
$$ \forall x(Ax\to Bx) $$
Les parenthèses ne viennent pas des quantificateurs, elles viennent toujours des relations binaires
|> elles sont obligatoires

$\forall e,\exists o(P^2eo)$