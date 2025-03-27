---
tags:
  - sorbonne
  - informatique
semestre: 2
---
On va implémenter un table de hashage et des files
## Files
On utilise par défaut des piles « Last In First Out » (LIFO) dans les listes
|> on ajoute en tête, on retire la tête

Mais comment faire une file ?
|> est un « First In First out »

On a les structs suivantes :
```c title=queue_list.c
typedef struct _cell{
	int donnee;
	struct _cell *suivant;
} cell;

typedef struct _fifo{
	cell *first;
	cell *last;
} fifo;
```

On utilise maintenant le type `*fifo` pour représenter une liste
```c title=queue_list.c
fifo *list = NULL; // est une nouvelle liste de type FIFO
```

Bibliothèque minimale pour les listes FIFO contient :
- `new_fifo` -> crée une nouvelle liste FIFO
- `is_empty` -> vérifie si la liste est vide
- `add` -> ajoute un élément à la fin
- `pop` -> retire le premier élément
- `print_fifo` -> affiche la liste

```c title=queue_list.c
fifo *new_fifo(){
	fifo *f = malloc(sizeof(fifo));
	f->last = NULL;
	f->first = NULL;
	return f;
}


int is_empty(fifo f){
	assert((f.last && f.first) || (!f.last && !f.first)); // permet de faire une vérification et de faire en sorte que le programme s'arrête proprement
	return !f.first && !f.last
}

void add(fifo *f, int val){
	if (*f == NULL) return;
	cell *c = malloc(sizeof(cell));
	c->suivant = NULL;
	c->donnee = val;
	if (is_empty(f)) f->first = c;
	else f->last->suivant = c;
	f->last = c;
}

int pop(fifo *f){
	if (!f || is_empty(f)) return 0;
	cell c = f->first;
	int d = c->donnee;
	f->first = c->suivant;
	free(c);
	if (!f->first) free(f);
	return d;
}

void print_fifo(fifo *f){
	if (!f) {
		printf("\n");
		return;
	}
	cell *first = fifo->first;
	printf("{");
	while (first){
		printf("%d, ", f->donnee);
		first = first->suivant;
	}
	printf("}\n");
}
```
## Table de hashage
Comme on ne peut pas représenter toutes les possibilités, on a besoin de trouver une structure de donnée et sa fonction pour les séparer
|> est le principe des maps

Soit $h$ une fonction de hashage de taille $t$
|> les valeurs qu'elles donnent sont dans $[0, t-1]$

Une fonction de hashage peut être la somme de la taille des caractères ASCII modulo la taille
|> $h$ de `"LU1IN002"` vaut donc `76+85+49+73+78+48+48+50 = 507` et si sa taille vaut 500, alors $h$ vaut `7`
|> cette fonction n'est pas très efficace car elle provoque beaucoup de collisions ($h$ de `"LU2IN001"` vaut aussi `7`)

Pour gérer les collisions, on a deux grandes possibilités :
- on prend la case d'après (hashage linéaire)
- on utilise une liste pour représenter les collisions dans la case
	|> cette liste devra contenir la clé et la valeur pour bien tout vérifier

Exemple de fonction de hashage
```c title=hash.c
int h(char *key, int t){
	int sum = 0;
	while (*key != '\0') {
		sum += *key;
		key = key+1;
	}
	return sum % t;
}
```

Pour construire le stockage, on fait :
```c title=hash.c
typedef struct _DataHash{
	char *key;
	int val;
} DataHash;

int main(){
	DataHash t_hash[] = cell[TAILLE];
	int ki = h("LUIN002", TAILLE);
	t_hash[ki].key = "LUIN002";
	t_hash[ki].val = 753;
}
```

Fonctions usuelles :
```c title=hash.c
int add_hash(DataHash t_hash[], int size, char *key, int val){
	int ki = h(key, size);
	int i = ki+1;
	while (t_hash[ki] != NULL && i != ki) i = (i+1)%size;
	if (!t_hash[ki]) return 0;
	t_hash[ki] = DataHash{key, val};
	return 1;
}
```

On peut aussi gérer les collisions à l'aide d'une liste
|> on a des pointeurs vers des listes au lieu d'avoir directement la valeur dans `DataHash`