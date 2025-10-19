---
tags:
  - sorbonne
  - informatique
  - architecture-des-ordinateurs
semestre: 3
---
## Registres
Un registre de $n$ bits est un composant capable de mémoriser un mot binaire de $n$ bits
|> changement de valeur possible uniquement lors de front montant/descendant du signal de l’horloge
|> émission de la valeur contenue dans le registre en continu
|> les registres dépendent du processeur
-> contient toutes les informations utilisées par le processeur

Tous les registres du Mips font 32 bits et en possèdent 32
|> les registres sont nommés par leur numéro

PC (Program Counter) = adresse de l’instruction en cours d’exécution (ou la suivante)
|> modifié après l’exécution de chaque instruction

IR (Instruction Register) = instruction en cours de traitement

HI/LO (High/Low) = les registres contenant le résultat d’opérations de multiplication ou de division

Il y a d'autres registres qu'on n'utilisera pas en cours

> [!info] L'architecture moderne du Mips est le RISC-V

Processus d'exécution :
1. Lire une instruction en mémoire (dans IR)
2. Décoder l'instruction
3. Exécuter l'instruction
4. Calculer l'adresse de l'instruction suivante : mettre à jour le PC

Utilisation des registres :
- `$0` contient la valeur 0 -> est le générateur du 0
- `$1` registre réservé à l'assembleur (programme qui génère le binaire)
- `$2 - $3` contiennent les résultats des appels de fonction
- `$2` peut aussi contenir le numéro d'appel système
- `$4 - $7` (est aussi appelé de `a0` à `a3`) utilisés pour le passage d'arguments lors des appels de fonctions ou appels systèmes
- `$8 - $15` contiennent les valeurs non persistantes (libre)
- `$16 - $25` contiennent les valeurs persistantes (libre)
- `$26 - $27` contiennent les valeurs OS
-> voir les diapos pour les autres

Les valeurs persistantes gardent les valeurs avant les appels

> [!NOTE] Notation des registres
> En Mips, on peut les notés avec `R`, `r` ou `$`, ainsi `R1 = r1 = $1`

> [!danger] On **doit** respecter les règles d'utilisation
## Jeu d'instruction
La vue externe d'un CPU peut être définie par l'ensemble des instructions qu'il est capable de traiter

Jeu d'instruction d'un CPU (aussi appelé ISA) est la donnée :
- de l'ensemble des instructions qu'il peut effectuer
- le codage de ces instructions en binaire

Une instruction, c'est une commande définissant le traitement à effectuer et quelle sera la prochaine instruction à exécuter
-> le traitement séquentiel est implicite

On peut spécifier quelle autre ligne à utiliser après l'instruction en cours
-> c'est un « saut »

Le code d'opération définit quelle opération utiliser
|> elle porte sur les opérandes
|> opérandes immédiates sont codées dans l'instruction
|> les autres opérandes sont dans des registres indiqués

`add $4, $2, $5` signifie `$4 <- $2 + $5`
`ori $4, $2, 0xABCF` signifie `$4 <- $2 | (0x0000 ABCF)`
`addi $4, $2, 0xABCF`signifie `$4 <- $2 + (0xFFFF ABCF)` car, par défaut, les entiers sont considérés comme relatifs
`mult $3, $4` signifie `(HI/LO) <- $3 × $4`
`div $3, $4` signifie `(HI/LO) <- $3 ÷ $4` (`HI` contient le quotient et `LO` le reste)

On peut définir un label pour savoir où sauter

4 classes d'instructions :
- arithmétique et logique -> addition, and...
- transfert mémoire -> lire la mémoire...
- rupture de séquence -> faire un saut...
- appels systèmes -> lire un caractère, écrire un entier sur l'écran

Voir le memento pour la liste des instructions

L'instruction `ori` permet de placer une certaine valeur dans un registre
|> `ori $2, $0, 0x1234` place `0x1234` dans `$2`

Les instructions en Mips possèdent 3 formats :
- R -> quand on utilise 3 registres
- I -> quand on fait des calculs avec des immédiats
- J -> quand on fait des sauts

| Nom\n° de bit | 31 - 26 | 25 - 21 | 20 - 16 | 15 - 11 | 10 - 6 | 5 - 0 |
| ------------- | ------- | ------- | ------- | ------- | ------ | ----- |
| **R**         | OPCODE  | RS      | RT      | RD      | SH     | FUNC  |
| **I**         | OPCODE  | RS      | RT      | IMM     | IMM    | IMM   |
| **J**         | OPCODE  | JUMP    | JUMP    | JUMP    | JUMP   | JUMP  |
OPCODE est spécifié dans un codage normé
|> détecte le format utilisé en fonction de l'OPCODE

Le codage normé ne contient pas tous les OPCODE
|> s'il n'est pas dedans, l'OPCODE est le "special" et l'opération est dans la case FUNC
|> l'opération dans FUNC est aussi dans un codage normé

On regarde le memento pour savoir ce que signifie RS, RT et RD
|> j'ai l'impression que le registre contenant le résultat est toujours le dernier affiché, mais c'est à vérifier

SH permet d'utiliser le shift

Langage haut niveau :
- $\forall$ ISA
- notions de type
- peut créer des variables
- structure les traitements
- gestions d'erreurs

Assembleur :
- Allocation des données et gestion mémoire
- Suite d'instructions spécifiques
- Présence d'étiquettes pour désigner les adresses (données ou instructions)

Un programme de haut niveau peut être :
- natif, i.e. il est compilé pour être exécuté sur la machine cible
- interprété, i.e. un programme natif interprète le programme et l'exécuté

Nous, on ne regarde que les programmes natifs

Assemblage = assembleur -> binaire
Désassemblage = binaire -> assembleur

Un label (ou étiquette) s'écrit comme : `nom: add $4, $4, $3`
|> ici le label `nom` désigne la ligne `add $4, $4, $3`
-> elles ne sont pas conservées par lors de l'assemblage

En Mips, toujours deux sections différentes :
1. les données du programme
2. la section de code

Directive `.data` permet de dire que la suite sera des données
Directive `.text` indique que la suite sera des instructions

On met toujours `.data`, y compris si c'est vide (dans le cadre de cette UE)

Pour exécuter un programme, on a besoin de le charger
|> le mettre en mémoire
|> mettre dans PC la première adresse à exécuter

En Mips, les syscall se font à l'aide de `syscall`
|> il cherche toujours le numéro de l'appel dans `$2`
-> se finit donc toujours par
```asm
ori $2, $0, 10 # place 10 dans $2
syscall # syscall dans $2, i.e. syscall 10, i.e. fin du programme
```

On utilise le simulateur Mars pour écrire / exécuter des programmes
## Lancer un programme
Pour exécuter un programme, on a besoin de le lancer
|> besoin de le charger en mémoire -> souvent, le *loader* s'en occupe
|> chargé en RAM depuis l'adresse de base contenant le début du programme
|> modifie PC pour contenir l'adresse du début (adresse en RAM)
## System call
Un appel système est une demande de service fourni par le système
|> est un garde fou
|> `syscall` appelle ces services
|> chaque service possède son numéro en Mips
|> on met le numéro du service dans `$2`
|> pour passer des argument à `syscall`, on doit les mettre dans les registres `$4` à `$7`

Pour afficher 125 :
```asm
ori $4, $0, 125
ori $2, $0, 1
syscall
```

`syscall` est un déroutement -> est gérer par l'OS
## Données en mémoire
Variables globales et partie `.data`

On peut voir la mémoire en mode "mot" (32 bits) ou en "octet" (8 bits)
|> représente la même mémoire
|> "mot" est 4 fois plus grand qu'un octet

Mips ne peut lire que 4 octets (ou un mot, ou 32 bits) à la fois
|> adresse mémoire d'un mot est l'adresse la plus petite des 4 octets
|> octet est l'unité adressable -> pas possible d'être plus petit que ça

On utilise toujours les notations en Kio

Mémoire non réinscriptible = ROM, lente d'accès, contient le code de démarrage ou l'ensemble du code dans certains systèmes embarqués
Mémoire vive = RAM, volatile et rapide
Mémoire flash (USB, SD Card) = non volatile, peut écrire (mais pas beaucoup)

RAM garde les données en mémoire et ne les supprime pas jusqu'à ce qu'on écrit dessus
|> lecture est non destructive (pas vraie partout !)

Écriture RAM -> *store*
Lecture RAM -> *load*

Type de stockage en RAM :
- Big Endian (grand boutien) -> l'octet de poids fort est rangé à l'adresse la plus petite
- Little Endian (petit boutien) -> l'octet de poids faible est rangé à l'adresse la plus petite
-> avec les mêmes bits en RAM, on n'obtient pas le même mot !

Mips est en Little Endian

Après avoir écrit `0xAABBCCDD` à `0x4`, on obtient

| Adresse | `0x0` | `0x1` | `0x2` | `0x3` | `0x4`  | `0x5`  | `0x6`  | `0x7`  | `0x8` |
| ------- | ----- | ----- | ----- | ----- | ------ | ------ | ------ | ------ | ----- |
| Contenu | ?     | ?     | ?     | ?     | `0xDD` | `0xCC` | `0xBB` | `0xAA` | ?     |
On peut écrire en mot, demi-mot ou octet

Mémoire est structuré pour éviter d'avoir des problèmes des sécurités
|> programme ne peut pas utiliser la RAM de l'OS par exemple
-> elle est d'abord coupé en deux
|> une partie utilisateur et une autre système
|> est séparée par une adresse (tous ceux qui sont inférieures sont dans l'utilisateur en Mips)

Mémoire utilisateur, c'est :
1. segment de code (le code du programme)
2. segment de données (données et variables globales)
3. segment de pile (variables locales et contextes d'appels) -> stack
4. (le tas dans la pile, mais on n'en a pas ici)

**Besoin de lire le diapo 22/48** (et un peu avant)

Le transfert RAM -> CPU en Mips doit être sur la même ligne !

Les contraintes d'alignement sont respectées par défaut quand utilise les données globales
|> quand utilise `.space`, on a besoin d'utiliser `.align` pour aligner correctement les zones libres

Quand on utilise la mémoire, on a besoin de copier les valeurs dans les registres et d'après la mettre à jour

Signature des instructions d'accès mémoire : `Codop Rt, Imm16(Rs)`
|> `Rt` est la destination ou le registre source
|> `Imm16(Rs)` est la zone mémoire avec `Rs` étant le décalage en octet

On se place tjs du côté du processeur pour les opcodes
|> `l.` servent à *load*
|> `s.` servent à *store*
|> `.w` gèrent les mots (4 octets)
|> `.h` gèrent les half-words (2 octets)
|> `.b` gèrent les octets (1 octet)

```asm
lh $4, 4($3) # load le half-word contenu dans l'adresse 4 + $3 dans $4

lw $4, -2(3) # load le word contenu dans l'adresse -2 + 3 dans $4
```

Par défaut, tout est signé, si on veut être en non signé, on rajoute `u`, i.e. `lhu` pour récupérer un `uint16`

Il n'existe pas de pointeur
|> besoin de mettre à jour la mémoire
|> faut faire attention aux problèmes de synchronisation

Il y a toujours au moins un transfert mémoire vers CPU
|> est celui qui place le code dans IR
## Structures de contrôle
Pour ne plus faire une instruction séquentielle, on doit faire des sauts
|> deux types : inconditionnels et conditionnels
-> changent PC

Sauts inconditionnels -> les jumps (commencent par `j`)
|> `j label` saute au label
|> `jr Rt` saute à valeur contenu dans Rt

Sauts conditionnels -> les branchements (commencent par `b`)
|> saute si une condition est vraie
|> voir le memento

Afficher la valeur absolue d'un nombre
```asm
.data
n:	.word -1

.text
	lui $3, 0x10010000
	lw $4, 0($3)
	
# syntaxe du *if then* ici
	bgez $4, show
	sub $4, $0, $4
show:
	ori $2, $0, 1
	syscall
	
	ori $2, $0, 10
	syscall
```

Pour utiliser plusieurs conditions, on a besoin d'utiliser une instruction avant
|> `slt $10, $8, $9` met `$10` à `1` si `$8 < $9`, il le met à `0` sinon
-> on utilise un branchement après
|> si on veut une comparaison large $a\leqslant b$, on vérifie si $a > b$ est faux

Pour faire un `if else`, on fait :
```asm
	bcond ..., $0, else
	# instruction du if
	j next
else:
	# instruction du else
next:
	# suite
```

Pour faire un `while`, on fait :
```asm
boucle:
	bcond ..., $0, next
	# instruction du while
	j boucle
next:
	# suite
```

Le codage de `j label` est
|> `00010 Immédiat_sur_26_bits`
-> besoin de calculer la bonne adresse pour qu'elle soit sur 26 bits
|> on fait `PC = PC[31:28] | I * 4`
|> `PC[31:28]` permet de rester dans la partie code
|> `I` est l'immédiat avec en plus `[1:0]` qui sont nuls car multiple de 4
|> `* 4` provient du multiple de 4

Branchement sont en format I
|> immédiat est donc sur 16 bits
-> on a tjs besoin de le mettre sur 32 bits
|> on fait `PC = PC + 4 + (I * 4)`
|> le calcul du PC suivant est donc relatif à la ligne d'instruction en cours

**Dans tous les cas, on a besoin de savoir où se trouve l'étiquette pour la coder**
|> on a donc besoin de le faire en deux étapes (on les appelle "passe")
1. on s'occupe de toutes les instructions sans traiter les étiquettes
2. on traite les étiquettes après qu'on connait bien tout

**Revoir la construction des sauts**
## Tableaux, structures
**revoir le début des tableaux**

Un tableau de taille $n$ prend $n$ fois la taille du type stocké
|> un tableau d'entier prend $4n$ octets

L'adresse du $i$-ième élément du tableau est l'adresse du début $+ i\times n$
|> c'est déréférencer `&T[i]`

On déclare les tableaux comme
```asm
.text
tab:  .word 1, 2, 3 # équivalent de int tab[] = {1,2,3};
```

Attention à l'alignement quand on utilise les tableaux !

Les structures sont des ensembles de variables
|> on utilise les `.space` pour en initialiser des vides

**besoin de vérifier si c'est complet**
## Variables locales
Elles ne sont pas au même endroit que les variables globales
|> elles sont dans une zone variable qui contient les infos dynamiques
-> la pile !
|> création d'un contexte pour chaque fonction
|> contexte sont en LIFO, d'où la pile

**rattraper la gestion mémoire**
`0x8000 0000` -> égal ou plus grand pour le système
|> ce qui précède `0x8000 0000` est pour l'utilisateur
|> le fond de la partie utilisateur sont les contextes de fonction (la pile !)
-> le sommet de la pile est variable et est dans un registre particulier, le `$29` (stack pointer)