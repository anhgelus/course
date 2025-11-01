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
	
for:
	# i >= 0
	lw $9, 0($29)
	bltz $9, end_for
	# corps
	# r = nb % 10
	lw $10, 4($29) # nb
	ori $11, $0, 10
	div $10, $11
	mfhi $12 # r
	# nb /= 10
	mflo $10
	sw $10, 4($29)
	# chaine[i] = r + 0x30
	# *(chaine + i) = r + 0x30
	addu $13, $8, $9
	addiu $12, $12, 0x30
	sb $12, 0($13)
	
	# i -= 1
	addiu $9, $9, -1
	sw $9, 0($29)
	j for
end_for:
	ori $2, $0, 4
	or $4, $0, $8
	#syscall
	
	# nbzero = 0
	ori $12, $0, 0
	# i = 0
	ori $9, $0, 0
	
while:
	sltiu $10, $9, 9
	beq $10, $0, end_while
	addu $11, $8, $9
	lb $11, 0($11)
	addiu $11, $11, -0x30
	bne $11, $0, end_while
	addiu $12, $12, 1
	addiu $9, $9, 1
	j while
end_while:
	ori $2, $0, 1
	or $4, $0, $12
	#syscall

	ori $9, $0, 0
	ori $10, $0, 10
	subu $10, $10, $12
for2:
	sltu $11, $9, $10
	beq $11, $0, end_for2
	addu $13, $8, $9
	addu $14, $13, $12
	lb $15, 0($14)
	sb $15, 0($13)
	addiu $9, $9, 1
	j for2
end_for2:
	ori $2, $0, 4
	or $4, $0, $8
	syscall

	# épilogue
	addiu $29, $29, 16
	ori $2, $0, 10
	syscall