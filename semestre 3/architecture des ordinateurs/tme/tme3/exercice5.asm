.data
.text
	lui $3, 0xAABB
	ori $3, $3, 0xCCDF
	
	# variable définissant le bit qu'on déplace
	ori $4, $0, 3
	# on génère le mask pour sélectionner le bit
st:	ori $8, $0, 1 # est le mask
	ori $9, $0, 3 # est le décallage pour le mask
	subu $9, $9, $4 # le nombre de décallage du bit pour le mask
	sllv $8, $8, $9 # on génére le mask
	# on applique le mask
	and $10, $3, $8 # on sélectionne le bon bit
	srlv $10, $10, $4 # on décalle le bit
	# on ajoute le résultat
	or $5, $5, $10
	# on boucle
	ori $11, $0, 1
	subu $4, $4, $11
	bgez $4, st
	
	ori $2, $0, 10
	syscall