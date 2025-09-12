---
tags:
  - sorbonne
  - informatique
  - maths
semestre: 3
---
Partiel en novembre

On passe au TME après un certain temps

QCM obligatoire
|> commence le jour du cours et se finit le lundi en 8
|> peut le faire plusieurs fois -> c'est la dernière qui compte
|> il y en a 4

Note : 50% examen + 25% partiel + 10% projet + 10% interro TD  + 5% QCM
|> règle du max
## Ensembles
**Définition**
Ensemble est une réunion dans une même entité de certains objets déterminés. Un ensemble ne possède pas d'ordre

**Définition**
Relation d'appartenance est noté $\in$. Elle indique si un élément $e$ appartient à un ensemble $E$.

**Définition**
$\varnothing$ est l'ensemble vide, celui qui ne contient rien
$\{e\}$ est le singleton $e$ (i.e. l'ensemble contenant exclusivement $e$)

**Définition**
Le cardinal d'un ensemble est le nombre d'éléments appartenant à cet ensemble. On le note $|E|$ ou $\mathrm{card}(E)$.

Par exemple, on a :
$$|\{e\}| = 1$$
> [!warning] Ensemble dans un ensemble
> $2\not\in\{\{2\}\}$

**Proposition**
Tout ensemble contient l'ensemble vide.

**Définition**
La relation $A\subseteq B$ indique si $A$ est un sous-ensemble de $B$, i.e.
$$ \forall a\in A,\quad a\in B $$
**Proposition**
Cette relation est réflexive, i.e. $E\subseteq E$ est vraie

**Proposition**
Cette relation est transitive, i.e. $E_1\subseteq E_2\land E_2\subseteq E_3\quad\implies\quad E_1\subseteq E_3$ est vraie

**Définition**
On dit que $A=B$ si, et seulement si :
$$ A\subseteq B\quad\land\quad B\subseteq A $$

**Proposition**
Ainsi, on a que $\subseteq$ est anti-symétrique.

**Définition**
Une relation est d'ordre si elle est :
- réflexive
- transitive
- anti-symétrique

Elle est dite partielle si elle ne fonctionne par pour tous les éléments.

**Proposition**
Comme $\subseteq$ est réflexive, transitive et anti-symétrique, alors $\subseteq$ est une relation d'ordre.
Par contre, deux ensembles ne sont pas nécessairement comparables avec $\subseteq$ : il s'agit donc d'une relation d'ordre partielle.

**Définition**
$A\cup B$ est l'union de $A$ et $B$, deux sous-ensembles de $E$, tel que :
$$ A\cup B = \{x| x\in A\lor x\in B\} $$
$A\cap B$ est l'intersection tel que :
$$ A\cap B = \{x| x\in A\land x\in B\} $$
> [!info] Construction d'ensembles
> La construction des ensembles dans la dernière définition est dite par compréhension, comme en Python.

**Définition**
$A$ et $B$ sont disjoints si, et seulement si :
$$ A\cap B = \varnothing $$

**Théorème** - Formule du crible, formule de Poincaré
Soient $A$ et $B$ deux sous-ensemble de $E$. On a :
$$ |A\cup B| = |A|+|B|+|A\cap B| $$

**Définition**
La différence $A\backslash B$ , deux sous-ensembles de $E$, est :
$$ A\backslash B = \{x|x\in A\land x\notin B\} $$

**Définition**
Le complémentaire de $A$, un sous-ensemble de $E$, est noté $\bar A$ et est défini tel que :
$$ \bar A= E\backslash A $$

**Définition**
Le produit cartésien $A\times B$ est l'ensemble des couples $(a,b)$ avec $a\in A$ et $b\in B$. Donc :
$$ A\times B = \{(a,b)|a\in A,b\in B\} $$

**Proposition**
Si $E_1,\ldots,E_n$ sont des ensembles finis, alors $$\left|\prod^n_{i=1} E_i\right| = \prod^n_{i=1}|E_i|$$
Voir le diapo pour les propriétés classiques

**Définition**
Une partie $A$ d'un ensemble $E$ est un sous-ensemble de $E$.

$\mathcal{P}(E)$ est l'ensemble des parties de $E$.

> [!warning] $\mathcal{P}(E)$ ne peut jamais être vide !
> En effet, on a $\mathcal{P}(\varnothing) = \{\varnothing\} \neq \varnothing$ !
> Ne pas oublier que $\mathcal{P}(E)$ est un ensemble d'ensemble et que $\varnothing$ est bien un ensemble valide !

**Construction de $\mathcal{P}(E)$**
Si $E=\varnothing$, alors $\mathcal{P}(E) = \{\varnothing\}$
Sinon, $E=\{e\}\cup F\neq\varnothing$ ($e$ est un élément de $E$ et $F$ est ce qui reste, il peut être vide !)
Proposition : $$\mathcal{P}(\{e\}\cup F) = \mathcal{P}(F)\cup\{\{e\}\cup A|A\in\mathcal{P}(F)\}$$Ceci est un appel récursif de la fonction $\mathcal{P}$ permettant ainsi de construire l'ensemble des parties.

**Corollaire**
Si $E$ est un ensemble fini contenant $n$ éléments, alors $|\mathcal{P}(E)|=2^n$

**Définition**
Soit $E$ un ensemble.
Quand on partitionne $E$, on construit des parties deux à deux disjointes.

Une partition de $E$ est une famille $(A_i)_{i\in I}$ de parties de $E$ telle que :
- $A_i\neq\varnothing$
- $A_i\cap A_j = \varnothing$ si $i\neq j$ (pour tout $(i,j)$ dans $I$)
- $E=\bigcup_{i\in I} A_i$

> [!warning] Une partition de $E$ n'est pas unique dans le cas générale !
