---
tags:
  - sorbonne
  - informatique
  - structure-des-données
semestre: 3
---
Comment gérer les structures de données ?
-> objectif est d'optimiser
|> références bibliographiques sur Moodle

Note : 50% examen, 30% TME Solo final, 10% TME Solo, 10% note TD
|> règle du max particulière : $\max(0.5\mathrm{examen}+0.1\mathrm{TD}+0.1\mathrm{TP},0.7\mathrm{examen})$
-> TME Solo final est gardé en seconde session

Une feuille A4 manuscrite est autorisée en examen
## Abstraction
Une structure de données est une implémentation concrète d'un type abstrait de données

Abstraction = considérer l'un caractère d'une chose indépendamment des autres
|> abstraction par simplification -> réduction la description d'un objet
|> abstraction par généralisation -> partir du particulier pour arriver au cas général

Abstraction en informatique = synthétiser les caractéristiques communes applicables à des entités ou concepts variés, afin de simplifier et unifier leur manipulation

> [!note] Abstraction est une bonne chose
> Mais il ne doit pas rendre le programme plus lent !

Un type abstrait de données est une spécification mathématique d'un ensemble d'objets et d'un ensemble d'opérations applicables à ces objets

Le type abstrait ne définit pas l'implémentation des méthodes ou la manière dont les données sont stockées
-> permet de rendre le code plus abstrait pour mieux le comprendre

Une structure de données représente concrètement les données dans la mémoire
|> elle implémente les opérations sur cette représentation

Le choix de la structure de données implique un coup
|> coup spatiale (mémoire que ça prend)
|> coup temporel (temps que ça prend)
-> toutes les structures de données n'ont pas les mêmes performances

Un programme est un ensemble :
- de variables
- d'opérations élémentaires
- de structures de contrôle

Variable = une boite contenant des données
Opération élémentaires = opération réalisant quelque chose de simple (ordinateur les faits en un nombre fini d'appels au CPU)
Structure de contrôle = instruction décrivant comment le programme s'exécute

Un algorithme est un programme résolvant un problème
|> problème = valeurs + question
-> doit avoir un nombre fini d'opérations élémentaires (terminaison)
-> doit répondre correctement à la question (vérification)
## Complexité
On estime la complexité temporelle en comptant le nombre d'opérations élémentaires faites
|> selon les entrées, il peut y avoir une complexité temporelle -> on regarde donc le pire des cas et le meilleur des cas

**Notation de Landau : $O$**
Soient $f(n)$ et $g(n)$ deux fonctions positives définies sur $\mathbb{N}$.
On dit que $f(n)$ est en $O(g(n))$ si la fonction $f$ est asymptotiquement bornée supérieurement par la fonction $g$ à un facteur près. Plus formellement, $f(n)$ est en $O(g(n))$ si :
$$ \exists n_0\in\mathbb{N},\quad\exists k\in\mathbb{R}>0,\quad\forall n \geqslant n_0,\quad f(n)\leqslant kg(n) $$

> [!NOTE] Simplification de la notation
> Quand on a $O(2n+4)$, on peut noter $O(n)$ car :
> - $2n+4\leqslant kn$ pour tout $n$ et pour tout $k > 4$
> 
> Cette simplification est valide pour tous les cas similaires

**Notation de Landau : $\Omega$**
Soient $f(n)$ et $g(n)$ deux fonctions positives définies sur $\mathbb{N}$.
On dit que $f(n)$ est en $\Omega(g(n))$ si la fonction $f$ est asymptotiquement bornée inférieurement par la fonction $g$ à un facteur près. Plus formellement, $f(n)$ est en $\Omega(g(n))$ si :
$$ \exists n_0\in\mathbb{N},\quad\exists k\in\mathbb{R}>0,\quad\forall n \geqslant n_0,\quad f(n)\geqslant kg(n) $$

> [!NOTE] Simplification de la notation
> Même principe !

**Notation de Landau : $\Theta$**
Soient $f(n)$ et $g(n)$ deux fonctions positives définies sur $\mathbb{N}$.
On dit que $f(n)$ est en $\Theta(g(n))$ si la fonction $f$ est dominée et soumise par la fonction $g$ asymptotiquement. Plus formellement, $f(n)$ est en $\Theta(g(n))$ si :
$$ \exists n_0\in\mathbb{N},\quad\exists (k_2,k_1)\in\mathbb{R}^2,\quad k_2\geqslant k_1>0\quad\implies\quad\forall n \geqslant n_0,\quad k_1g(n)\leqslant f(n)\leqslant k_2g(n) $$

La complexité spatiale est la place que prend un programme en mémoire
|> est l'analogue de la complexité temporelle pour la RAM
## Compilation et module en C
Programmation modulaire est le fait de séparer son code en plusieurs programmes
-> demande une réflexion sur le découpage du code

Un module en C est composé :
- du header `.h` qui donne les interfaces du module
- du fichier source `.c` qui contient le code source décrit dans le fichier header

Besoin de rajouter `#include "file.h"` en début pour implémenter le header

Quand on écrit un fichier header, on rajoute toujours :
```c
#ifndef FILE_H
#define FILE_H

// contenu du fichier

#endif
```
Ça permet d'éviter d'avoir des erreurs lors de la compilation
|> éviter d'inclure plusieurs fois le même chode

On peut compiler les fichiers seuls avec :
```bash
gcc -c file1.c # crée le fichier1.o
gcc -c file2.c # crée le fichier2.o
gcc -c main.c # crée le main.o
```
Et on peut créer l'exécutable `main` avec :
```bash
gcc -o main -c main.o fil2.o file1.o
```
Ceci permet de compiler le programme en plusieurs fois -> permet de gagner du temps si le projet est long à compiler

Le `Makefile` permet d'automatiser tout ça
|> il exécute uniquement ce qui est nécessaire
|> évaluation récursive des règles (voir le diapo pour plus d'infos)
```Makefile
build : main // peut utile car on n'a qu'un seul exécutable

main : main.o file2.o file1.o
	gcc -o main -c main.o file2.o file1.o

main.o:
	gcc -c main.c

file2.o:
	gcc -c file2.c

file.o:
	gcc -c file1.c

clean:
	rm -f *.o main
```
