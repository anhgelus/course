#import "@local/template:1.0.0": *
#import "@local/callout:1.0.0": *

#show: doc.with(
  authors: (
    (name: "William Hergès", affiliation: "Sorbonne Université", email: "william@herges.fr"),
  ),
  page_title: "Introduction",
)

= Introduction

Est un cours d'introduction aux bases de données.

Il y a 3 interros comptant pour 50% de la note en TD.
Il n'y a pas de partiel.
On a le droit à une feuille A4 comme support (écrite à la main).
À l'examen, on a le droit aux documents.

Le cours regardant le fonctionnement précis d'un DB est celui de L3.

= Pourquoi utiliser une base de données~?

Une base de données sert à la gestion des données.
On cherche à~:
- accéder aux données, les modifier
- partager entre plusieurs applications
- éviter de stocker la même information plusieurs fois
- tout en évitant les erreurs
- en étant capable de gérer des grands volumes de données
- et d'une manière sécurisée

Un système de fichiers ne répond pas à ces attentes~:
- accès séquentiel (en entier)
- accès simultané sans contrôle
- même information peut être répétée
- logiciel erroné peut facilement introduire des erreurs
- la gestion de grands fichiers est inefficace
- protection limitée

Besoin de trouver une autre façon pour gérer les données.
Cette façon est le _système de gestion de bases de données_ (SGBD).
Ce système gère les données~:
- accès faisable via SQL par exemple
- contrôle centralisé des accès aux données
- gestion du stockage indépendante des applications
- gestion globale de la cohérence des données (schémas, pannes, concurrence...)
- optimisation d'accès aux données (indexation, cache...)
- protection fine des données sensibles

= Architecture

== Architecture client/serveur

#defn[
  Une _base de données_ (BD, BDD) est un ensemble structuré de données liées, représentant une réalité spécifique.
]

#defn[
  Un _serveur_ est une instance d'un SGBD qui contrôle l'accès à la DB.

  Un _client_ est une application qui communique avec le serveur.

  La _communication_ est un échange de requêtes liés à des bases de données (via SQL, le protocol JDBC...).
]

Le serveur SGBD reçoit les requêtes de tous les clients.
Il les ordonne, les optimise et exécute les requêtes.
(Missing part...)

== Architecture des données

Dans une base de données, il y a trois niveaux d'organisation.

#defn[
  Niveau externe est celui accessible aux clients.
  Il contient les vues.

  Niveau logique est celui accessible aux développeurs.
  Il détermine comment les données sont organisées (via les tables par exemple).

  Niveau interne est celui accessible aux concepteurs et aux administrateurs.
  Il définit comment les données sont stockées en physique (index, fichiers, matériel...).
]

Ces couches sont indépendantes~: on peut modifier un niveau sans toucher les autres.

= Comment construire une base de données~?

On a besoin de connaître les besoins, de modéliser les données et d'implanter tout cela.

Pour modéliser les données, on traduit les besoins dans le *modèle Entité-Association*.
