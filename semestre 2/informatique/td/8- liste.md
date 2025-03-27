---
tags:
  - sorbonne
  - informatique
  - td
semestre: 2
---
```c title=chained_list.c
typedef struct cellule_t{
	int donnee;
	struct cellule_t *suivant;
} Cellule;
```

Pour créer une nouvelle `Cellule`, on fait
```c title=chained_list.c
Cellule *create_cellule(int d){
	Cellule *cell = malloc(sizeof(Cellule));
	cell->donnee = d;
	cell->suivant = NULL;
	return cell;
}
```

```c title=chained_list.c
Cellule *last_element_list(Cellule *list){
	if (!list) return NULL;
	while (list->suivant) list = list->suivant;
	return list;
}
```

Pour modifier une cellule à la position `pos`
```c title=chained_list.c
void modify_element_list(Cellule *list, int pos, int val){
	for (int i = 0; list && p <= pos; i++){
		if (p == pos) list->donnee = val;
		list = list->suivant;
	}
}
```

Pour vérifier si deux listes sont identiques
```c title=chained_list.c
int equal_list(Cellule *l1, Cellule *l2){
	if ((!l1 && l2) || (l1 && !l2)) return 0;
	while (l1 && l2){
		if (l1->donnee != l2->donnee) return 0;
		l1 = l1->suivant;
		l2 = l2->suivant;
	}
	return !l1 && !l2;
}
```

Pour vérifier si une liste est incluse dans l'autre
```c title=chained_list.c
// if l2 is included in l1
int include_list(Cellule *l1, Cellule *l2){
	if (!l1 && l2) return 0;
	while (l1 && l2){
		if (l1->donnee == l2->donnee) l2 = l2->suivant;
		else if (l1->donnee > l2->donnee) return 0;
		l1 = l1->suivant;
	}
	return !l2;
}
```