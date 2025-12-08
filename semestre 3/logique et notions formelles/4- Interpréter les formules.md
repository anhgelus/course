---
tags:
  - sorbonne
  - philosophie
  - logique-notions-formelles
semestre: 3
---
Les connecteurs propositionnels sont vérifonctionnels -> la valeur de vérité d'une formule composée dépend seulement de la valeur de vérité des formules qui la composent
|> permet de trouver les valeurs de vérité de toutes les formules
-> il suffit d'interpréter

Interpréter les formules est une fonction qui associe une valeur de vérité à chacune de ces lettres
|> est la distribution de valeur de vérité (dvv)

Une dvv pour le langage propositionnelle $\{p,q,r,s\}$ est par exemple :
$$ d : \{p,q,r,s\} \to \{V,F\} $$
telle que
$$ d(p)=V,\quad d(q)=F,\quad d(r)=F,\quad d(s)=V $$

$\bar d$ est extension de $d$ telle que $\bar d$ respecte les définitions des connecteurs

La table de vérité est un tableau donnant les différentes valeurs de vérité des différentes dvv existantes

Quand $d$ est vrai pour une formule (i.e. $\bar d(\phi) = V$ ), on dit qu'elle satisfait la formule ou que c'est un modèle de la formule

Une tautologie est une formule qui est vraie dans tous les cas (pour toutes les ddv)
|> on utilise $\models \phi$ pour dire que $\phi$ est une tautologie
|> $p\lor\lnot p$ est une tautologie
|> $(((p\to q)\to p) \to p)$ est aussi une tautologie

Une antilogie est quand une formule est fausse dans tous les cas
|> $p\land\lnot p$ est une antilogie

Une formule neutre n'est ni une tautologie, ni une antilogie

$\models\phi$ si et seulement si $\lnot\phi$ est une antilogie