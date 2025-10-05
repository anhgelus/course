Une hashmap semble pertinente, car on a une association clé/valeur.

La fonction de hachage devra donc renvoyé sur [0, 100 000-1], i.e. être modulo 100 000.

Elle provoque beaucoup de collisions, notamment si au moins une valeur est à 0. 
Pour régler ce problème, on pourrait utiliser
```c
int g(int x1, int x2, int x3, int x4, int x5, int x6) {
    return (x1+1)*(x2+1)*(x3+1)*(x4+1)*(x5+1)*(x6+1) % 100000;
}
```

La fonction ne prend pas en compte l'ordre des valeurs.

