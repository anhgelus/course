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