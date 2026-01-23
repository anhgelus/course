#import "@local/template:1.0.0": *
#import "@local/callout:1.0.0": *

#show: doc.with(
  authors: (
    (name: "William Hergès", affiliation: "Sorbonne Université", email: "william@herges.fr"),
  ),
  page_title: "Introduction",
)

= Introduction

Un algorithme est un moyen de décomposer un problème en plein de petites tâches.
Une recette de cuisine est un algorithme.

On cherche à trouver un moyen pour analyser les algorithmes et pour choisir le meilleur.

Plan du semestre :
1. Théorie sur les algorithmes ;
2. Structure des données.

Contrôle continu en TD, partiel et examen.
Utilise la règle du max.

Les QCM sur Moodle ne sont pas notés.
Il y a souvent des QCM aux exams.

= Rappels mathématiques

Raisonnements valides :
1. calculatoire
2. raisonnements logiques
  - directe
  - absurde
  - contraposé
3. par récurrence

C'est du blabla pour nous rappeler comment on fait des maths.

Ne pas oublier que~:
$ sum^n_(i=1) i = (n(n-1))/2 $
et que~:
$ forall x in RR, quad sum^n_(i=0) x^i = (x^(n+1)-1)/(x-1) $

= Solution générale des suites

== Suites récurrente linéaire homogène d'ordre 2

#defn[
  Une _suite récurrente linéaire homogène d'ordre 2_ est une suite définie par une relation de récurrence
  $ u_n = a u_(n-1) + b u_(n-2) $
  avec des conditions initiales
  $ u_0 = a_0 quad u_1 = a_1 $
  où $a$, $b$, $a_0$ et $a_1$ sont des nombres réels.
]

#defn[
  On définit le _polynôme caractéristique_ associé à la suite récurrente précédente le polynôme~:
  $ r^2 + a r - b $
]

Par exemple, le polynôme associé à la suite de Fibonacci est $ r^2-r-1 $

=== Méthode pour déterminer la solution

On calcule les racines du _polynôme caractéristique_.

*Si le polynôme possède deux racines* $r_1$, et $r_2$, alors la solution générale de la récurrence est de la forme~:
$ u_n = alpha r_1^n + beta r_2^n $
On détermine ensuite $alpha$ et $beta$ à l'aide des conditions initiales~:
$ alpha + beta = a_0 \
alpha r_1 + beta r_2 = a_1 $

*Si le polynôme possède une racine* $r$, alors la solution générale est de la forme~:
$ u_n = alpha r^n + beta n r^n $
$alpha$ et $beta$ sont déterminés comme dans le cas précédent.

== Autres cas

Voir le diapo, car le prof n'a pas détaillé et est allé très vite.

= Notations de Landau

#defn[
  Soient $f$ et $g$ deux fonctions de $NN$ dans $RR_+$.

  On écrit $f in O(g)$ si :
  $ exists D > 0, exists n_0 >= 0, quad forall n > n_0, quad f(n) <= D g(n) $

  On écrit $f in Omega (g)$ si :
  $ exists C > 0, exists n_0 >= 0, quad forall n > n_0, quad C g(n) <= f(n) $

  On écrit $f in Theta (g)$ si :
  $ exists D >, exists C > 0, exists n_0 >= 0, quad forall n > n_0, quad C g(n) <= f(n) <= D g(n) $
]
Autrement dit
- si $f in O(g)$, alors $f$ croit plus lentement que $g$~;
- si $f in Omega (g)$, alors $f$ croit plus vite que $g$, i.e. $g in O(f)$~;
- si $f in Theta (g)$, alors $f$ croit aussi vite que $g$, i.e. $f in O(g)$ et $f in Omega (g)$.

#props[
  Dans le cas où $(f(n))/(g(n))$ adment une limite dans $n$ tend vers $+inf$, si~:
  - $lim (f(n))/(g(n)) = 0$, alors $f in O(g)$~;
  - $lim (f(n))/(g(n)) = +inf$, alors $f in Omega (g)$~;
  - $lim (f(n))/(g(n)) = l$ (où $l in RR backslash {0}$), alors $f in Theta (g)$.
]
