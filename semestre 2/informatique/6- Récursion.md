---
tags:
  - sorbonne
  - informatique
semestre: 2
---
Une fonction récursive est une fonction qui s'appelle elle-même, e.g.
```c
int somme(int n){
	if (n == 0) return 0;
	return somme(n-1) + n;
}
```

Besoin d'avoir une hypothèse de récurrence quand on fait une récursion
|> besoin d'avoir une convergence, sinon la récursion est infinie

| Indice           | =   | valeur                 |
| ---------------- | --- | ---------------------- |
| (1) somme_int(3) | =   | 3+somme_int(2)         |
| (2)              | =   | 3+(2+somme_int(1))     |
| (3)              | =   | 3+(2+(1+somme_int(0))) |
| (4)              | =   | 3+(2+(1+0))            |
| (5)              | =   | 6                      |
La pile ressemble à la même chose que le tableau

Si l'appel est trop vénère, alors il remplit la mémoire et provoque une erreur

Autre exemple :
```c
int factoriel(int n){
	if (n <= 1) return 1;
	return factoriel(n-1) * n;
}
```

La suite de Fibonacci,
$$ F_n=\left\{\begin{matrix}1&\text{si $n=0$ ou $n=1$}\\F_{n-1}+F_{n-2}&\text{sinon}\end{matrix}\right. $$
sert à faire une dichotomie plus rapide en pratique (mais pas en théorie)
```c
int fibonacci(int n){
	if (n <= 1) return 1
	return fibonacci(n-1)+fibonacci(n-2)
}
```