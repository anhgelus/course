.data
ch: .asciiz "coucou"
.text
	lui $8, 0x1001
	ori $2, $0, 4
	or $4, $0, $8
	syscall
	
	# on garde en mémoire les deux caractères
	lb $9, 0($8)
	lb $10, 1($8)
	# on les échanges
	sb $9, 1($8)
	sb $10, 0($8)
	# et on affiche
	syscall
	
	ori $2, $0, 10
	syscall