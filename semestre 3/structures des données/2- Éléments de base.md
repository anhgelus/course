---
tags:
  - sorbonne
  - informatique
  - structure-des-données
semestre: 3
---
## Matrices
Matrice = ensemble d'éléments accessibles par un index (entier) à une ou plusieurs dimensions
|> matrice à une dimension sont exactement les array en C
|> matrice à plusieurs dimensions peuvent être représentés par un tableau de tableau

En mémoire, un tableau à deux entrées alloué statiquement est en réalité un tableau à une ligne -> les lignes sont les unes à la suite des autres
|> un tableau à deux entrées est de type `T**` où `T` est le type du pointeur

Un tableau à double entrée alloué dynamiquement est utile quand c'est trop compliqué d'avoir assez de place pour le mettre d'une manière contiguë
```c title="Allocation dynamique d'un tableau [2][3]"
int **m = (int **) malloc(2*sizeof(int));
for (int i = 0; i < 2; i++){
	m[i] = (int *) malloc(3*sizeof(int));
}
```
Ici, les lignes ne sont pas les unes à la suite des autres

> [!warning] Allocation dynamique
> Dès qu'on a une allocation dynamique, on ne doit pas oublier de faire un `free` pour libérer la mémoire
> |> on doit avoir un `free` par `malloc`, i.e. un `free` par ligne puis un `free` pour le tableau contenant les tableaux
> 
> En cas d'erreur (i.e. `malloc` renvoie `NULL`), on doit tous désallouer
> |> besoin de check après chaque `malloc` et si c'est pas bon, on doit désallouer tout ce qu'on a fait avant
### Complexité des opérations usuelles sur les tableaux
Accéder à un case dans un tableau, se fait en $\mathcal{O}(1)$ en C
La recherche dans un tableau est en $\mathcal{O}(n)$, mais s'il est trié, elle se fait en $\mathcal{O}(\log n)$
Suppression est en $\mathcal{O}(n)$
Insertion est en $\mathcal{O}(1)$ si le tableau possède de la place, sinon c'est $\mathcal{O}(n)$
## Listes
Une liste est une suite finie possédant chacun un élément pointant vers un autre de manière à créer une chaîne linéaire en mémoire
|> quand on parle de liste simplement chaînée (elle possède un lien qu'avec l'élément suivant), on parle de son implémentation
|> une liste doublement chaînée possède un lien avec l'élément suivant et le précédent

On implémente les listes avec une structure :
```c title="Implémentation standard d'une liste simplement chaînée"
typedef struct cellule{
	int value;
	struct cellule *next;
} Cellule;
```
### Complexité des opérations usuelles sur les listes
Insérer se fait en $\mathcal{O}(1)$ car on insère au début
Le reste est en $\mathcal{O}(n)$
## Files
Une file est un ensemble de données homogènes fondé sur le principe du « first in, first out » (FIFO)
|> permet d'insérer facilement et d'accéder facilement à la toute fin

File est doublement chaînée
### Complexité des opérations usuelles sur les files
Enfiler (rajouter un élément au début) et défiler (enlever l'élément de fin) sont en $\mathcal{O}(1)$
Les autres sont en $\mathcal{O}(n)$
## Piles
Une pile est un ensemble de données homogènes fondé sur le principe du « last in, first out » (LIFO)
|> permet d'insérer facilement et d'accéder facilement au dernier élément

Piles peuvent être représentés par des tableaux en C
|> on rajoute les éléments à la fin
### Complexité des opérations usuelles sur les piles
Empiler (rajouter un élément au début) et dépiler (enlever l'élément au début) sont en $\mathcal{O}(1)$
Les autres sont en $\mathcal{O}(n)$
## Allocation mémoire
Le stack contient les variables qui ne sont allouées par `malloc`
|> est une pile, d'où son nom en français « pile d'exécution »

La mémoire n'est libérée que quand la fonction finit de s'exécuter
|> pose problème pour les fonctions récursives

Une fonction récursive terminale est quand elle s'appelle elle-même à la fin de l'appel
|> permet de limiter les appels récursifs
|> permet d'optimiser la mémoire

> [!warning] Récursivité terminale
> Une fonction récursive terminale doit bien être de la forme `return fonction()` et non `return expression` (où expression fait appel à la fonction) !
> Une « mauvaise » fonction récursive n'est pas optimisée

```c title="Une fonction récursive NON terminale"
int somme(int n){
	if (n < 2){
		return n;
	}
	return n+somme(n-1);
}
```

```c title="Une fonction récursive terminale"
int somme(int n, int s){
	if (n == 0){
		return s;
	}
	return somme(n-1, s+n);
}
```

```elixir title="car c'est plus beau"
def somme(n) do
	somme(n, 0)
end

defp somme(n, a) when n > 0 do
	somme(n-1, a+n)
end

defp somme(0, a) do
	a
end
```
