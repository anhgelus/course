---
tags:
  - sorbonne
  - informatique
semestre: 2
---
LZW raisonne sur les syllables
|> les strings sont remplacés par des codes plus court stocker dans une map
|> n'a pas besoin d'analyser les strings pour compresser et n'a pas besoin de connaître la map pour décompresser

Algo :
- lit la chaîne la plus longue dans la map
- remplace la chaîne lue par son code dans le fichier de sortie
- insère une nouvelle chaîne composée du préfixe lu et du caractère suivant dans le fichier dans la map
 
 En gros, ça fait ça pour `"ABCDABCD"` :
 - `"A"` -> 65 (d'après la valeur initiale dans la map)
 - `"AB"` -> 256 (d'après l'algo de la map)
 - on enlève le préfixe `"A"` et on avance : `"BC"` -> 257 (toujours d'après l'algo)
 - on enlève le préfixe `"B"` et on avance : `"CD"` -> 258 (...)
 - on enlève le préfixe `"C"` et on avance : `"DA"` -> 259 (...)
 - on enlève le préfixe `"D"` et on avance :`"AB"` -> déjà dans le dictionnaire, donc 256 ; on insère `"ABC"`
 - on avance : `"ABCD"` -> déjà dans le dictionnaire, donc 258 ; on insère `"ABCD"`
 -> si la valeur est déjà dans la map, alors on l'utilise comme préfixe pour le prochain, sinon on garde le plus grand

Le fichier de sortie vaut donc : `65 66 67 68 256 258`
|> on ne rajoute pas de suite `257` pour remplacer `65 66` car ça pourrait augmenter la taille

Quand on décompresse, on a besoin d'utiliser le dictionnaire de base
|> quand on arrive sur une séquence compresser, on a besoin de faire le raisonnement inverse de la compression : on détermine la chaîne qui aurait donné la valeur