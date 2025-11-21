---
tags:
  - sorbonne
  - philosophie
  - logique-notions-formelles
semestre: 3
---
Limites de l'approche conceptuelle :
1. comment savoir qu'il y a conséquence logique ? (limite épistémique) -> quand les modèles possibles sont en nombre essentiellement fini, on peut les inspecter, mais ce n’est pas toujours le cas
2. autre intuition quant à la nature de la conséquence logique : il y a conséquence logique quand il y a une *preuve* (limite conceptuelle) -> « ces longues chaînes de raisons toutes simples et faciles, dont les géomètres ont coutume de se servir » (Descartes, _Discours de la méthode_)
## Approche preuve-théorie
Idée : proposer une notion de conséquence logique (notée $\vdash$) telle que $\Gamma\vdash\phi$ si, et seulement si, il existe une preuve de $\phi$ prenant pour hypothèses les formules de $\Gamma$
|> il y a une conséquence logique quand il y a une preuve

Preuve = ensemble d'étapes conduisant de certaines formules à d'autres par des mouvements autorisés
|> les règles d'autorisation définissent un *jeu*
|> formules ne sont pas interprétées, ce sont des suites de symboles (approche syntaxique)

**Rigoureusement**
Si $\Gamma$ est un ensemble de formule, une preuve à partir de $\Gamma$ est une suite finie de formules $A_1,\ldots,A_n$ telle que $\forall i, A_i$ réalise l'une condition suivante :
- $A_i$ est un axiome
- $A_i$ est une formule de $\Gamma$
- $A_i$ est la conclusion d'une instance d'une règle dont les prémisses appartiennent à $\{A_1,\ldots, A_{i-1}\}$

**Définition**
On a : $$ \Gamma\vdash\phi $$si, et seulement si, il existe une preuve de $\phi$ à partir de $\Gamma$.

**Définition**
Une formule $\phi$ prouvable à partir de l'ensemble vide est un théorème. On la note $\vdash\phi$.

Approche sémantique vs approche preuve-théorie
|> approche sémantique est centrée sur les significations et les situations
|> approche preuve-théorie est centrée sur les mouvements argumentatifs

**Définition**
On appelle un ensemble d'axiomes et de règles un système de preuve

En logique propositionnelle, il existe deux systèmes de preuve :
- Le système $\mathcal H$ d'Hilbert
- La déduction naturelle

Ces deux systèmes sont équivalents, i.e. $\Gamma\vdash_{\mathcal H} \phi\iff \Gamma\vdash_{\text{D.N}}\phi$
## Correction, complétude
La déduction naturelle ne repose sur aucun axiome
|> les règles consistent à indiquer pour chaque conteneur dans quel cas on peut introduire et dans quel cas on peut l'éliminer

> [!info] Exemple
> Si on a $\alpha$ et $\beta$, on peut écrire $(\alpha\land\beta)$
> si on a $(\alpha\land\beta)$, on peut écrire $\alpha$

Théorème de correction et complétude $\mathcal H$ prouvé par Gödel
|> voir [[7- Métalogique 2 - Les théories et leurs propriétés]] pour la def de correction et complétude

Pour démontrer la correction, il suffit de montrer que les règles ne peuvent pas passer du vrai au faux
|> ne permet pas de convaincre quelqu'un d'argumenter comme nous, car il est justifié par notre manière d'argumenter (argument circulaire ici)

Comment justifier les règles logiques ? Possibilités :
- Pas à justifier
- À justifier
	- localement
	- d'une manière holiste

Le théorème de correction permet juste de nous montrer qu'on préserve la vérité

Les théorèmes de correction et de complétude s'étendent à la logique de prédicat
|> mais on perd la décidabilité (capacité à déterminer mécaniquement en un temps fini si une formule est une tautologie (ou un théorème))