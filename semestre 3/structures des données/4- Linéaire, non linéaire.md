---
tags:
  - sorbonne
  - informatique
  - structure-des-données
semestre: 3
---
Linéaire = les éléments sont orga de manière séquentielle (l'une après l'autre)
|> tous les éléments possèdent un suivant et un précédent (sauf le premier et le dernier)
-> possible d'itérer dessus de manière univoque

Non-linéaire = pas d'ordre de manière séquentielle
## Arbre
Organise les éléments
|> les éléments sont des nœuds
|> organisation hiérarchique

Un arbre possède un premier (root), mais de dernier (il peut y avoir plusieurs feuilles)

Très souvent, la complexité dépend de la hauteur de l'arbre
|> peut aussi être en fonction du nombre de feuilles
## Graphe
Organise les éléments
|> les éléments sont des nœuds ou des sommets
|> organise en réseau

Ne possède pas de premier et pas de dernier
## Relation
**Association** = existence d'un lien logique ou fonctionnel entre deux entités
|> les deux entités restent indépendantes

**Agrégation** = relation de contenance ou de regroupement *faible*
|> entité contenue existe indépendamment de l'entité la contenant
|> relation est asymétrique
|> pas d'exclusivité

**Composition** = relation de contenance ou de regroupement *fort*
|> entité contenue dépend de l'entité la contenant
|> relation est asymétrique
|> exclusivité
|> est dite interne si elle opère uniquement sur la même entité
|> est dite externe si elle n'est pas interne

Le type de relation dépend de l'interprétation et des contraintes
|> chacune relation possède sa propre implémentation
### Multiplicité
Référence simple -> un objet lié à un objet
|> liste chaînée

Référence multiple unilatéral -> un objet lié à plusieurs objets
|> arbre

Référence multiple bilatéral -> plusieurs objets liés à plusieurs objets
|> graphe

> [!warning] On ne veut pas de cycle !
> Sinon, on a une récursivité infinie
