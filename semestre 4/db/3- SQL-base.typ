#import "@local/template:1.0.0": *
#import "@local/callout:1.0.0": *

#show: doc.with(
  authors: (
    (name: "William Hergès", affiliation: "Sorbonne Université", email: "william@herges.fr"),
  ),
  page_title: "SQL base",
)

= Création d'une table

On utilise H2 comme DB.

```sql
CREATE TABLE <table> (
  <attr_name> <attr_type> [NOT NULL] [DEFAULT <attr_val>],
  <attr_name> <attr_type> [NOT NULL] [DEFAULT <attr_val>],
  <attr_name> <attr_type> [NOT NULL] [DEFAULT <attr_val>],
  ...
  <attr_name> <attr_type> [NOT NULL] [DEFAULT <attr_val>],
  <contrainte>,
  <contrainte>,
  <contrainte>
)
```

== Types

=== Alphanumériques

Alphanumériques~:
- `char(n)`, `character(n)`
- `varchar(n)`, `varying(n)`

$n$ vaut $1$ par défaut, peut aller de $1$ à $1048576$.

`char(n)` est une allocation statique -> tous les mots feront toujours $n$.

`varchar(n)` est une allocation dynamique -> les mots font au maximum $n$.

=== Numériques

Numériques~:
- `smallint`, `int` (ou `integer`), `bigint`
- `numeric(t,d)` ou `decimal(t,d)`
- `real`, `double precision`

`numeric(t,d)` ou `decimal(t,d)` représentent les nombres à virgule.
- `t` est le nombre total de chiffres (on ne compte pas le signe)
- `d` est le nombre de chiffres après la virgule (partie décimale)

`real`, `double precision` représentent les floatants.

=== Temps

`date` est la date calendaire (jour, mois, année).

`time` est le temps d'un jour (heure, minutes, secondes), peut contenir un fuseau horaire.

`timestamp` est la combinaison de `date` et de `time`.

=== Domaine

Définition d'un nouveau type à partir d'un type de base.

Associe éventuellement une contraine devant être évaluée à vrai ou inconnu pour être vérifiée.

```sql
CREATE DOMAIN <nom> AS <type> [<contrainte>];
```

Par exemple,
```sql
CREATE DOMAIN fin_semaine as TEXT CHECK (VALUE in ('sam', 'dim'));
CREATE DOMAIN sal_min as NUMERIC(7,2) CHECK (VALUE >= 10000);
```

== Contrainte

Est une condition devant être vérifiée par toutes les données.
Cela permet d'avoir une cohérence et de garder cette cohérence avec une mise à jour.

=== Type

Peut toucher rôle des clés~:
- identification des $n$-uplets
- chaque table possède au moins une clé (la primaire)
- vérification efficace avec des index

Peut toucher les données basiques~:
- _voir diapo_

=== Contraintes de clés

Clé candidate sont les attributs dont les valeurs sont distinctes pour tous les $n$-uplets.

Clé primaire est une clé candidate dont chacun des attributs est renseigné.
```sql
PRIMARY KEY(<attr>)
```

Clé étrange est un attribut dans les valeurs proviennent d'une clé candidate ou d'une clé primaire définie autre part.
(Peut être la même table.)
```sql
FOREIGN KEY <attr> REFERENCES <table>
```
Comme on n'a pas indique d'attributs, cela signifie que l'on réfère à la clé primaire.

=== Contraintes sur les données

_Voir le diapo_

=== CHECK et ASSERTION

_Voir le diapo_

== Modifier une table

=== Suppression

Pour supprimer une table~:
```sql
DROP TABLE <name> [IF EXISTS];
```

Si il existe des contraintes portant sur cette table, on peut les supprimer durant la suppression~:
```sql
DROP TABLE <name> IF EXISTS CASCADE;
```

=== Modification d'un champ

= Requêtes SQL simples

SQL provient de la fusion entre l'algèbre relationnelle et des tuples.

```sql
SELECT <projection>
FROM <table>
[WHERE <condition>]
```
