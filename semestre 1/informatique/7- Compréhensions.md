---
tags:
  - sorbonne
  - informatique
semestre: 1
---
Il y a pleins de manière différente d'écrire une fonction
|> comment on peut trier ces fonctions ?

Du point de vue utilisateur, on s'en fout (s'il n'y a pas de diff niveau performance)

Un code est mieux s'il est concis, s'il est lisible pour un être humain et si sa structure est bonne
|> est subjectif
## Linting dans l'UE
- utiliser plus de `for` que des `while`
- parcourir une structure directement sans passer par les indices quand c'est possible
- minimiser le nombre de variable quand ça n'entraîne pas de calculs supplémentaires
- minimiser le nombre de ligne quand ça n'altère pas sa lisibilité
- décomposer son code en plusieurs fonctions
## Compréhensions
Les compréhensions sont les déclarations implicites de liste/d'ensemble

Explicite en maths = $\{1, 2, 3, 4\}$ ou $E_1\cup E_2$
Explicite en python = `[1, 2, 3, 4]`

Implicite en maths = $\{n\in [|1, 10|], n = 1\pmod 2\}$
Implicite en python = `[i for i in range(1, 11) if i % 2 == 1]`

Elles s'écrivent :
```python
[exp for var in seq cond]
```
où :
- `exp` est une expression pouvant utiliser `var` 
- `seq` est une séquence
- `cond` est une condition (utilisant possiblement une autre boucle)

```python
[(i,j) for i in range(3) if i % 2 == 0 for j in range(3) if j % 2 == 0] = [
	(0, 0),
	(0, 2),
	(2, 0),
	(2, 2)
]
```

Les compréhensions permettent de 
- gagner du temps (moins de chose à écrire)
- gagner des points (souvent les compréhensions donnent des points bonus)