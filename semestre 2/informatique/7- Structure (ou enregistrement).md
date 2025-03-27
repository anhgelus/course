---
tags:
  - sorbonne
  - informatique
semestre: 2
---
Pour organiser les données, on utilise `struct`
```c title=structure.c
struct s_int_pair {
	int fst;
	int snd;
}; // le ; est *obligatoire*
```
Est toujours au début du fichier `.c` ou dans le `.h` si elle est utilisée par plusieurs fichiers
|> possède deux champs nommés `fst` et `snd`

Les fichiers headers (`.h`) spécifient les interfaces utilisables par l'extérieur du fichier C
|> contient les struct publics, les functions publiques...
|> ne contient pas tout ce qui est privé

Pour qu'une variable utilise un struct, on écrit
```c title=structure.c
struct s_int_pair point;
```
sauf que c'est long à écrire, donc on renomme tout ça avec un `typedef` :
```c title=structure.c
typedef struct s_int_pair int_pair;
int main(){
	int_pair point; 
	return 0;
}
```
on peut aussi tout définir d'un coup
```c title=structure_better.c
typedef struct s_int_pair{
	int fst;
	int snd;
} int_pair;
```

> [!NOTE] Nom de la structure et nom du type associé
> Souvent, on nomme `_ABC` le nom de la structure et `ABC` le nom du type associé
> |> permet d'avoir un nom similaire mais différent
> |> est une convention

Pour initialiser un struct, on utilise les parenthèses
```c title=structure_init.c
int_pair p = {1,2}; // initialisation séquentielle
int_pair p2 = {.snd=3, .fst=4}; // initialisation sélective
```
la première est traditionnelle et est commune

Pour modifier les valeurs dans un struct, on accède aux champs avec l'opérateur `.` :
```c title=structure_init.c
p.fst = -1;
p.snd = -2;

p = p2; // copie la structure p2 dans p
```

*voir le cours pour la représentation dans le stack*

Quand on définit une structure, on peut perdre de la mémoire, notamment si on utilise pas tout un octet

Structures et fonctions
|> on peut retourner des structures depuis des fonctions sans aucun problème (pas besoin de faire un `malloc`)
|> il n'y a pas d'effet de bord quand on utilise des structures dans une fonctions -> on a besoin d'utiliser un pointeur pour en réaliser un

Il n'existe pas d'arithmétique des structures

On peut chaîner les structures, i.e.
```c title=chained_structure.c
struct _cell {
	int v;
	struct _cell* next;
}
```
(ce qui donne une liste chaînée)

L'opérateur `->` est un raccourcie permettant le déférencement rapide
```c title=arrow_operator.c
Foo *foo;

foo->bar = 10;
// est équivalent à
(*foo).bar = 10;

foo->baz();
// est équivalent à
(*foo).baz();
```

On a fini toutes les questions de syntaxe en C