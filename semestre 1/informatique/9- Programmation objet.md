---
tags:
  - sorbonne
  - informatique
semestre: 1
---
On utilise de plus des langages multi-paradigmes

Les langages les plus connus en POO sont Java et C++

POO permet de créer ses propres types de données

Une classe est un modèle des objets
```python
class FeuTricolore:
	def __init__(self) -> None:
		self._couleur = "rouge"
	def couleur(self) -> str:
		return self._couleur
	def change(self) -> None:
		if self._couleur == "rouge":
			self._couleur = "vert"
		elif self._couleur == "vert":
			self._couleur = "orange"
		elif self._couleur == "orange":
			self._couleur = "rouge"
	def __rep__(self) -> str:
		"""est l'équivalent du toString en Java"""
		return f"couleur {self._couleur}"

feu: FeuTricolore = FeuTricolore()
for _ in range(10):
	feu.change()
	print(f"la couleur du feu est {feu}")
```

Pour faire hériter une classe, on la met entre parenthèse, e.g.
```python
class Point:
	# ...
class PointColore(Point):
	# hérite de Point
```
cela permet d'avoir accès à toutes les méthodes de la méthode parente

On représente des classes avec des diagrammes de classes (UML)

Typage nominal = le nom de la classe détermine le type
|> simple mais limité

Typage structurel = le nom de la classe et toutes les méthodes dans la classe (alourdie le type)
|> puissant mais lourd

En python, c'est canardesque : duck-typing en anglais ; le typage est dynamique
|> presque aucun effort mais dangereux

On vérifie le type avec la fonction `isinstance`

Voir le cours pour créer des itérables