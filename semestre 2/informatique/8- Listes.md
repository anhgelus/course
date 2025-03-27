---
tags:
  - sorbonne
  - informatique
semestre: 2
---
Pour ajouter une élément dans un tableau, on a besoin de :
- rajouter une case
- déterminer l'emplacement de l'élément à insérer
- décaler d'une position tous les éléments situés après l'insertion

Struct d'une cellule d'une liste :
```c title=chained_list.c
typedef struct _cellule {
	int data;
	_cellule* before;
} Cellule;
```

Une liste vide est :
```c title=chained_list.c
Cellule* liste = NULL;
```

Pour créer une ajouter une cellule à une liste, on fait :
```c title=chained_list.c
Cellule* add_to_list(Cellule* cell, int val){
	Cellule* el = malloc(sizeof(Cellule)); // on alloue la prochaine valeur
	el->data = val;
	el->before = cell;
	return el;
}
```

Pour afficher une liste :
```c title=chained_list.c
void print_list(Cellule* cell){
	if (cell->before == NULL) printf("%d", cell->data);
	else {
		printf("%d ", cell->data);
		list_to_string(cell->before);
	}
}
```

Pour sommer la liste :
```c title=chained_list.c
int sum_list(Cellule* cell){
	return cell->before == NULL ?
		cell->data :
		cell->data + sum_list(cell->before);
}
```

Pour libérer une liste :
```c title=chained_list.c
// on préfère souvent utiliser un while pour éviter de consommer bcp de ram
void free_list(Cellule *cell){
	if (!cell) return; // on vérifie que cell n'est pas null (i.e. elle a déjà été initialisée)
	if (cell->before != NULL) free_list(cell->before);
	cell->before = NULL;
	free(cell);
}
```

> [!NOTE] Les cas de tests des listes
> On teste élément en premier, en dernier, au milieu et si la liste est vide

Pour supprimer un élément :
```c title=chained_list.c
// on pourrait aussi faire une version avec simple pointeur où on renverrait le first
void delete_el_list(Cellule **p_cell, int v){
	if (!*p_cell) return;
	Cellule *prec = NULL;
	Cellule *next = *p_cell;
	Cellule *first = *p_cell;
	while (next && liste->data != v) {
		prec = next;
		next = next->before;
	}
	if (next == NULL) return;
	if (prec != NULL) prec->before = next->before;
	else first = first->suivant;
	free(next);
	*p_cell = first; // est-ce vraiment utile ?
}
```
-> voir les diapos pour un truc plus clean