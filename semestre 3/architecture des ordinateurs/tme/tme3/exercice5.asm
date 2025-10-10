.data
.text
	lui $3, 0xAABB
	ori $3, $3, 0xCCDD
	
	# on sélectionne o_1, on le décalle de 3, on l'ajoute
	# on sélectionne o_2, on le décalle de 2, on l'ajoute
	# on sélectionne o_3, on le décalle de 1, on l'ajoute
	# on sélectionne o_4, on le décalle de 0, on l'ajoute
	
	ori $6, $0, 31 # est le nombre - 1 de bit à modifier
	or $7, $0, $6 # est notre i de la boucle qui bouge
repeat:	
	ori $8, $0, 1	# masque
	sub $10, $6, $7	# décallage pour sélection
	sllv $8, $8, $10	# on adapte notre masque pour prendre le bon
	and $9, $3, $8	# on sélectionne le bit
	srlv $9, $9, $10	# on remet le bit à l'origine
	sllv $9, $9, $7	# on le décalle
	or $4, $4, $9	# on l'ajoute
	# on calcule le nouveau i dans $7
	ori $12, $0, 1
	sub $7, $7, $12
	# on boucle si $7 >= 0
	bgez $7, repeat
	
	ori $2, $0, 35
	syscall
	
	ori $2, $0, 10
	syscall
