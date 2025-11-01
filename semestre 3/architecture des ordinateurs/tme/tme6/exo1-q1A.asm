.data
ch:	.space 11
.text
#main
	# prologue
	addiu $29, $29, -16 
	# scanf
	ori $2, $0, 5
	syscall
	sw $2, 4($29)
	# chaine[10] = 0
	lui $8, 0x1001
	sb $0, 10($8)

	# i = 9
	lw $9, 0($29) # i
	ori $9, $0, 9
	sw $9, 0($29)
	
while:
	# i >= 0
	lw $9, 0($29)
	bltz $9, end_while
	# corps
	# r = nb % 10
	lw $10, 4($29) # nb
	ori $11, $0, 10
	div $10, $11
	mfhi $12
	sw $12, 8($29)
	# nb /= 10
	mflo $12
	sw $12, 4($29)
	# chaine[i] = r + 0x30
	# *(chaine + i) = r + 0x30
	lw $9, 0($29)
	addu $13, $8, $9
	lw $10, 8($29) # r
	addiu $14, $10, 0x30
	sb $14, 0($13)
	
	# i -= 1
	lw $9, 0($29) # i
	addiu $9, $9, -1
	sw $9, 0($29)
	j while
end_while:
	ori $2, $0, 4
	or $4, $0, $8
	syscall
	# épilogue
	addiu $29, $29, 16
	ori $2, $0, 10
	syscall