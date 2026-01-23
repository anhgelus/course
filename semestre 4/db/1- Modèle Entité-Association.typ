#import "@local/template:1.0.0": *
#import "@local/callout:1.0.0": *

#show: doc.with(
  authors: (
    (name: "William Hergès", affiliation: "Sorbonne Université", email: "william@herges.fr"),
  ),
  page_title: "Modèle Entité-Association",
)

= Introduction

Ici, on s'intéresse à une forme abstraite~: description de haut niveau.
Il s'agit d'une première description formelle des données dans une base de données.

On va prendre comme exemple la création d'un DB d'un Université.

Les besoins~:
- inscripitons des étudiants à un module
- affectation des tuteurs à des étudiants
- planning des salles

Les objets à modéliser~:
- les étudiants
- les modules
- les tuteurs
- les salles

Les liens entre les objets~:
- les étudiants s'inscrivent à un ou plusieurs modules pour une année universitaire
- le cours d'un module a lieu dans une salle donnée, il débute à une heure connue et se déroule pendant une durée connue


= Définitions élémentaires

Cherche à transcrire les besoins en terme de _classes_ d'_entités_ et de _classes_ d'_associations_.

#defn[
  Une _entité_ est un objet du monde réel identifiable et pertinent pour l'application.
]

Une salle 24-34-208 est une entité.
Le médecin John Doe est une entité.

#defn[
  Un _attribut_ est une propriété/une caractéristique à une entitée.
  Il possède un nom et un domaine de valeurs atomiques.
]

Un prénom est un attribut pour une personne.

#defn[
  Une _classe d'entités_ est un ensemble d'entités ayant les mêmes attributs.
]

Les médecins sont une classe d'entité.
Les salles le sont aussi.

#defn[
  Un _identifiant d'entité_ est un sous-ensemble d'attributs permettant de distinguer les entités de la même classe.
  Il doit être unique et toute classe d'entités doit en posséder une.
]

Un identifiant peut être naturel (construit à partir des propriétés des entités) ou artificiel (rajouté aux attributs de
la classe).

#defn[
  Une _association_ est une relation entre plusieurs entités.
]

«~L'enseignant John Doe gère le cours X~» est une association.

#defn[
  Une _classe d'associations_ est un ensemble nommé de relations «~du même type~» entre des entités.
]

Enseigner est une classe d'associations.

Une association peut avoir des attributs, tout comme il peut avoir un identifiant.

*Souvent, on oublie la distinction X et classe de X.*

== Cardinalité d'une classe d'association

#defn[
  La _cardinalité d'association_ pour une classe d'entité $E$ et une classe d'association $A$, le nombre minimum et le
  maximum d'associations de $A$ qui peuvent exister pour une instance de $E$.

  La cardinalité est notée $min : max$.
]

Valeurs communes~: $0$, $1$ et $N$ (n'importe quelle valeur).

La cardinalité $1:N$ indique qu'il faut au moins une entité et qu'il n'y a pas de limites.

== Type d'association

#defn[
  Une association est dite _réflexive_, si elle relie des entités de la même classe.

  Elle peut être _symétrique_ si les cardinalités sont identiques des deux côtés.
  Sinon, elle est _asymétrique_.
]

La distance d'une ville à une autre est relation réflexive et symétrique.
La relation de subordination est aussi réflexive, mais elle est asymétrique.

== Type d'entité

#defn[
  Une entité est dite _faible_ si son identifiant dépend d'autres entités (dites fortes).
  Elles possèdent un _identifiant partiel_ qui est unique dans le contexte de leur entité forte.
]

La salle 24-25-103 est faible car elle dépend du bâtiment 24-25 (qui est fort).

= Exemples de schéma

Code~:
- les entités sont des rectangles
- les attributs par des ronds
- les associations sont des losanges
- l'identifiant est souligné (s'il est faible, il est souligné avec des pointillés)

#figure(
  image("./1- entité et association.png"),
  caption: [Deux entités liées par deux associations.],
)

#figure(
  image("./1- cardinalité.png"),
  caption: [Représentation de la cardinalité d'une association.]
)

#figure(
  image("./1- généralisation.png"),
  caption: [Représentation de la généralisation d'attributs. Les commentaires sont en gris.]
)
