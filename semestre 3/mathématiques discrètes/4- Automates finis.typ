#set page(
  paper: "a4",
  header: align(right)[
    Automates finis
  ],
  numbering: "1",
  margin: 1in,
)
#set par(justify: true)
#set text(
  size: 12pt,
  font: "Times New Roman"
)
#set heading(numbering: "1.")
#show heading: set block(above: 1.4em, below: 1em)
#show heading: set text(font: "Raveo")

#show title: set text(size: 24pt, font: "Raveo")
#show title: set align(center)

#title[
  Automates finis
]

= Langages et automates
#show heading.where(level: 1): it => pagebreak(weak: true) + it

== Problème de décision

Soient $L_1$ et $L_2$ deux langages sur un alphabet $A$.

On définit le _langage produit_ (ou _concaténation_) par~:
$ L_1 dot L_2 = {w in A^* | w = u dot v, u in L_1, v in L_2} $

On note $L^0$ le langage vide (i.e. ${epsilon}$).

On définit $L^n$ (avec $n in NN^*$) tel que~:
$L^n = L dot L^(n-1)$
pour tout $n>0$

L'_étoile_ d'un langage $L$ est, pour tout $n$ dans $NN$~:
$ L^* = union.big_(i = 0)^n L^i $

On définit également $L^+$~, pour tout $n$ dans $NN^*$:
$ L^+ = union.big_(i=1)^n L^i $

Par exemple, si on a $L_1={a,a b}$ et $L_2={c,b c}$, alors~:
- $L_1 dot L_2 = {a c, a b c, a b b c}$
- $L_1^2 = {a a, a a b, a b a, a b a b}$

Pour un problème de _décision_, les mots sont une façon de représenter les _données_ du problème.
Un langage permet de représenter les _solutions_ du problème.
Ainsi, on associe à tout problème de décision $P$ le langage $L_P$ des solutions de $P$.

== Problème du mot et automates

Étant donné un langage $L subset.eq A^*$ et un mot $u$ de $A^*$, est-ce que $u$ est dans $L$ ?
(Problème du mot)

Pour répondre à ce problème, on utilise un *automate*.
Il s'agit d'un modèle de programme simple.
Il reçoit en entrée un mot qu'il lit lettre à lettre et change ses états (qui sont en nombre _fini_~!) en fonction de
ces entrées.
À la fin de son exécution, l'état dans lequel se trouve l'automate détermine si le mot lu en entrée appartient au
langage recherché.

Sur un alphabet $A$, un automate fini est donné par $cal(A) = (S,T,I,F)$ où~:
- $S$ est un ensemble fini (non vide) d'états
- $T subset.eq S times A times S$ est une relation de transition
- $I subset.eq S$ est l'ensemble (non vide) des états initiaux
- $F subset.eq S$ est l'ensemble des états finaux

Par exemple, sur l'alphabet $A={0,1}$, on peut représenter l'ensemble des nombres écrits en base 2.
Le langage $L_("pair")={"nombres pairs"}$ est donc constitué de l'ensemble des mots de $A^*$ se terminant par $0$.

#figure(
  image("automates1.png", width: 50%),
  caption: [
    Un automate permettant de résoudre le problème du mot pour le langage $L_("pair")$.
  ]
) <auto1>

Une exécution de $cal(A)$ est une séquence finie $s_0a_1s_1 dots a_n s_n$ telle que~:
- $s_0 in I$ est un état initial
- pour tout $O <= i < n$, alors $(s_i, a_(i+1), s_(i+1)) in T$ est une transition autorisée par la relation de transition

La séquence $a_1 dots a_n$ est un mot de $A$ qui étiquette l'exécution.
On dit qu'une exécution est _acceptante_ si $s_n in F$.
Un mot est _accepté_ par $cal(A)$ s'il est étiquette d'au moins une exécution acceptante.

Le langage d'un automate $cal(A)$ est noté $L(cal(A))$~:
$ L(cal(A)) = {u in A^* | u "est accepté par" cal(A)} $

On dit que deux automates $cal(A)$ et $cal(B)$ sont _équivalents_ si $L(cal(A)) = L(cal(B))$.

Un langage $L subset.eq A^*$ est _reconnaissable_ s'il existe un automate fini $cal(A)$ sur l'alphabet $A$ tel que~:
$ L = L(cal(A)) $

= Automates déterministes, non déterministes et complets

== Déterminisme

=== Définitions

Un automate est dit déterministe si chaque exécution produit la même étiquette.
D'une manière formelle, un automate est déterministre si~:
- il a un unique état inital
- la relation $R$ (les transitions de l'automate) est fonctionnelle au sens suivant~:
$ (p,a,q) in R and (p,a,q') in R ==> q=q' $

Dans un automate fini déterministe, $T$ est une _fonction_ allant de $S times A$ vers $S$. On note parfois $ T(s,a) = s' $ pour $(s,a,s') in T$ dans un automate déterministe.

Dans un automate fini déterministe, tout mot est étiquette d'au plus une exécution.

@auto1 est un automate déterministe.

Un automate dit non déterministe s'il n'est pas déterministe.

#figure(
  image("automates2.png", width: 50%),
  caption: [
    Un automate non déterministe
  ]
)

=== Déterminiser

Tout automate fini est équivalent à un automate fini déterministe.

== Complétude

Un automate $cal(A)=(S,T,I,F)$ sur un alphabet $A$ est _complet_ si~:
$ forall s in S, forall a in A, exists s' in S, (s,a,s') in T $

Dans un automate complet, tout mot est étiquette d'au moins une exécution.

Tout automate fini est équivalent à un automate complet.

#figure(
  image("automates3.png", width: 50%),
  caption: [
    Automate de @auto1 complété
  ]
)

Soit $cal(A) = (S,T,I,F)$ un automate fini sur l'alphabet $A$.
On construit 
$ op("comp")(cal(A))=(S union.plus {bot}, T', I, F) $
avec
$ T' = T union.plus {(s,a,bot) | s in S union.plus {bot}, a in A, forall s' in S, (s,a,s') in.not T } $
On a que~:
- $L(op("comp")(cal(A))) = L(cal(A))$
- $op("comp")(cal(A))$ est complet

= Propriétés de clôture
