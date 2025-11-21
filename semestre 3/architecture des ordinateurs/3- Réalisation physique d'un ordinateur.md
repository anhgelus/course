---
tags:
  - sorbonne
  - informatique
  - architecture-des-ordinateurs
semestre: 3
---
On s'intéresse à comment on construit un ordinateur
## Logique booléenne
Deux valeurs : vrai (1) ou faux (0)
|> ordre -> 0 < 1
|> table de vérité est une énumération exhaustive des valeurs possibles d'une fonction booléenne

Complément = not ($\lnot$), noté par $\bar a$
Addition = or ($\lor$), noté par $a+b$
Multiplication = and ($\land$), noté par $a.b$

N'importe quelle fonction peut être écrite comme une composition de not, or et and
-> forme un algèbre (ici c'est l'algèbre de Boole)

**voir le diapo pour la définition formelle**

> [!warning] L'addition est distributive !
> $a+(b.c) = (a+b).(a+c)$
> |> n'est pas le cas dans l'algèbre classique des nombres

Comment on représente une fonction à partir des éléments élémentaires ?
|> on utilise la forme normale disjonctive (DNF)
|> DNF est une somme de termes où chaque terme contient un produit utilisant tous les paramètres
|> exemple : $\text{DNF}_s = (\bar a.b.c) + (a.\bar b.\bar c) + (a.\bar b.c)$
|> on la construit en énumérant dans tous les termes une configuration d'entrée telle que $s$ donne $1$
|> exemple : le DNF précédant indique que $s$ vaut 1 avec $(0,1,1)$, $(1,0,0)$ et $(1,0,1)$

Deux fonctions booléennes sont équivalentes ssi elles ont la même table de vérité
|> on dit que la table de vérité est canonique
-> ⚠ ce n'est pas le cas avec l'expression algébrique
|> par contre, si on peut réduire à une expression algébrique commune, alors elles sont aussi équivalentes

**voir le diapo pour les circuits logiques**

**rattraper cours sur les graphes et temps de propagation**

Toutes les opérations sur un bit sont extensibles sur $n$ bits
|> sauf qu'au lieu d'utiliser $1$ opérateur, on en utilise $n$ !

Multiplexeur permet de sélectionner une entrée, définition :
```elixir title="définition d'un multiplexeur avec deux entrées"
# la troisième valeur est c, il s'agit de la commande
def mux2(a,b,0), do: a
def mux2(a,b,1), do: b
```
Formellement, on a : $\text{mux2}(a,b,c) = a.\bar c+b.c$

**rattraper fin cours sur les circuits logiques**

Décodeur converti une entrée $n$ bits en sortie $p$ bits
|> permet de déterminer les adresses, les champs suivants...