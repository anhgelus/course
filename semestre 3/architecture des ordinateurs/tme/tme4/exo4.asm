# "123456" = 0x31 32 33 34 35 36 00
.data
cod:	.byte 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x00
.text
	lui $8, 0x1001
	ori $2, $0, 4
	or $4, $0, $8
	syscall
	
	lb $16, 2($8)
	or $4, $0, $16
	ori $2, $0, 1
	syscall
	
	# "0" est représenté par 0x30
	# les autres chiffres sont à la suite de 0x30 jusqu'à 0x39 ("9")
	# pour transformer le code ASCII d'un chiffre en chiffre, il suffit donc de lui soustraire 0x30 pour obtenir le chiffre
	
	# on a besoin de mettre 0x30 dans un registre car l'opcode subi n'existe pas
	ori $9, $0, 0x30
	sub $17, $16, $9
	or $4, $0, $17
	syscall
	
	ori $18, $0, 0x34 # est l'ascii de "4"
	sub $18, $18, $9
	or $4, $0, $18
	syscall
	
	ori $2, $0, 10
	syscall