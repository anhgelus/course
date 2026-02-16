---
tags:
  - sorbonne
  - informatique
  - db
  - td
semestre: 4
---
## Exo 5
```
Bateau(_immat_, nom, longueur, skippeur*)
Marin(_nom_)
Skipper(_nom*_)
Equipiers(_nom*_, profession)
Sponsor(_nom_)
Epreuves(_jour_, start, end)
Classement(_immat*_, _jour*_, position)
Engagé(_immat*_, _equipier*_, _jour*_)
Finance(_nom*_, _sponsor*_, _immat*_, montant)
```
## Exo 6
```
Drug(_code_, libelle, indication, posologie)
Consultation(_num_, date, medecin*, patient*)
Med(_matricule_, nom)
Patient(_num-ss_, nom)
Prescrit(nb-jours, _drug*_, _consult*_)
```
## Exo 7
```
Film(_titre_, real*, entrees)
Real(_nom_, prenom)
Acteur(_nom_, prenom, date-naissance, adresse)
Joue(_film*_, _acteur*_, cachets)
```

```sql
CREATE DATABASE IF NOT EXISTS reals(
	nom TEXT PRIMARY KEY,
	prenom TEXT
);

CREATE DATABASE IF NOT EXISTS acteurs(
	nom TEXT PRIMARY KEY,
	prenom TEXT,
	age INTEGER,
	adresse TEXT
);

CREATE DATABASE IF NOT EXISTS film(
	title TEXT PRIMARY KEY,
	real_name TEXT,
	entrees INTEGER,
	FOREIGN KEY(real_name) REFERENCES reals(nom)
);

CREATE DATABSE IF NOT EXISTS joue(
	film_title TEXT,
	film_acteur TEXT,
	cachet INTEGER,
	FOREIGN KEY(film_title) REFERENCES film(title),
	FOREIGN KEY(film_acteur) REFERENCES acteurs(nom),
	PRIMARY KEY (film_title, film_acteur)
);
```
## Exo 8
```
Ouvrage(_ref_, titre, editeur)
Revue(_ouvrage*_, period)
NumeroRevu(_numero_, date, revue*)
Livre(_ouvrage*_)
Abonne(_code_, nom, prenom, date-abo)
Calendrier(_date-pret_)
Pret(_ouvrage*_, _abonne*_, date)
HistPret(_ouvrage*_, _abonne*_, _calendrier*_)
```
## Exo 9
```
Personnel(_id_, nom, prenom, bureau)
Enseignant(_personnel*_)
Chercheur(_personnel*_, lab*)
EnseignantChercheur(_enseignant*_, _chercheur*_)
Reunion(_id_, date, start, end, salle)
Participe(_personnel*_, _reunion*_)
Matiere(_id_, annee)
Cours(_salle_, begin, finish, day, start, end, matiere*, enseignant*)
Lab(_nom_, secretariat)
Mission(_chercheur*_, begin, finish, lieu)
```
## Exo 10

(j'ai pas fait les 11 et 12 par flemme)