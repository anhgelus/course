---
tags:
  - sorbonne
  - informatique
  - structure-des-données
  - td
Semestre: 3
---
Code 1 est en $\Theta (1)$.

Code 2 est en $\mathcal{O} (n)$ et en $\Omega(1)$.

Code 3 est en $\mathcal{O} (n\times m)$ et en $\Omega(\min\{n,m\})$ car :
- `equals_tab` renvoie 0 car elle a fait $1$ tours, donc on fait $n$ tours dans `equals_one_line`
- `equals_tab` renvoie 1 car elle a fait $m$ tours, donc on fait $1$ tours dans `equals_one_line`


