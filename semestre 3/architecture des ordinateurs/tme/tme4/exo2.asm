.data
v1:	.word -1
v2:	.word 0xFF

o: 	.byte 0xFF
.text
	lui $8, 0x1001
	lw $9, 0($8)
	or $4, $0, $9
	ori $2,$0,1
	syscall
	
	lw $10, 4($8)
	or $4, $10, $10
	syscall
	
	addi $9, $9, 1
	sw $9, 0($8)
	addi $10, $10, 1
	sw $10, 4($8)
	
	addi $8, $8, 8 # on récupère l'adresse de o
	lb $9, 0($8)
	or $4, $0, $9
	syscall # affiche -1 car il l'étend
	lbu $10, 0($8)
	or $4, $0, $10
	syscall # affiche 255 car il n'est pas signé
	
	ori $2, $0, 10
	syscall
	