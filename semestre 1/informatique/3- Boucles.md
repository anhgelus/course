---
tags:
  - sorbonne
  - informatique
semestre: 1
---
On utilise `format(int) -> str` pour convertir un int en string

```python
def somme(n: int) -> int:
	"""Precond: n >= 1
	Retourne la somme des n premiers termes
	"""
	t: int = n
	for i in range(1,n):
		t += i
	return t
```
## Simulation de boucle
Durant l'examen, on peut nous demander de simuler une boucle
Exemple de tableau :

| tour de boucle | s   | i   |
| -------------- | --- | --- |
| entrée         | 0   | 1   |
| 1              | 1   | 2   |
| 2              | 3   | 3   |
| 3              | 6   | 4   |
| 4              | 10  | 5   |
| 5 (sortie)     | 15  | 6   |
($s$ et $i$ sont des variables)
L'ordre des variables dépendent de leur ordre de modification dans la boucle 
La valeur affichée est celle à la fin du tour du boucle

Pour chaque imbrication de boucle, on rajoute une colonne dans le tableau
## Correction
La correction est la validité de la fonction, i.e.
- correction de l'algorithme
- correction de l'implémentation

Pour vérifier la correction de l'implémentation, on a besoin de supposer que l'interpréteur est correct

Un invariant est une expression booléenne impliquant les variables modifiées dans le corps de la boucle qui est vraie lors de l'entrée de boucle et après chaque tour de boucle
|> particulièrement, il est vrai après la boucle

Exemple pour une implémentation de la fonction $p(x,n)=x^n$

| tour       | res | i   |
| ---------- | --- | --- |
| entrée     | 1   | 1   |
| 1          | 2   | 2   |
| 2          | 4   | 3   |
| 3          | 8   | 4   |
| 4          | 16  | 5   |
| 5 (sortie) | 32  | 6   |
On a que $res=x^{i-1}$ est invariant (il faudrait le montrer par récurrence)
|> en L1, on détaille sur un exemple (avec en plus l'invariant) et on est bon

Comment prouver qu'une fonction avec une boucle est correcte
|> une simulation ne nous dit rien formellement
|> besoin de trouver un invariant pour le démontrer formellement
|> on utilise le fait que l'expression de $i$ est fausse à la fin
|> on réinjecte dans l'invariant et on vérifie qu'elle est correcte

Suite de l'exemple :
>Comme $res=x^{i-1}$ est un invariant et que $i=n+1$ est la dernière valeur de $i$ après la boucle, on a que $res^{n+1-1}=res^n$, ce qui est vrai dans notre cas

> [!important] Autre méthode
> 1. On écrit notre $i$ et ce que l'on veut à la fin
> 2. On se débrouille pour trouver un invariant avec ces deux valeurs

Suite de l'exemple :
Démonstration de l'invariant
On a que l'invariant est vraie et pour le tour 0.
On suppose que pour tout tour de boucle, on a que l'invariant est vrai.
On pose :
$$r'=rx$$
$$ i'=i+1 $$
On a donc que :
$$ r' = xr=x\times x^{i-1} = x^i = x^{i'-1} $$
Donc $r'$ est bon.
(Voir le poly cours 4 pour une belle démo)
## Terminaison
Un variant de boucle est une expression arithmétique qui est un entier naturel positif, qui décroit strictement à chaque fois et qui vaut 0 en sortie de boucle
|> permet de montrer que la boucle `while` se termine

On le démontre de la même manière que l'invariant
|> doit montrer qu'il s'agit d'un entier positif au début
|> doit montrer que sa valeur décroit strictement entre le début et la fin d'un tour de boucle
|> doit montrer qu'il vaut 0 quand la boucle est finie

> [!info] Condition et variant
> Le variant pourrait être utilisée comme condition dans le while

Une boucle se termine si elle a un variant
## Efficacité
Un programme est correct vis-à-vis d'une fonction $F$ quand chaque calcul `f(x)` pour x satisfaisant les hypothèses, si le programme renvoie $v$, alors $F(x)=v$ (avec (x,v) représentation de $(x,v)$)
|> est une propriété indécidable
|> analyse statique est l'analyse du code
|> analyse dynamique sont les tests et les simulations
|> beaucoup de tests, de plus en plus de vérification

On fait de l'analyse statique de boucle

Un programme `f` est plus efficace en moyenne qu'un programme `g` :
- `f` et `g` calculent la même fonction mathématique
- sur toutes les entrées, `f` utilise en moyenne moins d'opération élémentaire que `g`

> [!warning] Sanction sur l'efficacité
> On doit limiter les répétitions de calcul
> On ne compare pas des booléens, on évite les raccourcies logiques
> On essaye de faire des algorithmes efficaces

L'efficacité dépend du contexte
|> espace mémoire en système intégré
|> appels aux fonctions de lib graphique pour du jv
etc

Voir la slide de conclusion sur le diapo (cours 4)