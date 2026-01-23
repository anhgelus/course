#import "@local/template:1.0.0": *
#import "@local/callout:1.0.0": *

#show: doc.with(
  authors: (
    (name: "William Hergès", affiliation: "Sorbonne Université", email: "william@herges.fr"),
  ),
  page_title: "Introduction",
)

= Introduction

Partiel le lundi 9 mars.
TP solo durant la séance TP9.
Mini-projet, rendu & soutenance lors du dernier TP.
On a le droit à une feuille A4 écrite à la main lors des examens.

== Programmation orientée objet

Cherche à développer des systèmes complexes.
Divise le système en plusieurs objets tout en sécurisant les données sensibles.

Permet de travailler à plusieurs~: toujours penser son programme pour les autres, donc on sécurise, on simplifie et on
compartimente.

== Java

Java est une application classique de l'OOP.
Langage moderne, robuste, sûre et fortement typée.

Propose une architecture dynamique avec un compilateur pour créer des applications performantes.
Repose sur la JVM pour exécuter le code compilé~: permet de créer des applications indépendantes de la machine physique.

= Premier programme

En Java, tout le code doit être écrit dans une classe.
```java
// contenu de MonPremierProgramme.java
public class MonPremierProgramme {
  // code
}
```

Un fichier `.java` contient forcément un fichier.
Il doit avoir le même nom de la classe.

Un programme est un ensemble de classes.
Le point d'entrée est la méthode `main`.

La signature de la fonction `main` est~:
```java
public class MonPremierProgramme {
  public static void main(String[] args) {
    System.out.println("Hello world :D");
  }
}
```

Besoin du JDK pour développer en Java.
Pour compiler, on écrit dans le terminal~:
```bash
javac MonPremierProgramme.java
```
Cela crée un fichier `MonPremierProgramme.class` qui contient du bytecode JVM.
Pour l'exécuter, on écrit
```bash
java MonPremierProgramme
```

Pour compiler plusieurs classes, on fait~:
```bash
javac *.java
```

= Concept de base de l'OOP

En OOP, tout est encapsulé dans un objet.
Un objet est autonome~: il est réutilisable partout.
Il est aussi sécurisé~: il garantie le bon usage.
Il intègre des données et des méthodes pour le manipuler proprement.

= Syntaxe de Java

...

Les objets sont représentés par deux valeurs en mémoire~: le type et ses attributs.
