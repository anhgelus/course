---
tags:
  - sorbonne
  - informatique
semestre: 2
---
## Architecture de von Neumann
Ordinateur est composé d'un processeur, d'une mémoire et de périphériques
![[computer_architecture_simplified.png]]
![[computer_architecture_detailled.png]]

Registres = mémoire interne au CPU

Unité de base = octet (8 bits)

**Organisation de la mémoire :**
![[ram_organisation_schema.png]]

Les tensions électriques pour la valeur binaire 1 = 5 V ou 3.3 V ou 1.65 V
|> compliqué de descendre plus bas que 1 V à cause de la tension de seuil du silicium
Les tensions électriques pour la valeur binaire 0 = 0 V

On peut ensuite calculer des choses :
|> $1010 \land 0011 = 0010$ (bool)
|> $1010 + 0010 = 1100$ (binaire)

Souvent, on représente la mémoire avec un tableau de 4 colonnes avançant de 4 en 4

Pour représenter les floatants, on les décompose en 3 parties :
- signe
- mantisse
- exposant

Après on peut les approximer à l'aide des sommes d'inverses de 2 ($\frac{1}{2}+\frac{1}{4}+\cdots$)
Exemple sur $-50.5$ :
- $2^5+2^4+2^1+2^{-1}$
- $(2^0+2^{-1}+2^{-4}+2^{-6})\times 2^{5}$
- la somme est la mantisse et la multiplication est l'exposant

Chaque octet a une adresse unique !
## Portée des variables
Globale = disponible partout dans le fichier
Paramètre = disponible dans toute la fonction
Locale = disponible dans le bloc

Le shadowing existe en C
## Pointeurs
On peut mettre une valeur et une adresse en mémoire
|> valeur est une valeur classique
|> une adresse est une zone de la mémoire contenant une valeur

Une variable qui contient une adresse est un pointeur
```c
int *n;
```

ici, `n` contient l'adresse vers un entier

On récupère l'adresse avec l'opérateur `&`
```c
int x = 0;
int *p;
p = &x;
printf("%t %d", p, *p);
```

On peut afficher l'adresse avec `printf("%t", n)`
On peut afficher le contenu du pointeur avec `*n`