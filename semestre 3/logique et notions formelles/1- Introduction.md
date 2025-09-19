---
tags:
  - philosophie
  - sorbonne
  - logique-notions-formelles
Semestre: 3
---
Cherche à obtenir des compétences de logiques formelles
|> manipulation d'objets formelles -> les TD servent à résoudre les exos typiques
|> présente des notions ou idées spécialisées qui sont utilisées en philosophie contemporaine

Sous-domaines du domaine formelle :
- logique
- ensembles
- probabilités

Bibliographie :
- Lepage, _Éléments de logique contemporaine_, Les Presses de l'Université de Montréal
- Papineau, _Philosophical devices : Proofs, probabilites, possibilities and sets_, Oxford University Press
- Wagner, _Logique et philosophie. Manuel d'introduction pour les étudiants du supérieur_, Ellipses
## Histoire
Durant l'antiquité, ils théorisent les paradoxes, les propositions, syllogismes et les connecteurs logiques
|> distinction entre les types de phrases (proposition / syllogisme, universelle / particulière) provient d'Aristote

Kant pense que les mathématiques ne sont pas indépendantes de l'expérience mais n'est pas totalement dépendante de l'expérience
|> est entre le rationalisme de Leibniz et l'empirisme de Mills
-> passe à un nouveau rationalisme : le logicisme

Frege propose de réduire l'arithmétique à la logique
|> construit une langue auxiliaire pour exprimer les rapports entre les propositions -> est l'idéographie (_Begriffsschrift_) (cf Frege, _Idéographie_)
|> continue dans _Fondements de l'arithmétique_
|> termine avec _Lois fondamentales de l'arithmétique_
-> mène au paradoxe de Russell

> [!NOTE] Paradoxes en logique
> Ils ont souvent été les moteurs du développement de la logique, comme le paradoxe du menteur, de Russell ou le théorème d'incomplétude de Gödel
> 
> Quine, _Les voies du paradoxe_ -> est une bonne introduction aux paradoxes
> |> est accessible
### La logique comme branche des mathématiques
Effondrement du système de Frege mènent les mathématiciens à penser la logique
|> souhaitent à sauver le système de Frege
|> théorie des types (Russell)
|> théorie des ensembles (Zermelo)
|> logique du premier ordre (Peano)

D'autres cherchent aux propriétés des systèmes logiques pour comprendre comment ça marche
|> théorie de la calculabilité
|> théorie de la démonstration
|> théorie des modèles
### La logique comme théorie du raisonnement
Développement des théories formelles et normatives du raisonnement
|> est de la logique en un sens large

Ces théories permettent de prendre en charge des raisonnements de complexité variée :
- raisonnement certain -> logique « classique »
- raisonnement incertain -> logique inductive, théorie des probabilités
- raisonnement pratique -> théorie de la décision
- raisonnement dans des situations qui impliquent plusieurs sujets -> théorie des jeux, théorie de l'agrégation des jugements
### La logique comme toolbox
Permet de comprendre les relations entre les propositions en jeu

Permet d'analyser formellement des concepts pour clarifier des débats philosophiques
|> philo du langage, théorie de la connaissance, philo des sciences, métaphysique

**Ce cours ne choisit pas quelle conception est valide**
|> on va commencer en pensant que c'est une théorie normative du raisonnement certain
-> est dans la lignée de la [[0- Présentation & Introduction|pensée critique]]
## Argument, validité
Argument est constitué de prémisses et d'une conclusion reliées par des expressions
|> prémisses et conclusions sont des énoncés, i.e. elles peuvent être vraies ou fausses

> [!warning] Tous les arguments ne se valent pas
> Les [[3- Charge de la preuve & sophismes|sophismes]] sont des arguments !

Validité ici est la *validité déductive* et non inductive

Un argument est dit correct si les prémisses sont vraies et si l'argument est correct

Il existe un lien entre validité et vérité
|> validité dépend pourtant du rapport entre prémisses et conclusion et non de la valeur de vérité des énoncés

Les arguments valides permettent de construire d'autres arguments en utilisant le même schema
|> validité est préserver par la substitution
-> ⚠ il faut bien tout substituer correctement

Forme logique ne contient pas de termes sur un sujet spécifique
|> généralise les arguments, e.g.
>Si $\phi$ alors $\psi$. On a $\phi$ donc $\psi$.

**Un argument est valide si, et seulement si, sa forme logique est valide**

Pour montrer qu'un argument n'est pas valide, on montre que sa forme logique n'est pas valide